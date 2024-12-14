/*
    This file is a part of Lilith. (https://github.com/yoyoengine/Lilith)
    Copyright (C) 2024  Ryan Zmuda

    Licensed under the MIT license. See LICENSE file in the project root for details.
*/

#ifndef LILITH_H
#define LILITH_H

#include <stdio.h>	// snprintf
#include <stdlib.h>	// malloc
#include <math.h>	// cos, sin, M_PI

#ifdef _WIN32
	#define LLA_API __declspec(dllexport) inline
#else
	#define LLA_API inline
#endif

/*
* Lilith Linear Algebra
* 
* A basic linear algebra library for 2D matrix operations,
* created for use with [yoyoengine](https://github.com/yoyoengine).
* 
* No gaurantees are made for correctness or optimization,
* I'm just a hobbyist. :)
*/

/*
* Types
*/

/*
* 3x3 Matrix
* [row][column]
*/
typedef struct mat3_t {
    float data[3][3];
} mat3_t;

/*
* Generic Vector, will be treated
* as row or column implicitly.
*/
typedef struct vec2_t {
    float data[2];
} vec2_t;

/*
* Implementation
*/

/*
* Creates a 0'd out 3x3 matrix
*/
LLA_API mat3_t lla_mat3_zero() {
	mat3_t zero = {
		.data = {
			{0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.0f}
		}
	};
	return zero;
}

/*
* Creates a 3x3 matrix with the given values
*/
LLA_API mat3_t lla_mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
	mat3_t mat = {
		.data = {
			{a, b, c},
			{d, e, f},
			{g, h, i}
		}
	};
	return mat;
}

/*
* Returns a heap string representation
* of a 3x3 matrix, useful for debugging.
* 
* !!! YOU MUST FREE THE RETURNED POINTER !!!
*/
LLA_API const char * lla_mat3_string(mat3_t mat) {
	// (20 chars per float * 9 floats) + ((2 commas + 2 brackets) * 3 rows) + 32 padding
	unsigned int buffer_size = (20 * 9) + ((2+2)*3) + 32;
	char *buffer = (char*)malloc(buffer_size);
	
	snprintf(buffer, buffer_size, "[%f, %f, %f]\n[%f, %f, %f]\n[%f, %f, %f]", 
		mat.data[0][0], mat.data[0][1], mat.data[0][2],
		mat.data[1][0], mat.data[1][1], mat.data[1][2],
		mat.data[2][0], mat.data[2][1], mat.data[2][2]
	);

	return (const char *)buffer;
}

/*
* Returns a heap string representation
* of a 2D vector, useful for debugging.
* 
* !!! YOU MUST FREE THE RETURNED POINTER !!!
*/
LLA_API const char * lla_vec2_string(vec2_t vec) {
	// (20 chars per float * 2 floats) + (1 comma) + 2 brackets + 16 padding
	unsigned int buffer_size = (20 * 2) + 1 + (1+2) + 16;
	char *buffer = (char*)malloc(buffer_size);
	
	snprintf(buffer, buffer_size, "[%f, %f]", vec.data[0], vec.data[1]);

	return (const char*)buffer;
}

/*
* Returns a 3x3 identity matrix
*/
LLA_API mat3_t lla_mat3_identity() {
	mat3_t ident = {
		.data = {
			{1.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 1.0f}
		}
	};
	return ident;
}

/*
* Add two 3x3 matrices
*/
LLA_API mat3_t lla_mat3_add(mat3_t a, mat3_t b) {
	mat3_t result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.data[i][j] = a.data[i][j] + b.data[i][j];
		}
	}
	return result;
}

/*
* Subtract two 3x3 matrices
*/
LLA_API mat3_t lla_mat3_sub(mat3_t a, mat3_t b) {
	mat3_t result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.data[i][j] = a.data[i][j] - b.data[i][j];
		}
	}
	return result;
}

/*
* Returns the dot product of two 2D vectors
*/
LLA_API float lla_vec2_dot(vec2_t a, vec2_t b) {
	return (a.data[0] * b.data[0]) + (a.data[1] * b.data[1]);
}

/*
* Scales a 2D vector by a given scalar
*/
LLA_API vec2_t lla_vec2_scale(vec2_t vec, float scalar) {
	vec2_t result;
	result.data[0] = vec.data[0] * scalar;
	result.data[1] = vec.data[1] * scalar;
	return result;
}

/*
* Scales a 3x3 matrix by a given scalar
*/
LLA_API mat3_t lla_mat3_scale(mat3_t mat, float scalar) {
	mat3_t result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.data[i][j] = mat.data[i][j] * scalar;
		}
	}
	return result;
}

/*
* Returns the transpose of a 3x3 matrix
*/
LLA_API mat3_t lla_mat3_transpose(mat3_t mat) {
	mat3_t result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.data[i][j] = mat.data[j][i];
		}
	}
	return result;
}

/*
* Multiplies two 3x3 matrices
*/
LLA_API mat3_t lla_mat3_mult(mat3_t a, mat3_t b) {
	mat3_t result;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result.data[i][j] = (a.data[i][0] * b.data[0][j]) + (a.data[i][1] * b.data[1][j]) + (a.data[i][2] * b.data[2][j]);
		}
	}
	return result;
}

/*
* Multiply a 3x3 matrix by a 2D vector
*
* Technically, this is impossible, but we can append a 1 to the vector for our use cases
*/
LLA_API vec2_t lla_mat3_mult_vec2(mat3_t mat, vec2_t vec) {
	vec2_t result;
	result.data[0] = (mat.data[0][0] * vec.data[0]) + (mat.data[0][1] * vec.data[1]) + (mat.data[0][2] * 1.0f);
	result.data[1] = (mat.data[1][0] * vec.data[0]) + (mat.data[1][1] * vec.data[1]) + (mat.data[1][2] * 1.0f);
	return result;
}

/*
* Translates a 3x3 matrix by a 2D vector
*/
LLA_API mat3_t lla_mat3_translate(mat3_t mat, vec2_t vec) {
	mat3_t result = lla_mat3_identity();
	result.data[0][2] = vec.data[0];
	result.data[1][2] = vec.data[1];
	return lla_mat3_mult(mat, result);
}

/*
* Rotates a 3x3 matrix by a given angle in degrees
*/
LLA_API mat3_t lla_mat3_rotate(mat3_t mat, float angle) {
	float radians = angle * (M_PI / 180.0f);
	mat3_t result = lla_mat3_identity();
	result.data[0][0] = cosf(radians);
	result.data[0][1] = -sinf(radians);
	result.data[1][0] = sinf(radians);
	result.data[1][1] = cosf(radians);
	return lla_mat3_mult(mat, result);
}

#endif // LILITH_H