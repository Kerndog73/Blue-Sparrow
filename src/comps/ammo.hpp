//
//  ammo.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 10/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef comps_ammo_hpp
#define comps_ammo_hpp

/*
struct MissileAmmo {
  int n;
};
*/

/// The remaining durability of the hull of a ship
struct Hull {
  int h;
};

/// The damage that a missile or blaster bolt deals to its target
struct Damage {
  int d;
};

/// The number of coins that the player has
struct Coins {
  int c;
};

#endif
