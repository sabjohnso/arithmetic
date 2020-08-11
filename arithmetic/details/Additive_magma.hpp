 #pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Magma.hpp>
#include <arithmetic/details/Addition.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A type for the derivation of a closed addition operator
   */
  template<typename T>
  struct Additive_magma : Magma<T, Addition>
  {
    using magma = Magma<T, Addition>;

    /**
     * @brief A closed addition operator
     */
    friend constexpr T
    operator +(Additive_magma<T> const& x, Additive_magma<T> const& y){
      return {op(static_cast<magma const&>(x), static_cast<magma const&>(y))};
    }
  }; // end of struct Multiplicative_magma
} // end of namespace Arithmetic::Details
