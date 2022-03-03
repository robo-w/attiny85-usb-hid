# ATTiny85 USB HID

This project installs `micronucleus` on an ATTiny85 microcontroller and stores different Arduino files for applications.

## Install micronucleus

This step is mainly needed for cloned Digispark ATTiny85 microcontrollers, which don't have the bootloader pre-installed.

```shell
# Install both versions of libusb for Digispark programming
sudo apt install libusb-0.1-4 libusb-1.0-0-dev
```

Fix known arduino bug on Ubuntu. Check first if Arduino starts up fine without this patch. If it starts fine, skip this block.

```shell
sudo apt install libserialport0 patchelf

cd /lib/x86_64-linux-gnu/
cp liblistSerialsj.so.1.4.0 liblistSerialsj.so.1.4.0.orig
# Check that all symlinks still point to the original file!

sudo patchelf --add-needed libserialport.so.0 liblistSerialsj.so.1.4.0
```

Download micronucleus `t85_default` bootloader and flash to digispark via ArduinoISP:
```shell
sudo avrdude -C /usr/share/arduino/hardware/tools/avrdude.conf \
-v -p attiny85 -c stk500v1 \
-P /dev/ttyACM0 -b 19200 \
-U flash:w:t85_default.hex \
-U lfuse:w:0xF1:m -U hfuse:w:0xD5:m -U efuse:w:0xFE:m
```

Example connection of ArduinoISP to ATTiny85 can be found at https://www.instructables.com/How-to-unlock-Digispark-ATtiny85-and-convert-it-to/.

[Download matching micronucleus cli](https://github.com/micronucleus/micronucleus/releases) (same version as installed into chip) and replace it in the Arduino installation folder (`.arduino15/packages/digistump/tools/micronucleus/`).