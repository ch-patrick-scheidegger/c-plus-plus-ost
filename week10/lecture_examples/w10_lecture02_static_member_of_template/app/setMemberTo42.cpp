#include "staticMember.hpp"

auto setMemberTo42() -> int {
  using MemberType = StaticMember<int>;
  MemberType::member = 42;
  return MemberType::member;
}

