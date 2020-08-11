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
  struct Multiplicative_identity : Identity<T, One>
  {
    using identity = Identity<T, One>;
    static constexpr T
    one(){ return identity::id(); }
  }; // end of struct Multiplicative_identity
} // end of namespace Arithmetic::Details
