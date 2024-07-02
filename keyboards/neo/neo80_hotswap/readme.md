# neo80 wired- PCB

![neo80 Solder]()

Sources originales: https://github.com/lizhenmingdirk/qmk_firmware

A 80% made by NEO Studio.

* Keyboard Maintainer: [NEO Studio](https://github.com/owlab-git)
* Hardware Supported: neo80 PCB

**Bootloader:** Press the button B on PCB while plugging in the board.

Install command:

```dfu-util -a 0 -d 1688:2220,1688:2220 -s 0x08006000:leave -D "xxxxxxxxx.bin"```

To fix the error

```dfu-util: Error: File ID 1eaf:0003 does not match device (1688:2220 or 1688:2220)```

Change the DFU suffix

```dfu-suffix -D xxxxxxxxxx.bin```
```dfu-suffix -a xxxxxxxxxx.bin -p 2220 -v 1688```

And then, flash.
