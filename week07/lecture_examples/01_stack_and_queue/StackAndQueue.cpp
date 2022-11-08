#include <iostream>
#include <queue>
#include <stack>
#include <string>


auto main() -> int {
  std::stack<std::string> lifo{};
  std::queue<std::string> fifo{};
  for (std::string s : {"Fall", "leaves", "after", "leaves", "fall"}) {
    lifo.push(s);
    fifo.push(s);
  }
  while (!lifo.empty()) {  // fall leaves after leaves Fall
    std::cout << lifo.top() << ' ';
    lifo.pop();
  }
  std::cout << '\n';
  while (!fifo.empty()) {  // Fall leaves after leaves fall
    std::cout << fifo.front() << ' ';
    fifo.pop();
  }
}
