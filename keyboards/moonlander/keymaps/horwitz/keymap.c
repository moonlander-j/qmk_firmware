#include "action_layer.h"
#include "os_detection.h"
#include QMK_KEYBOARD_H
#include "version.h"
#include "colors.h"
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

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    EN_DASH_W,
    EM_DASH_W,
    INV_EXLM_W,
    SUP_2_W,
    SUP_N_W,
    DEGREE_SIGN_W,
    FULL_BLOCK_W,
    FRAC_1_4_W,
    FRAC_1_2_W,
    FRAC_3_4_W,
    TM_SIGN_W,
    DAGGER_W,
    PLUS_MINUS_W,
    UP_ARROW_W,
    INFINITY_W,
    LEFT_ARROW_W,
    DOWN_ARROW_W,
    RIGHT_ARROW_W,
    MIDDLE_DOT_W,
    INV_QUES_W,
    NOT_EQUAL_TO_M,
    INV_EXLM_M,
    SUP_2_M,
    SUP_N_M,
    DEGREE_SIGN_M,
    FULL_BLOCK_M,
    FRAC_1_4_M,
    FRAC_1_2_M,
    FRAC_3_4_M,
    TM_SIGN_M,
    DAGGER_M,
    PLUS_MINUS_M,
    UP_ARROW_M,
    INFINITY_M,
    LEFT_ARROW_M,
    DOWN_ARROW_M,
    RIGHT_ARROW_M,
    MIDDLE_DOT_M,
    INV_QUES_M,
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
    PAREN_P,
    BRACKET_P,
    BRACE_P,
    QUOTE_P,
    GRAVE_P,
    ACUTE_A_W,
    ACUTE_E_W,
    ACUTE_I_W,
    ACUTE_O_W,
    ACUTE_U_W,
    ACUTE_Y_W,
    CARON_S_W,
    CARON_Z_W,
    CEDILLA_C_W,
    CIRCUMFLEX_A_W,
    CIRCUMFLEX_E_W,
    CIRCUMFLEX_I_W,
    CIRCUMFLEX_O_W,
    CIRCUMFLEX_U_W,
    DIAERESIS_A_W,
    DIAERESIS_E_W,
    DIAERESIS_I_W,
    DIAERESIS_O_W,
    DIAERESIS_U_W,
    DIAERESIS_Y_W,
    GRAVE_A_W,
    GRAVE_E_W,
    GRAVE_I_W,
    GRAVE_O_W,
    GRAVE_U_W,
    RING_ABOVE_A_W,
    STROKE_O_W,
    TILDE_A_W,
    TILDE_N_W,
    TILDE_O_W,
    C_CIRC_W,
    R_CIRC_W,
    MULT_SIGN_W,
    DIV_SIGN_W,
    DDAGGER_W,
    SECTION_SIGN_W,
    PILCROW_W,
    SUP_1_W,
    SUP_3_W,
    AE_W,
    OE_W,
    SHARP_S_W,
    CENT_SIGN_W,
    POUND_SIGN_W,
    YEN_SIGN_W,
    MICRO_W,
    NOT_SIGN_W,
    BULLET_W,
    ALMOST_EQ_W,
    // PI_W,
    NOTE_8TH_W,
    NOTES_8TH_W,
    LR_ARROW_W,
    UD_ARROW_W,
    LT_OR_EQ_W,
    GT_OR_EQ_W,
    C_CIRC_M,
    R_CIRC_M,
    MULT_SIGN_M,
    DIV_SIGN_M,
    DDAGGER_M,
    SECTION_SIGN_M,
    PILCROW_M,
    SUP_1_M,
    SUP_3_M,
    AE_M,
    OE_M,
    SHARP_S_M,
    CENT_SIGN_M,
    POUND_SIGN_M,
    YEN_SIGN_M,
    MICRO_M,
    NOT_SIGN_M,
    BULLET_M,
    ALMOST_EQ,
    ALMOST_EQ_M,
    // PI_M,
    NOTE_8TH_M,
    NOTES_8TH_M,
    LR_ARROW_M,
    UD_ARROW_M,
    LT_OR_EQ_M,
    GT_OR_EQ_M,
    ALPHA_W,
    GAMMA_W,
    DELTA_W,
    EPSILON_W,
    THETA_W,
    MU_W,
    PI_W,
    SIGMA_W,
    TAU_W,
    PHI_W,
    OMEGA_W,
    ALPHA_M,
    BETA_M,
    GAMMA_M,
    DELTA_M,
    EPSILON_M,
    ZETA_M,
    ETA_M,
    THETA_M,
    IOTA_M,
    KAPPA_M,
    LAMBDA_M,
    MU_M,
    NU_M,
    XI_M,
    OMICRON_M,
    PI_M,
    RHO_M,
    SIGMA_M,
    TAU_M,
    UPSILON_M,
    PHI_M,
    CHI_M,
    PSI_M,
    OMEGA_M,
    FINAL_SIGMA_M,
    PRINT_VER
};

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

enum layer_names { _WIN_BASE, _MAC_BASE, _WIN_SYM, _MAC_SYM, _NUMPAD, _GREEK_W, _GREEK_M, _ACCENT, _A_ACUTE, _A_CARON, _A_CEDILLA, _A_CIRCUMFLEX, _A_DIAERESIS, _A_GRAVE, _A_RING_ABOVE, _A_STROKE, _A_TILDE, _J1, _J2, _QWERTY };

