# simple-DS-controller-mod
Use Wii Classic controllers on a DS with a microcontroller.

Arduino Pro Mini 3.3V/8MHz recommended. Also works with RP2040/RP2350 boards.

DS Test Points:

VDD3.3 | 3.3V
P06 | UP
P07 | DOWN
P05 | LEFT
P04 | RIGHT
P00 | A (found across from the X button)
P01 | B
R00 | X
R01 | Y
P08 | R
P09 | L
P03 | START
P02 | SELECT (next to A)

Cut a hole anywhere on the back plate to make a port. Ideally pair with a capture card (https://3dscapture.com/ds/index.html). Then you can replace the charge port.

REQUIRED:
  [NintendoExtensionCtrl](https://github.com/dmadison/NintendoExtensionCtrl)
  by David Madison, used to read the Wii Classic Controller over I²C.
  Licensed under the [LGPLv3](https://github.com/dmadison/NintendoExtensionCtrl/blob/master/LICENSE).
  Install it through the Arduino Library Manager.
