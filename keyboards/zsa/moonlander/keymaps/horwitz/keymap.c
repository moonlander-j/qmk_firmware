#include "action_layer.h"
#include "os_detection.h"
#include QMK_KEYBOARD_H
#ifdef COMMUNITY_MODULE_DEFAULTS_ENABLE
#    include "defaults.h"
#endif
#include "version.h"
#include "colors.h"
#include "dance.h"
#include "led_logic.h"
#include "os_specific_char_map.h"
#include "custom_keycodes.h"
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

/**
 * Windows-accents layers:
 *
 * get to _ACCENT layer by pressing rightmost left thumb key; from accent layer, press one of the following keys
 * to get to its layer (e.g., press '`' to get to the GRAVE layer (named _A_GRAVE)):
 *
 * ' ACUTE (AEIOUY)
 * v CARON (SZ)
 * , CEDILLA (C)
 * ^/6 CIRCUMFLEX (AEIOU)
 * :/; DIAERESIS (AEIOUY)
 * ` GRAVE (AEIOU)
 * o RING RING_ABOVE (A)
 * / STROKE (O)
 * TAB TILDE (ANO)
 *
 * then press one of the keys in the parenthesized list on the relevant row above (e.g., one of A,E,I,O,U for
 * _A_GRAVE) to get an version of that key, using the accent chosen
 *
 * (union of all available keys (each only available for _some_ accents): AEIOUYCNSZ)
 */


static float zelda_uncover_secret[][2]    = SONG(ZELDA_UNCOVER_SECRET);
static float johnnys_theme[][2]           = SONG(JOHNNYS_THEME);
static float ode_to_joy[][2]              = SONG(ODE_TO_JOY);
static float rock_a_bye_baby[][2]         = SONG(ROCK_A_BYE_BABY);
static float clueboard_sound[][2]         = SONG(CLUEBOARD_SOUND);
static float startup_sound[][2]           = SONG(STARTUP_SOUND);
static float goodbye_sound[][2]           = SONG(GOODBYE_SOUND);
static float planck_sound[][2]            = SONG(PLANCK_SOUND);
static float preonic_sound[][2]           = SONG(PREONIC_SOUND);
static float qwerty_sound[][2]            = SONG(QWERTY_SOUND);
static float colemak_sound[][2]           = SONG(COLEMAK_SOUND);
static float dvorak_sound[][2]            = SONG(DVORAK_SOUND);
static float workman_sound[][2]           = SONG(WORKMAN_SOUND);
static float plover_sound[][2]            = SONG(PLOVER_SOUND);
static float plover_goodbye_sound[][2]    = SONG(PLOVER_GOODBYE_SOUND);
static float music_on_sound[][2]          = SONG(MUSIC_ON_SOUND);
static float audio_on_sound[][2]          = SONG(AUDIO_ON_SOUND);
static float audio_off_sound[][2]         = SONG(AUDIO_OFF_SOUND);
static float music_scale_sound[][2]       = SONG(MUSIC_SCALE_SOUND);
static float music_off_sound[][2]         = SONG(MUSIC_OFF_SOUND);
static float voice_change_sound[][2]      = SONG(VOICE_CHANGE_SOUND);
static float chromatic_sound[][2]         = SONG(CHROMATIC_SOUND);
static float major_sound[][2]             = SONG(MAJOR_SOUND);
static float minor_sound[][2]             = SONG(MINOR_SOUND);
static float guitar_sound[][2]            = SONG(GUITAR_SOUND);
static float violin_sound[][2]            = SONG(VIOLIN_SOUND);
static float caps_lock_on_sound[][2]      = SONG(CAPS_LOCK_ON_SOUND);
static float caps_lock_off_sound[][2]     = SONG(CAPS_LOCK_OFF_SOUND);
static float scroll_lock_on_sound[][2]    = SONG(SCROLL_LOCK_ON_SOUND);
static float scroll_lock_off_sound[][2]   = SONG(SCROLL_LOCK_OFF_SOUND);
static float num_lock_on_sound[][2]       = SONG(NUM_LOCK_ON_SOUND);
static float num_lock_off_sound[][2]      = SONG(NUM_LOCK_OFF_SOUND);
static float ag_norm_sound[][2]           = SONG(AG_NORM_SOUND);
static float ag_swap_sound[][2]           = SONG(AG_SWAP_SOUND);
static float unicode_windows[][2]         = SONG(UNICODE_WINDOWS);
static float unicode_linux[][2]           = SONG(UNICODE_LINUX);
static float terminal_sound[][2]          = SONG(TERMINAL_SOUND);
static float campanella[][2]              = SONG(CAMPANELLA);
static float fantasie_impromptu[][2]      = SONG(FANTASIE_IMPROMPTU);
static float nocturne_op_9_no_1[][2]      = SONG(NOCTURNE_OP_9_NO_1);
static float ussr_anthem[][2]             = SONG(USSR_ANTHEM);
static float tos_hymn_risen[][2]          = SONG(TOS_HYMN_RISEN);
static float close_encounters_5_note[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
static float doe_a_deer[][2]              = SONG(DOE_A_DEER);
static float in_like_flint[][2]           = SONG(IN_LIKE_FLINT);
static float imperial_march[][2]          = SONG(IMPERIAL_MARCH);
static float basket_case[][2]             = SONG(BASKET_CASE);
static float coin_sound[][2]              = SONG(COIN_SOUND);
static float one_up_sound[][2]            = SONG(ONE_UP_SOUND);
static float sonic_ring[][2]              = SONG(SONIC_RING);
static float zelda_puzzle[][2]            = SONG(ZELDA_PUZZLE);
static float zelda_treasure[][2]          = SONG(ZELDA_TREASURE);
static float overwatch_theme[][2]         = SONG(OVERWATCH_THEME);
static float mario_theme[][2]             = SONG(MARIO_THEME);
static float mario_gameover[][2]          = SONG(MARIO_GAMEOVER);
static float mario_mushroom[][2]          = SONG(MARIO_MUSHROOM);
static float e1m1_doom[][2]               = SONG(E1M1_DOOM);
static float disney_song[][2]             = SONG(DISNEY_SONG);
static float number_one[][2]              = SONG(NUMBER_ONE);
static float cabbage_song[][2]            = SONG(CABBAGE_SONG);
static float old_spice[][2]               = SONG(OLD_SPICE);
static float victory_fanfare_short[][2]   = SONG(VICTORY_FANFARE_SHORT);
static float all_star[][2]                = SONG(ALL_STAR);
static float rick_roll[][2]               = SONG(RICK_ROLL);
static float ff_prelude[][2]              = SONG(FF_PRELUDE);
static float to_boldly_go[][2]            = SONG(TO_BOLDLY_GO);
static float kataware_doki[][2]           = SONG(KATAWARE_DOKI);
static float megalovania[][2]             = SONG(MEGALOVANIA);
static float michishirube[][2]            = SONG(MICHISHIRUBE);
static float liebesleid[][2]              = SONG(LIEBESLEID);
static float melodies_of_life[][2]        = SONG(MELODIES_OF_LIFE);
static float eyes_on_me[][2]              = SONG(EYES_ON_ME);
static float song_of_the_ancients[][2]    = SONG(SONG_OF_THE_ANCIENTS);
static float nier_amusement_park[][2]     = SONG(NIER_AMUSEMENT_PARK);
static float copied_city[][2]             = SONG(COPIED_CITY);
static float vague_hope_cold_rain[][2]    = SONG(VAGUE_HOPE_COLD_RAIN);
static float kaine_salvation[][2]         = SONG(KAINE_SALVATION);
static float weight_of_the_world[][2]     = SONG(WEIGHT_OF_THE_WORLD);
static float isabellas_lullaby[][2]       = SONG(ISABELLAS_LULLABY);
static float terras_theme[][2]            = SONG(TERRAS_THEME);
static float renai_circulation[][2]       = SONG(RENAI_CIRCULATION);
static float platinum_disco[][2]          = SONG(PLATINUM_DISCO);

typedef struct {
    float    (*notes)[][2];
    uint16_t note_count;
} song_entry_t;

#define SONG_ENTRY(arr) { .notes = (float (*)[][2])&(arr), .note_count = (uint16_t)NOTE_ARRAY_SIZE(arr) }

// clang-format off
static const song_entry_t song_table[] = {
    /*
     * Generated code: this comment and the 80 lines following it were generated by
     * SongTable.getSongTableEntries in qmk-tools
     */
    SONG_ENTRY(ode_to_joy),              // PLAY_SONG_00
    SONG_ENTRY(rock_a_bye_baby),         // PLAY_SONG_01
    SONG_ENTRY(clueboard_sound),         // PLAY_SONG_02
    SONG_ENTRY(startup_sound),           // PLAY_SONG_03
    SONG_ENTRY(goodbye_sound),           // PLAY_SONG_04
    SONG_ENTRY(planck_sound),            // PLAY_SONG_05
    SONG_ENTRY(preonic_sound),           // PLAY_SONG_06
    SONG_ENTRY(qwerty_sound),            // PLAY_SONG_07
    SONG_ENTRY(colemak_sound),           // PLAY_SONG_08
    SONG_ENTRY(dvorak_sound),            // PLAY_SONG_09
    SONG_ENTRY(workman_sound),           // PLAY_SONG_10
    SONG_ENTRY(plover_sound),            // PLAY_SONG_11
    SONG_ENTRY(plover_goodbye_sound),    // PLAY_SONG_12
    SONG_ENTRY(music_on_sound),          // PLAY_SONG_13
    SONG_ENTRY(audio_on_sound),          // PLAY_SONG_14
    SONG_ENTRY(audio_off_sound),         // PLAY_SONG_15
    SONG_ENTRY(music_scale_sound),       // PLAY_SONG_16
    SONG_ENTRY(music_off_sound),         // PLAY_SONG_17
    SONG_ENTRY(voice_change_sound),      // PLAY_SONG_18
    SONG_ENTRY(chromatic_sound),         // PLAY_SONG_19
    SONG_ENTRY(major_sound),             // PLAY_SONG_20
    SONG_ENTRY(minor_sound),             // PLAY_SONG_21
    SONG_ENTRY(guitar_sound),            // PLAY_SONG_22
    SONG_ENTRY(violin_sound),            // PLAY_SONG_23
    SONG_ENTRY(caps_lock_on_sound),      // PLAY_SONG_24
    SONG_ENTRY(caps_lock_off_sound),     // PLAY_SONG_25
    SONG_ENTRY(scroll_lock_on_sound),    // PLAY_SONG_26
    SONG_ENTRY(scroll_lock_off_sound),   // PLAY_SONG_27
    SONG_ENTRY(num_lock_on_sound),       // PLAY_SONG_28
    SONG_ENTRY(num_lock_off_sound),      // PLAY_SONG_29
    SONG_ENTRY(ag_norm_sound),           // PLAY_SONG_30
    SONG_ENTRY(ag_swap_sound),           // PLAY_SONG_31
    SONG_ENTRY(unicode_windows),         // PLAY_SONG_32
    SONG_ENTRY(unicode_linux),           // PLAY_SONG_33
    SONG_ENTRY(terminal_sound),          // PLAY_SONG_34
    SONG_ENTRY(campanella),              // PLAY_SONG_35
    SONG_ENTRY(fantasie_impromptu),      // PLAY_SONG_36
    SONG_ENTRY(nocturne_op_9_no_1),      // PLAY_SONG_37
    SONG_ENTRY(ussr_anthem),             // PLAY_SONG_38
    SONG_ENTRY(tos_hymn_risen),          // PLAY_SONG_39
    SONG_ENTRY(close_encounters_5_note), // PLAY_SONG_40
    SONG_ENTRY(doe_a_deer),              // PLAY_SONG_41
    SONG_ENTRY(in_like_flint),           // PLAY_SONG_42
    SONG_ENTRY(imperial_march),          // PLAY_SONG_43
    SONG_ENTRY(basket_case),             // PLAY_SONG_44
    SONG_ENTRY(coin_sound),              // PLAY_SONG_45
    SONG_ENTRY(one_up_sound),            // PLAY_SONG_46
    SONG_ENTRY(sonic_ring),              // PLAY_SONG_47
    SONG_ENTRY(zelda_puzzle),            // PLAY_SONG_48
    SONG_ENTRY(zelda_treasure),          // PLAY_SONG_49
    SONG_ENTRY(overwatch_theme),         // PLAY_SONG_50
    SONG_ENTRY(mario_theme),             // PLAY_SONG_51
    SONG_ENTRY(mario_gameover),          // PLAY_SONG_52
    SONG_ENTRY(mario_mushroom),          // PLAY_SONG_53
    SONG_ENTRY(e1m1_doom),               // PLAY_SONG_54
    SONG_ENTRY(disney_song),             // PLAY_SONG_55
    SONG_ENTRY(number_one),              // PLAY_SONG_56
    SONG_ENTRY(cabbage_song),            // PLAY_SONG_57
    SONG_ENTRY(old_spice),               // PLAY_SONG_58
    SONG_ENTRY(victory_fanfare_short),   // PLAY_SONG_59
    SONG_ENTRY(all_star),                // PLAY_SONG_60
    SONG_ENTRY(rick_roll),               // PLAY_SONG_61
    SONG_ENTRY(ff_prelude),              // PLAY_SONG_62
    SONG_ENTRY(to_boldly_go),            // PLAY_SONG_63
    SONG_ENTRY(kataware_doki),           // PLAY_SONG_64
    SONG_ENTRY(megalovania),             // PLAY_SONG_65
    SONG_ENTRY(michishirube),            // PLAY_SONG_66
    SONG_ENTRY(liebesleid),              // PLAY_SONG_67
    SONG_ENTRY(melodies_of_life),        // PLAY_SONG_68
    SONG_ENTRY(eyes_on_me),              // PLAY_SONG_69
    SONG_ENTRY(song_of_the_ancients),    // PLAY_SONG_70
    SONG_ENTRY(nier_amusement_park),     // PLAY_SONG_71
    SONG_ENTRY(copied_city),             // PLAY_SONG_72
    SONG_ENTRY(vague_hope_cold_rain),    // PLAY_SONG_73
    SONG_ENTRY(kaine_salvation),         // PLAY_SONG_74
    SONG_ENTRY(weight_of_the_world),     // PLAY_SONG_75
    SONG_ENTRY(isabellas_lullaby),       // PLAY_SONG_76
    SONG_ENTRY(terras_theme),            // PLAY_SONG_77
    SONG_ENTRY(renai_circulation),       // PLAY_SONG_78
    SONG_ENTRY(platinum_disco),          // PLAY_SONG_79
};
// clang-format on

_Static_assert(
    PLAY_SONG_SENTINEL_ - PLAY_SONG_00 == sizeof(song_table) / sizeof(song_table[0]),
    "PLAY_SONG keycode range and song_table must stay in sync");

// clang-format off
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
    /*
     * Generated code: this comment and the 22 lines following it were generated by
     * LayerTapDanceCodes.getEnumEntries in qmk-tools
     */
    TD_L00,
    TD_L01,
    TD_L02,
    TD_L03,
    TD_L04,
    TD_L05,
    TD_L06,
    TD_L07,
    TD_L08,
    TD_L09,
    TD_L10,
    TD_L11,
    TD_L12,
    TD_L13,
    TD_L14,
    TD_L15,
    TD_L16,
    TD_L17,
    TD_L18,
    TD_L19,
    TD_L20,
    TD_LLIST
};
// clang-format on

