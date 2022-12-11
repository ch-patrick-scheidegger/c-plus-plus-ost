#ifndef INHERITANCE_HPP
#define INHERITANCE_HPP

#include <iostream>

struct monster {
  monster() { std::cout << "a monster is bread\n"; }
  ~monster() { std::cout << "monster killed\n"; }
  auto health() -> void { std::cout << "immortal?\n"; }
  virtual auto attack() -> void { std::cout << "roar\n"; }
};

struct troll : monster {
  troll() { std::cout << "a troll grows\n"; }
  ~troll() { std::cout << "troll petrified\n"; }
  auto attack() -> void { swing_club(); }
  virtual auto swing_club() -> void {
    std::cout << "clubbing kills me\n";
    myhealth--;
  }
  void health() { std::cout << "troll-health:" << myhealth << '\n'; }

protected:
  int myhealth{10};
};

struct forum_troll : troll {
  forum_troll() : troll{} { std::cout << "not quite a monster\n"; }
  ~forum_troll() { std::cout << "troll banned\n"; }
   auto swing_club() -> void {
    std::cout << "swinging is healthy\n";
    myhealth++;
  }
  void attack() { std::cout << "write stupid things\n"; }
};

#endif