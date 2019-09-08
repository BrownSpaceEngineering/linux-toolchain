# Installing OpenOCD
## Linux (Ubuntu)
1. Install the package: `sudo apt-get install openocd`. Unfortunately this doesn't seem to perform all the necessary operations:
2. Download the udev rules [here](https://repo.or.cz/openocd.git/blob_plain/HEAD:/contrib/60-openocd.rules)
3. Set the rules' owner to root: `sudo chown root:root ~/Downloads/60-openocd.rules`
3. Set the rules' permissions: `sudo chmod 644 ~/Downloads/60-openocd.rules`
4. Move the rules: `sudo mv ~/Downloads/60-openocd.rules /etc/udev/rules.d/`
5. Add yourself to the plugdev group: `sudo usermod -a -G plugdev $USERNAME`
6. Probably reboot. Just running `sudo udevadm control --reload` might also work.
7. Install the toolchain; Download the ARM GNU Toolchain from [here](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) and put the bin folder on your path.

## Mac OSX
1. Install homebrew [here](https://brew.sh/)
2. Install ARM developer tools: 
```
brew tap PX4/homebrew-px4
brew update
brew search px4
brew install gcc-arm-none-eabi-80
```
3. Install openOCD: `brew install openocd`

# Building and Deploying ASF4 (Atmel START)
1. From within this project directory, start `openocd`
2. In a new terminal, cd into `BlinkyBlinkyASF4/gcc/`
3. Run `make`
4. Run `arm-none-eabi-gdb -iex "target extended-remote localhost:3333" AtmelStart.elf`
5. At the `(gdb)` prompt run `load` to upload to the micro, `monitor reset halt` to reset the micro, and `c` to 'continue'.

# Building and Deploying Old ASF3
1. Download ASF 3 from [here](https://www.microchip.com/mplab/avr-support/advanced-software-framework)(bottom of the page, ignore that it says Windows) and export a environment variable `ASF_ROOT` with the path to that (e.g. `export ASF_ROOT=~/Programs/xdk-asf-3.44.0/`)
1. From within this directory, start `openocd`
2. In a new terminal, run `make debug`
3. At the `(gdb)` prompt run `load` to upload to the micro, `monitor reset halt` to reset the micro, and `c` to 'continue'.
