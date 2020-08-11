#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Additive_semigroup.hpp>
#include <arithmetic/details/Additive_identity.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A closed binary addition operator that
   * is associative and an element that is the
   * identity element under addition
   */
  template<typename T>
  struct Additive_monoid
    : Additive_semigroup<T>
    , Additive_identity<T>
  {
  }; // end of struct Additive_monoid
} // end of namespace Arithmetic::Details
