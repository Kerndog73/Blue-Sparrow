//
//  arena.cpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 9/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#include "arena.hpp"

#include "physics.hpp"
#include "../comps/graphics.hpp"
#include <entt/entity/registry.hpp>

entt::entity makeArena(entt::registry &reg, const float width, const float height) {
  entt::entity e = reg.create();
  setArenaPhysics(reg, e, width, height);
  reg.assign<BackgroundSprite>(e);
  reg.assign<SpriteRect>(e);
  return e;
}

entt::entity makeAsteroid(entt::registry &reg) {
  entt::entity e = reg.create();
  setAsteroidPhysics(reg, e);
  reg.assign<SpriteRect>(e);
  reg.assign<Sprite>(e, Sprite{129, 76, 38});
  return e;
}
