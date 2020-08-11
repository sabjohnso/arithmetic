#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/import.hpp>


namespace Arithmetic::Details
{
  struct Reciprocal : Static_callable<Reciprocal>
  {
    template<typename T>
    static constexpr auto
    call(T&& x){
      return 1 / forward<T>(x);
    }
  }; // end of struct Reciprocal
} // end of namespace Arithmetic::Details
