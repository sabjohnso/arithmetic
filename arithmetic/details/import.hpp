#pragma once

//
// ... standard header files
//
#include <utility>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>
#include <function_utility/function_utility.hpp>


namespace Arithmetic::Details
{
  using std::forward;

  using TypeUtility::CRTP;
  using TypeUtility::Partial_template;
  using TypeUtility::Type;
  using TypeUtility::type;

  using FunctionUtility::Static_callable;

} // end of namespace Arithmetic::Details
