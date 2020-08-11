#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Additive_magma.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation of a closed
   * associative addition operator
   *
   * @details Specializations of this template inherit Additive_magma,
   * which derives the addition operator.  This template does not add
   * any additional functionality but communicates the intent that the
   * operator is associative.  However, that constraint is not enforced,
   * and should be tested.
   */
  template<typename T>
  struct Additive_semigroup : Additive_magma<T>
  {}; // end of struct Additive_semigroup
} // end of namespace Arithmetic::Details
