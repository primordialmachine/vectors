///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Math Vectors Library
// Copyright (c) 2017-2019 Michael Heilmann
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "primordialmachine/arithmetic_functors/include.hpp"
#include "primordialmachine/math/vectors/vector_n.hpp"

namespace primordialmachine {

template<typename V>
struct binary_plus_functor<V, V, enable_if_t<is_vector_v<V>>>
  : public elementwise_binary_vector_functor<
      typename V::traits_type,
      binary_plus_functor<element_type_t<V>,
                          element_type_t<V>>>
{};

template<typename V>
struct plus_assignment_functor<V, V, enable_if_t<is_vector_v<V>>>
{
  using left_operand_type = V;
  using right_operand_type = V;
  using result_type = V;
  auto& operator()(left_operand_type& left_operand,
                   const right_operand_type& right_operand) const
  {
    left_operand = left_operand + right_operand;
    return left_operand;
  }
};

} // namespace primordialmachine
