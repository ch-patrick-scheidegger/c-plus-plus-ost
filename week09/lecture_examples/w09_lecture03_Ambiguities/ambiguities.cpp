template <typename T>
auto min(T left, T right) -> T {
  return left < right ? left : right;
}

auto main() -> int {
  min<int>(1, 1.0);
}