/*
(WIN|MAC)_SYM layout

¡ F F F F F ≈   ¼ F F F F F 2
``¹ ² ³ ⁿ π •   ½ F F † {}[]±
¬ Æ Œ ß ™ © ®   ¾ µ ↑ ‡ ∞ ()''
. + - × ÷ °       ← ↓ → · ⇞ ¿
. ↔ ↕ . .   ♪   ♫   § ¶ ⇱ ⇟ ⇲
        ¢ £ ¥   █ ≤ ≥


_GREEK_W layout (ignoring keys matching _WIN_BASE)

. . . . . . .   . . . . . . .
. . . Φ . . .   . . . Θ . . .
. . . Σ . Γ .   . . . . . . .
. . . . . Ω       . . . . . .
. . . . .   .   .   . . . . .
        . . .   . . .

. . . . . . .   . . . . . . .
. . . φ π . .   . . . . . . .
. α . σ τ . .   . μ . ε . . .
. . . . δ .       . . . . . .
. . . . .   .   .   . . . . .
        . . .   . . .


_GREEK_M layout (ignoring keys matching _MAC_BASE)

. . . . . . .   . . . . . . .
. . Φ Π Β . .   . Ξ Λ Θ Υ . .
. Α Ρ Σ Τ Γ .   . Μ Ν Ε Ι Ο .
. Ζ Χ Ψ Δ Ω       Κ Η . . . .
. . . . .   .   .   . . . . .
        . . .   . . .

. . . . . . .   . . . . . . .
. . ς φ π β .   . ξ λ θ υ . .
. α ρ σ τ γ .   . μ ν ε ι ο .
. ζ χ ψ δ ω       κ η . . . .
. . . . .   .   .   . . . . .
        . . .   . . .
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_WIN_BASE] = LAYOUT_moonlander(
        KC_ESCAPE,      TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),    KC_EQUAL,                EN_DASH_W,      TD(DANCE_5),    TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),    TD(DANCE_9),    TG(_MAC_BASE),
        KC_GRAVE,       KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_BSLS,                 EM_DASH_W,      KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_MINUS,
        KC_TAB,         KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_LBRC,                 KC_RBRC,        KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,
        KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                                    KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,
        KC_LCTL,        CW_TOGG,        LGUI(KC_PSCR),  TG(_NUMPAD),    MO(_WIN_SYM),                   KC_LGUI,                 KC_CAPS,                        LGUI(KC_DOT),   KC_RCTL,        KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                        KC_ENTER,       KC_LALT,        MO(_ACCENT),             KC_DELETE,      KC_BSPC,        KC_SPACE
    ),
    [_MAC_BASE] = LAYOUT_moonlander(
        _______,        _______,        _______,        _______,        _______,        _______,        _______,                 LALT(KC_MINUS), _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,           LALT(LSFT(KC_MINUS)), _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,        _______,                 _______,        _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,        _______,        _______,        _______,        _______,                                                 _______,        _______,        _______,        _______,        _______,        _______,
        _______,        _______,      LGUI(LSFT(KC_3)), _______,        MO(_MAC_SYM),                   _______,                 _______,                  LGUI(LCTL(KC_SPACE)), _______,        _______,        _______,        _______,
                                                                        _______,        _______,        NOT_EQUAL_TO_M,          _______,        _______,        _______
    ),
    [_WIN_SYM] = LAYOUT_moonlander(
        INV_EXLM_W,     KC_F1,          KC_F2,          KC_F3,          KC_F4,         KC_F5,          ALMOST_EQ_W,              FRAC_1_4_W,  KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         PLAY_ZELDA,
        GRAVE_P,        SUP_1_W,        SUP_2_W,        SUP_3_W,        SUP_N_W,       PI_W,           BULLET_W,                 FRAC_1_2_W,  KC_F11,         KC_F12,         DAGGER_W,       BRACE_P,        BRACKET_P,      PLUS_MINUS_W,
        NOT_SIGN_W,     AE_W,           OE_W,           SHARP_S_W,      TM_SIGN_W,     C_CIRC_W,       R_CIRC_W,                 FRAC_3_4_W,  MICRO_W,        UP_ARROW_W,     DDAGGER_W,      INFINITY_W,     PAREN_P,        QUOTE_P,
        _______,        KC_PLUS,        KC_MINUS,       MULT_SIGN_W,    DIV_SIGN_W,    DEGREE_SIGN_W,                                         LEFT_ARROW_W,   DOWN_ARROW_W,   RIGHT_ARROW_W,  MIDDLE_DOT_W,   KC_PGUP,        INV_QUES_W,
        TG(_GREEK_W),   LR_ARROW_W,     UD_ARROW_W,     _______,        _______,                       NOTE_8TH_W,               NOTES_8TH_W,                 SECTION_SIGN_W, PILCROW_W,      KC_HOME,        KC_PGDN,        KC_END,
                                                                        CENT_SIGN_W,   POUND_SIGN_W,   YEN_SIGN_W,               FULL_BLOCK_W, LT_OR_EQ_W,     GT_OR_EQ_W
    ),
    [_MAC_SYM] = LAYOUT_moonlander(
        INV_EXLM_M,     KC_F1,          KC_F2,          KC_F3,          KC_F4,         KC_F5,          ALMOST_EQ_M,              FRAC_1_4_M,  KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         PLAY_ZELDA,
        GRAVE_P,        SUP_1_M,        SUP_2_M,        SUP_3_M,        SUP_N_M,       PI_M,           BULLET_M,                 FRAC_1_2_M,  KC_F11,         KC_F12,         DAGGER_M,       BRACE_P,        BRACKET_P,      PLUS_MINUS_M,
        NOT_SIGN_M,     AE_M,           OE_M,           SHARP_S_M,      TM_SIGN_M,     C_CIRC_M,       R_CIRC_M,                 FRAC_3_4_M,  MICRO_M,        UP_ARROW_M,     DDAGGER_M,      INFINITY_M,     PAREN_P,        QUOTE_P,
        _______,        KC_PLUS,        KC_MINUS,       MULT_SIGN_M,    DIV_SIGN_M,    DEGREE_SIGN_M,                                         LEFT_ARROW_M,   DOWN_ARROW_M,   RIGHT_ARROW_M,  MIDDLE_DOT_M,   KC_PGUP,        INV_QUES_M,
        TG(_GREEK_M),   LR_ARROW_M,     UD_ARROW_M,     _______,        _______,                       NOTE_8TH_M,               NOTES_8TH_M,                 SECTION_SIGN_M, PILCROW_M,      KC_HOME,        KC_PGDN,        KC_END,
                                                                        CENT_SIGN_M,   POUND_SIGN_M,   YEN_SIGN_M,               FULL_BLOCK_M, LT_OR_EQ_M,     GT_OR_EQ_M
    ),
    [_NUMPAD] = LAYOUT_moonlander(
        QK_RBT,         QK_BOOT,        PRINT_VER,      XXXXXXX,        XXXXXXX,        XXXXXXX,        DT_UP,                   XXXXXXX,        XXXXXXX,        KC_NUM_LOCK,    KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    TG(_QWERTY),
        XXXXXXX,        XXXXXXX,        XXXXXXX,   KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,XXXXXXX,        DT_PRNT,                 XXXXXXX,        XXXXXXX,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     XXXXXXX,
        TG(_J1),        XXXXXXX,     KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, XXXXXXX,        DT_DOWN,                 XXXXXXX,        XXXXXXX,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     XXXXXXX,
        TG(_J2),   TOGGLE_LAYER_COLOR,  RGB_TOG,        RGB_MOD,        MOON_LED_LEVEL, XXXXXXX,                                                 XXXXXXX,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    XXXXXXX,
        AU_TOGG,        MU_TOGG,        MU_NEXT,        _______,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_ENTER,    XXXXXXX,
                                                                        _______,        XXXXXXX,        XXXXXXX,                 _______,        _______,        _______
    ),
    [_GREEK_W] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                EN_DASH_W,      KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           XXXXXXX,
        KC_GRAVE,       XXXXXXX,        XXXXXXX,        PHI_W,          PI_W,           XXXXXXX,        KC_BSLS,                 EM_DASH_W,      XXXXXXX,        XXXXXXX,        THETA_W,        XXXXXXX,        KC_SCLN,        KC_MINUS,
        KC_TAB,         ALPHA_W,        XXXXXXX,        SIGMA_W,        TAU_W,          GAMMA_W,        KC_LBRC,                 KC_RBRC,        MU_W,           XXXXXXX,        EPSILON_W,      XXXXXXX,        XXXXXXX,        KC_QUOTE,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        DELTA_W,        OMEGA_W,                                                 XXXXXXX,        XXXXXXX,        KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,
        TG(_GREEK_W),   CW_TOGG,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 KC_CAPS,                        LGUI(KC_DOT),   XXXXXXX,        KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                        KC_ENTER,       XXXXXXX,        XXXXXXX,                 KC_DELETE,      KC_BSPC,        KC_SPACE
    ),
    [_GREEK_M] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                LALT(KC_MINUS), KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           XXXXXXX,
        KC_GRAVE,       XXXXXXX,        FINAL_SIGMA_M,  PHI_M,          PI_M,           BETA_M,         KC_BSLS,           LALT(LSFT(KC_MINUS)), XI_M,           LAMBDA_M,       THETA_M,        UPSILON_M,      KC_SCLN,        KC_MINUS,
        KC_TAB,         ALPHA_M,        RHO_M,          SIGMA_M,        TAU_M,          GAMMA_M,        KC_LBRC,                 KC_RBRC,        MU_M,           NU_M,           EPSILON_M,      IOTA_M,         OMICRON_M,      KC_QUOTE,
        KC_LSFT,        ZETA_M,         CHI_M,          PSI_M,          DELTA_M,        OMEGA_M,                                                 KAPPA_M,        ETA_M,          KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,
        TG(_GREEK_M),   CW_TOGG,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 KC_CAPS,                  LGUI(LCTL(KC_SPACE)), XXXXXXX,        KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                        KC_ENTER,       XXXXXXX,        XXXXXXX,                 KC_DELETE,      KC_BSPC,        KC_SPACE
    ),
    [_ACCENT] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,    OSL(_A_CIRCUMFLEX), XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        OSL(_A_GRAVE),  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,     OSL(_A_DIAERESIS), XXXXXXX,
        OSL(_A_TILDE),  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,    OSL(_A_RING_ABOVE), OSL(_A_ACUTE),
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        OSL(_A_CARON),                                           XXXXXXX,        XXXXXXX,       OSL(_A_CEDILLA), XXXXXXX,        XXXXXXX,        OSL(_A_STROKE),
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_ACUTE] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        ACUTE_U_W,      ACUTE_Y_W,      XXXXXXX,        XXXXXXX,
        XXXXXXX,        ACUTE_A_W,      XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        ACUTE_E_W,      ACUTE_I_W,      ACUTE_O_W,      XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_CARON] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        CARON_S_W,      XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_LSFT,        CARON_Z_W,      XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_CEDILLA] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        CEDILLA_C_W,    XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_CIRCUMFLEX] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        CIRCUMFLEX_U_W, XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        CIRCUMFLEX_A_W, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        CIRCUMFLEX_E_W, CIRCUMFLEX_I_W, CIRCUMFLEX_O_W, XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_DIAERESIS] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        DIAERESIS_U_W,  DIAERESIS_Y_W,  XXXXXXX,        XXXXXXX,
        XXXXXXX,        DIAERESIS_A_W,  XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        DIAERESIS_E_W,  DIAERESIS_I_W,  DIAERESIS_O_W,  XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_GRAVE] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        GRAVE_U_W,      XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        GRAVE_A_W,      XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        GRAVE_E_W,      GRAVE_I_W,      GRAVE_O_W,      XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_RING_ABOVE] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        RING_ABOVE_A_W, XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_STROKE] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        STROKE_O_W,     XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_A_TILDE] = LAYOUT_moonlander(
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        TILDE_A_W,      XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        TILDE_N_W,      XXXXXXX,        XXXXXXX,        TILDE_O_W,      XXXXXXX,
        KC_LSFT,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        XXXXXXX,                 XXXXXXX,                        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_J1] = LAYOUT_moonlander(
        PLAY_SONG_00,   PLAY_SONG_01,   PLAY_SONG_02,   PLAY_SONG_03,   PLAY_SONG_04,   PLAY_SONG_05,   PLAY_SONG_06,            PLAY_SONG_07,   PLAY_SONG_08,   PLAY_SONG_09,   PLAY_SONG_10,   PLAY_SONG_11,   PLAY_SONG_12,   PLAY_SONG_13,
        PLAY_SONG_14,   PLAY_SONG_15,   PLAY_SONG_16,   PLAY_SONG_17,   PLAY_SONG_18,   PLAY_SONG_19,   PLAY_SONG_20,            PLAY_SONG_21,   PLAY_SONG_22,   PLAY_SONG_23,   PLAY_SONG_24,   PLAY_SONG_25,   PLAY_SONG_26,   PLAY_SONG_27,
        _______,        PLAY_SONG_28,   PLAY_SONG_29,   PLAY_SONG_30,   PLAY_SONG_31,   PLAY_SONG_32,   PLAY_SONG_33,            PLAY_SONG_34,   PLAY_SONG_35,   PLAY_SONG_36,   PLAY_SONG_37,   PLAY_SONG_38,   PLAY_SONG_39,   PLAY_SONG_40,
        XXXXXXX,        PLAY_SONG_41,   PLAY_SONG_42,   PLAY_SONG_43,   PLAY_SONG_44,   PLAY_SONG_45,                                            PLAY_SONG_46,   PLAY_SONG_47,   PLAY_SONG_48,   PLAY_SONG_49,   PLAY_SONG_50,   PLAY_SONG_51,
        PLAY_SONG_52,   PLAY_SONG_53,   PLAY_SONG_54,   PLAY_SONG_55,   PLAY_SONG_56,                   PLAY_JT,                 PLAY_ZELDA,                     PLAY_SONG_57,   PLAY_SONG_58,   PLAY_SONG_59,   PLAY_SONG_60,   PLAY_SONG_61,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_J2] = LAYOUT_moonlander(
        PLAY_SONG_62,   PLAY_SONG_63,   PLAY_SONG_64,   PLAY_SONG_65,   PLAY_SONG_66,   PLAY_SONG_67,   PLAY_SONG_68,            PLAY_SONG_69,   PLAY_SONG_70,   PLAY_SONG_71,   PLAY_SONG_72,   PLAY_SONG_73,   PLAY_SONG_74,   PLAY_SONG_75,
        PLAY_SONG_76,   PLAY_SONG_77,   PLAY_SONG_78,   PLAY_SONG_79,   XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        _______,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                                                 XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        PLAY_JT,                 PLAY_ZELDA,                     XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,
                                                                        XXXXXXX,        XXXXXXX,        XXXXXXX,                 XXXXXXX,        XXXXXXX,        XXXXXXX
    ),
    [_QWERTY] = LAYOUT_moonlander(
        KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_EQUAL,                XXXXXXX,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           _______,
        KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_BSLS,                 XXXXXXX,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,
        KC_TAB,         KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_LBRC,                 KC_RBRC,        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
        KC_LSFT,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_SLASH,
        KC_LCTL,        CW_TOGG,        XXXXXXX,        XXXXXXX,        XXXXXXX,                        KC_LGUI,                 KC_CAPS,                        XXXXXXX,        KC_RCTL,        KC_LEFT,        KC_DOWN,        KC_RIGHT,
                                                                        KC_ENTER,       KC_LALT,        XXXXXXX,                 KC_DELETE,      KC_BSPC,        KC_SPACE
    )
    // clang-format on
};

extern rgb_config_t rgb_matrix_config;

#define NUM_LEDS 6
// period for LED_BLINK_FAST blinking (smaller value implies faster)
#define LED_BLINK_FAST_PERIOD_MS 300

enum { LED_OFF = 0, LED_ON = 1, LED_BLINK_SLOW = 2, LED_BLINK_FAST = 3 };
static uint8_t led_blink_state[NUM_LEDS] = {0};

#ifdef START_UP_SONGS_BY_LAYER
float start_up_songs_by_layer_array[][16][2] = START_UP_SONGS_BY_LAYER;
#endif

void set_single_active_layer_with_sound(uint8_t layer_num) {
#if defined(AUDIO_ENABLE) && defined(START_UP_SONGS_BY_LAYER)
    PLAY_SONG(start_up_songs_by_layer_array[layer_num]);
#endif
    layer_state_t layer_state = (layer_state_t)(1 << layer_num);
    // default_layer_set(layer_state);
    layer_state_set(layer_state);
}

void keyboard_post_init_user(void) {
    rgb_matrix_enable();

    // to take control of the Moonlander's LEDs
    keyboard_config.led_level = false;

    uint32_t led_blink_callback(uint32_t trigger_time, void *cb_arg) {
        static const uint8_t pattern[4] = {0x00, 0xff, 0x0f, 0xaa};
        static uint8_t       phase      = 0;
        phase                           = (phase + 1) % 8;

        uint8_t bit = 1 << phase;
        ML_LED_1((pattern[led_blink_state[0]] & bit) != 0);
        ML_LED_2((pattern[led_blink_state[1]] & bit) != 0);
        ML_LED_3((pattern[led_blink_state[2]] & bit) != 0);
        ML_LED_4((pattern[led_blink_state[3]] & bit) != 0);
        ML_LED_5((pattern[led_blink_state[4]] & bit) != 0);
        ML_LED_6((pattern[led_blink_state[5]] & bit) != 0);

        return LED_BLINK_FAST_PERIOD_MS / 2;
    }

    defer_exec(1, led_blink_callback, NULL);

    // if _default_ layer is changed and we want it changed (back) to _WIN_BASE (i.e., lowest level), run:
    // set_single_persistent_default_layer(_WIN_BASE);

    uint32_t get_host_os(uint32_t trigger_time, void *cb_arg) {
        switch (detected_host_os()) {
            case OS_UNSURE:
                break;
            case OS_MACOS:
            case OS_IOS:
                set_single_active_layer_with_sound(_MAC_BASE);
                break;
            default: // OS_WINDOWS, OS_LINUX
                set_single_active_layer_with_sound(_WIN_BASE);
                break;
        }
        return 0;
    }

    defer_exec(500, get_host_os, NULL);
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
 * Generated code: this comment and the 41 lines following it were generated by
 * LayersColors.getLedMap in qmk-tools
 */
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    // clang-format off
    [_WIN_BASE] = {{HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_GREEN}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_GREEN}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_SFG_ORANGE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_YELLOW}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_WHITE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}, {HSV_PACIFIC_BLUE}},

    [_MAC_BASE] = {{HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_GREEN}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_GREEN}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_PACIFIC_BLUE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_YELLOW}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_RED}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_WHITE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}, {HSV_SFG_ORANGE}},

    [_WIN_SYM] = {{HSV_ORANGE}, {HSV_CYAN}, {HSV_ORANGE}, {HSV_BLUE}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_MUDDY_WATERS}, {HSV_MAGENTA}, {HSV_OFF}, {HSV_RED}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_ORANGE}, {HSV_GRAY40}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_PRINCE_PURP}, {HSV_ZELDA_CART}, {HSV_GRAY40}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_CYAN}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_OLIVE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_PRINCE_PURP}},

    [_MAC_SYM] = {{HSV_ORANGE}, {HSV_CYAN}, {HSV_ORANGE}, {HSV_RED}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_OLIVE}, {HSV_RED}, {HSV_PINK}, {HSV_WHITE}, {HSV_MAGENTA}, {HSV_GREEN}, {HSV_RED}, {HSV_PINK}, {HSV_MUDDY_WATERS}, {HSV_MAGENTA}, {HSV_OFF}, {HSV_RED}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_ORANGE}, {HSV_GRAY40}, {HSV_ORANGE}, {HSV_MUDDY_WATERS}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_MONEY_GREEN}, {HSV_PRINCE_PURP}, {HSV_ZELDA_CART}, {HSV_GRAY40}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_CYAN}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_RED}, {HSV_CYAN}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_YELLOW}, {HSV_RED}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_OLIVE}, {HSV_OLIVE}, {HSV_ORANGE}, {HSV_RED}, {HSV_RED}, {HSV_ORANGE}, {HSV_OLIVE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_PRINCE_PURP}},

    [_NUMPAD] = {{HSV_MAROON}, {HSV_OFF}, {HSV_PRINCE_PURP}, {HSV_PRINCE_PURP}, {HSV_BLUE}, {HSV_RED}, {HSV_OFF}, {HSV_OFF}, {HSV_ALLIGATOR}, {HSV_BLUE}, {HSV_WHITE}, {HSV_OFF}, {HSV_RED}, {HSV_ALLIGATOR}, {HSV_BLUE}, {HSV_OFF}, {HSV_DAVYS_GRAY}, {HSV_MAROON}, {HSV_ALLIGATOR}, {HSV_GREEN}, {HSV_OFF}, {HSV_DARK_GRAY}, {HSV_GREEN50}, {HSV_ALLIGATOR}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_VERMILION}, {HSV_VERM75}, {HSV_VERM50}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_RED}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_GRAY40}, {HSV_GRAY40}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_GRAY40}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_OFF}},

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

    [_QWERTY] = {{HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_CARDINAL}, {HSV_CARDINAL}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_RED}, {HSV_OFF}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_RED}, {HSV_OFF}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_RED}, {HSV_OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_CARDINAL}, {HSV_OFF}, {HSV_CARDINAL}, {HSV_GREEN}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_YELLOW}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_YELLOW}, {HSV_YELLOW}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_RED}, {HSV_YELLOW}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_RED}, {HSV_CARDINAL}, {HSV_RED}, {HSV_RED}, {HSV_WHITE}, {HSV_RED}, {HSV_OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_OFF}, {HSV_OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}}
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
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (!rawhid_state.rgb_control && !keyboard_config.disable_layer_led) {
        set_layer_color(get_highest_layer(layer_state));
        return false; // TODO! is this right?
    }

    return true; // TODO! is this right?
}

