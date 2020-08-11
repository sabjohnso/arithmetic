#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Multiplicative_magma.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation of a closed
   * associative multiplication operator
   *
   * @details Specializations of this template inherit Multiplicative_magma,
   * which derives the multiplication operator.  This template does not add
   * any additional functionality but communicates the intent that the
   * operator is associative.  However, that constraint is not enforced,
   * and should be tested.
   */
  template<typename T>
  struct Multiplicative_semigroup : Multiplicative_magma<T>
  {};

} // end of namespace Arithmetic::Details
