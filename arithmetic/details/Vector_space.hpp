#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Field.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A type for the derivation of the operators for a vector space
   */
  template<typename V, typename S>
  struct Vector_space : CRTP<Vector_space, V, S>
  {
    friend constexpr V
    operator *(Vector_space const& u, S const& s){
      return apply_right_sclar(Multiplication{}, static_cast<V const&>(u), s);
    }

    friend constexpr V
    operator *(S const& s, Vector_space const& u){
      return apply_left_sclar(Multiplication{}, static_cast<V const&>(u), s);
    }
  }; // end of class Vector_space



} // end of namespace Arithmetic::Details
