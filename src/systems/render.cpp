//
//  render.cpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 7/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#include "render.hpp"

#include <SDL_render.h>
#include "sdl_check.hpp"
#include "../utils/each.hpp"
#include "../comps/input.hpp"
#include "../comps/arena.hpp"
#include "../comps/graphics.hpp"
#include <entt/entity/registry.hpp>

void renderBackground(entt::registry &reg, const DrawCtx ctx) {
  int texW, texH;
  SDL_CHECK(SDL_QueryTexture(ctx.tex, nullptr, nullptr, &texW, &texH));
  entt::each(reg, [=](SpriteRect rect, BackgroundSprite) {
    int repeatW = rect.width / texW + 1.0f;
    int repeatH = rect.height / texH + 1.0f;
    const SDL_Rect srcrect = {0, 0, texW, texH};
    for (int y = 0; y != repeatH; ++y) {
      for (int x = 0; x != repeatW; ++x) {
        const SDL_FRect dstrect = {
          rect.x + x * texW,
          rect.y + y * texH,
          static_cast<float>(texW),
          static_cast<float>(texH)
        };
        SDL_CHECK(SDL_RenderCopyF(ctx.ren, ctx.tex, &srcrect, &dstrect));
      }
    }
  });
}

namespace {

void renderRect(
  const DrawCtx ctx,
  const SpriteRect &rect,
  const Sprite sprite,
  const float originX,
  const float originY
) {
  const SDL_Rect srcrect = {0, 0, 1, 1};
  const SDL_FRect dstrect = {rect.x, rect.y, rect.width, rect.height};
  const SDL_FPoint origin = {originX, originY};
  SDL_CHECK(SDL_SetTextureColorMod(ctx.tex, sprite.r, sprite.g, sprite.b));
  SDL_CHECK(SDL_RenderCopyExF(
    ctx.ren, ctx.tex, &srcrect, &dstrect, rect.angle, &origin, SDL_FLIP_NONE
  ));
}

void renderRelativeRect(
  const DrawCtx ctx,
  const SpriteRect &baseRect,
  const SpriteRect &relRect,
  const Sprite sprite
) {
  const SpriteRect rect = {
    baseRect.x + relRect.x,
    baseRect.y + relRect.y,
    relRect.width,
    relRect.height,
    baseRect.angle
  };
  const float originX = baseRect.width / 2.0f - relRect.x;
  const float originY = baseRect.height / 2.0f - relRect.y;
  renderRect(ctx, rect, sprite, originX, originY);
}

}

void renderSprite(entt::registry &reg, const DrawCtx ctx) {
  entt::each(reg, [&](entt::entity e, SpriteRect rect, Sprite sprite) {
    renderRect(ctx, rect, sprite, rect.width / 2.0f, rect.height / 2.0f);
    
    if (auto *command = reg.try_get<MotionCommand>(e)) {
      const Sprite thrustSprite = {255, 109, 0};
      
      if (command->forward) {
        const float width = rect.width / 4.0f;
        const float height = rect.height / 3.0f;
        const float x = -width;
        const float y = (rect.height - height) / 2.0f;
        renderRelativeRect(ctx, rect, {x, y, width, height, 0}, thrustSprite);
      }
      
      if (command->reverse) {
        const float width = rect.width / 5.0f;
        const float height = rect.height / 4.0f;
        const float x = rect.width;
        const float y = (rect.height - height) / 2.0f;
        renderRelativeRect(ctx, rect, {x, y, width, height, 0}, thrustSprite);
      }
      
      {
        const float width = rect.width / 6.0f;
        const float height = width;
        const float x1 = rect.width / 4.0f - width / 2.0f;
        const float x2 = rect.width * 3.0f/4.0f - width / 2.0f;
        const float y1 = -height;
        const float y2 = rect.height;
        
        if (command->ccw && !command->cw) {
          renderRelativeRect(ctx, rect, {x1, y1, width, height, 0}, thrustSprite);
          renderRelativeRect(ctx, rect, {x2, y2, width, height, 0}, thrustSprite);
        }
        
        if (command->cw && !command->ccw) {
          renderRelativeRect(ctx, rect, {x1, y2, width, height, 0}, thrustSprite);
          renderRelativeRect(ctx, rect, {x2, y1, width, height, 0}, thrustSprite);
        }
      }
      
      {
        const float width = rect.width / 5.0f;
        const float height = width;
        const float x = (rect.width - width) / 2.0f;
        
        if (command->left) {
          renderRelativeRect(ctx, rect, {x, rect.height, width, height, 0}, thrustSprite);
        }
        
        if (command->right) {
          renderRelativeRect(ctx, rect, {x, -height, width, height, 0}, thrustSprite);
        }
      }
    }
  });
  SDL_CHECK(SDL_SetTextureColorMod(ctx.tex, 255, 255, 255));
}

