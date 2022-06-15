CC := arm-linux-gnueabihf-gcc
LVGL_DIR ?= ${shell pwd}
export PRJ_DIR=${shell pwd}
LVGL_DIR_NAME ?= lvgl
WARNINGS = -Wall -Wextra \
		   -Wshadow -Wundef -Wmaybe-uninitialized -Wmissing-prototypes -Wpointer-arith -Wuninitialized \
		   -Wunreachable-code -Wreturn-type -Wmultichar -Wdouble-promotion -Wclobbered -Wdeprecated  \
		   -Wempty-body -Wtype-limits -Wsizeof-pointer-memaccess

CFLAGS += -O3 -g0 $(WARNINGS) -I$(LVGL_DIR)/$(LVGL_DIR_NAME) -I$(LVGL_DIR) -I. 

LDFLAGS ?= -lm

BIN = $(LVGL_DIR)/output/app

MAINSRC = $(LVGL_DIR)/main.c

include $(LVGL_DIR)/generated/generated.mk
include $(LVGL_DIR)/custom/custom.mk
include $(LVGL_DIR)/lvgl/lvgl.mk
include $(LVGL_DIR)/lv_drivers/lv_drivers.mk

OBJEXT ?= .o

AOBJS = $(ASRCS:.S=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))
GEN_COBJS = $(GEN_CSRCS:.c=$(OBJEXT))

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

SRCS = $(ASRCS) $(CSRCS) $(MAINSRC) $(GEN_CSRCS)
OBJS = $(AOBJS) $(COBJS) $(GEN_COBJS)

## MAINOBJ -> OBJFILES
all: default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@ 
	@echo "CC $<"
	
default: $(AOBJS) $(COBJS) $(MAINOBJ) $(GEN_COBJS)
	$(CC) -o $(BIN) $(MAINOBJ) $(GEN_COBJS) $(AOBJS) $(COBJS) $(LDFLAGS)
	@mv $(LVGL_DIR)/*.o $(LVGL_DIR)/objs/

clean: 
	@rm $(LVGL_DIR)/objs/* $(BIN)
