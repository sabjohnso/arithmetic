#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Approximate_additive_monoid.hpp>
#include <arithmetic/details/Additive_inverse.hpp>

namespace Arithmetic::Details
{
  template<typename T>
  struct Approximate_additive_group
    : Approximate_additive_monoid<T> , Additive_inverse<T> , CRTP<Approximate_additive_group, T>
  {
    friend constexpr T
    operator -(Approximate_additive_group const& x, Approximate_additive_group const& y){
      return static_cast<T const&>(x) + (- static_cast<T const&>(y));
    }
  }; // end of struct Approximate_additive_group

} // end of namespace Arithmetic::Details
