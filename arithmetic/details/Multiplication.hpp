#pragma once

namespace Arithmetic::Details
{
  struct Multiplication : Static_callable<Multiplication>
  {
    template<typename T, typename U>
    static constexpr auto
    call(T&& x, U&& y){
      return forward<T>(x) * forward<T>(y);
    }
  }; // end of struct Multiplication
} // end of namespace Arithmetic::Details
