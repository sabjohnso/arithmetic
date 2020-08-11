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

  } // end of anonymous namespace

  template< template<typename ...> class Structure>
  struct Wrapper : Structure<Wrapper<Structure>>
  {
    double value;

    constexpr
    Wrapper(double x) : value(x) {}

    static constexpr Wrapper
    apply_nullary(One){ return 1; }

    template<typename F>
    friend constexpr Wrapper
    apply_unary(F&& f, Wrapper x){
      return f(x.value);
    }

    template<typename F>
    friend constexpr Wrapper
    apply_binary(F&& f, Wrapper x, Wrapper y){
      return f(x.value, y.value);
    }

    friend constexpr bool
    operator ==(Wrapper x, Wrapper y){ return x.value == y.value; }

    friend constexpr bool
    operator !=(Wrapper x, Wrapper y){ return !(x == y); }
  }; // end of struct Wrapper1


  TEST(Multiplicative, Magma){
    using t = Wrapper<Multiplicative_magma>;
    constexpr t a{3.0};
    constexpr t b{4.0};
    constexpr auto c = a * b;
    ASSERT_EQ(c, t{12});
  }

  TEST(Multiplicative, Monoid){
    using t = Wrapper<Multiplicative_monoid>;
    constexpr t a{3.0};
    ASSERT_EQ(a * t::one(), a);
    ASSERT_EQ(t::one() * a, a);
    ASSERT_EQ(t::one() * a, a);
  }

  TEST(Multiplicative, Group){
    using t = Wrapper<Multiplicative_group>;
    constexpr t a{3.0};
    ASSERT_EQ(a / a, t::one());
  }
} // end of namespace Arithmetic::Testing
