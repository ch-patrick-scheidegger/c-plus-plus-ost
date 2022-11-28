#ifndef STATIC_MEMBER_HPP_
#define STATIC_MEMBER_HPP_

template <typename T>
struct StaticMember{
  inline static int member{sizeof(T)};
};

#endif
