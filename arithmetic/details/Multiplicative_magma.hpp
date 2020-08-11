#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Magma.hpp>
#include <arithmetic/details/Multiplication.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A type for the derivation of a closed multiplication operator
   */
  template<typename T>
  struct Multiplicative_magma : Magma<T, Multiplication>
  {
    using magma = Magma<T, Multiplication>;

    /**
     * @brief A closed addition operator
     */
    friend constexpr T
    operator *(Multiplicative_magma const& x, Multiplicative_magma const& y){
      return {op(static_cast<magma const&>(x), static_cast<magma const&>(y))};
    }
  }; // end of struct Multiplicative_magma
} // end of namespace Arithmetic::Details