/*
 * Generated code: this comment and the 23 lines following it were generated by
 * ForEachLayer.getForEachLayer in qmk-tools
 */
// single source of truth for layer order; enum and layer_name_strs[] both expand this macro
#define FOR_EACH_LAYER(X) \
    X(_WIN_BASE)      \
    X(_MAC_BASE)      \
    X(_COLEMAK_DH)    \
    X(_WIN_SYM)       \
    X(_MAC_SYM)       \
    X(_NUMPAD)        \
    X(_GREEK_W)       \
    X(_GREEK_M)       \
    X(_ACCENT)        \
    X(_A_ACUTE)       \
    X(_A_CARON)       \
    X(_A_CEDILLA)     \
    X(_A_CIRCUMFLEX)  \
    X(_A_DIAERESIS)   \
    X(_A_GRAVE)       \
    X(_A_RING_ABOVE)  \
    X(_A_STROKE)      \
    X(_A_TILDE)       \
    X(_J1)            \
    X(_J2)            \
    X(_LMAPS)

enum layer_names {
#define X(name) name,
    FOR_EACH_LAYER(X)
#undef X
    LAYER_COUNT,  // not a real layer, just used to count enum size (must be kept last)
};

static const char * const layer_name_strs[] = {
#define X(name) #name,
    FOR_EACH_LAYER(X)
#undef X
};