#define MAC_OPT(a, b, c, d) SEND_STRING(SS_LALT(SS_TAP(a) SS_TAP(b) SS_TAP(c) SS_TAP(d)));
#define WIN_ALT2(a, b) SEND_STRING(SS_LALT(SS_TAP(a) SS_TAP(b)))
#define WIN_ALT3(a, b, c) SEND_STRING(SS_LALT(SS_TAP(a) SS_TAP(b) SS_TAP(c)))
#define WIN_ALT4(a, b, c, d) SEND_STRING(SS_LALT(SS_TAP(a) SS_TAP(b) SS_TAP(c) SS_TAP(d)))
#define GET_MACRO(_1, _2, _3, _4, MACRO_NAME, ...) MACRO_NAME
#define WIN_ALT(...) GET_MACRO(__VA_ARGS__, WIN_ALT4, WIN_ALT3, WIN_ALT2)(__VA_ARGS__)

// clang-format off
#define WITHOUT_MODS(...)                      \
    do {                                       \
        const uint8_t saved_mods = get_mods(); \
        clear_mods();                          \
        {__VA_ARGS__}                          \
        set_mods(saved_mods);                  \
    } while (0)
// clang-format on

// Shift + Backspace = Delete
const key_override_t shift_backspace_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &shift_backspace_override,
    NULL // terminate the array
};

