#include "action_layer.h"
#include QMK_KEYBOARD_H
#include "version.h"
// #include "keymap_german.h"
// #include "keymap_nordic.h"
// #include "keymap_french.h"
// #include "keymap_spanish.h"
// #include "keymap_hungarian.h"
// #include "keymap_swedish.h"
// #include "keymap_br_abnt2.h"
// #include "keymap_canadian_multilingual.h"
// #include "keymap_german_ch.h"
// #include "keymap_jp.h"
// #include "keymap_korean.h"
// #include "keymap_bepo.h"
// #include "keymap_italian.h"
// #include "keymap_slovenian.h"
// #include "keymap_lithuanian_azerty.h"
// #include "keymap_danish.h"
// #include "keymap_norwegian.h"
// #include "keymap_portuguese.h"
// #include "keymap_contributions.h"
// #include "keymap_czech.h"
// #include "keymap_romanian.h"
// #include "keymap_russian.h"
// #include "keymap_uk.h"
// #include "keymap_estonian.h"
// #include "keymap_belgian.h"
// #include "keymap_us_international.h"
// #include "keymap_croatian.h"
// #include "keymap_turkish_q.h"
// #include "keymap_slovak.h"

// #define KC_MAC_UNDO LGUI(KC_Z)
// #define KC_MAC_CUT LGUI(KC_X)
// #define KC_MAC_COPY LGUI(KC_C)
// #define KC_MAC_PASTE LGUI(KC_V)
// #define KC_PC_UNDO LCTL(KC_Z)
// #define KC_PC_CUT LCTL(KC_X)
// #define KC_PC_COPY LCTL(KC_C)
// #define KC_PC_PASTE LCTL(KC_V)
// #define ES_LESS_MAC KC_GRAVE
// #define ES_GRTR_MAC LSFT(KC_GRAVE)
// #define ES_BSLS_MAC ALGR(KC_6)
// #define NO_PIPE_ALT KC_GRAVE
// #define NO_BSLS_ALT KC_EQUAL
// #define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
// #define BP_NDSH_MAC ALGR(KC_8)
// #define SE_SECT_MAC ALGR(KC_6)
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
  PLAY_ZELDA,
  PLAY_JT,
  PLAY_SONG_00,
  PLAY_SONG_01,
  PLAY_SONG_02,
  PLAY_SONG_03,
  PLAY_SONG_04,
  PLAY_SONG_05,
  PLAY_SONG_06,
  PLAY_SONG_07,
  PLAY_SONG_08,
  PLAY_SONG_09,
  PLAY_SONG_10,
  PLAY_SONG_11,
  PLAY_SONG_12,
  PLAY_SONG_13,
  PLAY_SONG_14,
  PLAY_SONG_15,
  PLAY_SONG_16,
  PLAY_SONG_17,
  PLAY_SONG_18,
  PLAY_SONG_19,
  PLAY_SONG_20,
  PLAY_SONG_21,
  PLAY_SONG_22,
  PLAY_SONG_23,
  PLAY_SONG_24,
  PLAY_SONG_25,
  PLAY_SONG_26,
  PLAY_SONG_27,
  PLAY_SONG_28,
  PLAY_SONG_29,
  PLAY_SONG_30,
  PLAY_SONG_31,
  PLAY_SONG_32,
  PLAY_SONG_33,
  PLAY_SONG_34,
  PLAY_SONG_35,
  PLAY_SONG_36,
  PLAY_SONG_37,
  PLAY_SONG_38,
  PLAY_SONG_39,
  PLAY_SONG_40,
  PLAY_SONG_41,
  PLAY_SONG_42,
  PLAY_SONG_43,
  PLAY_SONG_44,
  PLAY_SONG_45,
  PLAY_SONG_46,
  PLAY_SONG_47,
  PLAY_SONG_48,
  PLAY_SONG_49,
  PLAY_SONG_50,
  PLAY_SONG_51,
  PLAY_SONG_52,
  PLAY_SONG_53,
  PLAY_SONG_54,
  PLAY_SONG_55,
  PLAY_SONG_56,
  PLAY_SONG_57,
  PLAY_SONG_58,
  PLAY_SONG_59,
  PLAY_SONG_60,
  PLAY_SONG_61,
  PLAY_SONG_62,
  PLAY_SONG_63,
  PLAY_SONG_64,
  PLAY_SONG_65,
  PLAY_SONG_66,
  PLAY_SONG_67,
  PLAY_SONG_68,
  PLAY_SONG_69,
  PLAY_SONG_70,
  PLAY_SONG_71,
  PLAY_SONG_72,
  PLAY_SONG_73,
  PLAY_SONG_74,
  PLAY_SONG_75,
  PLAY_SONG_76,
  PLAY_SONG_77,
  PLAY_SONG_78,
  PLAY_SONG_79,
};


