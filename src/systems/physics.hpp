//
//  physics.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 7/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef systems_physics_hpp
#define systems_physics_hpp

#include <box2d/b2_math.h>
#include <entt/entity/fwd.hpp>

void initializePhysics(entt::registry &);
void stepPhysics(entt::registry &, float);
void limitVelocity(entt::registry &);
void setTransform(entt::registry &, entt::entity, b2Vec2, float);
void setMotion(entt::registry &, entt::entity, b2Vec2, float);

#endif