/*
 * Generated code: this comment and the 172 lines following it were generated by
 * Keymap.getKeymap in qmk-tools
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_WIN_BASE] = LAYOUT_moonlander(
        KC_ESCAPE,     TD(DANCE_0),   TD(DANCE_1),   TD(DANCE_2),   TD(DANCE_3),   TD(DANCE_4),   KC_EQUAL,                     EN_DASH,       TD(DANCE_5),   TD(DANCE_6),   TD(DANCE_7),   TD(DANCE_8),   TD(DANCE_9),   TG(_MAC_BASE),
        KC_GRAVE,      KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_BSLS,                      EM_DASH,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_MINUS,
        KC_TAB,        KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          KC_LBRC,                      KC_RBRC,       KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       KC_QUOTE,
        KC_LSFT,       KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,                                                       KC_N,          KC_M,          KC_COMMA,      KC_DOT,        KC_UP,         KC_SLASH,
        KC_LCTL,       CW_TOGG,       LGUI(KC_PSCR), TG(_NUMPAD),   MO(_WIN_SYM),                 KC_LGUI,                      KC_CAPS,                      LGUI(KC_DOT),  KC_RCTL,       KC_LEFT,       KC_DOWN,       KC_RIGHT,
                                                                    KC_ENTER,      KC_LALT,       MO(_ACCENT),                  KC_DELETE,     KC_BSPC,       KC_SPACE
    ),
    [_MAC_BASE] = LAYOUT_moonlander(
        _______,              _______,              _______,              _______,              _______,              _______,              _______,                                    LALT(KC_MINUS),       _______,              _______,              _______,              _______,              _______,              _______,
        _______,              _______,              _______,              _______,              _______,              _______,              _______,                                    LALT(LSFT(KC_MINUS)), _______,              _______,              _______,              _______,              _______,              _______,
        _______,              _______,              _______,              _______,              _______,              _______,              _______,                                    _______,              _______,              _______,              _______,              _______,              _______,              _______,
        _______,              _______,              _______,              _______,              _______,              _______,                                                                                _______,              _______,              _______,              _______,              _______,              _______,
        _______,              _______,              LGUI(LSFT(KC_3)),     _______,              MO(_MAC_SYM),                               _______,                                    _______,                                    LGUI(LCTL(KC_SPACE)), _______,              _______,              _______,              _______,
                                                                                                _______,              _______,              NOT_EQUAL_TO,                               _______,              _______,              _______
    ),
    [_COLEMAK_DH] = LAYOUT_moonlander(
        _______,         _______,         _______,         _______,         _______,         _______,         _______,                          _______,         _______,         _______,         _______,         _______,         _______,         TG(_COLEMAK_DH),
        _______,         _______,         _______,         KC_F,            KC_P,            KC_B,            _______,                          _______,         KC_J,            KC_L,            KC_U,            KC_Y,            KC_SCLN,         _______,
        _______,         _______,         KC_R,            KC_S,            KC_T,            _______,         _______,                          _______,         KC_M,            KC_N,            KC_E,            KC_I,            KC_O,            _______,
        _______,         _______,         _______,         _______,         KC_D,            KC_V,                                                               KC_K,            KC_H,            _______,         _______,         _______,         _______,
        _______,         _______,         _______,         _______,         _______,                          _______,                          _______,                          _______,         _______,         _______,         _______,         _______,
                                                                            _______,         _______,         _______,                          _______,         _______,         _______
    ),
    [_WIN_SYM] = LAYOUT_moonlander(
        INV_EXLM,     KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        ALMOST_EQ,                  FRAC_1_4,     KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       PLAY_ZELDA,
        GRAVE_P,      SUP_1,        SUP_2,        SUP_3,        SUP_N,        PI,           BULLET,                     FRAC_1_2,     KC_F11,       KC_F12,       DAGGER,       BRACE_P,      BRACKET_P,    PLUS_MINUS,
        NOT_SIGN,     AE,           OE,           SHARP_S,      TM_SIGN,      C_CIRC,       R_CIRC,                     FRAC_3_4,     MICRO,        UP_ARROW,     DDAGGER,      INFINITY,     PAREN_P,      QUOTE_P,
        _______,      KC_PLUS,      KC_MINUS,     MULT_SIGN,    DIV_SIGN,     DEGREE_SIGN,                                            LEFT_ARROW,   DOWN_ARROW,   RIGHT_ARROW,  MIDDLE_DOT,   KC_PGUP,      INV_QUES,
        TG(_GREEK_W), LR_ARROW,     UD_ARROW,     _______,      _______,                    NOTE_8TH,                   NOTES_8TH,                  SECTION_SIGN, PILCROW,      KC_HOME,      KC_PGDN,      KC_END,
                                                                CENT_SIGN,    POUND_SIGN,   YEN_SIGN,                   FULL_BLOCK,   LT_OR_EQ,     GT_OR_EQ
    ),
    [_MAC_SYM] = LAYOUT_moonlander(
        INV_EXLM,     KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        ALMOST_EQ,                  FRAC_1_4,     KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       PLAY_ZELDA,
        GRAVE_P,      SUP_1,        SUP_2,        SUP_3,        SUP_N,        PI,           BULLET,                     FRAC_1_2,     KC_F11,       KC_F12,       DAGGER,       BRACE_P,      BRACKET_P,    PLUS_MINUS,
        NOT_SIGN,     AE,           OE,           SHARP_S,      TM_SIGN,      C_CIRC,       R_CIRC,                     FRAC_3_4,     MICRO,        UP_ARROW,     DDAGGER,      INFINITY,     PAREN_P,      QUOTE_P,
        _______,      KC_PLUS,      KC_MINUS,     MULT_SIGN,    DIV_SIGN,     DEGREE_SIGN,                                            LEFT_ARROW,   DOWN_ARROW,   RIGHT_ARROW,  MIDDLE_DOT,   KC_PGUP,      INV_QUES,
        TG(_GREEK_M), LR_ARROW,     UD_ARROW,     _______,      _______,                    NOTE_8TH,                   NOTES_8TH,                  SECTION_SIGN, PILCROW,      KC_HOME,      KC_PGDN,      KC_END,
                                                                CENT_SIGN,    POUND_SIGN,   YEN_SIGN,                   FULL_BLOCK,   LT_OR_EQ,     GT_OR_EQ
    ),
    [_NUMPAD] = LAYOUT_moonlander(
        QK_RBT,             QK_BOOT,            PRINT_VER,          XXXXXXX,            XXXXXXX,            XXXXXXX,            DT_UP,                                  XXXXXXX,            XXXXXXX,            KC_NUM_LOCK,        KC_PSLS,            KC_PAST,            KC_PMNS,            TG(_COLEMAK_DH),
        XXXXXXX,            XXXXXXX,            XXXXXXX,            KC_BRID,            KC_BRIU,            XXXXXXX,            DT_PRNT,                                XXXXXXX,            XXXXXXX,            KC_P7,              KC_P8,              KC_P9,              KC_PPLS,            XXXXXXX,
        TG(_J1),            XXXXXXX,            KC_MUTE,            KC_VOLD,            KC_VOLU,            XXXXXXX,            DT_DOWN,                                XXXXXXX,            XXXXXXX,            KC_P4,              KC_P5,              KC_P6,              KC_PPLS,            XXXXXXX,
        TG(_J2),            TOGGLE_LAYER_COLOR, RGB_TOG,            RGB_MOD,            MOON_LED_LEVEL,     TG(_LMAPS),                                                                     XXXXXXX,            KC_P1,              KC_P2,              KC_P3,              KC_PENT,            XXXXXXX,
        AU_TOGG,            MU_TOGG,            MU_NEXT,            _______,            XXXXXXX,                                XXXXXXX,                                XXXXXXX,                                KC_P0,              KC_P0,              KC_PDOT,            KC_PENT,            XXXXXXX,
                                                                                        _______,            XXXXXXX,            XXXXXXX,                                _______,            _______,            _______
    ),
    [_GREEK_W] = LAYOUT_moonlander(
        KC_ESCAPE,    KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_EQUAL,                   EN_DASH,      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         XXXXXXX,
        KC_GRAVE,     XXXXXXX,      XXXXXXX,      PHI,          PI,           XXXXXXX,      KC_BSLS,                    EM_DASH,      XXXXXXX,      XXXXXXX,      THETA,        XXXXXXX,      KC_SCLN,      KC_MINUS,
        KC_TAB,       ALPHA,        XXXXXXX,      SIGMA,        TAU,          GAMMA,        KC_LBRC,                    KC_RBRC,      MU,           XXXXXXX,      EPSILON,      XXXXXXX,      XXXXXXX,      KC_QUOTE,
        KC_LSFT,      XXXXXXX,      XXXXXXX,      XXXXXXX,      DELTA,        OMEGA,                                                  XXXXXXX,      XXXXXXX,      KC_COMMA,     KC_DOT,       KC_UP,        KC_SLASH,
        TG(_GREEK_W), CW_TOGG,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,                    KC_CAPS,                    LGUI(KC_DOT), XXXXXXX,      KC_LEFT,      KC_DOWN,      KC_RIGHT,
                                                                KC_ENTER,     XXXXXXX,      XXXXXXX,                    KC_DELETE,    KC_BSPC,      KC_SPACE
    ),
    [_GREEK_M] = LAYOUT_moonlander(
        KC_ESCAPE,            KC_1,                 KC_2,                 KC_3,                 KC_4,                 KC_5,                 KC_EQUAL,                                   LALT(KC_MINUS),       KC_6,                 KC_7,                 KC_8,                 KC_9,                 KC_0,                 XXXXXXX,
        KC_GRAVE,             XXXXXXX,              FINAL_SIGMA,          PHI,                  PI,                   BETA,                 KC_BSLS,                                    LALT(LSFT(KC_MINUS)), XI,                   LAMBDA,               THETA,                UPSILON,              KC_SCLN,              KC_MINUS,
        KC_TAB,               ALPHA,                RHO,                  SIGMA,                TAU,                  GAMMA,                KC_LBRC,                                    KC_RBRC,              MU,                   NU,                   EPSILON,              IOTA,                 OMICRON,              KC_QUOTE,
        KC_LSFT,              ZETA,                 CHI,                  PSI,                  DELTA,                OMEGA,                                                                                  KAPPA,                ETA,                  KC_COMMA,             KC_DOT,               KC_UP,                KC_SLASH,
        TG(_GREEK_M),         CW_TOGG,              XXXXXXX,              XXXXXXX,              XXXXXXX,                                    XXXXXXX,                                    KC_CAPS,                                    LGUI(LCTL(KC_SPACE)), XXXXXXX,              KC_LEFT,              KC_DOWN,              KC_RIGHT,
                                                                                                KC_ENTER,             XXXXXXX,              XXXXXXX,                                    KC_DELETE,            KC_BSPC,              KC_SPACE
    ),
    [_ACCENT] = LAYOUT_moonlander(
        XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            OSL(_A_CIRCUMFLEX), XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
        OSL(_A_GRAVE),      XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            OSL(_A_DIAERESIS),  XXXXXXX,
        OSL(_A_TILDE),      XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            OSL(_A_RING_ABOVE), OSL(_A_ACUTE),
        XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            OSL(_A_CARON),                                                                  XXXXXXX,            XXXXXXX,            OSL(_A_CEDILLA),    XXXXXXX,            XXXXXXX,            OSL(_A_STROKE),
        XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,                                XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
                                                                                        XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX
    ),
    [_A_ACUTE] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, ACUTE_U, ACUTE_Y, XXXXXXX, XXXXXXX,
        XXXXXXX, ACUTE_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, ACUTE_E, ACUTE_I, ACUTE_O, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_A_CARON] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, CARON_S, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, CARON_Z, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_A_CEDILLA] = LAYOUT_moonlander(
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        KC_LSFT,   XXXXXXX,   XXXXXXX,   CEDILLA_C, XXXXXXX,   XXXXXXX,                                    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,              XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                                                    XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX
    ),
    [_A_CIRCUMFLEX] = LAYOUT_moonlander(
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      CIRCUMFLEX_U, XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      CIRCUMFLEX_A, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      CIRCUMFLEX_E, CIRCUMFLEX_I, CIRCUMFLEX_O, XXXXXXX,
        KC_LSFT,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,                    XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                                                XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX
    ),
    [_A_DIAERESIS] = LAYOUT_moonlander(
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     DIAERESIS_U, DIAERESIS_Y, XXXXXXX,     XXXXXXX,
        XXXXXXX,     DIAERESIS_A, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     DIAERESIS_E, DIAERESIS_I, DIAERESIS_O, XXXXXXX,
        KC_LSFT,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                                            XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
        XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,                  XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,
                                                            XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX
    ),
    [_A_GRAVE] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, GRAVE_U, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, GRAVE_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, GRAVE_E, GRAVE_I, GRAVE_O, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_A_RING_ABOVE] = LAYOUT_moonlander(
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      RING_ABOVE_A, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        KC_LSFT,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,                    XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                                                XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX
    ),
    [_A_STROKE] = LAYOUT_moonlander(
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  STROKE_O, XXXXXXX,
        KC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX
    ),
    [_A_TILDE] = LAYOUT_moonlander(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, TILDE_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, TILDE_N, XXXXXXX, XXXXXXX, TILDE_O, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_J1] = LAYOUT_moonlander(
        PLAY_SONG_00, PLAY_SONG_01, PLAY_SONG_02, PLAY_SONG_03, PLAY_SONG_04, PLAY_SONG_05, PLAY_SONG_06,               PLAY_SONG_07, PLAY_SONG_08, PLAY_SONG_09, PLAY_SONG_10, PLAY_SONG_11, PLAY_SONG_12, PLAY_SONG_13,
        PLAY_SONG_14, PLAY_SONG_15, PLAY_SONG_16, PLAY_SONG_17, PLAY_SONG_18, PLAY_SONG_19, PLAY_SONG_20,               PLAY_SONG_21, PLAY_SONG_22, PLAY_SONG_23, PLAY_SONG_24, PLAY_SONG_25, PLAY_SONG_26, PLAY_SONG_27,
        _______,      PLAY_SONG_28, PLAY_SONG_29, PLAY_SONG_30, PLAY_SONG_31, PLAY_SONG_32, PLAY_SONG_33,               PLAY_SONG_34, PLAY_SONG_35, PLAY_SONG_36, PLAY_SONG_37, PLAY_SONG_38, PLAY_SONG_39, PLAY_SONG_40,
        XXXXXXX,      PLAY_SONG_41, PLAY_SONG_42, PLAY_SONG_43, PLAY_SONG_44, PLAY_SONG_45,                                           PLAY_SONG_46, PLAY_SONG_47, PLAY_SONG_48, PLAY_SONG_49, PLAY_SONG_50, PLAY_SONG_51,
        PLAY_SONG_52, PLAY_SONG_53, PLAY_SONG_54, PLAY_SONG_55, PLAY_SONG_56,               PLAY_JT,                    PLAY_ZELDA,                 PLAY_SONG_57, PLAY_SONG_58, PLAY_SONG_59, PLAY_SONG_60, PLAY_SONG_61,
                                                                XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX
    ),
    [_J2] = LAYOUT_moonlander(
        PLAY_SONG_62, PLAY_SONG_63, PLAY_SONG_64, PLAY_SONG_65, PLAY_SONG_66, PLAY_SONG_67, PLAY_SONG_68,               PLAY_SONG_69, PLAY_SONG_70, PLAY_SONG_71, PLAY_SONG_72, PLAY_SONG_73, PLAY_SONG_74, PLAY_SONG_75,
        PLAY_SONG_76, PLAY_SONG_77, PLAY_SONG_78, PLAY_SONG_79, XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        _______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    PLAY_JT,                    PLAY_ZELDA,                 XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
                                                                XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX
    ),
    [_LMAPS] = LAYOUT_moonlander(
        TD(TD_L00),   TD(TD_L01),   TD(TD_L02),   TD(TD_L03),   TD(TD_L04),   TD(TD_L05),   XXXXXXX,                    XXXXXXX,      TD(TD_L06),   TD(TD_L07),   TD(TD_L08),   TD(TD_L09),   XXXXXXX,      XXXXXXX,
        TD(TD_L10),   TD(TD_L11),   TD(TD_L12),   TD(TD_L13),   TD(TD_L14),   TD(TD_L15),   XXXXXXX,                    XXXXXXX,      TD(TD_L16),   TD(TD_L17),   TD(TD_L18),   TD(TD_L19),   XXXXXXX,      XXXXXXX,
        TD(TD_L20),   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_UP,        XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    TD(TD_LLIST),               XXXXXXX,                    XXXXXXX,      XXXXXXX,      KC_LEFT,      KC_DOWN,      KC_RIGHT,
                                                                KC_ENTER,     XXXXXXX,      XXXXXXX,                    KC_DELETE,    KC_BSPC,      KC_SPACE
    )
    // clang-format on
};

extern rgb_config_t rgb_matrix_config;

// NUM_LEDS defined in led_logic.h
// period for LED_BLINK_FAST blinking (smaller value implies faster)
#define LED_BLINK_FAST_PERIOD_MS 300

#define LED_IDX_CAPS       0  // led_blink_state index for caps lock / caps word
#define LED_IDX_LAYER_BASE 1  // led_blink_state indices 1–5 encode current layer in binary

// LED mode values defined in led_logic.h: LED_OFF, LED_ON, LED_BLINK_SLOW, LED_BLINK_FAST
static uint8_t led_blink_state[NUM_LEDS] = {0};

// indexed by layer number; if more layers need songs, consider a map<layer,song> + get_song(layer) indirection instead
_Static_assert(_WIN_BASE == 0, "start_up_songs_by_layer assumes _WIN_BASE is at index 0");
_Static_assert(_MAC_BASE == 1, "start_up_songs_by_layer assumes _MAC_BASE is at index 1");
static const song_entry_t start_up_songs_by_layer[] = {
    SONG_ENTRY(mario_theme),          // _WIN_BASE
    SONG_ENTRY(zelda_uncover_secret), // _MAC_BASE
};
#define START_UP_SONGS_COUNT (sizeof(start_up_songs_by_layer) / sizeof(start_up_songs_by_layer[0]))
_Static_assert(START_UP_SONGS_COUNT <= LAYER_COUNT, "start_up_songs_by_layer has more entries than there are layers");

// returns without layer change if layer_num is invalid or has no startup song
// NB: returns (without layer change) if layer has no song (in start_up_songs_by_layer_array)--even if layer exists
void set_single_active_layer_with_sound(uint8_t layer_num) {
    if (layer_num >= LAYER_COUNT) {
#ifdef CONSOLE_ENABLE
        uprintf("set_single_active_layer_with_sound: layer_num %u >= LAYER_COUNT\n", layer_num);
#endif
        return;
    }
    if (layer_num >= START_UP_SONGS_COUNT) {
#ifdef CONSOLE_ENABLE
        uprintf("set_single_active_layer_with_sound: layer_num %u has no startup song\n", layer_num);
#endif
        return;
    }
#ifdef AUDIO_ENABLE
    const song_entry_t *s = &start_up_songs_by_layer[layer_num];
    audio_play_melody(s->notes, s->note_count, false);
#endif
    layer_state_t layer_state = (layer_state_t)(1 << layer_num);
    // default_layer_set(layer_state);
    layer_state_set(layer_state);
}

static uint32_t led_blink_callback(uint32_t trigger_time, void *cb_arg) {
    static uint8_t phase = 0;
    phase                = (phase + 1) % 8;

    STATUS_LED_1(led_on_at_phase_inner(led_blink_state[0], phase));
    STATUS_LED_2(led_on_at_phase_inner(led_blink_state[1], phase));
    STATUS_LED_3(led_on_at_phase_inner(led_blink_state[2], phase));
    STATUS_LED_4(led_on_at_phase_inner(led_blink_state[3], phase));
    STATUS_LED_5(led_on_at_phase_inner(led_blink_state[4], phase));
    STATUS_LED_6(led_on_at_phase_inner(led_blink_state[5], phase));

    return LED_BLINK_FAST_PERIOD_MS / 2;
}

bool process_detected_host_os_user(os_variant_t os) {
    switch (os) {
        case OS_MACOS:
        case OS_IOS:
            set_single_active_layer_with_sound(_MAC_BASE);
            break;
        default: // OS_WINDOWS, OS_LINUX
            set_single_active_layer_with_sound(_WIN_BASE);
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();

    // to take control of the Moonlander's LEDs
    keyboard_config.led_level = false;

    defer_exec(1, led_blink_callback, NULL);

    // if _default_ layer is changed and we want it changed (back) to _WIN_BASE (i.e., lowest level), run:
    // set_single_persistent_default_layer(_WIN_BASE);
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
/*
 * Generated code: this comment and the 45 lines following it were generated by
 * Ledmap.getLedmap in qmk-tools
 */
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    // clang-format off
    [_WIN_BASE] = {{HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_GREEN}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_GREEN}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_SFG_ORANGE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}},

    [_MAC_BASE] = {{HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_GREEN}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_GREEN}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_PACIFIC_BLUE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_RED}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}},

    [_COLEMAK_DH] = {{HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ALLIGATOR}, {HSV_ALLIGATOR}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_ZELDA_CART}, {HSV_GREEN}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_ZELDA_CART}, {HSV_GREEN}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ALLIGATOR}, {HSV_ALLIGATOR}, {HSV_ALLIGATOR}, {HSV_GREEN}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_YELLOW}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_ZELDA_CART}, {HSV_YELLOW}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_ZELDA_CART}, {HSV_ALLIGATOR}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_WHITE}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}, {HSV_ZELDA_CART}},

    [_WIN_SYM] = {{HSV_ORANGE}, {HSV_CYAN}, {HSV_ORANGE}, {HSV_BLUE}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_MUDDY_WATERS}, {HSV_MAGENTA}, {HSV_OFF}, {HSV_RED}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_ORANGE}, {HSV_GRAY40}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_PRINCE_PURP}, {HSV_ZELDA_CART}, {HSV_GRAY40}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_CYAN}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_OLIVE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_PRINCE_PURP}},

    [_MAC_SYM] = {{HSV_ORANGE}, {HSV_CYAN}, {HSV_ORANGE}, {HSV_RED}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_MUDDY_WATERS}, {HSV_MAGENTA}, {HSV_OFF}, {HSV_RED}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_ORANGE}, {HSV_GRAY40}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_PRINCE_PURP}, {HSV_ZELDA_CART}, {HSV_GRAY40}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_CYAN}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_OLIVE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_PRINCE_PURP}},

    [_NUMPAD] = {{HSV_MAROON}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_BLUE}, {HSV_RED}, {HSV_OFF}, {HSV_OFF}, {HSV_ALLIGATOR}, {HSV_BLUE}, {HSV_WHITE}, {HSV_OFF}, {HSV_RED}, {HSV_ALLIGATOR}, {HSV_BLUE}, {HSV_OFF}, {HSV_DAVYS_GRAY}, {HSV_MAROON}, {HSV_ALLIGATOR}, {HSV_GREEN}, {HSV_OFF}, {HSV_DARK_GRAY}, {HSV_GREEN50}, {HSV_ALLIGATOR}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_GREEN}, {HSV_VERMILION}, {HSV_VERM75}, {HSV_VERM50}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_ZELDA_CART}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_GRAY40}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}},

    [_GREEK_W] = {{HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_GREEN}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_BLUE}, {HSV_PRINCE_PURP}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}},

    [_GREEK_M] = {{HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_GREEN}, {HSV_SFG_ORANGE}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_OFF}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}},

    [_ACCENT] = {{HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_ACUTE] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_CARON] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_CEDILLA] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_CIRCUMFLEX] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_DIAERESIS] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_GRAVE] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_RING_ABOVE] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_STROKE] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_A_TILDE] = {{HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_BLUE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}},

    [_J1] = {{HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_GREEN}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}},

    [_J2] = {{HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_GREEN}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_PRINCE_PURP}},

    [_LMAPS] = {{HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_GREEN}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_DAVYS_GRAY}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_YELLOW}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_YELLOW}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_DAVYS_GRAY}, {HSV_DAVYS_GRAY}, {HSV_DAVYS_GRAY}, {HSV_OFF}}
    // clang-format on
};

