/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Combo definitions
const uint16_t PROGMEM combo_copy[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_cut[] = {KC_X, KC_V, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_copy, C(KC_INS)),   // X + C = Copy (Ctrl+Insert)
    COMBO(combo_paste, S(KC_INS)),  // C + V = Paste (Shift+Insert)
    COMBO(combo_cut, S(KC_DEL)),    // X + V = Cut (Shift+Delete)
};

/* Charybdis-specific features. */
#define CHARYBDIS_DRAGSCROLL_REVERSE_X
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_NUM,
    LAYER_SYM,
    LAYER_FUN,
    LAYER_POINTER,
};

// Home row mods - Left hand
#define HM_A    LALT_T(KC_A)
#define HM_S    LGUI_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)

// Home row mods - Right hand
#define HM_J    RSFT_T(KC_J)
#define HM_K    RCTL_T(KC_K)
#define HM_L    RGUI_T(KC_L)
#define HM_SCLN RALT_T(KC_SCLN)

// Layer-tap thumb keys
#define NAV_SPC  LT(LAYER_NAV, KC_SPC)
#define SYM_ENT  LT(LAYER_SYM, KC_ENT)
#define NUM_BSPC LT(LAYER_NUM, KC_BSPC)
#define FUN_DEL  LT(LAYER_FUN, KC_DEL)


// Pointer layer tap
#define PT_Z     LT(LAYER_POINTER, KC_Z)
#define PT_SLSH     LT(LAYER_POINTER, KC_SLSH)

// Custom keycodes for dragscroll/sniping tap-hold
enum custom_keycodes {
    DRG_ESC = SAFE_RANGE,
    SNP_X,
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        SNIPING,    HM_A,    HM_S,    HM_D,    HM_F,    KC_G,       KC_H,    HM_J,    HM_K,    HM_L, HM_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRGSCRL,    PT_Z,    SNP_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, PT_SLSH,  KC_ENT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  DRG_ESC,  NAV_SPC, KC_TAB,    SYM_ENT, NUM_BSPC,
                                           MS_BTN1, KC_LSFT,    FUN_DEL
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_AGIN,S(KC_INS),C(KC_INS),S(KC_DEL),KC_UNDO,XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SNIPING, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,    KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, CW_TOGG, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRGSCRL, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,    KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, XXXXXXX,     KC_ENT, KC_BSPC,
                                           MS_BTN1, KC_LSFT,     KC_DEL
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SNIPING, KC_PLUS,    KC_4,    KC_5,    KC_6,  KC_EQL,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRGSCRL,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,    XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_DOT,    KC_0, KC_MINS,    XXXXXXX, XXXXXXX,
                                           MS_BTN1, KC_LSFT,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SNIPING,   KC_LT,  KC_DLR, KC_PERC, KC_CIRC,   KC_GT,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRGSCRL, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,    XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, XXXXXXX,
                                           MS_BTN1, KC_LSFT,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUN] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX,  KC_F10,  KC_F11, KC_F12,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX,  XXXXXXX, KC_F7,   KC_F8,   KC_F9, KC_PSCR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       SNIPING,  XXXXXXX, KC_F4,   KC_F5,   KC_F6, KC_SCRL,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       DRGSCRL,  XXXXXXX, KC_F1,   KC_F2,   KC_F3, KC_PAUS,    XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                   KC_APP,  KC_SPC,  KC_TAB,    XXXXXXX, XXXXXXX,
                                           MS_BTN1, KC_LSFT,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

    [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        SNIPING,  KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT,XXXXXXX,   S_D_MOD, DPI_RMOD, DPI_MOD, S_D_RMOD, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        DRGSCRL,  XXXXXXX, SNIPING,XXXXXXX, XXXXXXX, XXXXXXX,   MS_BTN4, MS_BTN1, MS_BTN3,  MS_BTN2, XXXXXXX, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_ESC,  NAV_SPC,  KC_TAB,    SYM_ENT, NUM_BSPC,
                                           MS_BTN1, KC_LSFT,    FUN_DEL
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
//   [LAYER_POINTER] = LAYOUT(
//   // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SNP_TOG,    DRG_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,   S_D_MOD, DPI_RMOD, DPI_MOD, S_D_RMOD, SNIPING, XXXXXXX,
//   // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
//        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
//                                   MS_BTN1, MS_BTN3, MS_BTN2,    XXXXXXX, XXXXXXX,
//                                            DRGSCRL, XXXXXXX,    XXXXXXX
//   //                            ╰───────────────────────────╯ ╰──────────────────╯
//   ),
};

// void pointing_device_init_user(void) {
//     set_auto_mouse_layer(LAYER_POINTER);
//     set_auto_mouse_enable(true);
// }

// bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
//     switch (keycode) {
//         case DRGSCRL:
//         case DRG_TOG:
//         case SNIPING:
//         case SNP_TOG:
//         case DPI_MOD:
//         case S_D_MOD:
//             return true;
//         default:
//             return false;
//     }
// }

static uint16_t drg_esc_timer;
static uint16_t snp_tab_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRG_ESC:
            if (record->event.pressed) {
                drg_esc_timer = timer_read();
                charybdis_set_pointer_dragscroll_enabled(true);
            } else {
                charybdis_set_pointer_dragscroll_enabled(false);
                if (timer_elapsed(drg_esc_timer) < TAPPING_TERM) {
                    tap_code(KC_ESC);
                }
            }
            return false;
        case SNP_X:
            if (record->event.pressed) {
                snp_tab_timer = timer_read();
                charybdis_set_pointer_sniping_enabled(true);
            } else {
                charybdis_set_pointer_sniping_enabled(false);
                if (timer_elapsed(snp_tab_timer) < TAPPING_TERM) {
                    tap_code(KC_X);
                }
            }
            return false;
    }
    return true;
}