/**
 * @file arithmetic_testing/magma_test.cpp
 *
 * @brief Test the Magma class template.
 */

//
// ... Testing header files
//
#include <gtest/gtest.h>

//
// ... Arithmetic header files
//
#include <function_utility/function_utility.hpp>
#include <arithmetic/arithmetic.hpp>

namespace Arithmetic::Testing
{
  namespace // anonymous
  {

    using FunctionUtility::Static_callable;

    struct Addition : Static_callable<Addition>
    {
      template<typename T, typename U>
      constexpr static auto
      call(T&& x, U&& y){
        return std::forward<T>(x) + std::forward<U>(y);
      }
    };

    struct Multiplication : Static_callable<Multiplication>
    {
      template<typename T, typename U>
      constexpr static auto
      call(T&& x, U&& y){
        return std::forward<T>(x) + std::forward<U>(y);
      }
    };



    struct Wrapper1 :  Magma<Wrapper1,Addition>
    {
      constexpr
      Wrapper1(int x) : value(x) {}

      int value;

      template<typename F>
      friend constexpr Wrapper1
      apply_binary(F&& f, Wrapper1 x, Wrapper1 y){
        return Wrapper1{f(x.value, y.value)};
      }
    }; // end of struct Wrapper1




    struct Wrapper2
      : Magma<Wrapper2, Addition>
      , Magma<Wrapper2, Multiplication>
    {
      constexpr
      Wrapper2(int x) : value(x) {}
      int value;


      template<typename F>
      friend constexpr Wrapper2
      apply_binary(F&& f, Wrapper2 x, Wrapper2 y){
        return Wrapper2{f(x.value, y.value)};
      }

    };



  } // end of anonymous namespace

  TEST(Magma, AddWrapper1){
    constexpr Wrapper1 x{3};
    constexpr Wrapper1 y{4};
    constexpr auto z = op(x, y);

    ASSERT_EQ(z.value, 7);
  }

  TEST(Magma, AddWrapper2CastLeft){
    constexpr Wrapper2 x{3};
    constexpr Wrapper2 y{4};
    constexpr auto z = op(static_cast<Magma<Wrapper2,Addition> const&>( x ), y);
    ASSERT_EQ(z.value, 7);
  }

  TEST(Magma, AddWrapper2CastRight){
    constexpr Wrapper2 x{3};
    constexpr Wrapper2 y{4};
    constexpr auto z = op(x, static_cast<Magma<Wrapper2,Addition> const&>( y ));
    ASSERT_EQ(z.value, 7);
  }

  TEST(Magma, AddWrapper2CastBoth){
    constexpr Wrapper2 x{3};
    constexpr Wrapper2 y{4};
    constexpr auto z = op(
      static_cast<Magma<Wrapper2,Addition> const&>(x),
      static_cast<Magma<Wrapper2,Addition> const&>(y));
    ASSERT_EQ(z.value, 7);
  }

  TEST(Magma, MultiplyWrapper2CastLeft){
    constexpr Wrapper2 x{3};
    constexpr Wrapper2 y{4};
    constexpr auto z = op(static_cast<Magma<Wrapper2,Multiplication> const&>( x ), y);
    ASSERT_EQ(z.value, 7);
  }

  TEST(Magma, MultiplyWrapper2CastRight){
    constexpr Wrapper2 x{3};
    constexpr Wrapper2 y{4};
    constexpr auto z = op(x, static_cast<Magma<Wrapper2,Multiplication> const&>( y ));
    ASSERT_EQ(z.value, 7);
  }

  TEST(Magma, MultiplyWrapper2CastBoth){
    constexpr Wrapper2 x{3};
    constexpr Wrapper2 y{4};
    constexpr auto z = op(
      static_cast<Magma<Wrapper2,Multiplication> const&>(x),
      static_cast<Magma<Wrapper2,Multiplication> const&>(y));
    ASSERT_EQ(z.value, 7);
  }


} // end of namespace Arithmetic::Testing
