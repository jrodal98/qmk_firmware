#pragma once

#define MASTER_LEFT

#define USE_SERIAL_PD2

#define TAPPING_TERM 200
#define QUICK_TAP_TERM_PER_KEY

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// RGB MATRIX MODES
// https://docs.qmk.fm/#/feature_rgb_matrix
#ifdef RGB_MATRIX_ENABLE
    #define ENABLE_RGB_MATRIX_BREATHING
#endif // RGB_MATRIX_ENABLERGB_MATRIX_ENABLE

#ifdef OLED_ENABLE
    #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif // OLED_ENABLE


#ifdef CONVERT_TO_BLOK
    #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#endif // CONVERT_TO_BLOK
