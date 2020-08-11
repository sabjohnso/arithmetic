#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/import.hpp>

namespace Arithmetic::Details
{
  template<typename T, typename F>
  struct Closed_unary : CRTP<Closed_unary, T, F>
  {
    friend constexpr T
    op(Closed_unary const& x){
      return apply_unary(F{}, static_cast<T const&>(x));
    }
  }; // end of struct Closed_unary
} // end of namespace Arithmetic::Details
