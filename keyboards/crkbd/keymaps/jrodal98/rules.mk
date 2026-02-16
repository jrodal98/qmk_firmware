# Default settings
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no
CAPS_WORD_ENABLE = yes

ifeq ($(strip $(CONVERT_TO)), blok)
    OLED_ENABLE = no
    RGB_MATRIX_ENABLE = no
else
	OLED_ENABLE = yes
	OLED_DRIVER = ssd1306
	RGB_MATRIX_ENABLE = yes
    BOOTLOADER = atmel-dfu # elite-c
endif
