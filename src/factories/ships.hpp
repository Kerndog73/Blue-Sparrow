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

entt::entity makePlayer(entt::registry &, bool = false);
entt::entity makeScout(entt::registry &, Team);
entt::entity makeSniper(entt::registry &, Team);

void setShip(entt::registry &, entt::entity, Team);

void setPlayer(entt::registry &, entt::entity);
void setBeaconCaptureAI(entt::registry &, entt::entity);
void setSniperBehave(entt::registry &, entt::entity);

void setScoutSprite(entt::registry &, entt::entity, Team);
void setSniperSprite(entt::registry &, entt::entity, Team);

void setSniperMotion(entt::registry &, entt::entity);
void setSniperBlaster(entt::registry &, entt::entity);

void setSniperPosition(entt::registry &, entt::entity, float, float);

#endif
