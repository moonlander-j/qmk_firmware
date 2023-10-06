#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
  ST_MACRO_36,
  ST_MACRO_37,
  ST_MACRO_38,
  PLAY_ZELDA
};


static float zelda_uncover_secret[][2] = SONG(ZELDA_UNCOVER_SECRET);



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    KC_EQUAL,                ST_MACRO_0,     TD(DANCE_5),    TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    TG(1),          
    KC_GRAVE,       KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_BSLASH,               ST_MACRO_1,     KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_MINUS,       
    KC_TAB,         KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_LBRACKET,             KC_RBRACKET,    KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,       
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                                    KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,       
    KC_LCTRL,       CAPS_WORD,      LGUI(KC_PSCREEN),TG(4),         MO(2),                          KC_LGUI,                 KC_CAPSLOCK,                    LGUI(KC_DOT),   KC_RCTRL,       KC_LEFT,        KC_DOWN,        KC_RIGHT,       
                                                                    KC_ENTER,       KC_LALT,        KC_RALT,                 KC_DELETE,      KC_BSPACE,      KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                 LALT(KC_MINUS), _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                 LALT(LSFT(KC_MINUS)),_______,   _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,        _______,                 _______,        _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        _______,        _______,        _______,        _______,                                                 _______,        _______,        _______,        _______,        _______,        _______,        
    _______,        _______,        LGUI(LSFT(KC_3)),_______,       MO(3),                          _______,                 _______,                        LGUI(LCTL(KC_SPACE)),_______,   _______,        _______,        _______,        
                                                                    _______,        _______,        _______,                 _______,        _______,        _______
  ),
  [2] = LAYOUT_moonlander(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                 _______,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         _______,        
    _______,        ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     _______,                 _______,        KC_F11,         KC_F12,         ST_MACRO_11,    _______,        _______,        ST_MACRO_12,    
    _______,        ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    _______,        _______,                 _______,        _______,        ST_MACRO_13,    _______,        ST_MACRO_14,    _______,        _______,        
    _______,        KC_PLUS,        KC_MINUS,       KC_ASTR,        KC_SLASH,       KC_EQUAL,                                                ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    ST_MACRO_18,    KC_PGUP,        ST_MACRO_19,    
    _______,        _______,        _______,        _______,        _______,                        _______,                 _______,                        _______,        _______,        KC_HOME,        KC_PGDOWN,      KC_END,         
                                                                    _______,        _______,        _______,                 _______,        _______,        _______
  ),
  [3] = LAYOUT_moonlander(
    _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ST_MACRO_20,             _______,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         _______,        
    _______,        ST_MACRO_21,    ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    _______,                 _______,        KC_F11,         KC_F12,         ST_MACRO_30,    _______,        _______,        ST_MACRO_31,    
    _______,        ST_MACRO_26,    ST_MACRO_27,    ST_MACRO_28,    ST_MACRO_29,    _______,        _______,                 _______,        _______,        ST_MACRO_32,    _______,        ST_MACRO_33,    _______,        _______,        
    _______,        KC_PLUS,        KC_MINUS,       KC_ASTR,        KC_SLASH,       KC_EQUAL,                                                ST_MACRO_34,    ST_MACRO_35,    ST_MACRO_36,    ST_MACRO_37,    KC_PGUP,        ST_MACRO_38,    
    _______,        _______,        _______,        _______,        _______,                        _______,                 _______,                        _______,        _______,        KC_HOME,        KC_PGDOWN,      KC_END,         
                                                                    _______,        _______,        _______,                 _______,        _______,        _______
  ),
  [4] = LAYOUT_moonlander(
    RESET,          _______,        _______,        _______,        _______,        _______,        DT_UP,                   _______,        _______,        KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    TG(5),          
    _______,        _______,        _______,        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,_______,    DT_PRNT,                 _______,        _______,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     _______,        
    _______,        _______,        KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,_______,      DT_DOWN,                 _______,        _______,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     _______,        
    PLAY_ZELDA,     TOGGLE_LAYER_COLOR,RGB_TOG,     RGB_MOD,        MOON_LED_LEVEL, _______,                                                 _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    _______,        
    AU_TOG,         MU_TOG,         MU_MOD,         _______,        _______,                        _______,                 _______,                        KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    _______,        
                                                                    _______,        _______,        _______,                 _______,        _______,        _______
  ),
  [5] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                XXXXXXX,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,        
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_BSLASH,               XXXXXXX,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_LBRACKET,             KC_RBRACKET,    KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,       
    KC_LCTRL,       KC_LGUI,        KC_LALT,        XXXXXXX,        XXXXXXX,                        _______,                 _______,                        XXXXXXX,        KC_RCTRL,       KC_LEFT,        KC_DOWN,        KC_RIGHT,       
                                                                    _______,        _______,        _______,                 _______,        _______,        _______
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {139,218,205}, {139,218,205}, {139,218,205}, {172,255,255}, {172,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {86,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {86,255,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {172,255,255}, {172,255,255}, {172,255,255}, {11,225,254}, {139,218,205}, {139,218,205}, {139,218,205}, {43,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {43,255,255}, {43,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {43,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {172,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205} },

    [1] = { {11,225,254}, {11,225,254}, {11,225,254}, {0,255,255}, {0,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {86,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {86,255,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {0,255,255}, {0,255,255}, {0,255,255}, {139,218,205}, {11,225,254}, {11,225,254}, {11,225,254}, {43,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {43,255,255}, {43,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {43,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {0,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {86,255,255}, {0,255,255}, {27,255,255}, {86,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {86,255,255}, {0,0,0}, {215,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {86,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {86,255,255}, {86,255,255}, {43,255,255}, {0,255,255}, {27,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {43,255,136}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {86,255,255}, {0,255,255}, {27,255,255}, {86,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {86,255,255}, {0,0,0}, {215,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {86,255,255}, {0,0,0}, {86,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {86,255,255}, {86,255,255}, {43,255,255}, {0,255,255}, {27,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {43,255,136}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,255,255}, {0,0,0}, {0,0,0}, {43,90,87}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,135}, {172,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {35,255,135}, {172,255,255}, {0,0,0}, {0,0,85}, {0,255,128}, {35,255,135}, {86,255,255}, {0,0,0}, {0,0,170}, {86,255,128}, {35,255,135}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {11,255,255}, {10,255,192}, {10,255,128}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,102}, {0,0,102}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,102}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,255,255}, {0,255,255}, {0,255,255}, {250,215,196}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {250,215,196}, {250,215,196}, {250,215,196}, {86,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {43,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {43,255,255}, {43,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {43,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return;
  }
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9) ));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_8) ));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_9) ));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_0) ));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_4) ));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_7) ));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_4) ));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_7) ));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_5) ));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1) ));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_6) SS_TAP(X_0) ));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_A) SS_TAP(X_1) ));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_2) ));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_F) ));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_0) ));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_5) SS_TAP(X_8) SS_TAP(X_8) ));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_C) ));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_D) ));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_E) ));
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_2) SS_TAP(X_2) ));
    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_2) SS_TAP(X_0) ));
    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_1) ));
    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_1) ));
    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_E) ));
    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_0) ));
    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_3) ));
    }
    break;
    case ST_MACRO_36:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_2) ));
    }
    break;
    case ST_MACRO_37:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_7) ));
    }
    break;
    case ST_MACRO_38:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_F) ));
    }
    break;

    case PLAY_ZELDA:
        if (record->event.pressed) {
            PLAY_SONG(zelda_uncover_secret);
        }
        return false;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[10];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_1);
        tap_code16(KC_1);
        tap_code16(KC_1);
    }
    if(state->count > 3) {
        tap_code16(KC_1);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_1); break;
        case SINGLE_HOLD: register_code16(KC_F1); break;
        case DOUBLE_TAP: register_code16(KC_1); register_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_1); register_code16(KC_1);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_1); break;
        case SINGLE_HOLD: unregister_code16(KC_F1); break;
        case DOUBLE_TAP: unregister_code16(KC_1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_1); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_2);
        tap_code16(KC_2);
        tap_code16(KC_2);
    }
    if(state->count > 3) {
        tap_code16(KC_2);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_2); break;
        case SINGLE_HOLD: register_code16(KC_F2); break;
        case DOUBLE_TAP: register_code16(KC_2); register_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_2); register_code16(KC_2);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_2); break;
        case SINGLE_HOLD: unregister_code16(KC_F2); break;
        case DOUBLE_TAP: unregister_code16(KC_2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_2); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_3);
        tap_code16(KC_3);
        tap_code16(KC_3);
    }
    if(state->count > 3) {
        tap_code16(KC_3);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_3); break;
        case SINGLE_HOLD: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_3); register_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_3); register_code16(KC_3);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_3); break;
        case SINGLE_HOLD: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_3); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_3); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_4);
        tap_code16(KC_4);
        tap_code16(KC_4);
    }
    if(state->count > 3) {
        tap_code16(KC_4);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_4); break;
        case SINGLE_HOLD: register_code16(KC_F4); break;
        case DOUBLE_TAP: register_code16(KC_4); register_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_4); register_code16(KC_4);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_4); break;
        case SINGLE_HOLD: unregister_code16(KC_F4); break;
        case DOUBLE_TAP: unregister_code16(KC_4); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_4); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_5);
        tap_code16(KC_5);
        tap_code16(KC_5);
    }
    if(state->count > 3) {
        tap_code16(KC_5);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_5); break;
        case SINGLE_HOLD: register_code16(KC_F5); break;
        case DOUBLE_TAP: register_code16(KC_5); register_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_5); register_code16(KC_5);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_5); break;
        case SINGLE_HOLD: unregister_code16(KC_F5); break;
        case DOUBLE_TAP: unregister_code16(KC_5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_5); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(qk_tap_dance_state_t *state, void *user_data);
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_6);
        tap_code16(KC_6);
        tap_code16(KC_6);
    }
    if(state->count > 3) {
        tap_code16(KC_6);
    }
}