// #define USB_LED_CAPS_LOCK 1

bool is_caps_lock_on(void) {
    // return host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK);
    return host_keyboard_led_state().caps_lock;
}

bool is_shift_pressed(void) {
    return get_mods() & MOD_MASK_SHIFT;
}

bool should_capitalize(void) {
    return is_caps_lock_on() || is_caps_word_on() || is_shift_pressed();
}

static void update_caps_indicator(void) {
    if (is_caps_lock_on()) {
        led_blink_state[0] = LED_ON;
    } else if (is_caps_word_on()) {
        led_blink_state[0] = LED_BLINK_FAST;
    } else {
        led_blink_state[0] = LED_OFF;
    }
}

bool led_update_user(led_t led_state) {
    update_caps_indicator();

    return true;
}

void caps_word_set_user(bool active) {
    update_caps_indicator();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(layer_state);
    for (int iLed = 5; iLed >= 1; --iLed) {
        if ((current_layer & (1 << (5 - iLed))) == 0) {
            led_blink_state[iLed] = LED_OFF;
        } else {
            led_blink_state[iLed] = LED_ON;
        }
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EN_DASH_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_5, X_KP_0);
            }
            break;
        case EM_DASH_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_5, X_KP_1);
            }
            break;
        case INV_EXLM_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_6, X_KP_1);
            }
            break;
        case SUP_2_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_5, X_KP_3);
            }
            break;
        case SUP_N_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_5, X_KP_2);
            }
            break;
        case DEGREE_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_7, X_KP_6);
            }
            break;
        case FULL_BLOCK_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_1, X_KP_9);
            }
            break;
        case FRAC_1_4_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_8, X_KP_8);
            }
            break;
        case FRAC_1_2_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_8, X_KP_9);
            }
            break;
        case FRAC_3_4_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_0);
            }
            break;
        case TM_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_5, X_KP_3);
            }
            break;
        case DAGGER_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_3, X_KP_4);
            }
            break;
        case PLUS_MINUS_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_7, X_KP_7);
            }
            break;
        case UP_ARROW_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_4);
            }
            break;
        case INFINITY_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_3, X_KP_6);
            }
            break;
        case LEFT_ARROW_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_7);
            }
            break;
        case DOWN_ARROW_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_5);
            }
            break;
        case RIGHT_ARROW_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_6);
            }
            break;
        case MIDDLE_DOT_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_8, X_KP_3);
            }
            break;
        case INV_QUES_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_1);
            }
            break;
        case NOT_EQUAL_TO_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_2, X_6, X_0);
            }
            break;
        case INV_EXLM_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_1);
            }
            break;
        case SUP_2_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_2);
            }
            break;
        case SUP_N_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_0, X_7, X_F);
            }
            break;
        case DEGREE_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_0);
            }
            break;
        case FULL_BLOCK_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_5, X_8, X_8);
            }
            break;
        case FRAC_1_4_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_C);
            }
            break;
        case FRAC_1_2_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_D);
            }
            break;
        case FRAC_3_4_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_E);
            }
            break;
        case TM_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_1, X_2, X_2);
            }
            break;
        case DAGGER_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_0, X_2, X_0);
            }
            break;
        case PLUS_MINUS_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_1);
            }
            break;
        case UP_ARROW_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_1, X_9, X_1);
            }
            break;
        case INFINITY_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_2, X_1, X_E);
            }
            break;
        case LEFT_ARROW_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_1, X_9, X_0);
            }
            break;
        case DOWN_ARROW_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_1, X_9, X_3);
            }
            break;
        case RIGHT_ARROW_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_1, X_9, X_2);
            }
            break;
        case MIDDLE_DOT_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_7);
            }
            break;
        case INV_QUES_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_F);
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
            if (rawhid_state.rgb_control) {
                return false;
            }
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;

        case PRINT_VER:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;

        /*
         * Generated code: this comment and the 955 lines following it were generated by
         * ProcessRecordUserCases.getWithHeader in qmk-tools
         */
        case ACUTE_A_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_3););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_5);
                }
            }
            return false;

        case ACUTE_E_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_1););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_3);
                }
            }
            return false;

        case ACUTE_I_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_5););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_7);
                }
            }
            return false;

        case ACUTE_O_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_1););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_3);
                }
            }
            return false;

        case ACUTE_U_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_8););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_5, X_KP_0);
                }
            }
            return false;

        case ACUTE_Y_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_1););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_5, X_KP_3);
                }
            }
            return false;

        case CARON_S_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_3, X_KP_8););
                } else {
                    WIN_ALT(X_KP_0, X_KP_1, X_KP_5, X_KP_4);
                }
            }
            return false;

        case CARON_Z_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_4, X_KP_2););
                } else {
                    WIN_ALT(X_KP_0, X_KP_1, X_KP_5, X_KP_8);
                }
            }
            return false;

        case CEDILLA_C_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_9););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_1);
                }
            }
            return false;

        case CIRCUMFLEX_A_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_4););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_6);
                }
            }
            return false;

        case CIRCUMFLEX_E_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_2););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_4);
                }
            }
            return false;

        case CIRCUMFLEX_I_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_6););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_8);
                }
            }
            return false;

        case CIRCUMFLEX_O_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_2););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_4);
                }
            }
            return false;

        case CIRCUMFLEX_U_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_9););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_5, X_KP_1);
                }
            }
            return false;

        case DIAERESIS_A_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_6););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_8);
                }
            }
            return false;

        case DIAERESIS_E_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_3););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_5);
                }
            }
            return false;

        case DIAERESIS_I_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_7););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_9);
                }
            }
            return false;

        case DIAERESIS_O_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_4););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_6);
                }
            }
            return false;

        case DIAERESIS_U_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_0););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_5, X_KP_2);
                }
            }
            return false;

        case DIAERESIS_Y_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_5, X_KP_9););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_5, X_KP_5);
                }
            }
            return false;

        case GRAVE_A_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_2););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_4);
                }
            }
            return false;

        case GRAVE_E_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_0););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_2);
                }
            }
            return false;

        case GRAVE_I_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_4););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_6);
                }
            }
            return false;

        case GRAVE_O_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_0););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_2);
                }
            }
            return false;

        case GRAVE_U_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_7););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_9);
                }
            }
            return false;

        case RING_ABOVE_A_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_7););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_9);
                }
            }
            return false;

        case STROKE_O_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_6););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_8);
                }
            }
            return false;

        case TILDE_A_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_5););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_7);
                }
            }
            return false;

        case TILDE_N_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_0, X_KP_9););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_1);
                }
            }
            return false;

        case TILDE_O_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_3););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_5);
                }
            }
            return false;

        case ALPHA_W:
            if (record->event.pressed) {
                if (!should_capitalize()) {
                    WIN_ALT(X_KP_2, X_KP_2, X_KP_4);
                }
            }
            return false;

        case GAMMA_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_2, X_KP_2, X_KP_6););
                }
            }
            return false;

        case DELTA_W:
            if (record->event.pressed) {
                if (!should_capitalize()) {
                    WIN_ALT(X_KP_2, X_KP_3, X_KP_5);
                }
            }
            return false;

        case EPSILON_W:
            if (record->event.pressed) {
                if (!should_capitalize()) {
                    WIN_ALT(X_KP_2, X_KP_3, X_KP_8);
                }
            }
            return false;

        case THETA_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_2, X_KP_3, X_KP_3););
                }
            }
            return false;

        case MU_W:
            if (record->event.pressed) {
                if (!should_capitalize()) {
                    WIN_ALT(X_KP_2, X_KP_3, X_KP_0);
                }
            }
            return false;

        case PI_W:
            if (record->event.pressed) {
                if (!should_capitalize()) {
                    WIN_ALT(X_KP_2, X_KP_2, X_KP_7);
                }
            }
            return false;

        case SIGMA_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_2, X_KP_2, X_KP_8););
                } else {
                    WIN_ALT(X_KP_2, X_KP_2, X_KP_9);
                }
            }
            return false;

        case TAU_W:
            if (record->event.pressed) {
                if (!should_capitalize()) {
                    WIN_ALT(X_KP_2, X_KP_3, X_KP_1);
                }
            }
            return false;

        case PHI_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_2, X_KP_3, X_KP_2););
                } else {
                    WIN_ALT(X_KP_2, X_KP_3, X_KP_7);
                }
            }
            return false;

        case OMEGA_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_2, X_KP_3, X_KP_4););
                }
            }
            return false;

        case C_CIRC_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_6, X_KP_9);
            }
            return false;

        case R_CIRC_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_7, X_KP_4);
            }
            return false;

        case MULT_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_2, X_KP_1, X_KP_5);
            }
            return false;

        case DIV_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_2, X_KP_4, X_KP_7);
            }
            return false;

        case DDAGGER_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_3, X_KP_5);
            }
            return false;

        case SECTION_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_6, X_KP_7);
            }
            return false;

        case PILCROW_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_8, X_KP_2);
            }
            return false;

        case SUP_1_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_8, X_KP_5);
            }
            return false;

        case SUP_3_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_7, X_KP_9);
            }
            return false;

        case AE_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_9, X_KP_8););
                } else {
                    WIN_ALT(X_KP_0, X_KP_2, X_KP_3, X_KP_0);
                }
            }
            return false;

        case OE_W:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(WIN_ALT(X_KP_0, X_KP_1, X_KP_4, X_KP_0););
                } else {
                    WIN_ALT(X_KP_0, X_KP_1, X_KP_5, X_KP_6);
                }
            }
            return false;

        case SHARP_S_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_2, X_KP_2, X_KP_3);
            }
            return false;

        case CENT_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_6, X_KP_2);
            }
            return false;

        case POUND_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_6, X_KP_3);
            }
            return false;

        case YEN_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_6, X_KP_5);
            }
            return false;

        case MICRO_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_8, X_KP_1);
            }
            return false;

        case NOT_SIGN_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_7, X_KP_2);
            }
            return false;

        case BULLET_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_0, X_KP_1, X_KP_4, X_KP_9);
            }
            return false;

        case ALMOST_EQ_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_4, X_KP_7);
            }
            return false;

        case NOTE_8TH_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_1, X_KP_3);
            }
            return false;

        case NOTES_8TH_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_1, X_KP_4);
            }
            return false;

        case LR_ARROW_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_9);
            }
            return false;

        case UD_ARROW_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_1, X_KP_8);
            }
            return false;

        case LT_OR_EQ_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_4, X_KP_3);
            }
            return false;

        case GT_OR_EQ_W:
            if (record->event.pressed) {
                WIN_ALT(X_KP_2, X_KP_4, X_KP_2);
            }
            return false;

        case ALPHA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_1););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_1);
                }
            }
            return false;

        case BETA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_2););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_2);
                }
            }
            return false;

        case GAMMA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_3););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_3);
                }
            }
            return false;

        case DELTA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_4););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_4);
                }
            }
            return false;

        case EPSILON_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_5););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_5);
                }
            }
            return false;

        case ZETA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_6););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_6);
                }
            }
            return false;

        case ETA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_7););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_7);
                }
            }
            return false;

        case THETA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_8););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_8);
                }
            }
            return false;

        case IOTA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_9););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_9);
                }
            }
            return false;

        case KAPPA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_A););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_A);
                }
            }
            return false;

        case LAMBDA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_B););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_B);
                }
            }
            return false;

        case MU_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_C););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_C);
                }
            }
            return false;

        case NU_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_D););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_D);
                }
            }
            return false;

        case XI_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_E););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_E);
                }
            }
            return false;

        case OMICRON_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_9, X_F););
                } else {
                    MAC_OPT(X_0, X_3, X_B, X_F);
                }
            }
            return false;

        case PI_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_0););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_0);
                }
            }
            return false;

        case RHO_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_1););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_1);
                }
            }
            return false;

        case SIGMA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_3););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_3);
                }
            }
            return false;

        case TAU_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_4););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_4);
                }
            }
            return false;

        case UPSILON_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_5););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_5);
                }
            }
            return false;

        case PHI_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_6););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_6);
                }
            }
            return false;

        case CHI_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_7););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_7);
                }
            }
            return false;

        case PSI_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_8););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_8);
                }
            }
            return false;

        case OMEGA_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_3, X_A, X_9););
                } else {
                    MAC_OPT(X_0, X_3, X_C, X_9);
                }
            }
            return false;

        case FINAL_SIGMA_M:
            if (record->event.pressed) {
                if (!should_capitalize()) {
                    MAC_OPT(X_0, X_3, X_C, X_2);
                }
            }
            return false;

        case C_CIRC_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_9);
            }
            return false;

        case R_CIRC_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_E);
            }
            return false;

        case MULT_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_D, X_7);
            }
            return false;

        case DIV_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_F, X_7);
            }
            return false;

        case DDAGGER_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_0, X_2, X_1);
            }
            return false;

        case SECTION_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_7);
            }
            return false;

        case PILCROW_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_6);
            }
            return false;

        case SUP_1_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_9);
            }
            return false;

        case SUP_3_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_3);
            }
            return false;

        case AE_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_0, X_C, X_6););
                } else {
                    MAC_OPT(X_0, X_0, X_E, X_6);
                }
            }
            return false;

        case OE_M:
            if (record->event.pressed) {
                if (should_capitalize()) {
                    WITHOUT_MODS(MAC_OPT(X_0, X_1, X_5, X_2););
                } else {
                    MAC_OPT(X_0, X_1, X_5, X_3);
                }
            }
            return false;

        case SHARP_S_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_D, X_F);
            }
            return false;

        case CENT_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_2);
            }
            return false;

        case POUND_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_3);
            }
            return false;

        case YEN_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_5);
            }
            return false;

        case MICRO_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_B, X_5);
            }
            return false;

        case NOT_SIGN_M:
            if (record->event.pressed) {
                MAC_OPT(X_0, X_0, X_A, X_C);
            }
            return false;

        case BULLET_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_0, X_2, X_2);
            }
            return false;

        case ALMOST_EQ_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_2, X_4, X_8);
            }
            return false;

        case NOTE_8TH_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_6, X_6, X_A);
            }
            return false;

        case NOTES_8TH_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_6, X_6, X_B);
            }
            return false;

        case LR_ARROW_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_1, X_9, X_4);
            }
            return false;

        case UD_ARROW_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_1, X_9, X_5);
            }
            return false;

        case LT_OR_EQ_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_2, X_6, X_4);
            }
            return false;

        case GT_OR_EQ_M:
            if (record->event.pressed) {
                MAC_OPT(X_2, X_2, X_6, X_5);
            }
            return false;
    }

    return true;
}

