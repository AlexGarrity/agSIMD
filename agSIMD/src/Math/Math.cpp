#include "Math/Math.hpp"

#include "Math.hpp"
#include "Quad.hpp"

namespace ag {
namespace SIMD {

// No extensions so we'll use regular functions...

// Some templated helpers to save space
template <typename T> Quad<T> Add(const Quad<T> qA, const Quad<T> qB) {
  return Quad<T>(static_cast<T>(qA.a + qB.a), static_cast<T>(qA.b + qB.b),
                 static_cast<T>(qA.c + qB.c), static_cast<T>(qA.d + qB.d));
}

template <typename T> Quad<T> Sub(const Quad<T> qA, const Quad<T> qB) {
  return Quad<T>(static_cast<T>(qA.a - qB.a), static_cast<T>(qA.b - qB.b),
                 static_cast<T>(qA.c - qB.c), static_cast<T>(qA.d - qB.d));
}

template <typename T> Quad<T> Mul(const Quad<T> qA, const Quad<T> qB) {
  return Quad<T>(static_cast<T>(qA.a * qB.a), static_cast<T>(qA.b * qB.b),
                 static_cast<T>(qA.c * qB.c), static_cast<T>(qA.d * qB.d));
}

template <typename T> Quad<T> Div(const Quad<T> qA, const Quad<T> qB) {
  return Quad<T>(static_cast<T>(qA.a / qB.a), static_cast<T>(qA.b / qB.b),
                 static_cast<T>(qA.c / qB.c), static_cast<T>(qA.d / qB.d));
}

BQuad Add(const BQuad qA, const BQuad qB) { return Add<BYTE>(qA, qB); }

FQuad Add(const FQuad qA, const FQuad qB) { return Add<float>(qA, qB); }

DQuad Add(const DQuad qA, const DQuad qB) { return Add<double>(qA, qB); }

BQuad Mul(const BQuad qA, const BQuad qB) { return Mul<BYTE>(qA, qB); }

FQuad Mul(const FQuad qA, const FQuad qB) { return Mul<float>(qA, qB); }

DQuad Mul(const DQuad qA, const DQuad qB) { return Mul<double>(qA, qB); }

BQuad Sub(const BQuad qA, const BQuad qB) { return Sub<BYTE>(qA, qB); }

FQuad Sub(const FQuad qA, const FQuad qB) { return Sub<float>(qA, qB); }

DQuad Sub(const DQuad qA, const DQuad qB) { return Sub<double>(qA, qB); }

BQuad Div(const BQuad qA, const BQuad qB) { return Div<BYTE>(qA, qB); }

FQuad Div(const FQuad qA, const FQuad qB) { return Div<float>(qA, qB); }

DQuad Div(const DQuad qA, const DQuad qB) { return Div<double>(qA, qB); }

} // namespace SIMD
} // namespace ag