include $(REP_DIR)/lib/mk/pc_wifi.inc

REQUIRES += 32bit

SRC_C += lx_emul/spec/x86_32/atomic64_32.c
SRC_C += lx_emul/shadow/arch/x86/kernel/irq_32.c
