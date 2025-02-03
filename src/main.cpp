#include <array>
#include <iostream>
#include <random>

using std::array;
using std::cout;
using std::endl;
using u8 = unsigned short;

static u8 gen_rand_u8(u8 min, u8 max) {
    std::random_device rand_device;
    std::mt19937 gen(rand_device());

    std::uniform_int_distribution distribution(min, max);
    return distribution(gen);
}

static void fill_array(array<u8, 100> &arr) {
    for (u8 &element: arr) {
        element = gen_rand_u8(0, 100);
    }
}

static void print_array(const array<u8, 100> &arr) {
    for (const u8 &element: arr) {
        cout << element << endl;
    }
}

int main() {
    std::array<u8, 100> arr{};

    fill_array(arr);

    print_array(arr);

    return 0;
}
