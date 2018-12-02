# Installing OpenOCD
## Linux (Ubuntu)
1. Install the package: `sudo apt-get install openocd`. Unfortunately this doesn't seem to perform all the necessary operations:
2. Download the udev rules [here](https://repo.or.cz/openocd.git/blob_plain/HEAD:/contrib/60-openocd.rules)
3. Set the rules' owner to root: `sudo chown root:root ~/Downloads/60-openocd.rules`
3. Set the rules' permissions: `sudo chmod 644 ~/Downloads/60-openocd.rules`
4. Move the rules: `sudo mv ~/Downloads/60-openocd.rules /etc/udev/rules.d/`
5. Add yourself to the plugdev group: `sudo usermod -a -G plugdev $USERNAME`
6. Probably reboot. Just running `udevadm control --reload` might also work.