void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_6); break;
        case SINGLE_HOLD: register_code16(KC_F6); break;
        case DOUBLE_TAP: register_code16(KC_6); register_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_6); register_code16(KC_6);
    }
}

void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_6); break;
        case SINGLE_HOLD: unregister_code16(KC_F6); break;
        case DOUBLE_TAP: unregister_code16(KC_6); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_6); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(qk_tap_dance_state_t *state, void *user_data);
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_7);
        tap_code16(KC_7);
        tap_code16(KC_7);
    }
    if(state->count > 3) {
        tap_code16(KC_7);
    }
}

void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_7); break;
        case SINGLE_HOLD: register_code16(KC_F7); break;
        case DOUBLE_TAP: register_code16(KC_7); register_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_7); register_code16(KC_7);
    }
}

void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_7); break;
        case SINGLE_HOLD: unregister_code16(KC_F7); break;
        case DOUBLE_TAP: unregister_code16(KC_7); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_7); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(qk_tap_dance_state_t *state, void *user_data);
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_8);
        tap_code16(KC_8);
        tap_code16(KC_8);
    }
    if(state->count > 3) {
        tap_code16(KC_8);
    }
}

void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_8); break;
        case SINGLE_HOLD: register_code16(KC_F8); break;
        case DOUBLE_TAP: register_code16(KC_8); register_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_8); register_code16(KC_8);
    }
}

