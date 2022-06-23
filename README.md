# ADM42

![ADM42](https://adm42.dev/images/adm42.jpg)

A compact ergonomic 40% ortholinear keyboard. [More info on ADM42.dev](https://adm42.dev)

* Keyboard Maintainer: [Lorenzo Leonini](https://github.com/lleonini)  
* Hardware Supported: ADM42 rev4+
* Hardware Availability: [Shop](https://shop.adm42.dev)

Make example for this keyboard (after setting up your build environment):

    make adm42:default

Flashing example for this keyboard:

    make adm42:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Official repository and QMK repository

Official repository for the ADM42 keyboard:
[https://github.com/lleonini/](https://github.com/lleonini/)

A «pure» QMK version of the keyboard is also available in the QMK repository:
[https://github.com/qmk/qmk_firmware/](https://github.com/qmk/qmk_firmware/)

The official repository contains the latest code used in the commercial product. It
includes timings and contextual optimizations that are not available in QMK. It can be
installed as a replacement of the keyboards/adm42 folder of the QMK repository.

## Bootloader

Enter the bootloader in 3 ways:

* **Keycode in layout**: Press the key mapped to `RESET` if it is available
* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (the top left key) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB

## Documentation

[Layout](https://adm42.dev/layout)
