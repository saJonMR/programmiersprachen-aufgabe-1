#include <iostream>
#include <cmath>

double mile_to_kilometer(double meilen) {
    double kilometer = meilen / 0.62137;
    return kilometer;
}

int main() {
    std::cout << "Meilen zu Kilometer Rechner\n";
    std::cout << "Eingabe Meilen :\n";
    double meilen;
    std::cin >> meilen;

    std::cout << meilen << " Meilen entsprechen " << mile_to_kilometer(meilen) << " Kilometern.\n";
    return 0;
}