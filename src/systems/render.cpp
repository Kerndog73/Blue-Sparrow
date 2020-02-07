//
//  render.cpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 7/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#include "render.hpp"

#include "sdl_check.hpp"
#include <SDL2/SDL_render.h>
#include "../comps/graphics.hpp"
#include <entt/entity/registry.hpp>

void renderSprite(entt::registry &reg, SDL_Renderer *ren, SDL_Texture *tex) {
  reg.view<SpriteRect, Sprite>().each([=](auto rect, auto sprite) {
    const SDL_Rect srcrect = {0, 0, 1, 1};
    const SDL_FRect dstrect = {rect.x, rect.y, rect.width, rect.height};
    SDL_CHECK(SDL_SetTextureColorMod(tex, sprite.r, sprite.g, sprite.b));
    SDL_CHECK(SDL_RenderCopyExF(
      ren, tex, &srcrect, &dstrect, rect.angle, nullptr, SDL_FLIP_NONE
    ));
  });
  SDL_CHECK(SDL_SetTextureColorMod(tex, 255, 255, 255));
}