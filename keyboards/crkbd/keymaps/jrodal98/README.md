# jrodal98 crkbd

## Build with elite-c

```
qmk flash -kb crkbd -km jrodal98
```

## Build with blok

- [Boardsource blok](https://boardsource.xyz/store/628b95b494dfa308a6581622) is based on the RP2040
- More details about CONVERT_TO [here](https://docs.qmk.fm/#/feature_converters?id=converters)

```
qmk flash -kb crkbd -km jrodal98 -e CONVERT_TO=promicro_rp2040
```
