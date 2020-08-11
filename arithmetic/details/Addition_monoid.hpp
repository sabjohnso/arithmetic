#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Additive_semigroup.hpp>
#include <arithmetic/details/Identity.hpp>

namespace Arithmetic::Details
{

  template<typename T, typename Id>
  struct Additive_monoid
    : Additive_semigroup<T>
    , Identity<T, Id>
  {
    using identity = Identity<T,Id>;

    static constexpr T
    one(){ return identity::id(); }
  };
} // end of namespace Arithmetic::Details
