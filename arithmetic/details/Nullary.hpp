#pragma once

namespace Arithmetic::Details
{
  /**
   * @brief A struct for the derivation of constants
   */
  template<typename T, typename F>
  struct Nullary : CRTP<Nullary, T, F>
  {
    constexpr static T
    get(){ return T::apply_nullary(F{}); }
  }; // end of class Nullary

} // end of namespace Arithmetic::Details
