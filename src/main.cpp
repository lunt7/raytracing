#include <iostream>
#include "ray.h"
#include "color.h"

color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    // -1.0 < unit_direction.y() < 1.0
    // 0.0 <= t <= 1.0
    double t = 0.5 * (unit_direction.y() + 1.0);
    // at t = 0.0, color = white
    // at t = 1.0, color = blue
    return (1 - t) * color(1.0, 1.0, 1.0) + t * color(0.0, 0.0, 1.0);
}

int main() {
    constexpr double ASPECT_RATIO = 16.0 / 9.0;
    constexpr int IMAGE_WIDTH = 500;
    constexpr int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

    constexpr double VIEWPORT_HEIGHT = 2.0;
    constexpr double VIEWPORT_WIDTH = ASPECT_RATIO * VIEWPORT_HEIGHT;
    constexpr double FOCAL_LENGTH = 1.0;

    point3 origin(0, 0, 0);
    vec3 horizontal(VIEWPORT_WIDTH, 0, 0);
    vec3 vertical(0, VIEWPORT_HEIGHT, 0);
    vec3 lower_left_corner = origin - vec3(0, 0, FOCAL_LENGTH) - horizontal/2 - vertical/2;

    std::cout << "P3\n" << IMAGE_WIDTH << " " << IMAGE_HEIGHT << "\n255\n";
    for (int j = IMAGE_HEIGHT - 1; j >= 0; j--) {
        std::cerr << "\rScanlines remaining: " << j << " " << std::flush;
        for (int i = 0; i < IMAGE_WIDTH; i++) {
            double u = static_cast<double>(i) / (IMAGE_WIDTH - 1);
            double v = static_cast<double>(j) / (IMAGE_HEIGHT - 1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical);
            color pixel = ray_color(r);
            write_color(std::cout, pixel);
        }
    }
    std::cout << std::endl;
    std::cerr << "\nDone." << std::endl;

    return 0;
}

