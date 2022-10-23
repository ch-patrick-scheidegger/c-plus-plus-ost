#ifndef FIELD5_HPP_
#define FIELD5_HPP_

#include <iosfwd>
struct Field5 {
	explicit Field5(unsigned x = 0u) :
			val { x % 5 } {
	}

	auto value() const -> unsigned {
		return val;
	}

	constexpr operator unsigned() const {
		return val;
	}

	auto operator==(Field5 const &r) const -> bool = default;

	auto operator+=(Field5 const &r) -> Field5& {
		val = (val + r.value()) % 5;
		return *this;
	}

	auto operator*=(Field5 const &r) -> Field5& {
		val = (val * r.value()) % 5;
		return *this;
	}

	auto operator+(Field5 const &r) const -> Field5 {
		return Field5 { val + r.val };
	}

	auto operator*(Field5 const &r) const -> Field5 {
		return Field5 { val * r.val };
	}

	auto operator-=(Field5 const &r) -> Field5& {
		val = (5 + val - r.value()) % 5;
		return *this;
	}

	auto operator/=(Field5 const &r) -> Field5& {
		return *this *= r.inverse();
	}

private:
	auto inverse() const -> Field5 {
		if (val == 2)
			return Field5 { 3 };
		if (val == 3)
			return Field5 { 2 };
		return *this; // not exaclty right for 0
	}
	unsigned val;
};

inline auto operator-(Field5 l, Field5 const &r) -> Field5 {
	l -= r;
	return l;
}

inline auto operator/(Field5 l, Field5 const &r) -> Field5 {
	l /= r;
	return l;
}

auto operator <<(std::ostream &out, Field5 const &r) -> std::ostream&;

#endif
