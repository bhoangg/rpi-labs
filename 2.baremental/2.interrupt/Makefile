ARMGNU?=aarch64-linux-gnu
COPS = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -Istartup/include -mgeneral-regs-only
ASMOPS = -Iinclude -Istartup/include

BUILD_DIR = build
SRC_DIR = src
STARTUP_DIR = startup

all : kernel8.img

clean :
	rm -rf $(BUILD_DIR) *.img 

$(BUILD_DIR)/%_c.o: %.c
	@mkdir -p $(@D)
	$(ARMGNU)-gcc $(COPS) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: %.S
	@mkdir -p $(@D)
	$(ARMGNU)-gcc $(ASMOPS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c $(STARTUP_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S $(STARTUP_DIR)/*.S)

#$(info "C files:" $(C_FILES))
#$(info "ASM files:" $(ASM_FILES))

OBJ_FILES = $(C_FILES:%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:%.S=$(BUILD_DIR)/%_s.o)

#$(info "OBJ files:"$(OBJ_FILES))

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernel8.img: $(STARTUP_DIR)/linker.ld $(OBJ_FILES)
	$(ARMGNU)-ld -T $(STARTUP_DIR)/linker.ld -o $(BUILD_DIR)/kernel8.elf  $(OBJ_FILES)
	$(ARMGNU)-objcopy $(BUILD_DIR)/kernel8.elf -O binary kernel8.img
