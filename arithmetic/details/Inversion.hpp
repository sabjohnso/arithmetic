#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/import.hpp>
#include <arithmetic/details/Closed_unary.hpp>


namespace Arithmetic::Details
{

  template<typename T, typename F>
  struct Inversion : Closed_unary<T,F>
  {
    using unary = Closed_unary<T,F>;
    friend constexpr T
    inverse(Inversion const& x){
      return op(static_cast<unary const&>(x));
    }
  }; // end of struct Inversion
} // end of namespace Arithmetic::Details