void renderBar(entt::registry &reg, const DrawCtx ctx) {
  // TODO: Is this faster with three separate loops?
  entt::each(reg, [&](const BarRect rect) {
    const int progWidth = rect.width * rect.progress + 0.5f;
    const int antiWidth = rect.width - progWidth;
    const SDL_Rect value = {rect.x, rect.y, progWidth, rect.height};
    const SDL_Rect anti = {rect.x + progWidth, rect.y, antiWidth, rect.height};
    const SDL_Rect outline = {rect.x - 1, rect.y - 1, rect.width + 2, rect.height + 2};
    SDL_CHECK(SDL_SetRenderDrawColor(ctx.ren, 0, 255, 0, 255));
    SDL_CHECK(SDL_RenderFillRect(ctx.ren, &value));
    SDL_CHECK(SDL_SetRenderDrawColor(ctx.ren, 255, 0, 0, 255));
    SDL_CHECK(SDL_RenderFillRect(ctx.ren, &anti));
    SDL_CHECK(SDL_SetRenderDrawColor(ctx.ren, 255, 255, 255, 255));
    SDL_CHECK(SDL_RenderDrawRect(ctx.ren, &outline));
  });
}

void renderMap(entt::registry &reg, const DrawCtx ctx) {
  SDL_CHECK(SDL_SetRenderDrawBlendMode(ctx.ren, SDL_BLENDMODE_BLEND));
  SDL_CHECK(SDL_SetRenderDrawColor(ctx.ren, 63, 63, 63, 63));
  SDL_CHECK(SDL_RenderFillRect(ctx.ren, nullptr));
  
  SDL_CHECK(SDL_SetTextureBlendMode(ctx.tex, SDL_BLENDMODE_BLEND));
  SDL_CHECK(SDL_SetTextureColorMod(ctx.tex, 255, 255, 255));
  SDL_CHECK(SDL_SetTextureAlphaMod(ctx.tex, 127));
  SDL_CHECK(SDL_RenderCopy(ctx.ren, ctx.tex, nullptr, nullptr));
  
  SDL_CHECK(SDL_SetRenderDrawBlendMode(ctx.ren, SDL_BLENDMODE_NONE));
  
  entt::each(reg, [&](const SpriteRect rect, CameraFocus) {
    const float size = 4.0f;
    const SDL_FRect dstrect = {
      rect.x + (rect.width - size) / 2.0f,
      rect.y + (rect.height - size) / 2.0f,
      size,
      size
    };
    SDL_CHECK(SDL_SetRenderDrawColor(ctx.ren, 255, 255, 255, 255));
    SDL_CHECK(SDL_RenderFillRectF(ctx.ren, &dstrect));
  });
  
  entt::each(reg, [&](const SpriteRect rect, const Sprite sprite, Beacon) {
    const SDL_FRect dstrect = {rect.x, rect.y, rect.width, rect.height};
    SDL_CHECK(SDL_SetRenderDrawColor(ctx.ren, sprite.r, sprite.g, sprite.b, 255));
    SDL_CHECK(SDL_RenderFillRectF(ctx.ren, &dstrect));
  });
}
