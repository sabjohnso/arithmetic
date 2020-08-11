#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Additive_monoid.hpp>
#include <arithmetic/details/Additive_inverse.hpp>

namespace Arithmetic::Details
{

  template<typename T>
  struct Additive_group : Additive_monoid<T> , Additive_inverse<T> , CRTP<Additive_group, T>
  {
    friend constexpr T
    operator -(Additive_group const& x, Additive_group const& y){
      return static_cast<T const&>(x) + (- static_cast<T const&>(y));
    }
  }; // end of struct Additive_group

} // end of namespace Arithmetic::Details
