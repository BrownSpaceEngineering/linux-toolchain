# Installing OpenOCD
## Linux (Ubuntu)
1. Install the package: `sudo apt-get install openocd`. Unfortunately this doesn't seem to perform all the necessary operations:
2. Download the udev rules [here](https://repo.or.cz/openocd.git/blob_plain/HEAD:/contrib/60-openocd.rules)
3. Set the rules' owner to root: `sudo chown root:root ~/Downloads/60-openocd.rules`
3. Set the rules' permissions: `sudo chmod 644 ~/Downloads/60-openocd.rules`
4. Move the rules: `sudo mv ~/Downloads/60-openocd.rules /etc/udev/rules.d/`
5. Add yourself to the plugdev group: `sudo usermod -a -G plugdev $USERNAME`
6. Probably reboot. Just running `sudo udevadm control --reload` might also work.

# Additional Requirements
- Download the ARM GNU Toolchain from [here](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) and puth the bin folder on your path.
- Download ASF 3 from [here](https://www.microchip.com/mplab/avr-support/advanced-software-framework)(bottom of the page, ignore that it says Windows) and export a environment variable `ASF_ROOT` with the path to that (e.g. `export ASF_ROOT=~/Programs/xdk-asf-3.44.0/`)

# Building and Deploying Code
1. From within this directory, start `openocd`
2. In a new terminal, run `make debug`
3. At the `(gdb)` prompt run `load` to upload to the micro, `monitor reset halt` to reset the micro, and `c` to 'continue'.
