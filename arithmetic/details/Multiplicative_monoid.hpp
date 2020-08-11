#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Multiplicative_semigroup.hpp>
#include <arithmetic/details/Multiplicative_identity.hpp>

namespace Arithmetic::Details
{

  template<typename T>
  struct Multiplicative_monoid
    : Multiplicative_semigroup<T>
    , Multiplicative_identity<T>
  {}; // end of struct Multiplicative_monoid
} // end of namespace Arithmetic::Details
