/* Copyright 2020-2022 Lorenzo Leonini
 * SPDX-License-Identifier: GPL-2.0-only
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define BRANCH "HYPER_SPACE"

enum custom_layers {
	_QWERTY,
	_TARMAK1A,
	_TARMAK1B,
	_TARMAK2A,
	_TARMAK2B,
	_TARMAK3,
	_TARMAK4,
	_COLEMAKDH,

	_SPECIAL,
	_EXTRA,
	_ADM,
	_SETUP,
};

#define LW_GRV LWIN_T(KC_GRV)
#define RW_EQU RWIN_T(KC_EQUAL)
#define RW_BS RWIN_T(KC_BSLS)
#define LC_TAB LCTL_T(KC_TAB)
#define RC_QUT RCTL_T(KC_QUOT)
#define LS_BPC LSFT_T(KC_BSPC)
#define LA_BS LALT_T(KC_BSLS)
#define LW_F11 LWIN_T(KC_F11)
#define LC_APP LCTL_T(KC_APP)
#define LA_TOG LALT_T(RGB_TOG)
#define RW_F12 RWIN_T(KC_F12)

#define LLS_ESC LT(_SPECIAL, KC_ESC) 
#define LLS_RALT LT(_SPECIAL, KC_RALT) 
#define LLE_ENT LT(_EXTRA, KC_ENT) 
#define LLA_DEL LT(_ADM, KC_DEL)
#define SETUP MO(_SETUP)

enum custom_keycodes {
	REFLASH = SAFE_RANGE,
	LOREM,
	ADM_INF,

	HY_SPAC,
	LC_CIRC,
	RC_DLR,

	DF_QWER,
	DF_COLE,
	DF_TA1A,
	DF_TA1B,
	DF_TA2A,
	DF_TA2B,
	DF_TA3,
	DF_TA4,
};

// Not a mistake to have KC_LALT (also) on the right, RALT is kept for compose (LLS_RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RW_EQU,
			LC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),
	[_COLEMAKDH] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, RW_EQU,
			LC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),

	// https://dreymar.colemak.org/tarmak.html#tmk-dh
	[_TARMAK1A] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_J,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RW_EQU,
			LC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_N,    KC_E,    KC_L,    KC_SCLN, RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),
	[_TARMAK1B] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_J,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RW_EQU,
			LC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_M,    KC_N,    KC_E,    KC_L,    KC_SCLN, RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),
	[_TARMAK2A] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_J,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RW_EQU,
			LC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_M,    KC_N,    KC_E,    KC_L,    KC_SCLN, RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_B,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),
	[_TARMAK2B] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_F,    KC_R,    KC_B,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RW_EQU,
			LC_TAB,  KC_A,    KC_S,    KC_D,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_L,    KC_SCLN, RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_B,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),
	[_TARMAK3] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_F,    KC_J,    KC_B,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RW_EQU,
			LC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_L,    KC_SCLN, RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),
	[_TARMAK4] = LAYOUT_adm42_3x12_6(
			LW_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_U,    KC_I,    KC_Y,    KC_SCLN, RW_EQU,
			LC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_L,    KC_O,    RC_QUT,
			KC_LALT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
			                           LLS_ESC, LS_BPC,  LLA_DEL, LLE_ENT, HY_SPAC, LLS_RALT
	),

	[_SPECIAL] = LAYOUT_adm42_3x12_6(
			_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RW_BS,
			LC_CIRC, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_EXLM, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS, RC_DLR,
			_______, KC_AMPR, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_UNDS, KC_ASTR, KC_HASH, KC_PERC, KC_TILD, _______,
			                           KC_ESC,  _______, KC_DEL,  KC_ENT,  _______, KC_RALT
	),
	[_EXTRA] = LAYOUT_adm42_3x12_6(
			LW_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RW_F12,
			KC_LCTL, KC_PAUS, KC_INS,  KC_VOLD, KC_VOLU, KC_MUTE, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_APP,  KC_RCTL,
			_______, KC_SLEP, KC_PWR,  KC_MSTP, KC_MNXT, KC_MPLY, _______, KC_BRID, KC_BRIU, KC_PSCR, KC_WAKE, _______,
			                           KC_CAPS, _______, _______, _______, _______, KC_CAPS
	),
#ifdef RGB_MATRIX_ENABLE
	[_ADM] = LAYOUT_adm42_3x12_6(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_B, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUD, RGB_HUI, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,  RGB_M_P, RGB_SPD, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX,
			                           XXXXXXX, XXXXXXX, XXXXXXX, SETUP,   XXXXXXX, XXXXXXX
	),
#endif
#ifdef BACKLIGHT_ENABLE
	[_ADM] = LAYOUT_adm42_3x12_6(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_BRTG, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_TOGG, BL_DEC,  BL_INC,  XXXXXXX, XXXXXXX, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                           XXXXXXX, XXXXXXX, XXXXXXX, SETUP,   XXXXXXX, XXXXXXX
	),
#endif
#ifndef RGB_MATRIX_ENABLE
#ifndef BACKLIGHT_ENABLE
	[_ADM] = LAYOUT_adm42_3x12_6(
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
			                           XXXXXXX, XXXXXXX, XXXXXXX, SETUP,   XXXXXXX, XXXXXXX
	),
#endif
#endif
	[_SETUP] = LAYOUT_adm42_3x12_6(
			REFLASH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ADM_INF,
			XXXXXXX, DF_QWER, DF_COLE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOREM,   XXXXXXX, XXXXXXX,
			DF_TA1A, DF_TA1B, DF_TA2A, DF_TA2B, DF_TA3,  DF_TA4,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST,
			                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
	),

};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	 case RC_QUT:
		return true;
	 default:
		return false;
	}
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	 case LLS_ESC:
	 case LLS_RALT:
	 case LLE_ENT:
	 case LLA_DEL:
		return true;
	 default:
		return false;
	}
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	 case LLS_ESC:
	 case LLS_RALT:
		return true;
	 default:
		return false;
	}
}

/* HYPER_SPACE: Smart SPACE + SHIFT mod_tap key

Limitations:
- Before starting tap-hold, it's necessary to wait an additional TAPPING_TERM:
  we can't start before because it can be SPACE, SHIFT <key> or SPACE, SPACE/hold.
- Rolling shift with other mod_tap keys will not work: the mod_tap key send the tap key only
  on release, at the time, HYPER_SPACE as already been released and SHIFT is gone.
*/

