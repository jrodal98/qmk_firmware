# Default settings
MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no
CAPS_WORD_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
OS_DETECTION_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

ifeq ($(strip $(JROD_OLED)), enable)
	OLED_ENABLE = yes
	OLED_DRIVER = ssd1306
else
	OLED_ENABLE = no
endif

ifeq ($(strip $(JROD_RGB)), enable)
	RGB_MATRIX_ENABLE = yes # note, this takes up a lot of space
else
    RGB_MATRIX_ENABLE = no
endif

ifeq ($(strip $(CONVERT_TO)), blok)
	BOOTLOADER = rpi2040
else
    BOOTLOADER = atmel-dfu # elite-c
endif
