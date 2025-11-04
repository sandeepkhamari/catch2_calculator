// #define CATCH_CONFIG_MAIN
#include "../include/calculator.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Add Works","[calculator]")
{
  calculator<int> calc;
  int a=10, b=20;

  REQUIRE(calc.add(a,b) == 30);
}

TEST_CASE("Subtract Works","[calculator]")
{
  calculator<float> calc;
  float a=20.0, b=10.0;

  REQUIRE(calc.subtract(a,b) == 10.0);
}

TEST_CASE("Multiply Works", "[calculator]")
{
  calculator<double> calc;
  double a=10.0, b=20.0;

  REQUIRE(calc.multiply(a,b) == 200.0);
}

TEST_CASE("Divide Works","[calculator]")
{
  calculator<int> calc;
  int a=20, b=10;

  REQUIRE(calc.divide(a,b) == 2);
}
