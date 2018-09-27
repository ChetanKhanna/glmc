/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"

void inline glmc_mat3f_from_2f(mat3f dest, mat2f src)
{
	vec3f vec;
	vec[0] = 0;
	vec[1] = 0;
	vec[2] = 1.0;
	glmc_vec3f_from_2f(dest[0], src[0], 0.0);
	glmc_vec3f_from_2f(dest[1], src[1], 0.0);
	glmc_vec3f_copy(dest[2], vec);
}

void inline glmc_mat3f_from_4f(mat3f dest, mat4f src)
{
	glmc_vec3f_from_4f(dest[0], src[0]);
	glmc_vec3f_from_4f(dest[1], src[1]);
	glmc_vec3f_from_4f(dest[2], src[2]);
}

void inline glmc_mat3f_copy(mat3f dest, mat3f src)
{
	for(int i = 0; i < 3; i++)
		glmc_vec3f_copy(dest[i], src[i]);
}

void inline glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_add(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_add(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_add(dest[2], src_a[2], src_b[2]);
}

void inline glmc_mat3f_add_dest(mat3f src_dest, mat3f src_b)
{
	glmc_vec3f_add_dest(src_dest[0], src_b[0]);
	glmc_vec3f_add_dest(src_dest[1], src_b[1]);
	glmc_vec3f_add_dest(src_dest[2], src_b[2]);
}

void inline glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_sub(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_sub(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_sub(dest[2], src_a[2], src_b[2]);
}

void inline glmc_mat3f_sub_dest(mat3f src_dest, mat3f src_b)
{
	glmc_vec3f_sub_dest(src_dest[0], src_b[0]);
	glmc_vec3f_sub_dest(src_dest[1], src_b[1]);
	glmc_vec3f_sub_dest(src_dest[2], src_b[2]);	
}

void inline glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_mul(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_mul(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_mul(dest[2], src_a[2], src_b[2]);	
}

void inline glmc_mat3f_mul_dest(mat3f src_dest, mat3f src_b)
{
	glmc_vec3f_mul_dest(src_dest[0], src_b[0]);
	glmc_vec3f_mul_dest(src_dest[1], src_b[1]);
	glmc_vec3f_mul_dest(src_dest[2], src_b[2]);	
}

void inline glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b)
{
	glmc_vec3f_mul_s(dest[0], src_a[0], src_b);
	glmc_vec3f_mul_s(dest[1], src_a[1], src_b);
	glmc_vec3f_mul_s(dest[2], src_a[2], src_b);	
}

void inline glmc_mat3f_div(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_div(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_div(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_div(dest[2], src_a[2], src_b[2]);	
}

void inline glmc_mat3f_div_dest(mat3f src_dest, mat3f src_b)
{
	glmc_vec3f_div_dest(src_dest[0], src_b[0]);
	glmc_vec3f_div_dest(src_dest[1], src_b[1]);
	glmc_vec3f_div_dest(src_dest[2], src_b[2]);	
}

void inline glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b)
{
	glmc_vec3f_div_s(dest[0], src_a[0], src_b);
	glmc_vec3f_div_s(dest[1], src_a[1], src_b);
	glmc_vec3f_div_s(dest[2], src_a[2], src_b);	
}

void inline glmc_mat3f_addadd(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_addadd(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_addadd(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_addadd(dest[2], src_a[2], src_b[2]);
}

void inline glmc_mat3f_subadd(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_subadd(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_subadd(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_subadd(dest[2], src_a[2], src_b[2]);	
}

void inline glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_madd(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_madd(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_madd(dest[2], src_a[2], src_b[2]);	
}

void inline glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b)
{
	glmc_vec3f_msub(dest[0], src_a[0], src_b[0]);
	glmc_vec3f_msub(dest[1], src_a[1], src_b[1]);
	glmc_vec3f_msub(dest[2], src_a[2], src_b[2]);	
}

float inline glmc_mat3f_discriminant(mat3f src)
{
	float e1 = src[0][0]*((src[1][1]*src[2][2]) - (src[1][2]*src[2][1]));
	float e2 = src[1][0]*((src[0][2]*src[2][1]) - (src[0][1]*src[2][2]));
	float e3 = src[2][0]*((src[0][1]*src[1][2]) - (src[0][2]*src[1][1]));
	return (e1 + e2 + e3);
}

void inline glmc_mat3f_transpose(mat3f dest, mat3f src)
{
	for(int i = 0; i < 3; i++)
		dest[0][i] = src[i][0];
	for(int i = 0; i < 3; i++)
		dest[1][i] = src[i][1];
	for (int i = 0; i < 3; i++)
		dest[2][i] = src[i][2];
}

void inline glmc_mat3f_inverse(mat3f dest, mat3f src)
{
	mat3f cofac, co_trans;
	cofac[0][0] = (src[1][1]*src[2][2]) - (src[1][2]*src[2][1]);
	cofac[1][0] = (src[0][2]*src[2][1]) - (src[0][1]*src[2][2]);
	cofac[2][0] = (src[0][1]*src[1][2]) - (src[0][2]*src[1][1]);
	cofac[0][1] = (src[2][1]*src[0][2]) - (src[0][1]*src[2][2]);
	cofac[1][1] = (src[0][0]*src[2][2]) - (src[0][2]*src[2][0]);
	cofac[2][1] = (src[0][2]*src[1][0]) - (src[0][0]*src[1][2]);
	cofac[0][2] = (src[1][0]*src[2][1]) - (src[1][1]*src[2][0]);
	cofac[1][2] = (src[0][1]*src[2][0]) - (src[0][0]*src[2][1]);
	cofac[2][2] = (src[0][0]*src[1][1]) - (src[0][1]*src[1][0]);
	glmc_mat3f_transpose(co_trans, cofac);
	float disc = glmc_mat3f_discriminant(src);
	glmc_mat3f_div_s(dest, co_trans, disc);
}

int inline glmc_mat3f_is_normalized(mat3f src)
{
	if(glmc_mat3f_discriminant(src) == 1)
		return 1;
	else
		return 0;
}

void inline glmc_mat3f_normalized(mat3f dest, mat3f src)
{
	float disc = glmc_mat3f_discriminant(src);
	glmc_mat3f_div_s(dest, src, disc);
}
