#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/import.hpp>
#include <arithmetic/details/Identity.hpp>
#include <arithmetic/details/Zero.hpp>

namespace Arithmetic::Details
{
  template<typename T>
  struct Additive_identity : Identity<T, Zero>
  {
    using identity = Identity<T, Zero>;
    static constexpr T
    zero(){ return identity::id(); }

  }; // end of struct Additive_identity
} // end of namespace Arithmetic::Details
