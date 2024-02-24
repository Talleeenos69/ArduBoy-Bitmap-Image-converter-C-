# ArduBoy Bitmap Image Converter (C++)

This project is a C++ port of the [Arduboy bitmap converter](http://www.bloggingadeadhorse.com/TeamARGImgConverter/), designed to facilitate easy integration into various projects without relying on JavaScript.

## How to Use

This code is tailored for Linux systems with the X11 library installed. However, it doesn't require running X11 for functionality.

### Dependencies
- wget
- g++
- libx11-dev
- [CImg](http://www.cimg.eu/download.html)

### Install dependnecies
#### Ubnutu
```
sudo apt install g++ wget git libx11-dev
```
#### RHEL/Fedora
```
sudo dnf install g++ wget git libX11-devel
```
#### Arch/Manjaro
```
sudo pacman -S g++ wget git libx11
```

### Setting up
Clone the repo and cd into it
```
git clone https://github.com/Talleeenos69/ArduBoy-Bitmap-Image-converter-C-plus-plus && cd ./ArduBoy-Bitmap-Image-converter-C-plus-plus
```

Next, you need to download the CImg library from the official site and extract it to the project directory
```
wget https://cimg.eu/files/CImg_latest.zip
```
```
unzip CImg_latest.zip
```


### Compilation
```
g++ main.cpp -o converter -lX11
```

### Execution
```
./converter
```
