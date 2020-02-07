//
//  bolt.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 7/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef bolt_hpp
#define bolt_hpp

#include "../comps/teams.hpp"
#include <entt/entity/fwd.hpp>

entt::entity makeBolt(entt::registry &, Team);

#endif
