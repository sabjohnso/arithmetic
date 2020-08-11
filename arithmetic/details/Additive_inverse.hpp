#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Inversion.hpp>
#include <arithmetic/details/Negate.hpp>

namespace Arithmetic::Details
{

  template<typename T>
  struct Additive_inverse : Inversion<T, Negate>
  {
    friend constexpr T
    operator -(Additive_inverse const& x){
      return inverse(static_cast<Inversion<T, Negate> const&>(x));
    }
  }; // end of struct Additive_inverse

} // end of namespace Arithmetic::Details
