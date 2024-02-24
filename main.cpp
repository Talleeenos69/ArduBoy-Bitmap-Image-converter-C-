#include <iostream>
#include "CImg-3.3.5_pre02222415/CImg.h"
#include <cstdint>
#include <cmath>
#include <string>
#include <sstream>

using namespace cimg_library;

void generateArduinoBitmap(const std::string& imagePath) {

    CImg<unsigned char> image(imagePath.c_str());

    if (image.is_empty()) {
        std::cerr << "Error: Unable to load the image." << std::endl;
        return;
    }

    std::string spriteString = "const uint8_t PROGMEM bitmap[]{\n" +
        std::to_string(image.width()) + ", " +
        std::to_string(image.height()) + ",\n";
    int pageCount = ceil(image.height() / 8);
    int columnCount = image.width();
    int currentByte = 0;

    // Read the sprite page-by-page
    for(int page = 0; page < pageCount; page++){

        // Read the page column-by-column
        for(int column = 0; column < columnCount; column++){

            // Read the column into a byte
            unsigned char spriteByte = 0;
            for (int yPixel = 0; yPixel < 8; yPixel++) {
                // If the color of the pixel is not black, count it as white
                unsigned char pixelColor[3];
                pixelColor[0] = image(column, page * 8 + yPixel, 0, 0);  // Red channel
                pixelColor[1] = image(column, page * 8 + yPixel, 0, 1);  // Green channel
                pixelColor[2] = image(column, page * 8 + yPixel, 0, 2);  // Blue channel

                if (pixelColor[0] > 16 || pixelColor[1] > 16 || pixelColor[2] > 16) {
                    // Set the corresponding bit in spriteByte
                    spriteByte |= (1 << yPixel);
                }
            }

            // Print the column in hex notation, add a comma for formatting
            std::stringstream ss;
            ss << std::hex << static_cast<int>(spriteByte);
            std::string digitStr = ss.str();

            if(digitStr.length() == 1) {
                digitStr = "0" + digitStr;
            }
            spriteString += "0x" + digitStr + ", ";
            if(currentByte%image.width() == image.width() - 1) {
                spriteString += "\n";
            }
            currentByte++;
        }
    }

    spriteString += "};\n";

    std::cout << spriteString;
}

int main(){
    std::string image_path = ""; // Add the path to the image file
    generateArduinoBitmap(image_path);
}