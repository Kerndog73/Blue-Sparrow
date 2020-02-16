//
//  stats_view.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 14/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef ui_stats_view_hpp
#define ui_stats_view_hpp

#include "view.hpp"
#include "sdl_delete.hpp"
#include <entt/entity/fwd.hpp>

union SDL_Event;

class StatsView final : public View {
public:
  explicit StatsView(entt::registry &);

  void init(SDL_Renderer *);
  bool event(const SDL_Event &);
  void render(SDL_Renderer *);

private:
  entt::registry &reg;
  SDL::Font font;
};

#endif