#include <iostream>
#include "color.h"

int main() {
    constexpr int IMAGE_WIDTH = 256;
    constexpr int IMAGE_HEIGHT = 256;

    std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";
    for (int j = 0; j < IMAGE_HEIGHT; j++) {
        std::cerr << "\rScanlines remaining: " << IMAGE_HEIGHT - 1 - j << " " << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; i++) {
            color pixel(static_cast<double>(i) / (IMAGE_WIDTH - 1), static_cast<double>(j) / (IMAGE_HEIGHT - 1), 0.25);
            write_color(std::cout, pixel);
        }
    }
    std::cout << std::endl;
    std::cerr << "\nDone." << std::endl;

    return 0;
}

