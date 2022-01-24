#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288f
#endif
#ifndef TORAD
#define TORAD M_PI / 180.f
#endif
#ifndef TODEG
#define TODEG 180.f / M_PI
#endif

#include <cmath>
#include <cfloat>

#include "types.hpp"

#include <iostream>

namespace Math
{
	inline float min(const float& a, const float& b);
	inline float max(const float& a, const float& b);
	inline vec3	 min(const vec3& a, const vec3& b);
	inline vec3	 max(const vec3& a, const vec3& b);

	inline float clamp(const float& value, const float& mini, const float& maxi);
	inline float saturate(const float& value);
}

namespace Math2
{
	inline float dotProduct(const vec2& a, const vec2& b);

	//angle in degrees
	vec2 rotate(const vec2& v, const float& angle);
}

namespace Math3
{
	inline float dotProduct(const vec3& a, const vec3& b);
	vec3		 crossProduct(const vec3& a, const vec3& b);

	inline mat4 frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);
	inline mat4 perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far);
	inline mat4 orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	mat4 translateMatrix(const vec3& pos);

	//euler rotation
	mat4 rotateXMatrix(const float& pitch);		//angle in degrees
	mat4 rotateYMatrix(const float& yaw);		//angle in degrees
	mat4 rotateZMatrix(const float& roll);		//angle in degrees

	mat4 scaleMatrix(const vec3& scale);
}

//vec2 + vec2
inline vec2 operator+(const vec2& a, const vec2& b);
//vec2 - vec2
inline vec2 operator-(const vec2& a, const vec2& b);
//f * vec2
inline vec2 operator*(const float& a, const vec2& v);
//vec2 / f
inline vec2 operator/(const vec2& v, const float a);
//-vec3
inline vec3 operator-(const vec3& v);
//vec3 - vec3
inline vec3 operator-(const vec3& a, const vec3& b);
//f * vec3
inline vec3 operator*(const float& a, const vec3& v);
//vec3 / f
inline vec3 operator/(const vec3& v, const float a);
//vec3 += vec3
inline void operator+=(vec3& a, const vec3& b);
//mat4 * vec4
inline vec4 operator*(const mat4& m, const vec4& v);
//mat4 * mat4
inline mat4 operator*(const mat4& m, const mat4& m2);

std::ostream& operator<<(std::ostream& os, const vec2& v);
std::ostream& operator<<(std::ostream& os, const vec3& v);
std::ostream& operator<<(std::ostream& os, const vec4& v);
std::ostream& operator<<(std::ostream& os, const mat3& m);
std::ostream& operator<<(std::ostream& os, const mat4& m);

#include "math/math.inl"