#ifndef MIN_H_
#define MIN_H_


template <typename T>
auto min(T left, T right) -> T {
  return left < right ? left : right;
}


#endif /* MIN_H_ */
