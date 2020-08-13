//
// ... Standard header files
//
#include <iostream>

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... External header files
//
#include <boost/multiprecision/cpp_int.hpp>

//
// ... Arithmetic header files
//
#include <arithmetic/arithmetic.hpp>

namespace Arithmetic::Testing
{
  namespace // anonymous
  {
    using std::ostream;
    using boost::multiprecision::cpp_rational;

    struct Wrapper : Field<Wrapper>
    {
      cpp_rational value;

      template<typename ... Ts>
      Wrapper(Ts ... xs)
        : value(xs ...)
      {}

      operator cpp_rational() const { return value; }

      static Wrapper
      apply_nullary(Zero){ return Wrapper{0}; }

      static Wrapper
      apply_nullary(One){ return Wrapper{1}; }

      template<typename F>
      friend Wrapper
      apply_unary(F&& f, Wrapper const& x){ return f(x.value); }

      template<typename F>
      friend Wrapper
      apply_binary(F&& f, Wrapper const& x, Wrapper const& y){ return f(x.value, y.value); }

      friend bool
      operator ==(Wrapper const& x, Wrapper const& y){
        return x.value == y.value;
      }

      friend bool
      operator !=(Wrapper const& x, Wrapper const& y){
        return !(x == y);
      }

      friend ostream&
      operator <<(ostream& os, Wrapper const& x){ return os << "Wrapper{" << x.value << "}"; }
    };

  } // end of anonymous namespace

  TEST(Field, Inequality){
    ASSERT_TRUE(Wrapper(3) != Wrapper(4));
  }

  TEST(Field, Addition)
  {
    ASSERT_EQ(Wrapper(3) + Wrapper(4), Wrapper(7));
  }

  TEST(Field, Subtraction)
  {
    ASSERT_EQ(Wrapper(3) - Wrapper(4), Wrapper(-1));
  }

  TEST(Field, Multiplication)
  {
    ASSERT_EQ(Wrapper(3) * Wrapper(4), Wrapper(12));
  }

  TEST(Field, Division)
  {
    ASSERT_EQ(Wrapper(3) / Wrapper(4), Wrapper(3,4));
  }

  TEST(Field, Zero){
    ASSERT_EQ(Wrapper(3)-Wrapper(3), Wrapper::zero());
    ASSERT_EQ(Wrapper(3) + Wrapper::zero(), Wrapper(3));
    ASSERT_EQ(Wrapper::zero() + Wrapper(3), Wrapper(3));
  }

  TEST(Field, One){
    ASSERT_EQ(Wrapper(3)/Wrapper(3), Wrapper::one());
    ASSERT_EQ(Wrapper::one() * Wrapper(3), Wrapper(3));
    ASSERT_EQ(Wrapper(3) * Wrapper::one(), Wrapper(3));
  }


} // end of namespace Arithmetic::Testing
