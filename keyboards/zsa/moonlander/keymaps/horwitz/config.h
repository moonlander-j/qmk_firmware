/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 150

#define TAPPING_FORCE_HOLD

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 900000

#define USB_SUSPEND_WAKEUP_DELAY 0
// #define CAPS_LOCK_STATUS
#define FIRMWARE_VERSION u8"z43NM/ZXaD5"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_32BIT

#define RGB_MATRIX_STARTUP_SPD 60

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(T__NOTE(_REST)) // SONG(ZELDA_UNCOVER_SECRET) // (essentially) disabled (1/32-note rest)--superseded by START_UP_SONGS_BY_LAYER // TODO is this the best way to do this (i.e., a 1/32-note rest)?
#endif

#define START_UP_SONGS_BY_LAYER \
    { SONG(MARIO_THEME), SONG(ZELDA_UNCOVER_SECRET) }