void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {.h = pgm_read_byte(&ledmap[layer][i][0]), .s = pgm_read_byte(&ledmap[layer][i][1]), .v = pgm_read_byte(&ledmap[layer][i][2])};
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, RGB_BLACK);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, (uint8_t)(f * rgb.r), (uint8_t)(f * rgb.g), (uint8_t)(f * rgb.b));
        }
    }
}

bool rgb_matrix_indicators_user(void) {
#ifdef COMMUNITY_MODULE_ORYX_ENABLE
    if (!rawhid_state.rgb_control && !keyboard_config.disable_layer_led) {
#else
    if (!keyboard_config.disable_layer_led) {
#endif
        set_layer_color(get_highest_layer(layer_state));
        return false; // prevent further processing from overriding our colors
    }

    return true; // let rawhid/disable_layer_led path continue normally
}


// Shift + Backspace = Delete
const key_override_t shift_backspace_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &shift_backspace_override,
};

// #define USB_LED_CAPS_LOCK 1

bool is_caps_lock_on(void) {
    // return host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK);
    return host_keyboard_led_state().caps_lock;
}

bool is_shift_pressed(void) {
    return get_mods() & MOD_MASK_SHIFT;
}

/*
 * should_capitalize() is true iff shift is pressed, CAPS WORD is active, or CAPS LOCK is active.
 *
 * NB: CAPS LOCK and CAPS WORD therefore shift all char-map keycodes by default. To make a specific
 * character ignore CAPS LOCK/CAPS WORD (responding only to shift), replace should_capitalize() with
 * is_shift_pressed() at that character's call site.
 */
