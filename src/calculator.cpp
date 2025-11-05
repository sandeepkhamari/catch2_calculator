#include "../include/calculator.hpp"

template<typename T>
T calculator<T>::add(T a, T b)
{
  return a+b;
}

template<typename T>
T calculator<T>::subtract(T a, T b)
{
  return a-b;
}

template<typename T>
T calculator<T>::multiply(T a, T b)
{
  return a*b;
}

template<typename T>
T calculator<T>::divide(T a, T b)
{
  if(b==0)
  {
    throw std::domain_error("Division by zero condition.");
  }
  return a/b;
}

template class calculator<int>;
template class calculator<double>;
template class calculator<float>;
