#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Additive_group.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation of the operators for an
   * Abelian additive group.
   */
  template<typename T>
  struct Abelian_additive_group
    : Additive_group<T>
  {}; // end of struct Abelian_additive_group

} // end of namespace Arithmetic::Details
