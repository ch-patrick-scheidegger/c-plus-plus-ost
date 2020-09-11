#ifndef SWITCH_H_
#define SWITCH_H_

#include <iosfwd>

struct Switch {
	enum State : int;
	void pressButton();
	friend std::ostream& operator <<(std::ostream &out, Switch const &s);
private:
	State state;
};

#endif /* SWITCH_H_ */
