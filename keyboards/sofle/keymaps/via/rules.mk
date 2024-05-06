VIA_ENABLE = yes
ENCODER_MAP_ENABLE = yes
#RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE = yes
LTO_ENABLE = yes
RAW_ENABLE = yes            # Enable RAW HID communication to PC

# Reduce compiled size
MOUSEKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
Link_Time_Optimization = yes # Reduce size of firmware by optimizing at link time
EXTRAFLAGS += -flto