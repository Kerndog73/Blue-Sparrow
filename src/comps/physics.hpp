//
//  physics.hpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 7/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#ifndef physics_hpp
#define physics_hpp

class b2Body;

/// A Box2D physics body
struct Physics {
  b2Body *body = nullptr;
  float width, height;
};

#endif