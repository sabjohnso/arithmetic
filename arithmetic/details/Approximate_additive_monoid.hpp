#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Approximate_additive_semigroup.hpp>
#include <arithmetic/details/Identity.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A closed binary addition operator that
   * is approximately associative and an element that
   * is the identity element under addition
   */
  template<typename T, typename Id>
  struct Approximate_additive_monoid
    : Additive_semigroup<T>
    , Identity<T, Id>
  {
    using identity = Identity<T,Id>;

    static constexpr T
    zero(){ return identity::id(); }
  }; // end of struct Approximate_additive_monoid
} // end of namespace Arithmetic::Details
