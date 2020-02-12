//
//  ships.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 8/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef factories_ships_hpp
#define factories_ships_hpp

#include "../comps/teams.hpp"
#include <entt/entity/fwd.hpp>

entt::entity makePlayer(entt::registry &);
entt::entity makeScout(entt::registry &, Team);
entt::entity makeSniper(entt::registry &, Team);

void setShip(entt::registry &, entt::entity, Team);
void setHull(entt::registry &, entt::entity, int);

void setPlayer(entt::registry &, entt::entity);
void setOrbitBehave(entt::registry &, entt::entity);
void setSniperBehave(entt::registry &, entt::entity);

void setScoutSprite(entt::registry &, entt::entity, Team);
void setSniperSprite(entt::registry &, entt::entity, Team);

void setBasicMotion(entt::registry &, entt::entity);
void setBasicBlaster(entt::registry &, entt::entity);
void setBasicMissile(entt::registry &, entt::entity);

void setSniperMotion(entt::registry &, entt::entity);
void setSniperBlaster(entt::registry &, entt::entity);

// have sets of parameters in levels
// like level 1 blasters
// level 1 movement
// upgrade system will just choose levels

#endif
