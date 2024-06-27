# stm32g4-tiny-usb-pd-sink
Very small library for stm32g4-series microcontroller to request power from USB PD source

# Library features

- Allows to request desired voltage from USB PD source
- Dead-battery control to allow power source to be single source of the MCU
- Relies on stm32 LL library (don't need HAL)
- Size of library code is only about 1Kb

# Limitations

- There is no detection of changes in USB connection. You can't flip or reattach power cable. Only first connection is handled.
- You can't change requested voltage on the fly (not too hard to implement)
- Power source should provide fixed capability with required voltage, variable PDOs are not supported (easy to add)
- Supports only `stm32g4`, but it's easily extendable to `stm32g0` family as well

# Usage

At application startup you need to add:
```c
#define USBPD_REQUIRED_VOLTAGE_IN_MV 20000
#define USBPD_REQUIRED_CURRENT_IN_MA 5000

pd_startSinking(USBPD_REQUIRED_VOLTAGE_IN_MV, USBPD_REQUIRED_CURRENT_IN_MA);
```

And then you can check when power source would start to provide required voltage:
```c
if (pd_isReady() == 1) {
  // now we have voltage
}
```