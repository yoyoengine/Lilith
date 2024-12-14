/*
    This file is a part of Lilith. (https://github.com/yoyoengine/Lilith)
    Copyright (C) 2024  Ryan Zmuda

    Licensed under the MIT license. See LICENSE file in the project root for details.
*/

/*
    A simple test for Lilith Linear Algebra, mostly written by ChatGPT
*/

#include <Lilith.h>

int main() {
    // Test mat3_t: create an identity matrix
    mat3_t identity = lla_mat3_identity();
    const char* identity_str = lla_mat3_string(identity);
    printf("Identity matrix:\n%s\n", identity_str);
    free((void*)identity_str);

    // Test mat3_t: create a matrix with specific values
    mat3_t mat = lla_mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
    const char* mat_str = lla_mat3_string(mat);
    printf("Matrix created with values:\n%s\n", mat_str);
    free((void*)mat_str);

    // Test mat3_t: adding two matrices
    mat3_t added = lla_mat3_add(identity, mat);
    const char* added_str = lla_mat3_string(added);
    printf("Sum of identity and mat:\n%s\n", added_str);
    free((void*)added_str);

    // Test vec2_t: create a vector
    vec2_t vec = { 2.0f, 3.0f };
    const char* vec_str = lla_vec2_string(vec);
    printf("Vector:\n%s\n", vec_str);
    free((void*)vec_str);

    // Test vec2_t: dot product of two vectors
    vec2_t vec2 = { 1.0f, 4.0f };
    float dot_result = lla_vec2_dot(vec, vec2);
    printf("Dot product of vec and vec2: %f\n", dot_result);

    // Test mat3_t: scaling a matrix
    mat3_t scaled = lla_mat3_scale(mat, 2.0f);
    const char* scaled_str = lla_mat3_string(scaled);
    printf("Matrix scaled by 2.0:\n%s\n", scaled_str);
    free((void*)scaled_str);

    // Test mat3_t: transpose of a matrix
    mat3_t transposed = lla_mat3_transpose(mat);
    const char* transposed_str = lla_mat3_string(transposed);
    printf("Transposed matrix:\n%s\n", transposed_str);
    free((void*)transposed_str);

    // Test mat3_t: matrix multiplication with identity
    mat3_t multiplied_identity = lla_mat3_mult(identity, mat);
    const char* multiplied_identity_str = lla_mat3_string(multiplied_identity);
    printf("Multiplication of identity and mat:\n%s\n", multiplied_identity_str);
    free((void*)multiplied_identity_str);

    // Additional tests for matrix multiplication with non-identity matrices

    // Test mat3_t: matrix multiplication with arbitrary non-identity matrices
    mat3_t mat2 = lla_mat3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f); // Identity matrix
    mat3_t mat3 = lla_mat3(3.0f, 2.0f, 1.0f, 6.0f, 5.0f, 4.0f, 9.0f, 8.0f, 7.0f); // Custom matrix

    // Print mat2 and mat3
    printf("mat2: \n");
    const char* mat2_str = lla_mat3_string(mat2);
    printf("%s\n", mat2_str);
    free((void*)mat2_str);

    printf("mat3: \n");
    const char* mat3_str = lla_mat3_string(mat3);
    printf("%s\n", mat3_str);
    free((void*)mat3_str);

    mat3_t result_1 = lla_mat3_mult(mat2, mat3); // Multiply mat2 and mat3
    const char* result_1_str = lla_mat3_string(result_1);
    printf("res (mat2 * mat3): \n%s\n", result_1_str);
    free((void*)result_1_str);

    // Test mat3_t: matrix multiplication where the first matrix is a scaling matrix
    mat3_t scale_matrix = lla_mat3(2.0f, 0.0f, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 2.0f); // Scaling matrix

    // Print scale_matrix
    printf("scale_matrix: \n");
    const char* scale_matrix_str = lla_mat3_string(scale_matrix);
    printf("%s\n", scale_matrix_str);
    free((void*)scale_matrix_str);

    mat3_t result_2 = lla_mat3_mult(scale_matrix, mat3); // Multiply scale_matrix and mat3
    const char* result_2_str = lla_mat3_string(result_2);
    printf("res (scale_matrix * mat3): \n%s\n", result_2_str);
    free((void*)result_2_str);

    // Test mat3_t: matrix multiplication with arbitrary rotation matrix
    mat3_t rotation_matrix = lla_mat3(0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f); // 90 degree rotation matrix

    // Print rotation_matrix
    printf("rotation_matrix: \n");
    const char* rotation_matrix_str = lla_mat3_string(rotation_matrix);
    printf("%s\n", rotation_matrix_str);
    free((void*)rotation_matrix_str);

    mat3_t result_3 = lla_mat3_mult(rotation_matrix, mat3); // Rotate mat3 by 90 degrees
    const char* result_3_str = lla_mat3_string(result_3);
    printf("res (rotation_matrix * mat3): \n%s\n", result_3_str);
    free((void*)result_3_str);

    // zoogies test
    mat3_t a = lla_mat3(10.0f, 80.0f, 4.0f, 5.0f, 78.0f, 9.0f, 47.0f, 9.0f, 5.0f);
    mat3_t b = lla_mat3(4.0f, 35.0f, 0.0f, 42.0f, 1.0f, 23.0f, 44.0f, 55.0f, 6.0f);

    mat3_t res = lla_mat3_mult(a, b);

    const char* res_str = lla_mat3_string(res);
    printf("res (a * b): \n%s\n", res_str);
    free((void*)res_str);

    return 0;
}