// If space is not seen as space when typing fast, increase the delay.
// If shifted keys are not shifted, decrease the delay.
#define HS_OVERLAP_MS (TAPPING_TERM / 4)

static uint16_t hs_timer = 0;
static uint16_t hs_next_key_timer = 0;
static uint16_t hs_last_space_timer = 0;
static uint16_t hs_next_key = 0;
static bool hs_in_progress = false;
static bool hs_last_space = false;
static bool hs_potential_space_hold = false;
static int hs_release_space = false;
static int hs_space_hold = false;

bool hyper_space(uint16_t keycode, keyrecord_t *record) {

	if (!hs_in_progress) {
		if (keycode == HY_SPAC) {
			if (record->event.pressed) {
				// Will be considered as SPACE/hold only if repeated after a SPACE in the
				// TAPPING_TERM and if hold during TAPPING_TERM without any other key release
				if (hs_last_space && timer_elapsed(hs_last_space_timer) <= TAPPING_TERM) {
					hs_potential_space_hold = true;
				} else {
					hs_potential_space_hold = false;
				}
				hs_last_space = false;

				// The role of the key will be defined later
				hs_in_progress = true;
				// By default considered as SHIFT
				hs_release_space = false;
				// Buffer for the NEXT key
				hs_next_key = 0;
				// Start timer
				hs_timer = timer_read();
				// True if space + space (hold)
				hs_space_hold = false;

			} else { // release

				if (hs_release_space) {
					dprintf("HyperSpace: Release SPACE\n");
					unregister_code(KC_SPC);
				} else {
					dprintf("HyperSpace: Release SHIFT\n");
					unregister_code(KC_RSFT);
				}
				// Important!
				hs_space_hold = false;
			}
			return false;
		} else {
			// We are in space hold and another key is pressed, in that case we switch to SHIFT mode:
			if (hs_space_hold && record->event.pressed) {
				hs_space_hold = false;
				dprintf("HyperSpace: Release SPACE (hold)\n");
				unregister_code(KC_SPC);
				dprintf("HyperSpace: SHIFT\n");
				register_code(KC_RSFT);
				hs_release_space = false;
				return true;
			}
		}

	} else { // hs_in_progress

		hs_in_progress = false;

		if (record->event.pressed) { // Code below will concern another key than HYPER_SPACE
		
			if (keycode == HY_SPAC) dprintf("HyperSpace: BUG: HS pressed when already in progress\n");

			hs_potential_space_hold = false;

			// Next key press
			if (keycode >= KC_A && keycode <= KC_Z) {
				if (hs_next_key) {
					// More than one key is pressed after HYPER_SPACE, consider as SHIFT, press the previous
					// key and continue normal processing
					dprintf("HyperSpace: SHIFT-%u\n", hs_next_key);
					register_code(KC_RSFT);
					hs_release_space = false;
					register_code(hs_next_key);
					return true;
				} else {
					// Buffer key (and store time) until another event
					hs_in_progress = true;
					hs_next_key = keycode;
					hs_next_key_timer = timer_read();
					return false;
				}
			} else {
				// Another unrelated key is pressed, stop special ovelapping processing,
				// key will now immediately act as SHIFT and continue normal processing
				dprintf("HyperSpace: SHIFT (other key pressed)\n");
				register_code(KC_RSFT);
				hs_release_space = false;
				if (hs_next_key) { // unlikely (would mean that 3 keys are pressed ATM)
					register_code(hs_next_key);
				}
				return true;
			}

		} else { // release

			if (keycode == HY_SPAC) {
				if (hs_next_key) {
					// Here we have an overlap between HYPER_SPACE and the next key, we have
					// to determine if that's a SHIFT(key) or SPACE, key based on timings.
					if (timer_elapsed(hs_next_key_timer) < HS_OVERLAP_MS) {
						// Small overlap => SPACE + key
						dprintf("HyperSpace: SPACE, %u (overlap %ums < %u)\n",
								hs_next_key,
								timer_elapsed(hs_next_key_timer),
								HS_OVERLAP_MS);
						tap_code(KC_SPC);
						register_code(hs_next_key);
					} else {
						// Big overlap => SHIFT + key
						dprintf("HyperSpace: SHIFT-%u (overlap %ums >= %u)\n",
								hs_next_key,
								timer_elapsed(hs_next_key_timer),
								HS_OVERLAP_MS);
						register_code(KC_RSFT);
						register_code(hs_next_key);
						unregister_code(KC_RSFT);
					}
				} else { // No other key pressed
					if (timer_elapsed(hs_timer) <= TAPPING_TERM) {
						// Pure space
						dprintf("HyperSpace: SPACE\n");
						tap_code(KC_SPC);
						hs_last_space = true;
						hs_last_space_timer = timer_read();
					} else {
						// Nothing happened with HS key, also matrix_scan_user() hasn't
						// been called yet or we couldn't be here, we just do nothing
						// more (we already set hs_in_progress to false).
						dprintf("HyperSpace: No effect\n");
					}
				}
				return false;
			} else if (keycode == hs_next_key) {
				// HYPER_SPACE completely overlap the key (case 3 or 5)
				dprintf("HyperSpace: SHIFT-%u\n", keycode);
				register_code(KC_RSFT);
				hs_release_space = false;
				tap_code(keycode);
				return false;
			} else {
				// A key, pressed before HYPER_SPACE, is now released
				// 1) CTRL + SPACE, SHIFT + SPACE, ...
				// 2) Typing fast, a previous letter slightly overlap HYPER_SPACE
				// => Act as SPACE and continue normal processing
				hs_release_space = true;
				dprintf("HyperSpace: SPACE (prev overlap)\n");
				register_code(KC_SPC);
				if (hs_next_key) { // unlikely
					register_code(hs_next_key);
				}
				return true;
			}
		}
	}
	return true;
}

