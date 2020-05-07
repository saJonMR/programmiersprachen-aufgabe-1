#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>

//Aufgabe 1.8
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

//Aufgabe 1.9
int checksum(int a) {
    int sum = 0;
    if (a < 0) {
        a = a * -1;
    }
    for (int i = 1; i <= a; i = i * 10) {
        sum = (a / i) % 10 + sum;
    }
    std::cout << sum << std::endl;
    return sum;
}

TEST_CASE("describe_checksum", "[checksum]") {
  REQUIRE(checksum(25) == 7);
  REQUIRE(checksum(0) == 0);
  REQUIRE(checksum(1982) == 20);
  REQUIRE(checksum(-1982) == 20);
}

//Aufgabe 1.10
int sum_multiples() {
  int sum = 0;
  for (int i = 1; i <= 1000; i++) {
    if(i % 3 == 0 || i % 5 == 0) {
      sum = sum + i;
    }
  }
  std::cout << sum << std::endl;
  return sum;
}

TEST_CASE("describe_sum_multiples", "[sum_mulitples]") {
  REQUIRE(sum_multiples() == 234168);
}

//Aufgabe 1.11
float fract(float a) {
  int base = a;
  float res = a - base;
  return res;
}

TEST_CASE("describe_fract", "[fract]") {
  REQUIRE(fract(5.8763) == Approx(0.8763));
  REQUIRE(fract(0) == 0);
}

//Aufgabe 1.12
float zylVol(float radius, float height) {
  float gF = M_PI * (radius * radius);
  float vol = gF * height;
  return vol;
}

TEST_CASE("describe_zylVol", "[zylVol]") {
  REQUIRE(zylVol(20, 10) == Approx(12566.371));
  REQUIRE(zylVol(0, 10) == 0);
  REQUIRE(zylVol(20, 0) == 0);
}

float zylOb(float radius, float height) {
  if (height == 0) {
    return 0;
  } else {
      float gF = M_PI * (radius * radius);
      float Uf = 2 * M_PI * radius;
      float mF = Uf * height;
      float ObF = 2 * gF + mF;
      return ObF;
  }
}

TEST_CASE("describe_zylOb", "[zylOb]") {
  REQUIRE(zylOb(20, 10) == Approx(3769.911));
  REQUIRE(zylOb(0, 20) == 0);
  REQUIRE(zylOb(20, 0) == 0);
}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}
