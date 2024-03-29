# MCU name
MCU = STM32F072

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes   # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = yes   # Mouse keys
EXTRAKEY_ENABLE  = yes   # Audio control and System control
CONSOLE_ENABLE   = no    # Console for debug
COMMAND_ENABLE   = no    # Commands for debug and configuration
NKRO_ENABLE      = yes   # Enable N-Key Rollover
RGBLIGHT_ENABLE  = yes   # Enable keyboard RGB underglow

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
