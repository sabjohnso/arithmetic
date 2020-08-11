#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Inversion.hpp>
#include <arithmetic/details/Reciprocal.hpp>

namespace Arithmetic::Details
{
  template<typename T>
  struct Multiplicative_inverse : Inversion<T, Reciprocal>
  {
    using inversion = Inversion<T, Reciprocal>;
    friend constexpr T
    recip(Multiplicative_inverse const& x){
      return inverse(static_cast<inversion const&>( x ));
    }
  }; // end of struct Multiplicative_inverse

} // end of namespace Arithmetic::Details
