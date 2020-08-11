//
// ... Standard header files
//
#include <iostream>

//
// ... Testing header files
//
#include <gtest/gtest.h>


//
// ... Arithmetic header files
//
#include <arithmetic/arithmetic.hpp>


namespace Arithmetic::Testing
{
  namespace // anonymous
  {

    struct Wrapper : Approximate_field<Wrapper>
    {
      double value;

      constexpr
      Wrapper(double input) : value(input){}

      static constexpr Wrapper
      apply_nullary(Zero){ return Wrapper{0}; }

      static constexpr Wrapper
      apply_nullary(One){ return Wrapper{1}; }

      template<typename F>
      friend constexpr Wrapper
      apply_unary(F&& f, Wrapper x){ return f(x.value); }

      template<typename F>
      friend constexpr Wrapper
      apply_binary(F&& f, Wrapper x, Wrapper y){ return f(x.value, y.value); }

      friend constexpr bool
      operator ==(Wrapper x, Wrapper y){ return x.value == y.value; }

      friend constexpr bool
      operator !=(Wrapper x, Wrapper y){ return !(x == y); }

      friend std::ostream&
      operator <<(std::ostream& os, Wrapper const& x){ return os << "Wrapper{" << x.value << "}"; }

    }; // end of struct Wrapper
  } // end of anonymous namespace

  TEST(Approximate_field, Inequality){
    ASSERT_TRUE(Wrapper(3) != Wrapper(4));
  }

  TEST(Approximate_field, Zero){
    ASSERT_EQ(Wrapper::zero(), Wrapper(0));
  }

  TEST(Approximate_field, One){
    ASSERT_EQ(Wrapper::one(), Wrapper(1));
  }

  TEST(Approximate_field, Addition){
    ASSERT_EQ(Wrapper(3) + Wrapper(4), Wrapper(7));
  }

  TEST(Approximate_field, Subtraction){
    ASSERT_EQ(Wrapper(3) - Wrapper(4), Wrapper(-1));
  }

  TEST(Approximate_field, Multiplication){
    ASSERT_EQ(Wrapper(3) *  Wrapper(4), Wrapper(12));
  }

  TEST(Approximate_field, Division){
    ASSERT_EQ(Wrapper(12) / Wrapper(4), Wrapper(3));
  }

} // end of namespace Arithmetic::Testing
