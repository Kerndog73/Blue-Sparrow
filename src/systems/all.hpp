//
//  all.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 13/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef systems_all_hpp
#define systems_all_hpp

#include <entt/entity/fwd.hpp>

struct SDL_Rect;
struct Camera;

void prePhysicsSystems(entt::registry &);
void postPhysicsSystems(entt::registry &);
void cameraSystems(entt::registry &, Camera &, SDL_Rect);

#endif