bool should_capitalize(void) {
    return should_capitalize_inner(is_caps_lock_on(), is_caps_word_on(), is_shift_pressed());
}

static bool is_mac_os(void) {
    return layer_state_is(_MAC_BASE);
}

static void send_os_specific_sequence(const os_specific_sequence_t *seq) {
    register_mods(MOD_LALT);
    for (uint8_t i = 0; i < seq->count; i++) tap_code(seq->keys[i]);
    unregister_mods(MOD_LALT);
}

static bool handle_os_char(uint16_t keycode, keyrecord_t *record) {
    // Bounds check avoids the scan for the common case (non-char-map keycodes).
    // The linear scan is O(OS_SPECIFIC_CHAR_MAP_COUNT) ≈ 100 ns; the Alt/Option
    // sequences that follow take tens of ms, so this is negligible.
    if (keycode < OS_SPECIFIC_CHAR_MAP_KC_MIN || keycode > OS_SPECIFIC_CHAR_MAP_KC_MAX) return true;
    for (uint8_t i = 0; i < OS_SPECIFIC_CHAR_MAP_COUNT; i++) {
        if (os_specific_char_map[i].kc == keycode) {
            if (!record->event.pressed) return false;
            bool is_mac = is_mac_os();
            const os_specific_sequence_t *lower = is_mac ? &os_specific_char_map[i].mac_lower : &os_specific_char_map[i].win_lower;
            const os_specific_sequence_t *upper = is_mac ? &os_specific_char_map[i].mac_upper : &os_specific_char_map[i].win_upper;
            if (lower->count == 0 && upper->count == 0) return true;
            // should_capitalize() checks caps lock, caps word, and shift state
            bool capitalize = os_specific_char_map[i].is_cased && upper->count > 0 && should_capitalize();
            const os_specific_sequence_t *seq = capitalize ? upper : lower;
            if (capitalize) {
                uint8_t saved = get_mods();
                clear_mods();
                send_os_specific_sequence(seq);
                set_mods(saved);
            } else {
                send_os_specific_sequence(seq);
            }
            return false;
        }
    }
    return true;
}

