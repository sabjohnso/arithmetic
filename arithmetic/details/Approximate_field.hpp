#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Approximate_additive_group.hpp>
#include <arithmetic/details/Multiplicative_group.hpp>

namespace Arithmetic::Details
{

  /**
   * @brief A type for the derivateion of operators approximating a field.
   *
   * @details This class template inherits from Approximate_additive_group and
   * Multiplicative_group to provide the addition, subtraction,
   * multiplication and division operators of a field.  It it is also
   * intended to communicate commutative properties for addition and
   * multiplication, but those properties are not enforced and should
   * be tested.
   *
   * As this class inherits from Approximate_additive group, the associativity
   * of the addition opperator is concidered to only by approximate, such as that
   * of floating-point numbers.
   */
  template<typename T>
  struct Approximate_field
    : Approximate_additive_group<T>, Multiplicative_group<T>
  {}; // end of struct Approximate_field
} // end of namespace Arithmetic::Details
