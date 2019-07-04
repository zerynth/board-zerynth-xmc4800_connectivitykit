#ifndef __VBOARD__
#define __VBOARD__

extern uint8_t __ramvectors__[];


#if !defined(CORTEX_FLASH_VTABLE)
#   define CORTEX_FLASH_VTABLE 0x8000000
#endif

#define CORTEX_VTOR_INIT ((uint32_t)(&__ramvectors__))
#define CORTEX_VECTOR_COUNT 85 /* 101 total vectors - 16 cortex standard vectors */

#define CORTEX_ENABLE_WFI_IDLE          TRUE
#define CORTEX_SIMPLIFIED_PRIORITY      FALSE

#ifndef CORTEX_USE_FPU
#define CORTEX_USE_FPU                  TRUE
#endif

#define PORT_PRIO_BITS 4
#define PORT_PRIO_MASK(n) ((n) << (8 - PORT_PRIO_BITS))


#define VHAL_SER_RXFIFO_LEN 128

#if defined(VM_POWERSAVING)

// dividers' value depend on how the RTC is clocked on a specific board
// their value should obtain 1Hz ck_spre
#define VHAL_RTC_ASYNC_PREDIV 127
#define VHAL_RTC_SYNC_PREDIV  254

// set this value to call HAL_PWR_EnableBkUpAccess in vhalInitPowersave
// if not already performed at board startup
#define VHAL_RTC_ENABLE_BKUP 0
#define WKUP_PINS {}

#define VOS_SET_CLOCK_ENABLE_SYSTICK 1
#endif

#endif