static void update_caps_indicator(void) {
    led_blink_state[LED_IDX_CAPS] = caps_led_mode(is_caps_lock_on(), is_caps_word_on());
}

bool led_update_user(led_t led_state) {
    update_caps_indicator();

    return true;
}

void caps_word_set_user(bool active) {
    update_caps_indicator();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(state);
    for (int i_led = LED_IDX_LAYER_BASE; i_led < NUM_LEDS; ++i_led) {
        led_blink_state[i_led] = layer_led_mode(current_layer, i_led);
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

        case PLAY_SONG_00 ... PLAY_SONG_SENTINEL_ - 1:
            if (record->event.pressed) {
                const song_entry_t *s = &song_table[keycode - PLAY_SONG_00];
                audio_play_melody(s->notes, s->note_count, false);
            }
            return false;

        case PAREN_P:
            if (record->event.pressed) {
                SEND_STRING("()" SS_TAP(X_LEFT));
            }
            return false;

        case BRACKET_P:
            if (record->event.pressed) {
                SEND_STRING("[]" SS_TAP(X_LEFT));
            }
            return false;

        case BRACE_P:
            if (record->event.pressed) {
                SEND_STRING("{}" SS_TAP(X_LEFT));
            }
            return false;

        case QUOTE_P:
            if (record->event.pressed) {
                if (is_shift_pressed()) {
                    SEND_STRING("\"\"" SS_TAP(X_LEFT));
                } else {
                    SEND_STRING("''" SS_TAP(X_LEFT));
                }
            }
            return false;

        case GRAVE_P:
            if (record->event.pressed) {
                SEND_STRING("``" SS_TAP(X_LEFT));
            }
            return false;

        case RGB_SLD:
#ifdef COMMUNITY_MODULE_ORYX_ENABLE
            if (rawhid_state.rgb_control) {
                return false;
            }
#endif
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;

        case PRINT_VER:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;

        case TG(_COLEMAK_DH):
            if (record->event.pressed) {
                layer_invert(_COLEMAK_DH);
                layer_off(_NUMPAD);
            }
            return false;

        default:
            return handle_os_char(keycode, record);
    }

    return true;
}

// Forward declarations for functions defined in dance.c (use tap_dance_state_t from QMK_KEYBOARD_H)
// clang-format off
void on_dance_0(tap_dance_state_t *, void *); void dance_0_finished(tap_dance_state_t *, void *); void dance_0_reset(tap_dance_state_t *, void *);
void on_dance_1(tap_dance_state_t *, void *); void dance_1_finished(tap_dance_state_t *, void *); void dance_1_reset(tap_dance_state_t *, void *);
void on_dance_2(tap_dance_state_t *, void *); void dance_2_finished(tap_dance_state_t *, void *); void dance_2_reset(tap_dance_state_t *, void *);
void on_dance_3(tap_dance_state_t *, void *); void dance_3_finished(tap_dance_state_t *, void *); void dance_3_reset(tap_dance_state_t *, void *);
void on_dance_4(tap_dance_state_t *, void *); void dance_4_finished(tap_dance_state_t *, void *); void dance_4_reset(tap_dance_state_t *, void *);
void on_dance_5(tap_dance_state_t *, void *); void dance_5_finished(tap_dance_state_t *, void *); void dance_5_reset(tap_dance_state_t *, void *);
void on_dance_6(tap_dance_state_t *, void *); void dance_6_finished(tap_dance_state_t *, void *); void dance_6_reset(tap_dance_state_t *, void *);
void on_dance_7(tap_dance_state_t *, void *); void dance_7_finished(tap_dance_state_t *, void *); void dance_7_reset(tap_dance_state_t *, void *);
void on_dance_8(tap_dance_state_t *, void *); void dance_8_finished(tap_dance_state_t *, void *); void dance_8_reset(tap_dance_state_t *, void *);
void on_dance_9(tap_dance_state_t *, void *); void dance_9_finished(tap_dance_state_t *, void *); void dance_9_reset(tap_dance_state_t *, void *);
// clang-format on

/*
 * Generated code: this comment and the 219 lines following it were generated by
 * LmapTapDances.getLmapTapDances in qmk-tools
 */
void dance_l00(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "KC_ESCAPE,     TD(DANCE_0),   TD(DANCE_1),   TD(DANCE_2),   TD(DANCE_3),   TD(DANCE_4),   KC_EQUAL,                     EN_DASH,       TD(DANCE_5),   TD(DANCE_6),   TD(DANCE_7),   TD(DANCE_8),   TD(DANCE_9),   TG(_MAC_BASE),\nKC_GRAVE,      KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_BSLS,                      EM_DASH,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_MINUS,\nKC_TAB,        KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          KC_LBRC,                      KC_RBRC,       KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       KC_QUOTE,\nKC_LSFT,       KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,                                                       KC_N,          KC_M,          KC_COMMA,      KC_DOT,        KC_UP,         KC_SLASH,\nKC_LCTL,       CW_TOGG,       LGUI(KC_PSCR), TG(_NUMPAD),   MO(_WIN_SYM),                 KC_LGUI,                      KC_CAPS,                      LGUI(KC_DOT),  KC_RCTL,       KC_LEFT,       KC_DOWN,       KC_RIGHT,\n                                                            KC_ENTER,      KC_LALT,       MO(_ACCENT),                  KC_DELETE,     KC_BSPC,       KC_SPACE\n"
        );
    } else {
        SEND_STRING("_WIN_BASE");
    }
}

void dance_l01(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "_______,              _______,              _______,              _______,              _______,              _______,              _______,                                    LALT(KC_MINUS),       _______,              _______,              _______,              _______,              _______,              _______,\n_______,              _______,              _______,              _______,              _______,              _______,              _______,                                    LALT(LSFT(KC_MINUS)), _______,              _______,              _______,              _______,              _______,              _______,\n_______,              _______,              _______,              _______,              _______,              _______,              _______,                                    _______,              _______,              _______,              _______,              _______,              _______,              _______,\n_______,              _______,              _______,              _______,              _______,              _______,                                                                                _______,              _______,              _______,              _______,              _______,              _______,\n_______,              _______,              LGUI(LSFT(KC_3)),     _______,              MO(_MAC_SYM),                               _______,                                    _______,                                    LGUI(LCTL(KC_SPACE)), _______,              _______,              _______,              _______,\n                                                                                        _______,              _______,              NOT_EQUAL_TO,                               _______,              _______,              _______\n"
        );
    } else {
        SEND_STRING("_MAC_BASE");
    }
}

void dance_l02(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "_______,         _______,         _______,         _______,         _______,         _______,         _______,                          _______,         _______,         _______,         _______,         _______,         _______,         TG(_COLEMAK_DH),\n_______,         _______,         _______,         KC_F,            KC_P,            KC_B,            _______,                          _______,         KC_J,            KC_L,            KC_U,            KC_Y,            KC_SCLN,         _______,\n_______,         _______,         KC_R,            KC_S,            KC_T,            _______,         _______,                          _______,         KC_M,            KC_N,            KC_E,            KC_I,            KC_O,            _______,\n_______,         _______,         _______,         _______,         KC_D,            KC_V,                                                               KC_K,            KC_H,            _______,         _______,         _______,         _______,\n_______,         _______,         _______,         _______,         _______,                          _______,                          _______,                          _______,         _______,         _______,         _______,         _______,\n                                                                    _______,         _______,         _______,                          _______,         _______,         _______\n"
        );
    } else {
        SEND_STRING("_COLEMAK_DH");
    }
}

