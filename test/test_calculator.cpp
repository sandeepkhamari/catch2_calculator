// #define CATCH_CONFIG_MAIN
#include "../include/calculator.hpp"
#include <catch2/catch_test_macros.hpp>
#include <stdexcept>
#include <catch2/generators/catch_generators_range.hpp>

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

TEST_CASE("Add Soft Asserts", "[calculator]")
{
  calculator<int> calc;
  int a=20, b=10;

  // soft assertion.
  CHECK(calc.add(a,b) == 30);
}

TEST_CASE("Divide Hard Asserts ", "[calculator]")
{
  calculator<int> calc;
  int a=30, b=0;

  // hard assertion for Divide By 0 exception.
  REQUIRE_THROWS(calc.divide(a, b));
}

TEST_CASE("Multiply Nothrows", "[calculator]")
{
  calculator<int> calc;
  int a=20, b=10;

  // hard assert.
  REQUIRE_NOTHROW(calc.multiply(a,b));
}

// catch2 generators. tag: "generator"
TEST_CASE("Data-driver test", "[generator]")
{
  // The testcase runs 3 times, once for each value.
  auto input_value= GENERATE(1, 5, 10, 15);

  // The code block runs for input_value=1, then 5, then 10 etc.
  CAPTURE(input_value);

  REQUIRE(input_value > 0);
  REQUIRE(input_value <= 100);
}

// catch2 generator expressions to test calculator functionalities. tag: "generator"
TEST_CASE("Add works with generators", "[generator]")
{
  auto i= GENERATE(1,2);
  auto j= GENERATE(10,20);

  // This test runs 4 times (1,10), (1,20), (2,10), (2,20)
  CAPTURE(i, j);
  calculator<int> calc;
  REQUIRE(calc.add(i, j) < 30);
}

// catch2 generator with values() tagged with "generator"
TEST_CASE("Add works with generator and values()", "[generator]")
{
  auto input_value1= GENERATE(values({1,2,3}));
  auto input_value2= GENERATE(values({3,4,5}));

  calculator<int> calc;
  REQUIRE(calc.add(input_value1, input_value2) < 10);
}

// catch2 generator with range() tagged with "generator"
TEST_CASE("Add works with generator and range()", "[generator]")
{
  auto input1= GENERATE(Catch::Generators::range(1,5));
  auto input2= GENERATE(Catch::Generators::range(1,5));

  CAPTURE(input1, input2);

  calculator<int> calc;
  REQUIRE(calc.add(input1, input2) < 10);
}
