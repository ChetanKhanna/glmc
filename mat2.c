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

inline void glmc_mat2f_from_3f(mat2f dest, mat3f src)
{
	glmc_vec2f_from_3f(dest[0], src[0]);
	glmc_vec2f_from_3f(dest[1], src[1]);
}

inline void glmc_mat2f_from_4f(mat2f dest, mat4f src)
{
	glmc_vec2f_from_4f(dest[0], src[0]);
	glmc_vec2f_from_4f(dest[1], src[1]);
}

inline void glmc_mat2f_copy(mat2f dest, mat2f src)
{
	glmc_vec2f_copy(dest[0], src[0]);
	glmc_vec2f_copy(dest[1], src[1]);	
}

inline void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_add(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_add(dest[0], src_a[1], src_b[1]);	
}

inline void glmc_mat2f_add_dest(mat2f src_dest, mat2f src_b)
{
	glmc_vec2f_add_dest(src_dest[0], src_b[0]);
	glmc_vec2f_add_dest(src_dest[1], src_b[1]);
}

inline void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_sub(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_sub(dest[1], src_a[1], src_b[1]);
}

inline void glmc_mat2f_sub_dest(mat2f src_dest, mat2f src_b)
{
	glmc_vec2f_sub_dest(src_dest[0], src_b[0]);
	glmc_vec2f_sub_dest(src_dest[1], src_b[1]);
}

inline void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_mul(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_mul(dest[1], src_a[1], src_b[1]);
}

inline void glmc_mat2f_mul_dest(mat2f src_dest, mat2f src_b)
{
	glmc_vec2f_mul_dest(src_dest[0], src_b[0]);
	glmc_vec2f_mul_dest(src_dest[1], src_b[1]);
}

inline void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b)
{
	glmc_vec2f_mul_s(dest[0], src_a[0], src_b);
	glmc_vec2f_mul_s(dest[1], src_a[1], src_b);
}

inline void glmc_mat2f_div(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_div(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_div(dest[1], src_a[1], src_b[1]);
}

inline void glmc_mat2f_div_dest(mat2f src_dest, mat2f src_b)
{
	glmc_vec2f_div_dest(src_dest[0], src_b[0]);
	glmc_vec2f_div_dest(src_dest[1], src_b[1]);
}

inline void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b)
{
	glmc_vec2f_div_s(dest[0], src_a[0], src_b);
	glmc_vec2f_div_s(dest[1], src_a[1], src_b);
}

inline void glmc_mat2f_addadd(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_addadd(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_addadd(dest[1], src_a[1], src_b[1]);	
}

inline void glmc_mat2f_subadd(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_subadd(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_subadd(dest[1], src_a[1], src_b[1]);
}

inline void glmc_mat2f_madd(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_madd(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_madd(dest[1], src_a[1], src_b[1]);
}

inline void glmc_mat2f_msub(mat2f dest, mat2f src_a, mat2f src_b)
{
	glmc_vec2f_msub(dest[0], src_a[0], src_b[0]);
	glmc_vec2f_msub(dest[1], src_a[1], src_b[1]);
}

inline float glmc_mat2f_discriminant(mat2f src)
{
	return ((src[0][0]*src[1][1]) - (src[0][1]*src[1][0]));
}

inline void glmc_mat2f_transpose(mat2f dest, mat2f src)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
}

inline void glmc_mat2f_inverse(mat2f dest, mat2f src)
{
	dest[0][0] = src[1][1];
	dest[1][1] = src[0][0];
	dest[0][1] = -1 * src[0][1];
	dest[1][0] = -1 * src[1][0];
	float disc = glmc_mat2f_discriminant(src);
	dest[0][0] /= disc;
	dest[0][1] /= disc;
	dest[1][0] /= disc;
	dest[1][1] /= disc;
}
 
inline int glmc_mat2f_is_normalized(mat2f src)
{
	if(glmc_mat2f_discriminant(src) == 1)
		return 1;
	else
		return 0;
}
inline void glmc_mat2f_normalize(mat2f dest, mat2f src)
{
	float disc = glmc_mat2f_discriminant(src);
	glmc_mat2f_div_s(dest, src, disc);
}

inline void glmc_mat2f_normalize_dest(mat2f src_dest)
{
	mat2f temp;
	glmc_mat2f_normalize(temp, src_dest);
	glmc_mat2f_copy(src_dest, temp);
}

inline void glmc_mat2f_scale(mat2f dest, vec2f src_vec)
{
	dest[0][0] = src_vec[0];
	dest[0][1] = 0.0;

	dest[1][0] = 0.0;
	dest[1][1] = src_vec[1];
}

inline void glmc_mat2f_translate(mat2f dest, float src_vec)
{
	dest[0][0] = 1.0;
	dest[0][1] = 0.0;

	dest[1][0] = src_vec;
	dest[1][1] = 1.0;
}

inline void glmc_mat2f_rotate(mat2f dest, double src_radians)
{
	dest[0][0] = float(cos(src_radians));
	dest[0][1] = float(sin(src_radians));

	dest[1][0] = -float(sin(src_radians));
	dest[1][1] = float(cos(src_radians));
}