void dance_l03(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "INV_EXLM,     KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        ALMOST_EQ,                  FRAC_1_4,     KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       PLAY_ZELDA,\nGRAVE_P,      SUP_1,        SUP_2,        SUP_3,        SUP_N,        PI,           BULLET,                     FRAC_1_2,     KC_F11,       KC_F12,       DAGGER,       BRACE_P,      BRACKET_P,    PLUS_MINUS,\nNOT_SIGN,     AE,           OE,           SHARP_S,      TM_SIGN,      C_CIRC,       R_CIRC,                     FRAC_3_4,     MICRO,        UP_ARROW,     DDAGGER,      INFINITY,     PAREN_P,      QUOTE_P,\n_______,      KC_PLUS,      KC_MINUS,     MULT_SIGN,    DIV_SIGN,     DEGREE_SIGN,                                            LEFT_ARROW,   DOWN_ARROW,   RIGHT_ARROW,  MIDDLE_DOT,   KC_PGUP,      INV_QUES,\nTG(_GREEK_W), LR_ARROW,     UD_ARROW,     _______,      _______,                    NOTE_8TH,                   NOTES_8TH,                  SECTION_SIGN, PILCROW,      KC_HOME,      KC_PGDN,      KC_END,\n                                                        CENT_SIGN,    POUND_SIGN,   YEN_SIGN,                   FULL_BLOCK,   LT_OR_EQ,     GT_OR_EQ\n"
        );
    } else {
        SEND_STRING("_WIN_SYM");
    }
}

void dance_l04(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "INV_EXLM,     KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        ALMOST_EQ,                  FRAC_1_4,     KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       PLAY_ZELDA,\nGRAVE_P,      SUP_1,        SUP_2,        SUP_3,        SUP_N,        PI,           BULLET,                     FRAC_1_2,     KC_F11,       KC_F12,       DAGGER,       BRACE_P,      BRACKET_P,    PLUS_MINUS,\nNOT_SIGN,     AE,           OE,           SHARP_S,      TM_SIGN,      C_CIRC,       R_CIRC,                     FRAC_3_4,     MICRO,        UP_ARROW,     DDAGGER,      INFINITY,     PAREN_P,      QUOTE_P,\n_______,      KC_PLUS,      KC_MINUS,     MULT_SIGN,    DIV_SIGN,     DEGREE_SIGN,                                            LEFT_ARROW,   DOWN_ARROW,   RIGHT_ARROW,  MIDDLE_DOT,   KC_PGUP,      INV_QUES,\nTG(_GREEK_M), LR_ARROW,     UD_ARROW,     _______,      _______,                    NOTE_8TH,                   NOTES_8TH,                  SECTION_SIGN, PILCROW,      KC_HOME,      KC_PGDN,      KC_END,\n                                                        CENT_SIGN,    POUND_SIGN,   YEN_SIGN,                   FULL_BLOCK,   LT_OR_EQ,     GT_OR_EQ\n"
        );
    } else {
        SEND_STRING("_MAC_SYM");
    }
}

void dance_l05(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "QK_RBT,             QK_BOOT,            PRINT_VER,          XXXXXXX,            XXXXXXX,            XXXXXXX,            DT_UP,                                  XXXXXXX,            XXXXXXX,            KC_NUM_LOCK,        KC_PSLS,            KC_PAST,            KC_PMNS,            TG(_COLEMAK_DH),\nXXXXXXX,            XXXXXXX,            XXXXXXX,            KC_BRID,            KC_BRIU,            XXXXXXX,            DT_PRNT,                                XXXXXXX,            XXXXXXX,            KC_P7,              KC_P8,              KC_P9,              KC_PPLS,            XXXXXXX,\nTG(_J1),            XXXXXXX,            KC_MUTE,            KC_VOLD,            KC_VOLU,            XXXXXXX,            DT_DOWN,                                XXXXXXX,            XXXXXXX,            KC_P4,              KC_P5,              KC_P6,              KC_PPLS,            XXXXXXX,\nTG(_J2),            TOGGLE_LAYER_COLOR, RGB_TOG,            RGB_MOD,            MOON_LED_LEVEL,     TG(_LMAPS),                                                                     XXXXXXX,            KC_P1,              KC_P2,              KC_P3,              KC_PENT,            XXXXXXX,\nAU_TOGG,            MU_TOGG,            MU_NEXT,            _______,            XXXXXXX,                                XXXXXXX,                                XXXXXXX,                                KC_P0,              KC_P0,              KC_PDOT,            KC_PENT,            XXXXXXX,\n                                                                                _______,            XXXXXXX,            XXXXXXX,                                _______,            _______,            _______\n"
        );
    } else {
        SEND_STRING("_NUMPAD");
    }
}

void dance_l06(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "KC_ESCAPE,    KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         KC_EQUAL,                   EN_DASH,      KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         XXXXXXX,\nKC_GRAVE,     XXXXXXX,      XXXXXXX,      PHI,          PI,           XXXXXXX,      KC_BSLS,                    EM_DASH,      XXXXXXX,      XXXXXXX,      THETA,        XXXXXXX,      KC_SCLN,      KC_MINUS,\nKC_TAB,       ALPHA,        XXXXXXX,      SIGMA,        TAU,          GAMMA,        KC_LBRC,                    KC_RBRC,      MU,           XXXXXXX,      EPSILON,      XXXXXXX,      XXXXXXX,      KC_QUOTE,\nKC_LSFT,      XXXXXXX,      XXXXXXX,      XXXXXXX,      DELTA,        OMEGA,                                                  XXXXXXX,      XXXXXXX,      KC_COMMA,     KC_DOT,       KC_UP,        KC_SLASH,\nTG(_GREEK_W), CW_TOGG,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,                    KC_CAPS,                    LGUI(KC_DOT), XXXXXXX,      KC_LEFT,      KC_DOWN,      KC_RIGHT,\n                                                        KC_ENTER,     XXXXXXX,      XXXXXXX,                    KC_DELETE,    KC_BSPC,      KC_SPACE\n"
        );
    } else {
        SEND_STRING("_GREEK_W");
    }
}

void dance_l07(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "KC_ESCAPE,            KC_1,                 KC_2,                 KC_3,                 KC_4,                 KC_5,                 KC_EQUAL,                                   LALT(KC_MINUS),       KC_6,                 KC_7,                 KC_8,                 KC_9,                 KC_0,                 XXXXXXX,\nKC_GRAVE,             XXXXXXX,              FINAL_SIGMA,          PHI,                  PI,                   BETA,                 KC_BSLS,                                    LALT(LSFT(KC_MINUS)), XI,                   LAMBDA,               THETA,                UPSILON,              KC_SCLN,              KC_MINUS,\nKC_TAB,               ALPHA,                RHO,                  SIGMA,                TAU,                  GAMMA,                KC_LBRC,                                    KC_RBRC,              MU,                   NU,                   EPSILON,              IOTA,                 OMICRON,              KC_QUOTE,\nKC_LSFT,              ZETA,                 CHI,                  PSI,                  DELTA,                OMEGA,                                                                                  KAPPA,                ETA,                  KC_COMMA,             KC_DOT,               KC_UP,                KC_SLASH,\nTG(_GREEK_M),         CW_TOGG,              XXXXXXX,              XXXXXXX,              XXXXXXX,                                    XXXXXXX,                                    KC_CAPS,                                    LGUI(LCTL(KC_SPACE)), XXXXXXX,              KC_LEFT,              KC_DOWN,              KC_RIGHT,\n                                                                                        KC_ENTER,             XXXXXXX,              XXXXXXX,                                    KC_DELETE,            KC_BSPC,              KC_SPACE\n"
        );
    } else {
        SEND_STRING("_GREEK_M");
    }
}

void dance_l08(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            OSL(_A_CIRCUMFLEX), XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,\nOSL(_A_GRAVE),      XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            OSL(_A_DIAERESIS),  XXXXXXX,\nOSL(_A_TILDE),      XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            OSL(_A_RING_ABOVE), OSL(_A_ACUTE),\nXXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            OSL(_A_CARON),                                                                  XXXXXXX,            XXXXXXX,            OSL(_A_CEDILLA),    XXXXXXX,            XXXXXXX,            OSL(_A_STROKE),\nXXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,                                XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,\n                                                                                XXXXXXX,            XXXXXXX,            XXXXXXX,                                XXXXXXX,            XXXXXXX,            XXXXXXX\n"
        );
    } else {
        SEND_STRING("_ACCENT");
    }
}

void dance_l09(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, ACUTE_U, ACUTE_Y, XXXXXXX, XXXXXXX,\nXXXXXXX, ACUTE_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, ACUTE_E, ACUTE_I, ACUTE_O, XXXXXXX,\nKC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\n                                    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_ACUTE");
    }
}

