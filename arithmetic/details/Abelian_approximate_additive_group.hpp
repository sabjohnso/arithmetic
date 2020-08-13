#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Approximate_additive_group.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation of the operators for an
   * Abelian approximate additive group.
   */
  template<typename T>
  struct Abelian_approximate_additive_group
    : Approximate_additive_group<T>
  {}; // end of struct Abelian_approximate_additive_group

} // end of namespace Arithmetic::Details
