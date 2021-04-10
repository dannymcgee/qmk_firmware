#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layer definitions
#define _BASE 0
#define _FN1  1
#define _FN2  2

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
};

/**
 * Layout:
 *   [ ][ ]  [ ][ ][ ][ ][ ][ ][ ]    [ ][ ][ ][ ][ ][ ][     ][ ]
 *   [ ][ ]  [   ][ ][ ][ ][ ][ ]    [ ][ ][ ][ ][ ][ ][ ][   ][ ]
 *   [ ][ ]  [    ][ ][ ][ ][ ][ ]    [ ][ ][ ][ ][ ][ ][     ][ ]
 *   [ ][ ]  [     ][ ][ ][ ][ ][ ]    [ ][ ][ ][ ][ ][    ][ ][ ]
 *   [ ][ ]  [  ][  ][  ][  ][    ]    [       ][ ][ ][ ][ ][ ][ ]
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_65_with_macro(
		KC_MUTE, KC_ESC,     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,    XXXXXXX, \
		XXXXXXX, XXXXXXX,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL, \
		XXXXXXX, XXXXXXX,    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,              XXXXXXX, \
		XXXXXXX, XXXXXXX,    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,               XXXXXXX, \
		XXXXXXX, XXXXXXX,    KC_LCTL, KC_LGUI, KC_LALT, MO(_FN1),KC_SPC,                       KC_SPC,  KC_SPC,  KC_RALT, KC_APP,  KC_RCTL, KC_LEFT, KC_DOWN,             KC_RGHT
	),

	[_FN1] = LAYOUT_65_with_macro(
		_______, _______,    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,    _______, \
		_______, _______,    RGB_TOG, _______, _______, _______, _______, _______,             KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PAST, _______, _______, _______,    _______, \
		_______, _______,    KC_NLCK, _______, _______, _______, _______, _______,             KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______, _______, KC_PENT,             _______, \
		_______, _______,    _______, _______, _______, _______, _______, _______,             KC_P1,   KC_P2,   KC_P3,   KC_PPLS, _______, KC_MUTE, KC_VOLU,             _______, \
		_______, _______,    _______, _______, _______, _______, _______,                      KC_P0,   KC_P0,   KC_PDOT, MO(_FN2),_______, KC_MPRV, KC_VOLD,             KC_MNXT
	),

	[_FN2] = LAYOUT_65_with_macro(
		RESET,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, \
		XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, \
		XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, \
		XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, \
		XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX
	)
};

void encoder_update_user(uint8_t index, bool clockwise) {
	if (index == 0) {
		if (clockwise) tap_code(KC_VOLU);
		else           tap_code(KC_VOLD);
	}
	else if (index == 1) {
		if (clockwise) tap_code(KC_VOLU);
		else           tap_code(KC_VOLD);
	}
}
