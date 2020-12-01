#include <iostream>

auto &out = std::cout; // hack for shortening the slide code, DO NOT COPY

struct Animal {
  void makeSound() {out << "---\n";}
  virtual void move() {out << "---\n";}
  Animal() {out << "animal born\n";}
  ~Animal() {out << "animal died\n";}
};

struct Bird : Animal {
  virtual void makeSound() {out << "chirp\n";}
  void move() {out << "fly\n";}
  Bird() {out << "bird hatched\n";}
  ~Bird() {out << "bird crashed\n";}
};

struct Hummingbird : Bird {
  void makeSound() {out << "peep\n";}
  virtual void move() {out << "hum\n";}
  Hummingbird() {out << "hummingbird hatched\n";}
  ~Hummingbird() {out << "hummingbird died\n";}
};

int main() {
  out << "(a)----------------------------\n";
    Hummingbird hummingbird;
    Bird bird = hummingbird;
    Animal & animal = hummingbird;
  out << "(b)-----------------------------\n";
    hummingbird.makeSound();
    bird.makeSound();
    animal.makeSound();
  out << "(c)-----------------------------\n";
    hummingbird.move();
    bird.move();
    animal.move();
  out << "(d)-----------------------------\n";
}
