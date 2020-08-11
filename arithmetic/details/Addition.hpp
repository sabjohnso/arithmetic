#pragma once

namespace Arithmetic::Details
{
  struct Addition : Static_callable<Addition>
  {
    template<typename T, typename U>
    static constexpr auto
    call(T&& x, U&& y){
      return forward<T>(x) + forward<T>(y);
    }
  }; // end of struct Addition
} // end of namespace Arithmetic::Details
