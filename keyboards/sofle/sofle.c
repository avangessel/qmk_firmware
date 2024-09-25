// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#ifdef SWAP_HANDS_ENABLE

__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] =
    // The LAYOUT macro could work for this, but it was harder to figure out the
    // identity using it.

    // This is the identity layout.
/*
{
    { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} },
    { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} },
    { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} },
    { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} },
    { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} },

    { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} },
    { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} },
    { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} },
    { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} },
    { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} },
};
*/

    // This is the mirror, q <-> p, w <-> o, etc...
{
 { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5} },
 { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6} },
 { {0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7} },
 { {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8} },
 { {0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9} },

 { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0} },
 { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1} },
 { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2} },
 { {0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3} },
 { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4} },
};

#    ifdef ENCODER_MAP_ENABLE
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = {1, 0};
#    endif

#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

static void render_emblem(void) {
    static const char PROGMEM raw_emblem[] = {
        0,  0,  0,128,192,112, 56, 24, 12,134,134,130,131,131,  3,  1,  1,  3, 35, 35, 98,102, 70, 76, 88, 56,112,192,128,  0,  0,  0,248, 12,252,223,193,128,  0,  1,  1,  1, 13, 14,128,128,176,152,152,176,128,128, 14, 12,  0,  0,  0,  0,128,193,223,252, 12,248,  1,  3,  3, 31, 63,255,254,252,254,254,243,227,227,193,201,221,221,221,221,239,227,243,254,254,252,254,255, 63, 31,  3,  3,  1,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7,  7,  7, 15, 15, 15, 15, 15, 15, 15, 15,  7,  7,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_emblem, sizeof(raw_emblem));
}

/*static void render_logos(void) {
    static const char PROGMEM raw_logos[] = {
        0,  0,192, 32, 16,  8, 68,164, 66,  2, 34, 46, 62, 62, 94,126,180,124,232,208, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,127,128,  0,  0,136, 97,128, 52, 93, 63,166,231,221, 86, 20,193,118,193,255,255,195,254, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  6, 12,  8, 16, 38,245,230, 25,228, 96,199,153, 29, 97, 51, 99, 66,126, 13,243, 15,252,241, 14,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  2,127,112,247,  3,252,  6,120, 48, 48,224, 49,223,  0,255,255,  0,255,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  8,  0,111, 48, 67,184,224,128, 15,127,188,103,152, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,192,112,184,206,110,124,  0,  0,  1,  0,  1,  2,  4,  1,  1,  0, 60, 38,102, 54, 54,226,134, 12, 12,  8,  8, 14,  3, 25,124,230,  2,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,255,  1,227,227,194,  4,  0,  0,  0,  0,  1,  3,  2,  6, 12,206,  4, 12, 24, 56, 48,112,192,128,  0,  0,  0, 
        0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  3,  3,254,184, 16,  0,  0,  0,  0,128, 64,  2,  0, 12,  0,  0,  0,  0, 15,203,124, 16,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224, 62, 15,  1,194,116, 24,240, 32,  3,  6,240,120, 96,192,112, 24, 12,  6,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,227,230,226,230,243,112,192,131,134,134,134,131,128,224,240,112, 48, 32, 96,192,128,  0,  0,  0,  0,  0,  0, 48,240,112,190,255,255,255,255,255,255,255,255,255,255,255,255,255,191,255,124,184,248,184,  0,  0,  1,  0, 
        0,  8, 24, 56, 60,152,224,254,255,255,255,255,255,255,255,255,255,255,255,123, 63,127,126,126, 62, 58, 24,152,254,152,  0,  0, 16, 24, 28, 60, 52, 31,255,255,255,255,255,255,255,255,255,255,207,199,129,192,120,252,224,224,192,252,255,255,239, 63, 64,  0,  0,  0,  0,  0, 24, 30, 14, 13,  7,  3,  3, 19,243,241, 51,  3,  7, 15, 15, 15,167,199,  3, 11, 15, 29,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30, 63, 61, 65,119,125, 62, 12,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logos, sizeof(raw_logos));
}*/


void print_status_narrow(void) {
    oled_set_cursor(0, 6);
    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0: 
            oled_write_ln_P(PSTR("Main\n\n"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Game\n"), false);
            break;
        case 2:
            oled_write_ln_P(PSTR("Ctrl\nMacro"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Other\n"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR("CAPS"), led_usb_state.caps_lock);
    }
    oled_write_ln_P(PSTR("\n\n"), led_usb_state.caps_lock);
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        render_emblem();
        print_status_narrow();
    } else {
        //render_logos();
        render_emblem();
    }
    return true;
}

#endif

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif