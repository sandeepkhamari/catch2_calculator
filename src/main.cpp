#include "../include/calculator.hpp"

int main()
{
  calculator<int> calc;
  int a=10, b=20;

  std::cout<<calc.add(a,b)<<std::endl;
  std::cout<<calc.multiply(a,b)<<std::endl;
  std::cout<<calc.subtract(b,a)<<std::endl;
  std::cout<<calc.divide(b,a)<<std::endl;

  return 0;
}
