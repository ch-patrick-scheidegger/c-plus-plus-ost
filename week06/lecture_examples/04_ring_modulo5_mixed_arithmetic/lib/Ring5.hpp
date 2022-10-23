#ifndef RING5_H_
#define RING5_H_

#include <iosfwd>
#include <boost/operators.hpp>

struct Ring5 {
  explicit Ring5(unsigned x = 0u);

  auto value() const -> unsigned { return val; }

  explicit operator unsigned() const { return val; }

  auto operator==(Ring5 const &r) const -> bool = default;

  auto operator+=(Ring5 const &r) -> Ring5 {
    val = (val + r.value()) % 5;
    return *this;
	}

	auto operator+=(unsigned r) -> Ring5 {
		val = (val + r) % 5;
		return *this;
	}

	auto operator+(Ring5 const &r) const -> Ring5 {
		Ring5 res = *this;
		res += r;
		return res;
	}

	friend auto operator+(unsigned l, Ring5 const &r) -> Ring5 {
		return Ring5 { l + r.val };
	}

	friend auto operator+(Ring5 l, unsigned r) -> Ring5 {
		l.val = (l.val + r) % 5;
		return l;
	}

	auto operator*=(Ring5 const &r) -> Ring5 {
		val = (val * r.value()) % 5;
		return *this;
	}

	auto operator*=(unsigned r) -> Ring5 {
		val = (val * r) % 5;
		return *this;
	}

	auto operator*(unsigned r) const -> Ring5 {
		Ring5 res { r };
		res.val = (res.val * val) % 5;
		return res;
	}

private:
	unsigned val;
};

inline auto operator*(Ring5 l, Ring5 const &r) -> Ring5 {
	l *= r;
	return l;
}

inline auto operator*(unsigned l, Ring5 const &r) -> Ring5 {
	return Ring5 { l * r.value() };
}

auto operator <<(std::ostream &out, const Ring5 &r) -> std::ostream&;

#endif
