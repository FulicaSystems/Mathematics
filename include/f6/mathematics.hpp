#pragma once

// TODO : find a better way to exclude Windows macros
#ifdef WIN32
#undef min
#undef max
#undef near
#undef far
#endif

// typedef float as vec (float2 becomes vec2)
#define FLOAT_AS_VEC

#define _USE_MATH_DEFINES
#include <cmath>

#include <cfloat>

namespace Math
{
	// precision calculator
	// https://www.mathsisfun.com/calculator-precision.html

	struct Constant
	{
		// pi
		// https://www.angio.net/pi/bigpi.cgi
		static inline const double pi = M_PI;
		static inline const double tau = 2 * M_PI;
		static inline const double e = 2.71828182845904523536028747135266249775724709369995;
	};

	struct Conversion
	{
		static inline const double degrad = M_PI / 180.f;
		static inline const double raddeg = 180.f / M_PI;
	};
}

#include "types/float2.hpp"
#include "types/float3.hpp"
#include "types/float4.hpp"

#include "types/vect.hpp"

#include "types/mat3.hpp"
#include "types/mat4.hpp"

#include "types/quaternion.hpp"

#include <random>

namespace Random
{
	/**
	 * Return a random float between a and b included.
	 */
	inline float crandomf(const float a, const float b);

	// TODO : c++11 <random> handles (rng engines with reset option)
}

namespace Math
{
	/**
	 * cosine
	 */
	template<typename T>
	inline T cos(const T a);
	template<>
	inline float cos(const float a);

	/**
	 * sine
	 */
	template<typename T>
	inline T sin(const T a);
	template<>
	inline float sin(const float a);

	/**
	 * tangent
	 */
	template<typename T>
	inline T tan(const T a);
	template<>
	inline float tan(const float a);

	/**
	 * exponential
	 */
	template<typename T>
	inline T exp(const T a);
	template<>
	inline float exp(const float a);

	/**
	 * power
	 */
	template<typename T>
	inline T pow(const T v, const T a);
	template<>
	inline float pow(const float v, const float a);

	/**
	 * Minimal value between a and b.
	 */
	template<typename T>
	inline T min(const T& a, const T& b);

	/**
	 * Maximal value between a and b.
	 */
	template<typename T>
	inline T max(const T& a, const T& b);

	/**
	 * Minimal vector between a and b.
	 *
	 * @return float3 where its elements are the minimums of the corresponding elements between a and b
	 */
	template<>
	inline float3 min(const float3& a, const float3& b);

	/**
	 * Maximal vector between a and b.
	 *
	 * @return float3 where its elements are the maximums of the corresponding elements between a and b
	 */
	template<>
	inline float3 max(const float3& a, const float3& b);

	/**
	 * Cap a value for it not to exceed the specified range.
	 *
	 * @param value
	 * @param minimal step
	 * @param maximal step
	 */
	template<typename T>
	inline T clamp(const T& value, const T& mini, const T& maxi);

	/**
	 * Clamp between 0 and 1.
	 */
	inline float saturate(const float& value);

	/**
	 * Remap a value.
	 * Transform a value from a range for it to fit into a new range.
	 *
	 * @param value
	 * @param first minimal step
	 * @param first maximal step
	 * @param second minimal step
	 * @param second maximal step
	 */
	template<typename T>
	inline T remap(const T val, const T min1, const T max1, const T min2, const T max2);

	/**
	 * Linear interpolation from a specified value to another according to a specified time.
	 */
	template<typename T>
	inline T lerp(const T& from, const T& to, const float& t);

	/**
	 * Linear interpolation from a specified vector to another according to a specified time.
	 */
	template<>
	inline float3 lerp(const float3& from, const float3& to, const float& t);

	/**
	 * Normalized linear interpolation used in rotation.
	 */
	inline Quaternion nlerp(const Quaternion& from, const Quaternion& to, const float& t);

	/**
	 * Spherical linear interpolation used in rotation.
	 */
	inline Quaternion slerp(const Quaternion& from, const Quaternion& to, const float& t);
}

namespace Math2
{
	/**
	 * Dot product between 2 vectors.
	 */
	inline float dot(const float2& a, const float2& b);

	/**
	 * Rotate a vector.
	 *
	 * @param float2
	 * @param angle in degrees
	 */
	inline float2 rotate(const float2& v, const float& angle);
}

namespace Math3
{
	/**
	 * Dot product between 2 vector3.
	 */
	inline float dot(const float3& a, const float3& b);

	/**
	 * Dot product between 2 vector4.
	 */
	inline float dot(const float4& a, const float4& b);

	/**
	 * Cross product between 2 vector3.
	 */
	inline float3 cross(const float3& a, const float3& b);

	/**
	 * Transpose of a matrix.
	 */
	inline mat4 transpose(const mat4& m);

	/**
	 * Frustum matrix.
	 */
	inline mat4 frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	/**
	 * Perspective matrix using frustum matrix.
	 */
	inline mat4 perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far);

	/**
	 * Orthographic frustum matrix.
	 */
	inline mat4 orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	/**
	 * Translation matrix.
	 */
	inline mat4 translateMatrix(const float3& pos);

	/**
	 * Rotation matrix based on Euler's rotation.
	 *
	 * @param angle in degrees
	 */
	inline mat4 rotateXMatrix(const float& pitch);

	/**
	 * Rotation matrix based on Euler's rotation.
	 *
	 * @param angle in degrees
	 */
	inline mat4 rotateYMatrix(const float& yaw);

	/**
	 * Rotation matrix based on Euler's rotation.
	 *
	 * @param angle in degrees
	 */
	inline mat4 rotateZMatrix(const float& roll);

	/**
	 * Scale matrix.
	 */
	inline mat4 scaleMatrix(const float3& scale);

	/**
	 * Convert a screen space position to a world space position
	 * TODO
	 */
	inline mat4 screenSpaceToWorldSpace(const mat4& view, const mat4& perspective, const float2& pos, const float depth)

	/**
	 * Convert a world space position to a screen space position
	 * TODO
	 */
	inline mat4 worldSpaceToScreenSpace(const float3& pos);

	/**
	 * Rotate a vector3 using quaternion calculation.
	 *
	 * @param vector3
	 * @param angle in degrees
	 * @param rotation axis
	 */
	inline float3 rotateQ(const float3& v, const float& angle, const float3& axis);

	/**
	 * Rotate a vector3 using a quaternion.
	 * This function only accepts a quaternion in its template slot.
	 */
	template <class Q>
	inline float3 rotateQ(const float3& v, const Q& q);

	/**
	 * Rotate a vector3 using a certain number of quaternions.
	 * The rotations are made in the same order than the order of the arguments.
	 */
	template <typename firstQuaternion, typename... quaternionArgs>
	inline float3 rotateQ(const float3& v, const firstQuaternion& q1, const quaternionArgs&... qs);
}

#include "mathematics.inl"