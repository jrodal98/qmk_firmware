# Default settings
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no
CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
OS_DETECTION_ENABLE = yes
LEADER_ENABLE = yes

ifeq ($(strip $(CONVERT_TO)), blok)
    OLED_ENABLE = no
    RGB_MATRIX_ENABLE = no
else
	OLED_ENABLE = yes
	OLED_DRIVER = ssd1306
	RGB_MATRIX_ENABLE = yes # note, this takes up a lot of space
    BOOTLOADER = atmel-dfu # elite-c
endif