// Print output via keyboard
void print_keyboard(char *msg) {
	uint8_t temp = keyboard_report->mods;
	unregister_mods(temp);
	send_string(msg);
	register_mods(temp);
}

void adm_info(void) {
	print_keyboard("\n### ADM42 ###\n\n");
	print_keyboard("- TAPPING_TERM: " STR(TAPPING_TERM) "\n");
#ifdef CONSOLE_ENABLE
	print_keyboard("- Console enabled\n");
#else
	print_keyboard("- Console disabled\n");
#endif
	print_keyboard("\n" BRANCH " " __DATE__ " " __TIME__ "\n");
}

static uint16_t last_timer = 0;
static int last_key = 0;
bool cleanup_return(uint16_t keycode, keyrecord_t *record, bool value) {
	if (record->event.pressed) {
		last_key = keycode;
		last_timer = timer_read();
	}
	return value;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
	uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

	if (!hyper_space(keycode, record)) {
		return cleanup_return(keycode, record, false);
	}

	switch (keycode) {

		// Layer 1 emulation (shifted keys don't work in mod-tap keys)
	 case RC_DLR:
		if (record->event.pressed) {
			register_code(KC_RCTL);
		} else {
			unregister_code(KC_RCTL);
			if (last_key == keycode && timer_elapsed(last_timer) <= TAPPING_TERM) {
				send_string("$");
			}
		}
		return cleanup_return(keycode, record, false);

		// Layer 1 emulation (shifted keys don't work in mod-tap keys)
	 case LC_CIRC:
		if (record->event.pressed) {
			register_code(KC_LCTL);
		} else {
			unregister_code(KC_LCTL);
			if (last_key == keycode && timer_elapsed(last_timer) <= TAPPING_TERM) {
				send_string("^");
			}
		}
		return cleanup_return(keycode, record, false);

	 case DF_QWER:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_QWERTY);
			send_string("QWERTY layout");
		}
		return false;
	 case DF_COLE:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_COLEMAKDH);
			send_string("COLEMAKDH layout");
		}
		return false;
	 case DF_TA1A:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_TARMAK1A);
			send_string("TARMAK(DH) 1A layout");
		}
		return false;
	 case DF_TA1B:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_TARMAK1B);
			send_string("TARMAK(DH) 1B layout");
		}
		return false;
	 case DF_TA2A:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_TARMAK2A);
			send_string("TARMAK(DH) 2A layout");
		}
		return false;
	 case DF_TA2B:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_TARMAK2B);
			send_string("TARMAK(DH) 2B layout");
		}
		return false;
	 case DF_TA3:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_TARMAK3);
			send_string("TARMAK(DH) 3 layout");
		}
		return false;
	 case DF_TA4:
		if (record->event.pressed) {
			set_single_persistent_default_layer(_TARMAK4);
			send_string("TARMAK(DH) 4 layout");
		}
		return false;

	 case ADM_INF:
		if (record->event.pressed) {
			adm_info();
		}
		return false;

	 case REFLASH:
    eeconfig_init();