typedef struct {
    bool    is_press_action;
    uint8_t step;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD, DOUBLE_TAP, DOUBLE_HOLD, DOUBLE_SINGLE_TAP, MORE_TAPS };

static tap dance_state[10];

uint8_t dance_step(tap_dance_state_t *state) {
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
const uint8_t num_row[] = {KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0};

// left to right, so [0]=F1, [1]=F2, ..., [9]=F10
const uint8_t f_row[] = {KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10};

void on_dance_i(tap_dance_state_t *state, void *user_data, int i) {
    if (state->count == 3) {
        tap_code16(num_row[i]);
        tap_code16(num_row[i]);
        tap_code16(num_row[i]);
    }
    if (state->count > 3) {
        tap_code16(num_row[i]);
    }
}

void dance_i_finished(tap_dance_state_t *state, void *user_data, int i) {
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

void dance_i_reset(tap_dance_state_t *state, void *user_data, int i) {
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

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 0);
}
void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 0);
}
void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 0);
}

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 1);
}
void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 1);
}
void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 1);
}

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 2);
}
void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 2);
}
void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 2);
}

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 3);
}
void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 3);
}
void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 3);
}

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 4);
}
void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 4);
}
void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 4);
}

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 5);
}
void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 5);
}
void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 5);
}

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 6);
}
void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 6);
}
void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 6);
}

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 7);
}
void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 7);
}
void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 7);
}

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 8);
}
void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 8);
}
void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 8);
}

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    return on_dance_i(state, user_data, 9);
}
void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    return dance_i_finished(state, user_data, 9);
}
void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    return dance_i_reset(state, user_data, 9);
}

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
    [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset)
    // clang-format on
};
