#include QMK_KEYBOARD_H
#include "keymap.h"

#ifdef RGBLIGHT_LAYERS
#   include "rgblight.c"
#endif

#ifdef RAW_ENABLE
#   include "rawhid.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = | Backsp|
   * |-----------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P | [ | ] |  \  |
   * |-----------------------------------------------------------|
   * | Caps  | A | S | D | F | G | H | J | K | L | ; | ' | Enter |
   * |-----------------------------------------------------------|
   * | Shift  | Z | X | C | V | B | N | M | , | . | / |    Shift |
   * |-----------------------------------------------------------|
   * |Ctrl|GUI |Alt |         Space         | Alt| GUI| Fn | Ctrl|
   * `-----------------------------------------------------------'
   */
  [_BL] = LAYOUT_60_ansi(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, MO(_FL), KC_RCTL
  ),

  /* Keymap _FL: Function Layer 1
   * ,-----------------------------------------------------------.
   * | ~ |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|  DEL  |
   * |-----------------------------------------------------------|
   * |     |   |Up|  |  |  |Cal|   |Ins|   |PrSc|Sclk|Paus|      |
   * |-----------------------------------------------------------|
   * |      |Left|Down|Rig|  |  |  |  |   |   |Home|PgUp|        |
   * |-----------------------------------------------------------|
   * |       |BL-|BL+|BL|BLBRT|  |Vdn|Vup|Mute|End|PgDn|         |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |_ML|    |    |
   * `-----------------------------------------------------------'
   */
  [_FL] = LAYOUT_60_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, KC_UP,   _______, _______, _______, KC_CALC, _______,  KC_INS,  _______, KC_PSCR, KC_SCRL, KC_PAUS, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______,  _______, _______, KC_HOME, KC_PGUP,          _______,
    _______,          BL_DEC,  BL_INC,  BL_TOGG, BL_BRTG, _______, KC_VOLD, KC_VOLU,  KC_MUTE, KC_END,  KC_PGDN,          _______,
    _______, _______, _______,                            _______,                             _______, TO(_ML), _______, _______
  ),

  /* Keymap _ML: Macro Layer
   * ,-----------------------------------------------------------------------.
   * |N/A|F13¹|F14¹|F15¹|F16¹|F17¹|F18¹|F19¹|F20¹|F21¹|F22¹|F23¹|F24¹| Reset |
   * |-----------------------------------------------------------------------|
   * | N/A |F13²|F14²|F15²|F16²|F17²|F18²|F19²|F20²|F21²|F22²|F23²|F24²| N/A |
   * |-----------------------------------------------------------------------|
   * | N/A  |F13³|F14³|F15³|F16³|F17³|F18³|F19³|F20³|F21³|F22³|F23³|    F24³ |
   * |-----------------------------------------------------------------------|
   * | N/A    |F13⁴|F14⁴|F15⁴|F16⁴|F17⁴|F18⁴|F19⁴|F20⁴|F21⁴|F22⁴|       N/A  |
   * |-----------------------------------------------------------------------|
   * | N/A|F23⁴|N/A |                 N/A                | N/A|F24⁴| _BL|N/A |
   * `-----------------------------------------------------------------------'
   * 
   * ¹ RGUI (Right GUI)
   * ² RAG (Right Alt and Right GUI)
   * ³ RSG (Right Shift and Right GUI)
   * ⁴ LCAG (Left Control, Alt and GUI )
   */
  [_ML] = LAYOUT_60_ansi(
    KC_NO, RGUI(KC_F13), RGUI(KC_F14), RGUI(KC_F15), RGUI(KC_F16), RGUI(KC_F17), RGUI(KC_F18), RGUI(KC_F19), RGUI(KC_F20), RGUI(KC_F21), RGUI(KC_F22), RGUI(KC_F23), RGUI(KC_F24), QK_BOOT,  
    KC_NO, RAG(KC_F13), RAG(KC_F14), RAG(KC_F15), RAG(KC_F16), RAG(KC_F17), RAG(KC_F18), RAG(KC_F19), RAG(KC_F20), RAG(KC_F21), RAG(KC_F22), RAG(KC_F23), RAG(KC_F24), KC_NO,
    KC_NO, RSG(KC_F13),  RSG(KC_F14),  RSG(KC_F15),  RSG(KC_F16),  RSG(KC_F17),  RSG(KC_F18),  RSG(KC_F19),  RSG(KC_F20),  RSG(KC_F21),  RSG(KC_F22),  RSG(KC_F23),                RSG(KC_F24),  
    KC_NO,               LCAG(KC_F13), LCAG(KC_F14), LCAG(KC_F15), LCAG(KC_F16), LCAG(KC_F17), LCAG(KC_F18), LCAG(KC_F19), LCAG(KC_F20), LCAG(KC_F21), LCAG(KC_F22),               KC_NO,    
    KC_NO, LCAG(KC_F23), KC_NO,                                                  KC_NO,                                                  KC_NO,        LCAG(KC_F24), TO(_BL),      KC_NO
  )
};
