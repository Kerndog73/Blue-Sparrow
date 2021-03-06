//
//  load_texture.cpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 9/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#include "load_texture.hpp"

#include <SDL_render.h>
#include "sdl_check.hpp"

SDL::Texture loadTexture(SDL_Renderer *renderer, const char *path) {
  return loadTexture(renderer, loadImage(path));
}

SDL::Texture loadTexture(SDL_Renderer *renderer, const Image &image) {
  SDL::Texture tex{SDL_CHECK(SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_ABGR8888,
    SDL_TEXTUREACCESS_STATIC,
    image.width, image.height
  ))};
  SDL_CHECK(SDL_UpdateTexture(tex.get(), nullptr, image.data.get(), image.width * 4));
  return tex;
}
