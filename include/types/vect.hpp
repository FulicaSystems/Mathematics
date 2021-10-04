#pragma once

#include <cassert>
#include <cstdarg>

//used for printing the vector
//#define RAW_VEC_TEMPLATE_NAME

template<typename T, unsigned int N>
struct vec
{
	union
	{
		T elem[N];
	};

	inline vec<T, N>() = default;

	/**
	 * Create a vector setting its values to the specified parameters.
	 * If there are not enough parameters, the remaining elements will not be initialized.
	 * If a parameter is not of type T, the corresponding element will not be initialized.
	 * The additional parameters are ignored.
	 * 
	 * This constructor does not work with float type : use array manual initialization.
	 * This constructor must work with small classical types : int, unsigned int, double, ...
	 * This constructor may not work with array types : mat3, mat4, ...
	 *
	 * @param ts...
	 */
	inline vec<T, N>(const T ts...);

	/**
	 * Get the square magnitude of this vector.
	 *
	 * @return
	 */
	inline float sqrMag() const;

	/**
	 * Get the magnitude of this vector.
	 *
	 * @return
	 */
	inline float mag() const;

	/**
	 * Get this vector with normalized magnitude.
	 *
	 * @return
	 */
	inline vec<T, N> normalized() const;

	/**
	 * Access this vector's elements with [].
	 *
	 * @param i
	 * @return
	 */
	inline T& operator[](const unsigned int i);

	/**
	 * Access this vector's elements with [].
	 *
	 * @param i
	 * @return
	 */
	inline const T& operator[](const unsigned int i) const;
};

template<typename T, unsigned int N>
inline vec<T, N>::vec(const T ts...)
{
	std::va_list args;
	va_start(args, ts);

	elem[0] = ts;

	for (unsigned int i = 1; i < N; ++i)
	{
		elem[i] = va_arg(args, T);
	}

	va_end(args);
}

template<typename T, unsigned int N>
inline float vec<T, N>::sqrMag() const
{
	float m = 0.f;
	for (unsigned int i = 0; i < N; ++i)
	{
		m += (float)elem[i] * (float)elem[i];
	}

	return m;
}

template<typename T, unsigned int N>
inline float vec<T, N>::mag() const
{
	return sqrtf(sqrMag());
}

template<typename T, unsigned int N>
inline vec<T, N> vec<T, N>::normalized() const
{
	float m = mag();
	if (m == 0.f)
		return *this;

	vec<T, N> v;
	for (unsigned int i = 0; i < N; ++i)
	{
		v[i] = (float)elem[i] / m;
	}

	return v;
}

template<typename T, unsigned int N>
inline T& vec<T, N>::operator[](const unsigned int i)
{
	assert(("out of range", i < N));
	return elem[i];
}

template<typename T, unsigned int N>
inline const T& vec<T, N>::operator[](const unsigned int i) const
{
	assert(("out of range", i < N));
	return elem[i];
}