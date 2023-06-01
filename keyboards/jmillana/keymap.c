// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
#include QMK_KEYBOARD_H
#include <stdio.h>

enum userspace_layers {
    _BASE = 0,
    _EXTRA,
    _TAP,
    _BUTTON,
    _NAV,
    _MOUSE,
    _MEDIA,
    _NUM,
    _SYM,
    _FUN
};

// _NAV,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_fun_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_RED});
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_BLUE});
const rgblight_segment_t PROGMEM layer_sym_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_GREEN});
const rgblight_segment_t PROGMEM layer_mouse_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_ORANGE});
const rgblight_segment_t PROGMEM layer_nav_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_TEAL});
const rgblight_segment_t PROGMEM layer_media_lights[]    = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_PURPLE});
const rgblight_segment_t PROGMEM layer_extra_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_PINK});
const rgblight_segment_t PROGMEM layer_tap_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_YELLOW});
const rgblight_segment_t PROGMEM layer_button_lights[] = RGBLIGHT_LAYER_SEGMENTS({0, RGBLED_NUM, HSV_WHITE});


// _MOUSE,
// Light on inner column and underglow

//_MEDIA
// havent worked out how to do each side individually either

// _SYMBOLS   // light up top row
// _NUMBERS   // light up top row
// _FUN   // light up top row
// RGBLIGHT_LAYER_SEGMENTS({0,RGBLED_NUM, HSV_GREEN}, {9, 2, HSV_GREEN}, {17, 2, HSV_GREEN}, {23, 2, HSV_GREEN});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_nav_lights,
    layer_mouse_lights,
    layer_media_lights,
    layer_num_lights,
    layer_sym_lights,
    layer_fun_lights,
    layer_extra_lights
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    rgblight_mode(10); // haven't found a way to set this in a more useful way
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _NAV)); // OK
    rgblight_set_layer_state(1, layer_state_cmp(state, _MOUSE)); // OK
    rgblight_set_layer_state(2, layer_state_cmp(state, _MEDIA));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
    rgblight_set_layer_state(4, layer_state_cmp(state, _SYM));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FUN));
    rgblight_set_layer_state(6, layer_state_cmp(state, _EXTRA));
    rgblight_set_layer_state(7, layer_state_cmp(state, _TAP));
    rgblight_set_layer_state(8, layer_state_cmp(state, _BUTTON));

    return state;
}
