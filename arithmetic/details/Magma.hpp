#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/import.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A type for the derivation of a closed binary operator
   *
   * @details  The Magma class template derives a closed
   * binary operator named `op` from the subtypes implementing
   * an operator named apply_binary, which applies closed binary
   * functions.
   *
   * The operator `op` is not intended to be user facing as
   * most types of interest will be involved in more than one magma
   * which will make the operator ambiguous, and disambiguation would
   * be combersome.  Rather, this class is intended to be used by
   * other classes that the magma generalizes.
   */
  template<typename T, typename F>
  struct Magma : CRTP<Magma, T, F>
  {

    /**
     * @brief A closed binary operator
     */
    friend constexpr T
    op(Magma const& x, Magma const& y){
      return apply_binary(
        F(),
        static_cast<T const&>(x),
        static_cast<T const&>(y));
    }
  }; // end of class Magma

} // end of namespace Arithmetic::Details
