#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Multiplicative_group.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation of the operators for an
   * Abelian multiplicative group.
   */
  template<typename T>
  struct Abelian_multiplicative_group
    : Multiplicative_group<T>
  {}; // end of struct Abelian_multiplicative_group

} // end of namespace Arithmetic::Details
