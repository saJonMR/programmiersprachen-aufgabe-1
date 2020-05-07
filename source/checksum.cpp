#include <iostream>
#include <cmath>

int checksum(int a) {
    int sum = 0;
    for (int i = 1; i <= a; i = i * 10) {
        sum = a / i % 10 + sum;
    }
    std::cout << sum << std::endl;
    return sum;
}

int main() {
    checksum(25);
}