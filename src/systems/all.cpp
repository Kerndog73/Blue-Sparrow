//
//  all.cpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 13/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#include "all.hpp"

#include "ai.hpp"
#include "camera.hpp"
#include "expire.hpp"
#include "behave.hpp"
#include "physics.hpp"
#include "collisions.hpp"
#include "find_target.hpp"
#include "apply_commands.hpp"
#include "../utils/scope_time.hpp"

void prePhysicsSystems(entt::registry &reg) {
  SCOPE_TIME("prePhysicsSystems");
  
  thinkBeaconCapture(reg);
  thinkSniper(reg);
  thinkMissile(reg);
  
  behaveOrbit(reg);
  behaveAim(reg);
  behaveSeek(reg);
  behaveStationary(reg);
  behaveMouse(reg);
  behaveNavigate(reg);
  behaveIdle(reg);
  behavePacifist(reg);
  
  applyMotionCommands(reg);
  applyBlasterCommands(reg);
  applyMissileCommands(reg);
  
  expireTemporary(reg);
}

void postPhysicsSystems(entt::registry &reg) {
  SCOPE_TIME("postPhysicsSystems");

  limitVelocity(reg);
  handleCollisions(reg);
  handlePostCollisions(reg);
}

void cameraSystems(entt::registry &reg, Camera &cam, const SDL_Rect viewport) {
  SCOPE_TIME("cameraSystems");

  updateCameraViewport(cam, viewport);
  moveCamera(reg, cam);
  
  writeSpriteRect(reg, cam);
  writeHullBarRect(reg, cam);
  writeBeaconBarRect(reg, cam);
}
