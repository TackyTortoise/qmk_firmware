#include "quantum.h"
#include <stdio.h>

enum layer_number {  
  _COLEMAK = 0,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ADJUST_TRI = _ADJUST | _RAISE | _LOWER
};

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _COLEMAK:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Colemak");
            break;
        case _QWERTY:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Qwerty");
            break;
        case _RAISE:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
            break;
        case _LOWER:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
            break;
        case _ADJUST:
        case _ADJUST_TRI:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
            break;
        default:
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
    }

    return layer_state_str;
}
