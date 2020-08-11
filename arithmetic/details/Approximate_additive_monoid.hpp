#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Approximate_additive_semigroup.hpp>
#include <arithmetic/details/Additive_identity.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A closed binary addition operator that is approximately associative and
   * an element that is the identity element under addition
   */
  template<typename T>
  struct Approximate_additive_monoid
    : Approximate_additive_semigroup<T>
    , Additive_identity<T>
  {}; // end of struct Approximate_additive_monoid
} // end of namespace Arithmetic::Details
