#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Additive_magma.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation of a closed
   * approximately associative addition operator
   *
   * @details Specializations of this template inherit Additive_magma,
   * which derives the addition operator. This template is intended
   * to communicate that the type is not associative under addition
   * but may be approximated as associated under some conditions.
   */
  template<typename T>
  struct Approximate_additive_semigroup : Additive_magma<T>
  {};

} // end of namespace Arithmetic::Details
