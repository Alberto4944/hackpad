// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬
     * │ 1 │ 
     * ├───┼───┼
     * │ 2 │ 3 │
     * ├───┼───┼
     * │ 4 │ 5 │
     * 
     */
    [0] = LAYOUT(
        KC_1,   KC_NO,
        KC2,   KC_3,
        KC_4,   KC_5
    )
};

const uint16_t PROGMEM encoder_map[][1][2] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD) },
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}