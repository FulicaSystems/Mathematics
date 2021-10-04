#pragma once

#include <iostream>

/**
 * Display a float2 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const float2& v);

/**
 * Display a float3 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const float3& v);

/**
 * Display a float4 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const float4& v);

/**
 * Display a mat3 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const mat3& m);

/**
 * Display a mat4 in the console.
 */
inline std::ostream& operator<<(std::ostream& os, const mat4& m);

/**
 * Display a vec<T, N> in the console.
 * Some custom types are strangely displayed.
 * If the type T cannot be printed in an ostream, this operator cannot be called.
 */
template<typename T, unsigned int N>
inline std::ostream& operator<<(std::ostream& os, const vec<T, N>& v);




// impl

inline std::ostream& operator<<(std::ostream& os, const float2& v)
{
	os << v.x << ", " << v.y;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const float3& v)
{
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const float4& v)
{
	os << v.x << ", " << v.y << ", " << v.z << ", " << v.w;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const mat3& m)
{
	os << m.row[0].x << ", " << m.row[0].y << ", " << m.row[0].z << std::endl;
	os << m.row[1].x << ", " << m.row[1].y << ", " << m.row[1].z << std::endl;
	os << m.row[2].x << ", " << m.row[2].y << ", " << m.row[2].z;

	return os;
}

inline std::ostream& operator<<(std::ostream& os, const mat4& m)
{
	os << m.row[0].x << ", " << m.row[0].y << ", " << m.row[0].z << ", " << m.row[0].w << std::endl;
	os << m.row[1].x << ", " << m.row[1].y << ", " << m.row[1].z << ", " << m.row[1].w << std::endl;
	os << m.row[2].x << ", " << m.row[2].y << ", " << m.row[2].z << ", " << m.row[2].w << std::endl;
	os << m.row[3].x << ", " << m.row[3].y << ", " << m.row[3].z << ", " << m.row[3].w;

	return os;
}

template<typename T, unsigned int N>
inline std::ostream& operator<<(std::ostream& os, const vec<T, N>& v)
{
#ifdef RAW_VEC_TEMPLATE_NAME
	os << "---vec<" << typeid(T).name() << ", " << N << ">---" << std::endl;
#else
	os << "---" << typeid(T).name() << N << "---" << std::endl;
#endif

	for (unsigned int i = 0; i < N; ++i)
	{
		os << v.elem[i];
		if (i < N - 1)
			os << ", ";
	}

	return os;
}