# ArduBoy Bitmap Image Converter (C++)

This project is a C++ port of the [Arduboy bitmap converter](http://www.bloggingadeadhorse.com/TeamARGImgConverter/), designed to facilitate easy integration into various projects without relying on JavaScript.

## How to Use

This code is tailored for Linux systems with the X11 library installed. However, it doesn't require running X11 for functionality.

### Dependencies
- gcc
- libx11-dev
- CImg

### Compilation
```
g++ main.cpp -o converter -lX11
```

### Execution
```
./converter
```
