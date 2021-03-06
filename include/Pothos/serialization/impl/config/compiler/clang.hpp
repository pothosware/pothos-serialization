// (C) Copyright Douglas Gregor 2010
//
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org for most recent version.

// Clang compiler setup.

#define POTHOS_HAS_PRAGMA_ONCE

#if !__has_feature(cxx_exceptions) && !defined(POTHOS_NO_EXCEPTIONS)
#  define POTHOS_NO_EXCEPTIONS
#endif

#if !__has_feature(cxx_rtti) && !defined(POTHOS_NO_RTTI)
#  define POTHOS_NO_RTTI
#endif

#if !__has_feature(cxx_rtti) && !defined(POTHOS_NO_TYPEID)
#  define POTHOS_NO_TYPEID
#endif

#if defined(__int64) && !defined(__GNUC__)
#  define POTHOS_HAS_MS_INT64
#endif

#define POTHOS_HAS_NRVO

// Branch prediction hints
#if defined(__has_builtin)
#if __has_builtin(__builtin_expect)
#define POTHOS_LIKELY(x) __builtin_expect(x, 1)
#define POTHOS_UNLIKELY(x) __builtin_expect(x, 0)
#endif
#endif

// Clang supports "long long" in all compilation modes.
#define POTHOS_HAS_LONG_LONG

//
// Dynamic shared object (DSO) and dynamic-link library (DLL) support
//
#if !defined(_WIN32) && !defined(__WIN32__) && !defined(WIN32)
#  define POTHOS_SYMBOL_EXPORT __attribute__((__visibility__("default")))
#  define POTHOS_SYMBOL_IMPORT
#  define POTHOS_SYMBOL_VISIBLE __attribute__((__visibility__("default")))
#endif

//
// The BOOST_FALLTHROUGH macro can be used to annotate implicit fall-through
// between switch labels.
//
#if __cplusplus >= 201103L && defined(__has_warning)
#  if __has_feature(cxx_attributes) && __has_warning("-Wimplicit-fallthrough")
#    define POTHOS_FALLTHROUGH [[clang::fallthrough]]
#  endif
#endif

#if !__has_feature(cxx_auto_type)
#  define POTHOS_NO_CXX11_AUTO_DECLARATIONS
#  define POTHOS_NO_CXX11_AUTO_MULTIDECLARATIONS
#endif

#if !(defined(__GXX_EXPERIMENTAL_CXX0X__) || __cplusplus >= 201103L)
#  define POTHOS_NO_CXX11_CHAR16_T
#  define POTHOS_NO_CXX11_CHAR32_T
#endif

#if !__has_feature(cxx_constexpr)
#  define POTHOS_NO_CXX11_CONSTEXPR
#endif

#if !__has_feature(cxx_decltype)
#  define POTHOS_NO_CXX11_DECLTYPE
#endif

#if !__has_feature(cxx_decltype_incomplete_return_types)
#  define POTHOS_NO_CXX11_DECLTYPE_N3276
#endif

#if !__has_feature(cxx_defaulted_functions)
#  define POTHOS_NO_CXX11_DEFAULTED_FUNCTIONS
#endif

#if !__has_feature(cxx_deleted_functions)
#  define POTHOS_NO_CXX11_DELETED_FUNCTIONS
#endif

#if !__has_feature(cxx_explicit_conversions)
#  define POTHOS_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#endif

#if !__has_feature(cxx_default_function_template_args)
#  define POTHOS_NO_CXX11_FUNCTION_TEMPLATE_DEFAULT_ARGS
#endif

#if !__has_feature(cxx_generalized_initializers)
#  define POTHOS_NO_CXX11_HDR_INITIALIZER_LIST
#endif

#if !__has_feature(cxx_lambdas)
#  define POTHOS_NO_CXX11_LAMBDAS
#endif

#if !__has_feature(cxx_local_type_template_args)
#  define POTHOS_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#endif

#if !__has_feature(cxx_noexcept)
#  define POTHOS_NO_CXX11_NOEXCEPT
#endif

#if !__has_feature(cxx_nullptr)
#  define POTHOS_NO_CXX11_NULLPTR
#endif

#if !__has_feature(cxx_range_for)
#  define POTHOS_NO_CXX11_RANGE_BASED_FOR
#endif

#if !__has_feature(cxx_raw_string_literals)
#  define POTHOS_NO_CXX11_RAW_LITERALS
#endif

#if !__has_feature(cxx_generalized_initializers)
#  define POTHOS_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
#endif

#if !__has_feature(cxx_rvalue_references)
#  define POTHOS_NO_CXX11_RVALUE_REFERENCES
#endif

#if !__has_feature(cxx_strong_enums)
#  define POTHOS_NO_CXX11_SCOPED_ENUMS
#endif

#if !__has_feature(cxx_static_assert)
#  define POTHOS_NO_CXX11_STATIC_ASSERT
#endif

#if !__has_feature(cxx_alias_templates)
#  define POTHOS_NO_CXX11_TEMPLATE_ALIASES
#endif

#if !__has_feature(cxx_unicode_literals)
#  define POTHOS_NO_CXX11_UNICODE_LITERALS
#endif

#if !__has_feature(cxx_variadic_templates)
#  define POTHOS_NO_CXX11_VARIADIC_TEMPLATES
#endif

#if !__has_feature(cxx_user_literals)
#  define POTHOS_NO_CXX11_USER_DEFINED_LITERALS
#endif

#if !(__has_feature(cxx_alignas) || __has_extension(cxx_alignas))
#  define POTHOS_NO_CXX11_ALIGNAS
#endif

#if !__has_feature(cxx_trailing_return)
#  define POTHOS_NO_CXX11_TRAILING_RESULT_TYPES
#endif

#if !__has_feature(cxx_inline_namespaces)
#  define POTHOS_NO_CXX11_INLINE_NAMESPACES
#endif

// Clang always supports variadic macros
// Clang always supports extern templates

#ifndef POTHOS_COMPILER
#  define POTHOS_COMPILER "Clang version " __clang_version__
#endif

// Macro used to identify the Clang compiler.
#define POTHOS_CLANG 1