void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_8); break;
        case SINGLE_HOLD: unregister_code16(KC_F8); break;
        case DOUBLE_TAP: unregister_code16(KC_8); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_8); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(qk_tap_dance_state_t *state, void *user_data);
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_9);
        tap_code16(KC_9);
        tap_code16(KC_9);
    }
    if(state->count > 3) {
        tap_code16(KC_9);
    }
}

void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_9); break;
        case SINGLE_HOLD: register_code16(KC_F9); break;
        case DOUBLE_TAP: register_code16(KC_9); register_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_9); register_code16(KC_9);
    }
}

void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_9); break;
        case SINGLE_HOLD: unregister_code16(KC_F9); break;
        case DOUBLE_TAP: unregister_code16(KC_9); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_9); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(qk_tap_dance_state_t *state, void *user_data);
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_0);
        tap_code16(KC_0);
        tap_code16(KC_0);
    }
    if(state->count > 3) {
        tap_code16(KC_0);
    }
}

void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_0); break;
        case SINGLE_HOLD: register_code16(KC_F10); break;
        case DOUBLE_TAP: register_code16(KC_0); register_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_0); register_code16(KC_0);
    }
}

void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_0); break;
        case SINGLE_HOLD: unregister_code16(KC_F10); break;
        case DOUBLE_TAP: unregister_code16(KC_0); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_0); break;
    }
    dance_state[9].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
};
