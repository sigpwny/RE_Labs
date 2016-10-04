# RE_Labs
SIGPwny binary reverse engineering exercises.

The binaries should be good to go, but if you want or need to recompile, please use the Makefile provided.

## Troubleshooting

### ASLR

For these labs, you probably do not need to disable Address Space Layout Randomization (ASLR). In case you do, you can run the command:

as root: echo 0 > /proc/sys/kernel/randomize_va_space

This only persists until next reboot.

### Makefile Compile Error

If you get a Makefile compile error about missing libraries (probably if you are using a 64-bit machine) install g++-multilib

sudo apt-get install g++-multilib
