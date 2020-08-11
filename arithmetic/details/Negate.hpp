#pragma once
//
// ... Arithmetic header files
//
#include <arithmetic/details/import.hpp>

namespace Arithmetic::Details
{
  struct Negate : Static_callable<Negate>
  {
    template<typename T>
    static constexpr auto
    call( T&& x){
      return - x;
    }
  }; // end of struct Negate

} // end of namespace Arithmetic::Details
