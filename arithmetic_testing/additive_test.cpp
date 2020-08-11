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
    using std::is_same_v;
    using std::result_of_t;
  } // end of anonymous namespace

  template< template<typename ...> class Structure>
  struct Wrapper1 : Structure<Wrapper1<Structure>>
  {
    int value;

    constexpr
    Wrapper1(int x) : value(x) {}


    friend constexpr bool
    operator ==(Wrapper1 x , Wrapper1 y){
      return x.value == y.value;
    }

    friend constexpr bool
    operator !=(Wrapper1 x , Wrapper1 y){
      return !(x == y);
    }

    template<typename F>
    friend constexpr Wrapper1
    apply_binary(F&& f, Wrapper1 x, Wrapper1 y){
      return {f(x.value, y.value)};
      static_assert(is_same_v<result_of_t<F(int,int)>, int>);
    }

    template<typename F>
    friend constexpr Wrapper1
    apply_unary(F&& f, Wrapper1 x){
      return f(x.value);
    }

    static constexpr Wrapper1
    apply_nullary(Zero){
      return {0};
    }
    friend std::ostream&
    operator <<(std::ostream& os, Wrapper1 const& x){
      return os << "wrapper1(" << x.value << ")" << std::endl;
    }
  }; // end of struct Wrapper1

  TEST(Additive,Magma){
    using t = Wrapper1<Additive_magma>;
    constexpr t x{3};
    constexpr t y{4};
    constexpr auto z = x + y;
    ASSERT_EQ(z.value, 7);
  }

  TEST(Additive, Identity){
    using t = Wrapper1<Additive_identity>;
    constexpr auto x = t::zero();
    ASSERT_EQ(x.value, 0);
  }

  TEST(Additive, Monoid){
    using t = Wrapper1<Additive_monoid>;
    constexpr t a{3};
    constexpr t b{4};

    ASSERT_EQ(a + t::zero(), a);
    ASSERT_EQ(t::zero() + a, a);
    ASSERT_EQ(b + t::zero(), b);
    ASSERT_EQ(t::zero() + b, b);
    ASSERT_EQ(a + b, b + a);
  }


  TEST(Additive, Inverse){
    using t = Wrapper1<Additive_inverse>;
    constexpr t a{3};
    constexpr t b{-3};
    ASSERT_EQ(-a, b);
  }

  TEST(Additive, Group){
    using t = Wrapper1<Additive_group>;
    constexpr t a{3};
    constexpr t b{-3};
    ASSERT_EQ(-a, b);
    ASSERT_EQ(a - a, t::zero());
  }

} // end of namespace Arithmetic::Testing
