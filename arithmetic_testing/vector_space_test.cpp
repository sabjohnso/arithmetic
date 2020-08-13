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

    struct Scalar : Field<Scalar>
    {
      template<typename ... Ts>
      Scalar(Ts ... xs) : value(xs ...){}

      operator cpp_rational() const { return value; }
      cpp_rational value;

      static Scalar
      apply_nullary(Zero){ return Scalar{0}; }

      static Scalar
      apply_nullary(One){ return Scalar{1}; }

      template<typename F>
      friend Scalar
      apply_unary(F&& f, Scalar const& x){ return f(x.value); }

      template<typename F>
      friend Scalar
      apply_binary(F&& f, Scalar const& x, Scalar const& y){ return f(x.value, y.value); }

      friend bool
      operator ==(Scalar const& x, Scalar const& y){
        return x.value == y.value;
      }

      friend bool
      operator !=(Scalar const& x, Scalar const& y){
        return !(x == y);
      }

    }; // end of struct Scalar

    struct Vector : Additive_group<Vector>, Vector_space<Vector,Scalar>
    {
      Vector(Scalar x, Scalar y)
        : x(x), y(y)
      {}

      Scalar x;
      Scalar y;

      static Vector
      apply_nullary(Zero){ return Vector(Scalar::zero(), Scalar::zero()); }

      template<typename F>
      friend Vector
      apply_unary(F&& f, Vector const& v){
        return {apply_unary(f, v.x), apply_unary(f, v.y)};
      }

      template<typename F>
      friend Vector
      apply_binary(F&& f, Vector const& u, Vector const& v){
        return {apply_binary(f, u.x, v.x), apply_binary(f, u.y, v.y)};
      }

      template<typename F>
      friend Vector
      apply_right_scalar(F&& f, Vector const& v, Scalar const& s){
        return {apply_binary(f, v.x, s), apply_binary(f, v.y, s)};
      }

      template<typename F>
      friend Vector
      apply_left_scalar(F&& f, Scalar const& s, Vector const& v){
        return {apply_binary(f, v.x, s), apply_binary(f, v.y, s)};
      }

      friend bool
      operator ==(Vector const& u, Vector const& v){
        return u.x == v.x && u.y == v.y;
      }

      friend bool
      operator !=(Vector const& u, Vector const& v){
        return !(u == v);
      }
    }; // end of struct Euclidean

  } // end of namespace // anonymous

  TEST(Vector_space, Inequality){
    ASSERT_TRUE(Scalar(3) != Scalar(4));
    ASSERT_TRUE(Vector(3,4) != Vector(5, 6));
  }

  TEST(Vector_space, Additive_group)
  {
    Vector u{3, 4};
    Vector v{5, 6};
    auto w = u + v;

    ASSERT_EQ(w.x, u.x + v.x);
    ASSERT_EQ(w.y, u.y + v.y);
  }





} // end of namespace Arithmetic::Testing
