#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Multiplicative_monoid.hpp>
#include <arithmetic/details/Multiplicative_inverse.hpp>

namespace Arithmetic::Details
{

  template<typename T>
  struct Multiplicative_group : Multiplicative_monoid<T> , Multiplicative_inverse<T> , CRTP<Multiplicative_group, T>
  {
    friend constexpr T
    operator /(Multiplicative_group const& x, Multiplicative_group const& y){
      return static_cast<T const&>(x) * recip(static_cast<T const&>(y));
    }
  }; // end of class Multiplicative_group

} // end of namespace Arithmetic::Details
