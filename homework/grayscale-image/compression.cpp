#include "compression.hpp"

#include <iostream>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(const std::array<std::array<uint8_t, width>, height>& arr) {
    std::vector<std::pair<uint8_t, uint8_t>> vector;
    vector.reserve(width * height);
    for (int i = 0; i < height; ++i) {
        int count = 1;
        for (int j = 1; j < width; ++j) {
            if (arr[i][j] != arr[i][j - 1]) {
                vector.emplace_back(arr[i][j - 1], count);
                count = 0;
            }
            ++count;
        }
        vector.emplace_back(arr[i][width - 1], count);
    }
    vector.shrink_to_fit();
    return vector;
}

std::array<std::array<uint8_t, width>, height> decompressGrayscale(const std::vector<std::pair<uint8_t, uint8_t>>& bitmap) {
    std::array<std::array<uint8_t, width>, height> arr{};
    int index = 0;
    for (const std::pair<uint8_t, uint8_t>& pair : bitmap) {
        for (int i = 0; i < pair.second; i++) {
            arr[index / width][index % height] = pair.first;
            ++index;
        }
    }
    return arr;
}
void printMap(const std::array<std::array<uint8_t, width>, height>& map) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << static_cast<char>(map[i][j]);
        }
        std::cout << '\n';
    }
}

class Joke {
public:
    Joke(int d, int e, int f)
        : a(d),
          b(e),
          c(f) {}

private:
    int a;
    double b;
    long c;
};
