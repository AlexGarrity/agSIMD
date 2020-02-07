#pragma once

#define LIB_VERSION "1.0.1"
#define LIB_NAME "SIMD"
#define LIB_EXTENSION "AVX2"

#if defined(_MSC_VER)
// Windows DLL exporting
#ifdef BUILD_LIB
#define AG_API __declspec(dllexport)
#else
#define AG_API __declspec(dllimport)
#endif
#elif defined(__GNUC__)
// GCC exports everything anyway...
#ifdef BUILD_LIB
#define AG_API __attribute__((visibility("default")))
#else
#define AG_API
#endif
#else
#error SIMD is not supported on your platform
#endif
