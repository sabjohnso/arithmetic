#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Additive_group.hpp>
#include <arithmetic/details/Multiplicative_group.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A type for the derivation of the operators for a field.
   *
   * @details This class template inherits from Additive_group and
   * Multiplicative_group to provide the addition, subtraction,
   * multiplication and division operators of a field.  It it is also
   * intended to communicate commutative properties for addition and
   * multiplication, but those properties are not enforced and should
   * be tested.   */
  template<typename T>
  struct Field
    : Additive_group<T> , Multiplicative_group<T>
  {}; // end of struct Field

} // end of namespace Arithmetic::Details
