#include QMK_KEYBOARD_H
#include "keymap_german.h"


extern keymap_config_t keymap_config;

enum plaid_layers {
  _QWERTY,
  _KOY,
  _KOY2,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum plaid_keycodes {
  KOY = SAFE_RANGE,
  KOY2,
  QWERTY,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define OSLOW OSL(_LOWER)
#define OSRAI OSL(_RAISE)
#define N_PASTE LCTL(KC_V) // CTRL+V
#define N_COPY LCTL(KC_C) // CTRL+C
#define N_CUT LCTL(KC_X) // CTRL+X
#define N_UNDO LCTL(DE_Z) // CTRL+Z
#define N_REDO LCTL(DE_Y) // CTRL+Y
#define N_SPC SFT_T(KC_SPC) //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  | RAlt | GUI  |Shift |Space |Lower |Raise |Space | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_RALT, KC_LALT, KC_LGUI, KC_LSFT, KC_SPC,  LOWER,   RAISE,   N_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* KOY
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   K  |   .  |   O  |   ,  |   Y  |   V  |   G  |   C  |   L  |   ß  |  Z   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   H  |   A  |   E  |   I  |   U  |   D  |   T  |   R  |   N  |   S  |  F   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   X  |   Q  |   Ä  |   Ü  |   Ö  |   B  |   P  |   W  |   M  |   J  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  | RAlt | GUI  |Shift |Space |Lower |Raise |Space | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_KOY] = LAYOUT_ortho_4x12(
   KC_ESC,  DE_K,    DE_DOT,  DE_O,    DE_COMM, DE_Y,    DE_V,    DE_G,   DE_C,    DE_L,    DE_SS,   DE_Z,    
   KC_TAB,  DE_H,    DE_A,    DE_E,    DE_I,    DE_U,    DE_D,    DE_T,   DE_R,    DE_N,    DE_S,    DE_F,     
   KC_LCTL, DE_X,    DE_Q,    DE_AE,   DE_UE,   DE_OE,   DE_B,    DE_P,   DE_W,    DE_M,    DE_J,    KC_ENT,
   KC_RALT, KC_LALT, KC_LGUI, KC_BSPC, N_SPC,   LOWER,   RAISE,   N_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
),

/* KOY2
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   K  |   .  |   O  |   ,  |   Y  |   V  |   G  |   C  |   L  |   ß  |  Z   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   H  |   A  |   E  |   I  |   U  |   D  |   T  |   R  |   N  |   S  |  F   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   X  |   Q  |   Ä  |   Ü  |   Ö  |   B  |   P  |   W  |   M  |   J  |Up    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RAlt  | Win | Alt  | BSpc |Space |Lower |Raise |Space |Enter | Left |Right |Down  |
 * `-----------------------------------------------------------------------------------'
 */
[_KOY2] = LAYOUT_ortho_4x12(
   KC_ESC,  DE_K,    DE_DOT,  DE_O,    DE_COMM, DE_Y,    DE_V,    DE_G,   DE_C,    DE_L,    DE_SS,   DE_Z,    
   KC_TAB,  DE_H,    DE_A,    DE_E,    DE_I,    DE_U,    DE_D,    DE_T,   DE_R,    DE_N,    DE_S,    DE_F,     
   KC_LCTL, DE_X,    DE_Q,    DE_AE,   DE_UE,   DE_OE,   DE_B,    DE_P,   DE_W,    DE_M,    DE_J,    KC_UP,
   KC_RALT, KC_LGUI, KC_LALT, KC_BSPC, N_SPC,   LOWER,   RAISE,   N_SPC,  KC_ENT,  KC_LEFT, KC_RGHT, KC_DOWN 
),

[_LOWER] = LAYOUT_ortho_4x12(
    _______, _______, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LESS, DE_MORE, DE_EQL,  DE_AMPR, _______,
    _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QST,  DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT  ,
    _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT, DE_PLUS, DE_PERC, DE_DQOT, DE_QUOT, DE_SCLN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_ortho_4x12(
   _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, _______, DE_7,     DE_8,   DE_9,    _______, _______,
   _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, DE_4,     DE_5,   DE_6,    DE_DOT,  _______,
   _______, N_CUT,   N_COPY,  N_PASTE, N_UNDO,  N_REDO,  DE_0,    DE_1,     DE_2,   DE_3,    DE_COMM, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_ortho_4x12(

    KOY    , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10,  KC_PWR,
    KOY2   , BL_TOGG, BL_DEC,  BL_INC,  _______, _______, _______, KC_F4  , KC_F5  , KC_F6  , _______, _______, 
    QWERTY , _______, _______, _______, _______, _______, KC_F10 , KC_F1  , KC_F2  , KC_F3  , _______, _______,
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KOY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_KOY);
      }
      return false;
      break;
    case KOY2:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_KOY2);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    }
  return true;
}
