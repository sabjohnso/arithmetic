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
  struct Algebra : Vector_space<U,S>
  {
    template<typename V>
    friend constexpr auto
    op(Algebra const& u, Algebra<V,S,F> const& v){
      return apply_bilinear(
        F(),
        static_cast<U const&>(u),
        static_cast<V const&>(v))
    }
  }; // end of struct Algebra
} // end of namespace Arithmetic::Details
