#pragma once

#define MASTER_LEFT

#define USE_SERIAL_PD2

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 200

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

// RGB MATRIX MODES
// https://docs.qmk.fm/#/feature_rgb_matrix
#ifdef RGB_MATRIX_ENABLE
    #define ENABLE_RGB_MATRIX_BREATHING
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#endif // RGB_MATRIX_ENABLERGB_MATRIX_ENABLE

#ifdef OLED_ENABLE
    #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#endif // OLED_ENABLE
