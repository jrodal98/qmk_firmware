# jrodal98 crkbd

## Build with elite-c

```
qmk flash -kb crkbd -km jrodal98
```

with oled and rgb:

```
qmk flash -kb crkbd -km jrodal98 -e JROD_OLED=enable -e JROD_RGB=enable

```

## Build with blok

- [Boardsource blok](https://boardsource.xyz/store/628b95b494dfa308a6581622) is based on the RP2040
- More details about CONVERT_TO [here](https://docs.qmk.fm/#/feature_converters?id=converters)

```
qmk flash -kb crkbd -km jrodal98 -e CONVERT_TO=blok
```

with oled:

```
qmk flash -kb crkbd -km jrodal98 -e CONVERT_TO=blok -e JROD_OLED=enable
```

## Can't enter bootloader mode

I found that this magic key combo got me into bootloader mode:

- Start qmk flash command
- Unplug the keyboard
- Hold down the Q or P key (depending on layout)
- plug it back in
- If using blok, mount RPI filesystem