void dance_l10(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, CARON_S, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nKC_LSFT, CARON_Z, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\n                                    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_CARON");
    }
}

void dance_l11(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\nXXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\nXXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\nKC_LSFT,   XXXXXXX,   XXXXXXX,   CEDILLA_C, XXXXXXX,   XXXXXXX,                                    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\nXXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,              XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\n                                            XXXXXXX,   XXXXXXX,   XXXXXXX,              XXXXXXX,   XXXXXXX,   XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_CEDILLA");
    }
}

void dance_l12(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      CIRCUMFLEX_U, XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      CIRCUMFLEX_A, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      CIRCUMFLEX_E, CIRCUMFLEX_I, CIRCUMFLEX_O, XXXXXXX,\nKC_LSFT,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,                    XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\n                                                        XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_CIRCUMFLEX");
    }
}

void dance_l13(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,\nXXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     DIAERESIS_U, DIAERESIS_Y, XXXXXXX,     XXXXXXX,\nXXXXXXX,     DIAERESIS_A, XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     DIAERESIS_E, DIAERESIS_I, DIAERESIS_O, XXXXXXX,\nKC_LSFT,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                                            XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,\nXXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,                  XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,     XXXXXXX,\n                                                    XXXXXXX,     XXXXXXX,     XXXXXXX,                  XXXXXXX,     XXXXXXX,     XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_DIAERESIS");
    }
}

void dance_l14(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, GRAVE_U, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, GRAVE_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, GRAVE_E, GRAVE_I, GRAVE_O, XXXXXXX,\nKC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\n                                    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_GRAVE");
    }
}

void dance_l15(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      RING_ABOVE_A, XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nKC_LSFT,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,                    XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\n                                                        XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_RING_ABOVE");
    }
}

void dance_l16(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,\nXXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,\nXXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  STROKE_O, XXXXXXX,\nKC_LSFT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,\nXXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,\n                                        XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_STROKE");
    }
}

void dance_l17(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, TILDE_A, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, TILDE_N, XXXXXXX, XXXXXXX, TILDE_O, XXXXXXX,\nKC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\nXXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\n                                    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX\n"
        );
    } else {
        SEND_STRING("_A_TILDE");
    }
}

void dance_l18(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "PLAY_SONG_00, PLAY_SONG_01, PLAY_SONG_02, PLAY_SONG_03, PLAY_SONG_04, PLAY_SONG_05, PLAY_SONG_06,               PLAY_SONG_07, PLAY_SONG_08, PLAY_SONG_09, PLAY_SONG_10, PLAY_SONG_11, PLAY_SONG_12, PLAY_SONG_13,\nPLAY_SONG_14, PLAY_SONG_15, PLAY_SONG_16, PLAY_SONG_17, PLAY_SONG_18, PLAY_SONG_19, PLAY_SONG_20,               PLAY_SONG_21, PLAY_SONG_22, PLAY_SONG_23, PLAY_SONG_24, PLAY_SONG_25, PLAY_SONG_26, PLAY_SONG_27,\n_______,      PLAY_SONG_28, PLAY_SONG_29, PLAY_SONG_30, PLAY_SONG_31, PLAY_SONG_32, PLAY_SONG_33,               PLAY_SONG_34, PLAY_SONG_35, PLAY_SONG_36, PLAY_SONG_37, PLAY_SONG_38, PLAY_SONG_39, PLAY_SONG_40,\nXXXXXXX,      PLAY_SONG_41, PLAY_SONG_42, PLAY_SONG_43, PLAY_SONG_44, PLAY_SONG_45,                                           PLAY_SONG_46, PLAY_SONG_47, PLAY_SONG_48, PLAY_SONG_49, PLAY_SONG_50, PLAY_SONG_51,\nPLAY_SONG_52, PLAY_SONG_53, PLAY_SONG_54, PLAY_SONG_55, PLAY_SONG_56,               PLAY_JT,                    PLAY_ZELDA,                 PLAY_SONG_57, PLAY_SONG_58, PLAY_SONG_59, PLAY_SONG_60, PLAY_SONG_61,\n                                                        XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX\n"
        );
    } else {
        SEND_STRING("_J1");
    }
}

void dance_l19(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "PLAY_SONG_62, PLAY_SONG_63, PLAY_SONG_64, PLAY_SONG_65, PLAY_SONG_66, PLAY_SONG_67, PLAY_SONG_68,               PLAY_SONG_69, PLAY_SONG_70, PLAY_SONG_71, PLAY_SONG_72, PLAY_SONG_73, PLAY_SONG_74, PLAY_SONG_75,\nPLAY_SONG_76, PLAY_SONG_77, PLAY_SONG_78, PLAY_SONG_79, XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\n_______,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    PLAY_JT,                    PLAY_ZELDA,                 XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\n                                                        XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX\n"
        );
    } else {
        SEND_STRING("_J2");
    }
}

void dance_l20(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        SEND_STRING(
            "TD(TD_L00),   TD(TD_L01),   TD(TD_L02),   TD(TD_L03),   TD(TD_L04),   TD(TD_L05),   XXXXXXX,                    XXXXXXX,      TD(TD_L06),   TD(TD_L07),   TD(TD_L08),   TD(TD_L09),   XXXXXXX,      XXXXXXX,\nTD(TD_L10),   TD(TD_L11),   TD(TD_L12),   TD(TD_L13),   TD(TD_L14),   TD(TD_L15),   XXXXXXX,                    XXXXXXX,      TD(TD_L16),   TD(TD_L17),   TD(TD_L18),   TD(TD_L19),   XXXXXXX,      XXXXXXX,\nTD(TD_L20),   XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      _______,                                                XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_UP,        XXXXXXX,\nXXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,                    TD(TD_LLIST),               XXXXXXX,                    XXXXXXX,      XXXXXXX,      KC_LEFT,      KC_DOWN,      KC_RIGHT,\n                                                        KC_ENTER,     XXXXXXX,      XXXXXXX,                    KC_DELETE,    KC_BSPC,      KC_SPACE\n"
        );
    } else {
        SEND_STRING("_LMAPS");
    }
}

void dance_llist(tap_dance_state_t *state, void *user_data) {
    char num[12]; // 10 digits + sign + null covers any int32
    if (state->count == 2) {
        for (int i = 0; i < LAYER_COUNT; i++) {
            snprintf(num, sizeof(num), "%d", i);
            send_string(num);
            send_string(" ");
            send_string(layer_name_strs[i]);
            send_string("\n");
        }
    } else {
        snprintf(num, sizeof(num), "%d", (int)LAYER_COUNT);
        send_string(num);
    }
}

// clang-format on
tap_dance_action_t tap_dance_actions[] = {
    // clang-format off
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
    /*
     * Generated code: this comment and the 22 lines following it were generated by
     * LayerTapDanceCodes.getActionEntries in qmk-tools
     */
    [TD_L00] = ACTION_TAP_DANCE_FN(dance_l00),
    [TD_L01] = ACTION_TAP_DANCE_FN(dance_l01),
    [TD_L02] = ACTION_TAP_DANCE_FN(dance_l02),
    [TD_L03] = ACTION_TAP_DANCE_FN(dance_l03),
    [TD_L04] = ACTION_TAP_DANCE_FN(dance_l04),
    [TD_L05] = ACTION_TAP_DANCE_FN(dance_l05),
    [TD_L06] = ACTION_TAP_DANCE_FN(dance_l06),
    [TD_L07] = ACTION_TAP_DANCE_FN(dance_l07),
    [TD_L08] = ACTION_TAP_DANCE_FN(dance_l08),
    [TD_L09] = ACTION_TAP_DANCE_FN(dance_l09),
    [TD_L10] = ACTION_TAP_DANCE_FN(dance_l10),
    [TD_L11] = ACTION_TAP_DANCE_FN(dance_l11),
    [TD_L12] = ACTION_TAP_DANCE_FN(dance_l12),
    [TD_L13] = ACTION_TAP_DANCE_FN(dance_l13),
    [TD_L14] = ACTION_TAP_DANCE_FN(dance_l14),
    [TD_L15] = ACTION_TAP_DANCE_FN(dance_l15),
    [TD_L16] = ACTION_TAP_DANCE_FN(dance_l16),
    [TD_L17] = ACTION_TAP_DANCE_FN(dance_l17),
    [TD_L18] = ACTION_TAP_DANCE_FN(dance_l18),
    [TD_L19] = ACTION_TAP_DANCE_FN(dance_l19),
    [TD_L20] = ACTION_TAP_DANCE_FN(dance_l20),
    [TD_LLIST] = ACTION_TAP_DANCE_FN(dance_llist)
    // clang-format on
};
