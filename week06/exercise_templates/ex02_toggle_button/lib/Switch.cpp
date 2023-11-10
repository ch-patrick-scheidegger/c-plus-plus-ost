#include "Switch.hpp"

auto Switch::pressButton() -> void {
    if(state == blinking) {
        state = off;
    } else {
        state = static_cast<SwitchState>(static_cast<int>(state) + 1);
    }
}
