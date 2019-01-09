///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Primordial Machine's Vectors Library
// Copyright (C) 2017-2019 Michael Heilmann
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

namespace primordialmachine {

template<typename ELEMENT_TYPE, size_t DIMENSIONALITY>
struct vector_traits
{
  using element_type = ELEMENT_TYPE;
  static constexpr size_t dimensionality = DIMENSIONALITY;
};

template<typename SCALAR>
struct is_scalar
{
  static constexpr bool value = false;
};

template<>
struct is_scalar<float>
{
  static constexpr bool value = true;
};

template<>
struct is_scalar<double>
{
  static constexpr bool value = true;
};

template<>
struct is_scalar<long double>
{
  static constexpr bool value = true;
};

template<typename TYPE>
struct is_vector
{
  static constexpr bool value = false;
};

template<typename TRAITS, typename ENABLED = void>
struct vector;

} // namespace primordialmachine
