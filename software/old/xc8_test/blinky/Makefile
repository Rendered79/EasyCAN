PROJ_DIR	= .
XC8DIR		= /opt/microchip/xc8/v1.30
CC_INCLUDE	= -I$(XC8DIR)/include

PROCESSOR	= 18F26K80
MAIN		= main
SRC		= main.c
CC_FLAGS	= -P -N255 --warn=0 --addrqual=ignore --mode=free# --echo
OPTIMISATION	= --opt=default,+asm,-asmfile,+speed,-space,-debug,9 --runtime=+plib
CC		= $(XC8DIR)/bin/xc8
BOOTLOADER	= pirate-loader
# CC		= sdcc

all: $(MAIN).hex

$(MAIN).hex: $(SRC)
	$(CC) $(SRC) $(CC_FLAGS) $(OPTIMISATION) --ROM=default,-fc00-ffff --chip=$(PROCESSOR) $(CC_INCLUDE) --ASMLIST -M

flash: 
	$(BOOTLOADER) --reset_rts --dev=/dev/ttyUSB0 --hex=$(MAIN).hex

clean:
	rm -f $(MAIN).hex funclist $(MAIN).cof $(MAIN).hxl *.p1 $(MAIN).sdb startup.* *.cmf *.rlf *.map *.as *.d *.obj *.lst *.pre $(MAIN).sym

