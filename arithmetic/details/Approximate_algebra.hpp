#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Vector_space.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation
   */
  template<typename U, typename S, typename F>
  struct Approximate_algebra : Vector_space<U,S>
  {
    template<typename V>
    friend constexpr auto
    op(Approximate_algebra const& u, Approximate_algebra<V,S,F> const& v){
      return apply_bilinear(
        F(),
        static_cast<U const&>(u),
        static_cast<V const&>(v))
    }
  }; // end of struct Approximate_algebra
} // end of namespace Arithmetic::Details