static float zelda_uncover_secret[][2] = SONG(ZELDA_UNCOVER_SECRET);
static float johnnys_theme[][2] = SONG(JOHNNYS_THEME);
static float ode_to_joy[][2] = SONG(ODE_TO_JOY);
static float rock_a_bye_baby[][2] = SONG(ROCK_A_BYE_BABY);
static float clueboard_sound[][2] = SONG(CLUEBOARD_SOUND);
static float startup_sound[][2] = SONG(STARTUP_SOUND);
static float goodbye_sound[][2] = SONG(GOODBYE_SOUND);
static float planck_sound[][2] = SONG(PLANCK_SOUND);
static float preonic_sound[][2] = SONG(PREONIC_SOUND);
static float qwerty_sound[][2] = SONG(QWERTY_SOUND);
static float colemak_sound[][2] = SONG(COLEMAK_SOUND);
static float dvorak_sound[][2] = SONG(DVORAK_SOUND);
static float workman_sound[][2] = SONG(WORKMAN_SOUND);
static float plover_sound[][2] = SONG(PLOVER_SOUND);
static float plover_goodbye_sound[][2] = SONG(PLOVER_GOODBYE_SOUND);
static float music_on_sound[][2] = SONG(MUSIC_ON_SOUND);
static float audio_on_sound[][2] = SONG(AUDIO_ON_SOUND);
static float audio_off_sound[][2] = SONG(AUDIO_OFF_SOUND);
static float music_scale_sound[][2] = SONG(MUSIC_SCALE_SOUND);
static float music_off_sound[][2] = SONG(MUSIC_OFF_SOUND);
static float voice_change_sound[][2] = SONG(VOICE_CHANGE_SOUND);
static float chromatic_sound[][2] = SONG(CHROMATIC_SOUND);
static float major_sound[][2] = SONG(MAJOR_SOUND);
static float minor_sound[][2] = SONG(MINOR_SOUND);
static float guitar_sound[][2] = SONG(GUITAR_SOUND);
static float violin_sound[][2] = SONG(VIOLIN_SOUND);
static float caps_lock_on_sound[][2] = SONG(CAPS_LOCK_ON_SOUND);
static float caps_lock_off_sound[][2] = SONG(CAPS_LOCK_OFF_SOUND);
static float scroll_lock_on_sound[][2] = SONG(SCROLL_LOCK_ON_SOUND);
static float scroll_lock_off_sound[][2] = SONG(SCROLL_LOCK_OFF_SOUND);
static float num_lock_on_sound[][2] = SONG(NUM_LOCK_ON_SOUND);
static float num_lock_off_sound[][2] = SONG(NUM_LOCK_OFF_SOUND);
static float ag_norm_sound[][2] = SONG(AG_NORM_SOUND);
static float ag_swap_sound[][2] = SONG(AG_SWAP_SOUND);
static float unicode_windows[][2] = SONG(UNICODE_WINDOWS);
static float unicode_linux[][2] = SONG(UNICODE_LINUX);
static float terminal_sound[][2] = SONG(TERMINAL_SOUND);
static float campanella[][2] = SONG(CAMPANELLA);
static float fantasie_impromptu[][2] = SONG(FANTASIE_IMPROMPTU);
static float nocturne_op_9_no_1[][2] = SONG(NOCTURNE_OP_9_NO_1);
static float ussr_anthem[][2] = SONG(USSR_ANTHEM);
static float tos_hymn_risen[][2] = SONG(TOS_HYMN_RISEN);
static float close_encounters_5_note[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
static float doe_a_deer[][2] = SONG(DOE_A_DEER);
static float in_like_flint[][2] = SONG(IN_LIKE_FLINT);
static float imperial_march[][2] = SONG(IMPERIAL_MARCH);
static float basket_case[][2] = SONG(BASKET_CASE);
static float coin_sound[][2] = SONG(COIN_SOUND);
static float one_up_sound[][2] = SONG(ONE_UP_SOUND);
static float sonic_ring[][2] = SONG(SONIC_RING);
static float zelda_puzzle[][2] = SONG(ZELDA_PUZZLE);
static float zelda_treasure[][2] = SONG(ZELDA_TREASURE);
static float overwatch_theme[][2] = SONG(OVERWATCH_THEME);
static float mario_theme[][2] = SONG(MARIO_THEME);
static float mario_gameover[][2] = SONG(MARIO_GAMEOVER);
static float mario_mushroom[][2] = SONG(MARIO_MUSHROOM);
static float e1m1_doom[][2] = SONG(E1M1_DOOM);
static float disney_song[][2] = SONG(DISNEY_SONG);
static float number_one[][2] = SONG(NUMBER_ONE);
static float cabbage_song[][2] = SONG(CABBAGE_SONG);
static float old_spice[][2] = SONG(OLD_SPICE);
static float victory_fanfare_short[][2] = SONG(VICTORY_FANFARE_SHORT);
static float all_star[][2] = SONG(ALL_STAR);
static float rick_roll[][2] = SONG(RICK_ROLL);
static float ff_prelude[][2] = SONG(FF_PRELUDE);
static float to_boldly_go[][2] = SONG(TO_BOLDLY_GO);
static float kataware_doki[][2] = SONG(KATAWARE_DOKI);
static float megalovania[][2] = SONG(MEGALOVANIA);
static float michishirube[][2] = SONG(MICHISHIRUBE);
static float liebesleid[][2] = SONG(LIEBESLEID);
static float melodies_of_life[][2] = SONG(MELODIES_OF_LIFE);
static float eyes_on_me[][2] = SONG(EYES_ON_ME);
static float song_of_the_ancients[][2] = SONG(SONG_OF_THE_ANCIENTS);
static float nier_amusement_park[][2] = SONG(NIER_AMUSEMENT_PARK);
static float copied_city[][2] = SONG(COPIED_CITY);
static float vague_hope_cold_rain[][2] = SONG(VAGUE_HOPE_COLD_RAIN);
static float kaine_salvation[][2] = SONG(KAINE_SALVATION);
static float weight_of_the_world[][2] = SONG(WEIGHT_OF_THE_WORLD);
static float isabellas_lullaby[][2] = SONG(ISABELLAS_LULLABY);
static float terras_theme[][2] = SONG(TERRAS_THEME);
static float renai_circulation[][2] = SONG(RENAI_CIRCULATION);
static float platinum_disco[][2] = SONG(PLATINUM_DISCO);



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

enum layer_names { _WIN_BASE, _MAC_BASE, _WIN_SYM, _MAC_SYM, _NUMPAD, _J1, _J2, _QWERTY };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN_BASE] = LAYOUT_moonlander(
        KC_ESCAPE,      TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    KC_EQUAL,                ST_MACRO_0,     TD(DANCE_5),    TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    TG(_MAC_BASE),          
        KC_GRAVE,       KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_BSLASH,               ST_MACRO_1,     KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_MINUS,       
        KC_TAB,         KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_LBRACKET,             KC_RBRACKET,    KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,       
        KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                                    KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,       
        KC_LCTRL,       CAPS_WORD,    LGUI(KC_PSCREEN), TG(_NUMPAD),    MO(_WIN_SYM),                   KC_LGUI,                 KC_CAPSLOCK,                    LGUI(KC_DOT),   KC_RCTRL,       KC_LEFT,        KC_DOWN,        KC_RIGHT,       
                                                                        KC_ENTER,       KC_LALT,        KC_RALT,                 KC_DELETE,      KC_BSPACE,      KC_SPACE
    ),
    [_MAC_BASE] = LAYOUT_moonlander(
        _______,        _______,        _______,        _______,        _______,        _______,        _______,                 LALT(KC_MINUS), _______,        _______,        _______,        _______,        _______,        _______,        
        _______,        _______,        _______,        _______,        _______,        _______,        _______,           LALT(LSFT(KC_MINUS)), _______,        _______,        _______,        _______,        _______,        _______,        
        _______,        _______,        _______,        _______,        _______,        _______,        _______,                 _______,        _______,        _______,        _______,        _______,        _______,        _______,        
        _______,        _______,        _______,        _______,        _______,        _______,                                                 _______,        _______,        _______,        _______,        _______,        _______,        
        _______,        _______,      LGUI(LSFT(KC_3)), _______,        MO(_MAC_SYM),                   _______,                 _______,                  LGUI(LCTL(KC_SPACE)), _______,        _______,        _______,        _______,        
                                                                        _______,        _______,        _______,                 _______,        _______,        _______
    ),
    [_WIN_SYM] = LAYOUT_moonlander(
        _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          _______,                 _______,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         PLAY_ZELDA,        
        _______,        ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     _______,                 _______,        KC_F11,         KC_F12,         ST_MACRO_11,    _______,        _______,        ST_MACRO_12,    
        _______,        ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    _______,        _______,                 _______,        _______,        ST_MACRO_13,    _______,        ST_MACRO_14,    _______,        _______,        
        _______,        KC_PLUS,        KC_MINUS,       KC_ASTR,        KC_SLASH,       KC_EQUAL,                                                ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    ST_MACRO_18,    KC_PGUP,        ST_MACRO_19,    
        _______,        _______,        _______,        _______,        _______,                        _______,                 _______,                        _______,        _______,        KC_HOME,        KC_PGDOWN,      KC_END,         
                                                                        _______,        _______,        _______,                 _______,        _______,        _______
    ),
    [_MAC_SYM] = LAYOUT_moonlander(
        _______,        KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          ST_MACRO_20,             _______,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         PLAY_ZELDA,        
        _______,        ST_MACRO_21,    ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    _______,                 _______,        KC_F11,         KC_F12,         ST_MACRO_30,    _______,        _______,        ST_MACRO_31,    
        _______,        ST_MACRO_26,    ST_MACRO_27,    ST_MACRO_28,    ST_MACRO_29,    _______,        _______,                 _______,        _______,        ST_MACRO_32,    _______,        ST_MACRO_33,    _______,        _______,        
        _______,        KC_PLUS,        KC_MINUS,       KC_ASTR,        KC_SLASH,       KC_EQUAL,                                                ST_MACRO_34,    ST_MACRO_35,    ST_MACRO_36,    ST_MACRO_37,    KC_PGUP,        ST_MACRO_38,    
        _______,        _______,        _______,        _______,        _______,                        _______,                 _______,                        _______,        _______,        KC_HOME,        KC_PGDOWN,      KC_END,         
                                                                        _______,        _______,        _______,                 _______,        _______,        _______
    ),
    [_NUMPAD] = LAYOUT_moonlander(
        RESET,          _______,        _______,        _______,        _______,        _______,        DT_UP,                   _______,        _______,        KC_NUMLOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    TG(_QWERTY),          
        _______,        _______,        _______,   KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,_______,        DT_PRNT,                 _______,        _______,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     _______,        
        TG(_J1),        _______,     KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, _______,        DT_DOWN,                 _______,        _______,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     _______,        
        TG(_J2),   TOGGLE_LAYER_COLOR,  RGB_TOG,        RGB_MOD,        MOON_LED_LEVEL, _______,                                                 _______,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    _______,        
        AU_TOG,         MU_TOG,         MU_MOD,         _______,        _______,                        _______,                 _______,                        KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    _______,        
                                                                        _______,        _______,        _______,                 _______,        _______,        _______
    ),
    [_J1] = LAYOUT_moonlander(
        PLAY_SONG_00,   PLAY_SONG_01,   PLAY_SONG_02,   PLAY_SONG_03,   PLAY_SONG_04,   PLAY_SONG_05,   PLAY_SONG_06,            PLAY_SONG_07,   PLAY_SONG_08,   PLAY_SONG_09,   PLAY_SONG_10,   PLAY_SONG_11,   PLAY_SONG_12,   PLAY_SONG_13,
        PLAY_SONG_14,   PLAY_SONG_15,   PLAY_SONG_16,   PLAY_SONG_17,   PLAY_SONG_18,   PLAY_SONG_19,   PLAY_SONG_20,            PLAY_SONG_21,   PLAY_SONG_22,   PLAY_SONG_23,   PLAY_SONG_24,   PLAY_SONG_25,   PLAY_SONG_26,   PLAY_SONG_27,
        _______,        PLAY_SONG_28,   PLAY_SONG_29,   PLAY_SONG_30,   PLAY_SONG_31,   PLAY_SONG_32,   PLAY_SONG_33,            PLAY_SONG_34,   PLAY_SONG_35,   PLAY_SONG_36,   PLAY_SONG_37,   PLAY_SONG_38,   PLAY_SONG_39,   PLAY_SONG_40,
        XXXXXXX,        PLAY_SONG_41,   PLAY_SONG_42,   PLAY_SONG_43,   PLAY_SONG_44,   PLAY_SONG_45,                                            PLAY_SONG_46,   PLAY_SONG_47,   PLAY_SONG_48,   PLAY_SONG_49,   PLAY_SONG_50,   PLAY_SONG_51,
    PLAY_SONG_52,    PLAY_SONG_53,   PLAY_SONG_54,   PLAY_SONG_55,   PLAY_SONG_56,                   PLAY_JT,                 PLAY_ZELDA,                     PLAY_SONG_57,   PLAY_SONG_58,   PLAY_SONG_59,   PLAY_SONG_60,   PLAY_SONG_61,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_J2] = LAYOUT_moonlander(
        PLAY_SONG_62,   PLAY_SONG_63,   PLAY_SONG_64,   PLAY_SONG_65,   PLAY_SONG_66,   PLAY_SONG_67,   PLAY_SONG_68,   PLAY_SONG_69,            PLAY_SONG_70,   PLAY_SONG_71,   PLAY_SONG_72,   PLAY_SONG_73,   PLAY_SONG_74,   PLAY_SONG_75,
        PLAY_SONG_76,   PLAY_SONG_77,   PLAY_SONG_78,   PLAY_SONG_79,   XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,     
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,     
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,     
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        PLAY_JT,                 PLAY_ZELDA,                     XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_QWERTY] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                XXXXXXX,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,        
        KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_BSLASH,               XXXXXXX,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
        KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_LBRACKET,             KC_RBRACKET,    KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
        KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,       
        KC_LCTRL,       KC_LGUI,        KC_LALT,        XXXXXXX,        XXXXXXX,                        _______,                 _______,                        XXXXXXX,        KC_RCTRL,       KC_LEFT,        KC_DOWN,        KC_RIGHT,       
                                                                        _______,        _______,        _______,                 _______,        _______,        _______
    )
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}


