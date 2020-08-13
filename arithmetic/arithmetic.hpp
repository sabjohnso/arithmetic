#pragma once

//
// ... Arithmetic header files
//
#include <arithmetic/details/Magma.hpp>
#include <arithmetic/details/Identity.hpp>
#include <arithmetic/details/Inversion.hpp>
#include <arithmetic/details/One.hpp>
#include <arithmetic/details/Zero.hpp>
#include <arithmetic/details/Negate.hpp>
#include <arithmetic/details/Addition.hpp>
#include <arithmetic/details/Multiplication.hpp>
#include <arithmetic/details/Additive_magma.hpp>
#include <arithmetic/details/Additive_identity.hpp>
#include <arithmetic/details/Additive_monoid.hpp>
#include <arithmetic/details/Additive_inverse.hpp>
#include <arithmetic/details/Additive_group.hpp>
#include <arithmetic/details/Multiplicative_magma.hpp>
#include <arithmetic/details/Multiplicative_identity.hpp>
#include <arithmetic/details/Multiplicative_monoid.hpp>
#include <arithmetic/details/Multiplicative_inverse.hpp>
#include <arithmetic/details/Multiplicative_group.hpp>
#include <arithmetic/details/Abelian_additive_group.hpp>
#include <arithmetic/details/Abelian_approximate_additive_group.hpp>
#include <arithmetic/details/Field.hpp>
#include <arithmetic/details/Approximate_field.hpp>
#include <arithmetic/details/Vector_space.hpp>
#include <arithmetic/details/Approximate_vector_space.hpp>




namespace Arithmetic
{
  using ::Arithmetic::Details::Zero;
  using ::Arithmetic::Details::One;
  using ::Arithmetic::Details::Magma;
  using ::Arithmetic::Details::Identity;
  using ::Arithmetic::Details::Inversion;

  using ::Arithmetic::Details::Additive_magma;
  using ::Arithmetic::Details::Additive_identity;
  using ::Arithmetic::Details::Additive_monoid;
  using ::Arithmetic::Details::Additive_inverse;
  using ::Arithmetic::Details::Additive_group;

  using ::Arithmetic::Details::Multiplicative_magma;
  using ::Arithmetic::Details::Multiplicative_identity;
  using ::Arithmetic::Details::Multiplicative_monoid;
  using ::Arithmetic::Details::Multiplicative_inverse;
  using ::Arithmetic::Details::Multiplicative_group;

  using ::Arithmetic::Details::Field;
  using ::Arithmetic::Details::Approximate_field;

  using ::Arithmetic::Details::Vector_space;
  using ::Arithmetic::Details::Vector_space;

} // end of namespace Arithmetic
