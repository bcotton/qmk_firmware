#include QMK_KEYBOARD_H

layer_state_t layer_state_set_user(layer_state_t state) {

   return update_tri_layer_state(state, 1, 2, 3);
}
