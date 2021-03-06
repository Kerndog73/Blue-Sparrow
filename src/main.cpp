//
//  main.cpp
//  Blue Sparrow
//
//  Created by Indi Kernick on 6/2/20.
//  Copyright © 2020 Indiana Kernick. All rights reserved.
//

#include "ui/application.hpp"
#include "utils/scope_time.hpp"

int main() {
  Application app;
  app.run();
  SCOPE_TIME_PRINT();
}

// Multiplayer?

// What if we took the game in a completely different direction and gave the
// control over the AI players? I mean something like age of empires. Would that
// even work?

// Perhaps where the game is going is simply not a good idea and not going to
// work. I need to seriously consider the design before I go any futher. Even if
// I never finish this game, it's not a waste of time. You would have learnt
// from it. An obvious example is the path finding. You finally got A* to work
// correctly and efficiently.

// Code
//   Should we abandon entt::each?
//   Move constants into one place
//     there are a lot of them

// Objects
//   Turrets
//     Should beacons shoot?
//     Activation
//       shooting (same as beacons)
//       spending coins (gives coins a use beyond upgrading)
//     Killing enemies gives the killer coins, ammo and hull
//     Coins can be used to activate turrets
//     When turrets destroy ships, the coins either go nowhere or are stored in the turret
//     Turrets can be destroyed
//     Maybe they give coins to the killer?

// UI
//   Minimap
//     Should include the status of the beacons
//     Show allies
//     Show enemies that are visible to player or allies
//     Indicate whether beacons are being attacked
//   Left panel should be hidden and revealed to cover the game view
//   Show missile target lock

// Game mechanics
//   Winning and losing
//   Respawning
//   Healing over time
//   Maybe the ability to grab onto asteroids and move them around
//   A signal to send to team mates
//     e.g. "come help me" or "go destroy that thing" or "go defend that thing"

// AIs
//   Make AI feel more natural
//     For example, the orbit behaviour is a dead giveaway that it's a bot
//     Changing this will be really difficult
//   Fulfill the different roles of a team
//   Avoiding walls (missiles should do this)
//   Dodging (missiles should do this)
//   Defending
//   Guarding
//   Attacking
//   High level AI
//     We have behaviours (seek and orbit) that define an immediate goal
//     We have levels that define how well the immediate goal is reached
//     We need some way of switching between behaviours dynamically
//     Example:
//       if there are no nearby targets, wander around
//       if a target is spotted, engage in the target
//   Can/should we separate aiming behaviours from moving behaviours?

// Controls
//   Should we move away from digital controls and use analog controls?
//     Would make AIs a little bit more effective
//     AIs can take full advantage of it but players only get improved aiming
//     Might help improve aim assist for the player
//     https://gamedev.stackexchange.com/questions/1083/what-makes-aiming-in-a-console-first-person-shooter-feel-good/1325#1325

// Weapons
//   Drop mines that only effect the enemy
//     Perhaps fancy mines could have tiny blasters on them
//     Disappear after a while
//   Pulsing laser
//     Bouncing the laser off of mirrors could provide some interesting gameplay
//   Area of effect weapons (e.g. bombs)
//   Smart drones that can be spawned and shoot
//   Dumb drones that spin around and shoot
//   Missiles that shoot

// CMake
//   https://cmake.org/cmake/help/v3.11/module/FetchContent.html
//   https://discourse.libsdl.org/t/deploying-for-macos-how-are-we-supposed-to-do-it/23897
//   https://github.com/urho3d/Urho3D/tree/master/CMake/Toolchains
