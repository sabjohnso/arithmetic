#pragma once

namespace Arithmetic::Details
{

  template<typename V, typename S>
  struct Field_extension : CRTP<Field_extension, V, S>
  {
    friend constexpr V
    operator +( Field_extension const& v, S const& s){ return static_cast<V const&>(v) + V(s); }

    friend constexpr V
    operator +( S const& s, Field_extension const& v){ return  V(s) + static_cast<V const&>(v); }

    friend constexpr V
    operator -( Field_extension const& v, S const& s){ return static_cast<V const&>(v) - V(s); }

    friend constexpr V
    operator -( S const& s, Field_extension const& v){ return  V(s) - static_cast<V const&>(v); }


    friend constexpr V
    operator *( Field_extension const& v, S const& s){ return static_cast<V const&>(v) * V(s); }

    friend constexpr V
    operator *( S const& s, Field_extension const& v){ return  V(s) * static_cast<V const&>(v); }

    friend constexpr V
    operator /( Field_extension const& v, S const& s){ return static_cast<V const&>(v) / V(s); }

    friend constexpr V
    operator /( S const& s, Field_extension const& v){ return  V(s) / static_cast<V const&>(v); }


  }; // end of struct Field_extension

} // end of namespace Arithmetic::Details
