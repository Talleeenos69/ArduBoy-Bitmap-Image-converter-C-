# ArduBoy-Bitmap-Image-converter-C-
A port of the arduboy bitmap converter but written in c++ so that the script can be easily used in other projects without  the need to use JavaScript.

# How to use

This code is meant to work on Linux systems that have the X11 library installed. This does not mean that you need to be running X11 for it to work.

### Dependencies
- gcc
- libx11-dev
- CImg

### Compile
```g++ main.cpp -o converter -lX11```

### Run

```./converter```
