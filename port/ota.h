

#if defined(VM_OTA)

#define VM_OTA_MAX_VM 2
#define VM_OTA_MAX_BC 2
#define VM_OTA_RECORD 0x08004000
#define VM_OTA_VM_ADDR(idx) ( ((idx)%(VM_OTA_MAX_VM)) ? (0x8080000):(0x8000000))
#define VM_OTA_BYTECODE(idx) ( ((idx)%(VM_OTA_MAX_BC)) ? (0x80A0000):(0x8020000))
#define VM_OTA_NEXT_VM_SLOT() (((VM_OTA_INDEX)+1)%(VM_OTA_MAX_VM))
#define VM_OTA_NEXT_BC_SLOT(curbc) (((curbc)+1)%(VM_OTA_MAX_BC))

#define VM_OTA_FLASH_CHUNK 4

#ifndef VM_OTA_INDEX
#define VM_OTA_INDEX 0
#endif

#define VM_OTA_MAP_ADDRESS(x) ((x))
#define VM_OTA_UNMAP_ADDRESS(x) ((x))

//redefine vtable
#undef CORTEX_FLASH_VTABLE
#define CORTEX_FLASH_VTABLE VM_OTA_VM_ADDR(VM_OTA_INDEX)

#define VM_OTA_PREFERRED_CHUNK 256

#endif
