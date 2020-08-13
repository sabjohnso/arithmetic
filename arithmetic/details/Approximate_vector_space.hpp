#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Approximate_field.hpp>

namespace Arithmetic::Details
{
  /**
   * @brief A type for the derivation of the operators for a vector space
   * where the scalar type is an approximate field.
   */
  template<typename V, typename S>
  struct Approximate_vector_space: CRTP<Vector_space, V, S>
  {
    friend constexpr V
    operator *(Approximate_vector_space const& u, S const& s){
      return apply_right_sclar(Multiplication{}, static_cast<V const&>(u), s);
    }

    friend constexpr V
    operator *(S const& s, Approximate_vector_space const& u){
      return apply_left_sclar(Multiplication{}, static_cast<V const&>(u), s);
    }
  }; // end of class Vector_space



} // end of namespace Arithmetic::Details
