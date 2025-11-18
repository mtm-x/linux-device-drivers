In order to develop a in order char driver module we need to couple of changes that is 

- place the .c file in the /drivers/char
- make modifications in Kconfig, Makefile of that dir ( drivers/char )


Use menu config to add our module to config file for compliation

```
make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- menuconfig

```

- goto Device Drivers -> Character driver -> Thamarai's character driver