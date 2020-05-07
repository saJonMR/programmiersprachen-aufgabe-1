#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>

int gcd(unsigned int a, unsigned int b) {
    int r = 1;

    if (a == 0 || b == 0) {
        std::cout << a << std::endl;
        return 0;
    } else {
        if (a == b) {
            std::cout << a << std::endl;
            return a;
        } else {
            if (a > b) {
                while(r != 0) {
                    r = a % b;
                    a = b;
                    b = r; 
                }
                std::cout << a << std::endl;
                return a;
            } else {
                while(r != 0) {
                    r = b % a;
                    b = a;
                    a = r;
                }
                std::cout << b << std::endl;
                return b;
            }
        }
    }
}

TEST_CASE("describe_gcd", "[gcd]") {
  REQUIRE(gcd(2, 4) == 2);
  REQUIRE(gcd(9, 6) == 3);
  REQUIRE(gcd(3, 7) == 1);
  REQUIRE(gcd(0, 7) == 0);
  REQUIRE(gcd(-2, 4) == 2);
  REQUIRE(gcd(20, 20) == 20);
}

int checksum(unsigned int a) {
    int sum = 0;
    for (int i = 1; i <= a; i = i * 10) {
        sum = a / i % 10 + sum;
    }
    std::cout << sum << std::endl;
    return sum;
}

TEST_CASE("describe_checksum", "[checksum]") {
  REQUIRE(checksum(25) == 7);
  REQUIRE(checksum(0) == 0);
  REQUIRE(checksum(-1982) == 20);
}

int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