#ifdef RGB_MATRIX_ENABLE
    eeconfig_update_rgb_matrix_default();
#endif
#ifdef QMK_LED
		writePinLow(QMK_LED);
#endif
		reset_keyboard();
		return false;

	 case LOREM:
		send_string("Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Nullam \
libero sem, venenatis vel, iaculis vel, placerat sed, augue. Phasellus vitae \
dictum ac, viverra ac, imperdiet a, lacus. Nulla mi.");
		return false;

	 default:
		return cleanup_return(keycode, record, true);
	}
}

void matrix_scan_user(void) {
	if (hs_in_progress && timer_elapsed(hs_timer) > TAPPING_TERM) {
		// If TAPPING_TERM is elapsed, we now decide the role of HYPER_SPACE
		hs_in_progress = false;
		if (hs_potential_space_hold) {
			hs_space_hold = true;
			dprintf("HyperSpace: SPACE HOLD\n");
			register_code(KC_SPC);
			hs_release_space = true;
		} else {
			dprintf("HyperSpace: SHIFT (> TAPPING_TERM)\n");
			register_code(KC_RSFT);
			hs_release_space = false;
		}
		if (hs_next_key) {
			register_code(hs_next_key);
		}
	}
}

void keyboard_pre_init_kb(void) {
#ifdef QMK_LED
	setPinOutput(QMK_LED);
	writePinHigh(QMK_LED);
#endif
}

void keyboard_post_init_kb(void) {
	debug_enable = true;
	debug_matrix = false;
	debug_keyboard = false;
#ifdef QMK_LED
  writePinHigh(QMK_LED);
#endif
}

void suspend_power_down_kb(void) {
#ifdef QMK_LED
	writePinLow(QMK_LED);
#endif
}

void suspend_wakeup_init_kb(void) {
#ifdef QMK_LED
  writePinHigh(QMK_LED);
#endif
}
