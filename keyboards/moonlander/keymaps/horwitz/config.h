/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define IGNORE_MOD_TAP_INTERRUPT
#undef TAPPING_TERM
#define TAPPING_TERM 150

#define TAPPING_FORCE_HOLD

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 900000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define CAPS_LOCK_STATUS
#define FIRMWARE_VERSION u8"z43NM/ZXaD5"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT

#define RGB_MATRIX_STARTUP_SPD 60

#ifdef AUDIO_ENABLE
    // "Uncover Secret" by Koji Kondo (from _The Legend of Zelda_)
    #define ZELDA      \
        Q__NOTE(_G5),  \
        Q__NOTE(_FS5), \
        Q__NOTE(_DS5), \
        Q__NOTE(_A4),  \
        Q__NOTE(_GS4), \
        Q__NOTE(_E5),  \
        Q__NOTE(_GS5), \
        Q__NOTE(_C6)

    #define STARTUP_SONG SONG(ZELDA)
#endif
