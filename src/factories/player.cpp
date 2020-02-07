//
//  player.cpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 7/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#include "player.hpp"

#include "../comps/input.hpp"
#include "../comps/timers.hpp"
#include "../comps/params.hpp"
#include "../comps/physics.hpp"
#include "../comps/graphics.hpp"

#include <box2d/b2_body.h>
#include <box2d/b2_world.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>

#include <entt/entity/registry.hpp>

namespace {

Physics makePhysics(b2World &world) {
  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.angularDamping = 8.0f;
  bodyDef.linearDamping = 0.1f;
  bodyDef.position = {64.0f, 36.0f};
  bodyDef.angle = 0;
  
  b2PolygonShape shape;
  shape.SetAsBox(1.5f, 1.0f);
  
  b2FixtureDef fixDef;
  fixDef.shape = &shape;
  fixDef.density = 1.0f;
  
  b2Body *body = world.CreateBody(&bodyDef);
  body->CreateFixture(&fixDef);
  return {body, 3.0f, 2.0f};
}

}

entt::entity makePlayer(entt::registry &reg) {
  entt::entity e = reg.create();
  reg.assign<Physics>(e, makePhysics(reg.ctx<b2World>()));
  reg.assign<SpriteRect>(e);
  reg.assign<Sprite>(e, Sprite{63, 63, 191});
  reg.assign<KeyInput>(e);
  reg.assign<MoveInput>(e);
  MoveParams moveParams;
  moveParams.thrustForce = 60.0f;
  moveParams.turnTorque = 200.0f;
  reg.assign<MoveParams>(e, moveParams);
  reg.assign<BlasterInput>(e);
  BlasterParams blasterParams;
  blasterParams.rof = 2.0f;
  blasterParams.speed = 50.0f;
  reg.assign<BlasterParams>(e, blasterParams);
  reg.assign<BlasterTimer>(e, std::uint32_t{});
  return e;
}