/*
ledmap per-layer order (column 1, ..., C7, thumb-key group (of 3 keys) 1, pentagonal key 1, ...)
C1 (5) 1–5
C2 (5) 6–10
C3 (5) 11–15
C4 (5) 16–20
C5 (5) 21–25
C6 (4) 26–29
C7 (3) 30–32
T1 (3) 33–35
P1 (1) 36
C14 (5) 37–41
C13 (5) 42–46
C12 (5) 47–51
C11 (5) 52–56
C10 (5) 57–61
C9 (4) 62–65
C8 (3) 66–68
T2 (3) 69–71
P2 (1) 72
*/
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_WIN_BASE] = { {139,218,205}, {139,218,205}, {139,218,205}, {172,255,255}, {172,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {86,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {86,255,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {172,255,255}, {172,255,255}, {172,255,255}, {11,225,254}, {139,218,205}, {139,218,205}, {139,218,205}, {43,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {43,255,255}, {43,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {43,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {172,255,255}, {139,218,205}, {139,218,205}, {0,0,255}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205}, {139,218,205} },

    [_MAC_BASE] = { {11,225,254}, {11,225,254}, {11,225,254}, {0,255,255}, {0,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {86,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {86,255,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {0,255,255}, {0,255,255}, {0,255,255}, {139,218,205}, {11,225,254}, {11,225,254}, {11,225,254}, {43,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {43,255,255}, {43,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {43,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {0,255,255}, {11,225,254}, {11,225,254}, {0,0,255}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254}, {11,225,254} },

    [_WIN_SYM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {86,255,255}, {0,255,255}, {27,255,255}, {86,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {86,255,255}, {0,0,0}, {215,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,90,87}, {86,255,255}, {0,0,0}, {86,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {86,255,255}, {86,255,255}, {43,255,255}, {0,255,255}, {27,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {43,255,136}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_MAC_SYM] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {27,255,255}, {172,255,255}, {215,255,255}, {86,255,255}, {0,255,255}, {27,255,255}, {86,255,255}, {215,255,255}, {0,0,0}, {0,255,255}, {86,255,255}, {0,0,0}, {215,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,90,87}, {86,255,255}, {0,0,0}, {86,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,255,255}, {0,0,0}, {86,255,255}, {86,255,255}, {43,255,255}, {0,255,255}, {27,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {43,255,136}, {43,255,136}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,0}, {43,255,136}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_NUMPAD] = { {0,255,255}, {0,0,0}, {194,126,196}, {194,126,196}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {35,255,135}, {172,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {35,255,135}, {172,255,255}, {0,0,0}, {0,0,85}, {0,255,128}, {35,255,135}, {86,255,255}, {0,0,0}, {0,0,170}, {86,255,128}, {35,255,135}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {11,255,255}, {10,255,192}, {10,255,128}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,102}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,102}, {0,0,102}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,102}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [_J1] = { {194,126,196}, {194,126,196}, {86,255,255}, {0,0,0}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196} },

    [_J2] = { {194,126,196}, {194,126,196}, {0,0,0}, {86,255,255}, {0,0,0}, {194,126,196}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {194,126,196} },

    [_QWERTY] = { {0,255,255}, {0,255,255}, {0,255,255}, {250,215,196}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {250,215,196}, {250,215,196}, {250,215,196}, {86,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {43,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {43,255,255}, {43,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {43,255,255}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {250,215,196}, {0,255,255}, {0,255,255}, {0,0,255}, {0,255,255}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255}, {0,255,255} }
};

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2])
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB rgb = hsv_to_rgb(hsv);
            float f = (float) rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (!rawhid_state.rgb_control && !keyboard_config.disable_layer_led) {
        set_layer_color(get_highest_layer(layer_state));
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_0)));
            }
            break;
        case ST_MACRO_1:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_1)));
            }
            break;
        case ST_MACRO_2:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1)));
            }
            break;
        case ST_MACRO_3:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_3)));
            }
            break;
        case ST_MACRO_4:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_5) SS_TAP(X_KP_2)));
            }
            break;
        case ST_MACRO_5:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
            }
            break;
        case ST_MACRO_6:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_9)));
            }
            break;
        case ST_MACRO_7:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_8)));
            }
            break;
        case ST_MACRO_8:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_9)));
            }
            break;
        case ST_MACRO_9:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_0)));
            }
            break;
        case ST_MACRO_10:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_3)));
            }
            break;
        case ST_MACRO_11:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_4)));
            }
            break;
        case ST_MACRO_12:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_7)));
            }
            break;
        case ST_MACRO_13:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_4)));
            }
            break;
        case ST_MACRO_14:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_3) SS_TAP(X_KP_6)));
            }
            break;
        case ST_MACRO_15:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_7)));
            }
            break;
        case ST_MACRO_16:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_5)));
            }
            break;
        case ST_MACRO_17:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_2) SS_TAP(X_KP_6)));
            }
            break;
        case ST_MACRO_18:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_8) SS_TAP(X_KP_3)));
            }
            break;
        case ST_MACRO_19:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_1)));
            }
            break;
        case ST_MACRO_20:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_6) SS_TAP(X_0)));
            }
            break;
        case ST_MACRO_21:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_A) SS_TAP(X_1)));
            }
            break;
        case ST_MACRO_22:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_2)));
            }
            break;
        case ST_MACRO_23:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_7) SS_TAP(X_F)));
            }
            break;
        case ST_MACRO_24:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_0)));
            }
            break;
        case ST_MACRO_25:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_5) SS_TAP(X_8) SS_TAP(X_8)));
            }
            break;
        case ST_MACRO_26:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_C)));
            }
            break;
        case ST_MACRO_27:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_D)));
            }
            break;
        case ST_MACRO_28:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_E)));
            }
            break;
        case ST_MACRO_29:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_2) SS_TAP(X_2)));
            }
            break;
        case ST_MACRO_30:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_0) SS_TAP(X_2) SS_TAP(X_0)));
            }
            break;
        case ST_MACRO_31:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_1)));
            }
            break;
        case ST_MACRO_32:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_1)));
            }
            break;
        case ST_MACRO_33:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_E)));
            }
            break;
        case ST_MACRO_34:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_0)));
            }
            break;
        case ST_MACRO_35:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_3)));
            }
            break;
        case ST_MACRO_36:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_2) SS_TAP(X_1) SS_TAP(X_9) SS_TAP(X_2)));
            }
            break;
        case ST_MACRO_37:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_7)));
            }
            break;
        case ST_MACRO_38:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_0) SS_TAP(X_0) SS_TAP(X_B) SS_TAP(X_F)));
            }
            break;

    case PLAY_ZELDA:
        if (record->event.pressed) {
            PLAY_SONG(zelda_uncover_secret);
        }
        return false;

    case PLAY_JT:
        if (record->event.pressed) {
            PLAY_SONG(johnnys_theme);
        }
        return false;


    case PLAY_SONG_00:
        if (record->event.pressed) {
            PLAY_SONG(ode_to_joy);
        }
        return false;

    case PLAY_SONG_01:
        if (record->event.pressed) {
            PLAY_SONG(rock_a_bye_baby);
        }
        return false;

    case PLAY_SONG_02:
        if (record->event.pressed) {
            PLAY_SONG(clueboard_sound);
        }
        return false;

    case PLAY_SONG_03:
        if (record->event.pressed) {
            PLAY_SONG(startup_sound);
        }
        return false;

    case PLAY_SONG_04:
        if (record->event.pressed) {
            PLAY_SONG(goodbye_sound);
        }
        return false;

    case PLAY_SONG_05:
        if (record->event.pressed) {
            PLAY_SONG(planck_sound);
        }
        return false;

    case PLAY_SONG_06:
        if (record->event.pressed) {
            PLAY_SONG(preonic_sound);
        }
        return false;

    case PLAY_SONG_07:
        if (record->event.pressed) {
            PLAY_SONG(qwerty_sound);
        }
        return false;

    case PLAY_SONG_08:
        if (record->event.pressed) {
            PLAY_SONG(colemak_sound);
        }
        return false;

    case PLAY_SONG_09:
        if (record->event.pressed) {
            PLAY_SONG(dvorak_sound);
        }
        return false;

    case PLAY_SONG_10:
        if (record->event.pressed) {
            PLAY_SONG(workman_sound);
        }
        return false;

    case PLAY_SONG_11:
        if (record->event.pressed) {
            PLAY_SONG(plover_sound);
        }
        return false;

    case PLAY_SONG_12:
        if (record->event.pressed) {
            PLAY_SONG(plover_goodbye_sound);
        }
        return false;

    case PLAY_SONG_13:
        if (record->event.pressed) {
            PLAY_SONG(music_on_sound);
        }
        return false;

    case PLAY_SONG_14:
        if (record->event.pressed) {
            PLAY_SONG(audio_on_sound);
        }
        return false;

    case PLAY_SONG_15:
        if (record->event.pressed) {
            PLAY_SONG(audio_off_sound);
        }
        return false;

    case PLAY_SONG_16:
        if (record->event.pressed) {
            PLAY_SONG(music_scale_sound);
        }
        return false;

    case PLAY_SONG_17:
        if (record->event.pressed) {
            PLAY_SONG(music_off_sound);
        }
        return false;

    case PLAY_SONG_18:
        if (record->event.pressed) {
            PLAY_SONG(voice_change_sound);
        }
        return false;

    case PLAY_SONG_19:
        if (record->event.pressed) {
            PLAY_SONG(chromatic_sound);
        }
        return false;

    case PLAY_SONG_20:
        if (record->event.pressed) {
            PLAY_SONG(major_sound);
        }
        return false;

    case PLAY_SONG_21:
        if (record->event.pressed) {
            PLAY_SONG(minor_sound);
        }
        return false;

    case PLAY_SONG_22:
        if (record->event.pressed) {
            PLAY_SONG(guitar_sound);
        }
        return false;

    case PLAY_SONG_23:
        if (record->event.pressed) {
            PLAY_SONG(violin_sound);
        }
        return false;

    case PLAY_SONG_24:
        if (record->event.pressed) {
            PLAY_SONG(caps_lock_on_sound);
        }
        return false;

    case PLAY_SONG_25:
        if (record->event.pressed) {
            PLAY_SONG(caps_lock_off_sound);
        }
        return false;

    case PLAY_SONG_26:
        if (record->event.pressed) {
            PLAY_SONG(scroll_lock_on_sound);
        }
        return false;

    case PLAY_SONG_27:
        if (record->event.pressed) {
            PLAY_SONG(scroll_lock_off_sound);
        }
        return false;

    case PLAY_SONG_28:
        if (record->event.pressed) {
            PLAY_SONG(num_lock_on_sound);
        }
        return false;

    case PLAY_SONG_29:
        if (record->event.pressed) {
            PLAY_SONG(num_lock_off_sound);
        }
        return false;

    case PLAY_SONG_30:
        if (record->event.pressed) {
            PLAY_SONG(ag_norm_sound);
        }
        return false;

    case PLAY_SONG_31:
        if (record->event.pressed) {
            PLAY_SONG(ag_swap_sound);
        }
        return false;

    case PLAY_SONG_32:
        if (record->event.pressed) {
            PLAY_SONG(unicode_windows);
        }
        return false;

    case PLAY_SONG_33:
        if (record->event.pressed) {
            PLAY_SONG(unicode_linux);
        }
        return false;

    case PLAY_SONG_34:
        if (record->event.pressed) {
            PLAY_SONG(terminal_sound);
        }
        return false;

    case PLAY_SONG_35:
        if (record->event.pressed) {
            PLAY_SONG(campanella);
        }
        return false;

    case PLAY_SONG_36:
        if (record->event.pressed) {
            PLAY_SONG(fantasie_impromptu);
        }
        return false;

    case PLAY_SONG_37:
        if (record->event.pressed) {
            PLAY_SONG(nocturne_op_9_no_1);
        }
        return false;

    case PLAY_SONG_38:
        if (record->event.pressed) {
            PLAY_SONG(ussr_anthem);
        }
        return false;

    case PLAY_SONG_39:
        if (record->event.pressed) {
            PLAY_SONG(tos_hymn_risen);
        }
        return false;

    case PLAY_SONG_40:
        if (record->event.pressed) {
            PLAY_SONG(close_encounters_5_note);
        }
        return false;

    case PLAY_SONG_41:
        if (record->event.pressed) {
            PLAY_SONG(doe_a_deer);
        }
        return false;

    case PLAY_SONG_42:
        if (record->event.pressed) {
            PLAY_SONG(in_like_flint);
        }
        return false;

    case PLAY_SONG_43:
        if (record->event.pressed) {
            PLAY_SONG(imperial_march);
        }
        return false;

    case PLAY_SONG_44:
        if (record->event.pressed) {
            PLAY_SONG(basket_case);
        }
        return false;

    case PLAY_SONG_45:
        if (record->event.pressed) {
            PLAY_SONG(coin_sound);
        }
        return false;

    case PLAY_SONG_46:
        if (record->event.pressed) {
            PLAY_SONG(one_up_sound);
        }
        return false;

    case PLAY_SONG_47:
        if (record->event.pressed) {
            PLAY_SONG(sonic_ring);
        }
        return false;

    case PLAY_SONG_48:
        if (record->event.pressed) {
            PLAY_SONG(zelda_puzzle);
        }
        return false;

    case PLAY_SONG_49:
        if (record->event.pressed) {
            PLAY_SONG(zelda_treasure);
        }
        return false;

    case PLAY_SONG_50:
        if (record->event.pressed) {
            PLAY_SONG(overwatch_theme);
        }
        return false;

    case PLAY_SONG_51:
        if (record->event.pressed) {
            PLAY_SONG(mario_theme);
        }
        return false;

    case PLAY_SONG_52:
        if (record->event.pressed) {
            PLAY_SONG(mario_gameover);
        }
        return false;

    case PLAY_SONG_53:
        if (record->event.pressed) {
            PLAY_SONG(mario_mushroom);
        }
        return false;

    case PLAY_SONG_54:
        if (record->event.pressed) {
            PLAY_SONG(e1m1_doom);
        }
        return false;

    case PLAY_SONG_55:
        if (record->event.pressed) {
            PLAY_SONG(disney_song);
        }
        return false;

    case PLAY_SONG_56:
        if (record->event.pressed) {
            PLAY_SONG(number_one);
        }
        return false;

    case PLAY_SONG_57:
        if (record->event.pressed) {
            PLAY_SONG(cabbage_song);
        }
        return false;

    case PLAY_SONG_58:
        if (record->event.pressed) {
            PLAY_SONG(old_spice);
        }
        return false;

    case PLAY_SONG_59:
        if (record->event.pressed) {
            PLAY_SONG(victory_fanfare_short);
        }
        return false;

    case PLAY_SONG_60:
        if (record->event.pressed) {
            PLAY_SONG(all_star);
        }
        return false;

    case PLAY_SONG_61:
        if (record->event.pressed) {
            PLAY_SONG(rick_roll);
        }
        return false;

    case PLAY_SONG_62:
        if (record->event.pressed) {
            PLAY_SONG(ff_prelude);
        }
        return false;

    case PLAY_SONG_63:
        if (record->event.pressed) {
            PLAY_SONG(to_boldly_go);
        }
        return false;

    case PLAY_SONG_64:
        if (record->event.pressed) {
            PLAY_SONG(kataware_doki);
        }
        return false;

    case PLAY_SONG_65:
        if (record->event.pressed) {
            PLAY_SONG(megalovania);
        }
        return false;

    case PLAY_SONG_66:
        if (record->event.pressed) {
            PLAY_SONG(michishirube);
        }
        return false;

    case PLAY_SONG_67:
        if (record->event.pressed) {
            PLAY_SONG(liebesleid);
        }
        return false;

    case PLAY_SONG_68:
        if (record->event.pressed) {
            PLAY_SONG(melodies_of_life);
        }
        return false;

    case PLAY_SONG_69:
        if (record->event.pressed) {
            PLAY_SONG(eyes_on_me);
        }
        return false;

    case PLAY_SONG_70:
        if (record->event.pressed) {
            PLAY_SONG(song_of_the_ancients);
        }
        return false;

    case PLAY_SONG_71:
        if (record->event.pressed) {
            PLAY_SONG(nier_amusement_park);
        }
        return false;

    case PLAY_SONG_72:
        if (record->event.pressed) {
            PLAY_SONG(copied_city);
        }
        return false;

    case PLAY_SONG_73:
        if (record->event.pressed) {
            PLAY_SONG(vague_hope_cold_rain);
        }
        return false;

    case PLAY_SONG_74:
        if (record->event.pressed) {
            PLAY_SONG(kaine_salvation);
        }
        return false;

    case PLAY_SONG_75:
        if (record->event.pressed) {
            PLAY_SONG(weight_of_the_world);
        }
        return false;

    case PLAY_SONG_76:
        if (record->event.pressed) {
            PLAY_SONG(isabellas_lullaby);
        }
        return false;

    case PLAY_SONG_77:
        if (record->event.pressed) {
            PLAY_SONG(terras_theme);
        }
        return false;

    case PLAY_SONG_78:
        if (record->event.pressed) {
            PLAY_SONG(renai_circulation);
        }
        return false;

    case PLAY_SONG_79:
        if (record->event.pressed) {
            PLAY_SONG(platinum_disco);
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

uint8_t dance_step(qk_tap_dance_state_t *state) {
    uint8_t dance_step;
    switch (state->count) {
        case 1:
            if (state->interrupted || !state->pressed) {
                dance_step = SINGLE_TAP;
            } else {
                dance_step = SINGLE_HOLD;
            }
            break;
        case 2:
            if (state->interrupted) {
                dance_step = DOUBLE_SINGLE_TAP;
            } else if (state->pressed) {
                dance_step = DOUBLE_HOLD;
            } else {
                dance_step = DOUBLE_TAP;
            }
            break;
        default:
            dance_step = MORE_TAPS;
    }

    return dance_step;
}

// left to right, so [0]=1, [1]=2, ..., [9]=0
const uint8_t num_row[] = { KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0 };

// left to right, so [0]=F1, [1]=F2, ..., [9]=F10
const uint8_t f_row[] = { KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10 };


void on_dance_i(qk_tap_dance_state_t *state, void *user_data, int i) {
    if(state->count == 3) {
        tap_code16(num_row[i]);
        tap_code16(num_row[i]);
        tap_code16(num_row[i]);
    }
    if(state->count > 3) {
        tap_code16(num_row[i]);
    }
}

void dance_i_finished(qk_tap_dance_state_t *state, void *user_data, int i) {
    dance_state[i].step = dance_step(state);
    switch (dance_state[i].step) {
        case SINGLE_TAP:
            register_code16(num_row[i]);
            break;
        case SINGLE_HOLD:
            register_code16(f_row[i]);
            break;
        case DOUBLE_TAP:
            register_code16(num_row[i]);
            register_code16(num_row[i]);
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(num_row[i]);
            register_code16(num_row[i]);
    }
}

void dance_i_reset(qk_tap_dance_state_t *state, void *user_data, int i) {
    wait_ms(10);
    switch (dance_state[i].step) {
        case SINGLE_TAP:
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
            unregister_code16(num_row[i]);
            break;
        case SINGLE_HOLD:
            unregister_code16(f_row[i]);
            break;
    }
    dance_state[i].step = 0;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 0); }
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 0); }
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 0); }

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 1); }
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 1); }
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 1); }

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 2); }
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 2); }
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 2); }

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 3); }
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 3); }
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 3); }

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 4); }
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 4); }
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 4); }

void on_dance_5(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 5); }
void dance_5_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 5); }
void dance_5_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 5); }

void on_dance_6(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 6); }
void dance_6_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 6); }
void dance_6_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 6); }

void on_dance_7(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 7); }
void dance_7_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 7); }
void dance_7_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 7); }

void on_dance_8(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 8); }
void dance_8_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 8); }
void dance_8_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 8); }

void on_dance_9(qk_tap_dance_state_t *state, void *user_data) { return on_dance_i(state, user_data, 9); }
void dance_9_finished(qk_tap_dance_state_t *state, void *user_data) { return dance_i_finished(state, user_data, 9); }
void dance_9_reset(qk_tap_dance_state_t *state, void *user_data) { return dance_i_reset(state, user_data, 9); }


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
    [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset)
};
