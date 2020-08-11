#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/import.hpp>
#include <arithmetic/details/Nullary.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A type for the derivation of an identity element
   */
  template<typename T, typename F>
  struct Identity : Nullary<T,F>
  {
    using constant = Nullary<T,F>;

    static constexpr T
    id(){ return constant::get(); }
  }; // end of struct Identity

} // end of namespace Arithmetic::Details
