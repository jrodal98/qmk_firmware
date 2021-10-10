#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// macros: https://docs.qmk.fm/#/feature_macros
// Definitions are in process_record_user
enum custom_keycodes {
    DUNDER = SAFE_RANGE,
    ARROW,
    SPACED_EQUAL,
};

/*
 * 1. configure layout here: https://config.qmk.fm/#/lily58/rev1/LAYOUT
 * 2. run qmk json2c -o <path to output> <path to json>
 * 3. copy-paste into here
 * 4. To go in opposite direction, run qmk c2json -km KEYMAP -kb KEYBOARD [-q] [--no-cpp] [-o OUTPUT] filename
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MEH, KC_LALT, KC_LGUI, KC_SPC, MO(_LOWER), KC_ENT, KC_BSPC, MO(_RAISE), MO(_ADJUST)),
	[_LOWER] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_PIPE, KC_GRV, KC_UNDS, DUNDER, ARROW, SPACED_EQUAL, KC_PEQL, KC_TRNS, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_UNDS, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS),
	[_RAISE] = LAYOUT(KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MNXT, KC_BRID, KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, KC_1, KC_MS_U, KC_3, KC_4, KC_5, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_0, KC_TRNS, KC_F1, KC_MS_L, KC_MS_D, KC_MS_R, KC_F5, KC_F6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS, KC_TRNS),
	[_ADJUST] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
    case DUNDER:
        if (record->event.pressed) {
            // when keycode DUNDER is pressed
            SEND_STRING("____"SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        } else {
            // when keycode DUNDER is released
        }
        break;

    case ARROW:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(" -> ");
        }
        break;

    case SPACED_EQUAL:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING(" = ");
        }
        break;
    }
    return true;
}
