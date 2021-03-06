//
//  upgrade_view.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 16/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef ui_upgrade_view_hpp
#define ui_upgrade_view_hpp

#include "view.hpp"
#include <entt/entity/fwd.hpp>

class UpgradeView final : public View {
public:
  explicit UpgradeView(entt::registry &);
};

#endif
