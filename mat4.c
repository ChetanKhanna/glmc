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

inline void glmc_mat4f_from_2f(mat4f dest, mat2f src)
{
	vec4f vec;
	vec[0] = vec[1] = vec[3] = 0.0;
	vec[2] = 1.0;
	glmc_vec4f_from_2f(dest[0], src[0], 0.0, 0.0);
	glmc_vec4f_from_2f(dest[1], src[1], 0.0, 0.0);
	glmc_vec4f_copy(dest[2], vec);
	vec[2] = 0.0;
	vec[3] = 1.0;
	glmc_vec4f_copy(dest[3], vec);
}

inline void glmc_mat4f_from_3f(mat4f dest, mat3f src)
{
	vec4f vec;
	vec[0] = vec[1] = vec[2] = 0.0;
	vec[3] = 1.0;
	glmc_vec4f_from_3f(dest[0], src[0], 0.0);
	glmc_vec4f_from_3f(dest[1], src[1], 0.0);
	glmc_vec4f_from_3f(dest[2], src[2], 0.0);
	glmc_vec4f_copy(dest[3], vec);
}

inline void glmc_mat4f_copy(mat4f dest, mat4f src)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_copy(dest[i], src[i]);
}

inline void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_add(dest[i], src_a[i], src_b[i]);
}

inline void glmc_mat4f_add_dest(mat4f src_dest, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_add_dest(src_dest[i], src_b[i]);
}

inline void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_sub(dest[i], src_a[i], src_b[i]);	
}

inline void glmc_mat4f_sub_dest(mat4f src_dest, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_sub_dest(src_dest[i], src_b[i]);	
}

inline void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_mul(dest[i], src_a[i], src_b[i]);	
}

inline void glmc_mat4f_mul_dest(mat4f src_dest, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_mul_dest(src_dest[i], src_b[i]);	
}

inline void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_mul_s(dest[i], src_a[i], src_b);	
}

inline void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_div(dest[i], src_a[i], src_b[i]);	
}

inline void glmc_mat4f_div_dest(mat4f src_dest, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_div_dest(src_dest[i], src_b[i]);	
}

inline void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_div_s(dest[i], src_a[i], src_b);	
}

inline void glmc_mat4f_addadd(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_addadd(dest[i], src_a[i], src_b[i]);	
}

inline void glmc_mat4f_subadd(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_subadd(dest[i], src_a[i], src_b[i]);	
}

inline void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_madd(dest[i], src_a[i], src_b[i]);	
}

inline void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b)
{
	for(int i = 0; i < 4; i++)
		glmc_vec4f_msub(dest[i], src_a[i], src_b[i]);	
}

inline float glmc_mat4f_discriminant(mat4f src)
{
	mat3f c1, c2, c3, c4;
	c1[0][0] = src[1][1];
	c1[0][1] = src[1][2];
	c1[0][2] = src[1][3];
	c1[1][0] = src[2][1];
	c1[1][1] = src[2][2];
	c1[1][2] = src[2][3];
	c1[2][0] = src[3][1];
	c1[2][1] = src[3][2];
	c1[2][2] = src[3][3];

	c2[0][0] = src[0][1];
	c2[0][1] = src[0][2];
	c2[0][2] = src[0][3];
	c2[1][0] = src[2][1];
	c2[1][1] = src[2][2];
	c2[1][2] = src[2][3];
	c2[2][0] = src[3][1];
	c2[2][1] = src[3][2];
	c2[2][2] = src[3][3];

	c3[0][0] = src[0][1];
	c3[0][1] = src[0][2];
	c3[0][2] = src[0][3];
	c3[1][0] = src[1][1];
	c3[1][1] = src[1][2];
	c3[1][2] = src[1][3];
	c3[2][0] = src[3][1];
	c3[2][1] = src[3][2];
	c3[2][2] = src[3][3];

	c4[0][0] = src[0][1];
	c4[0][1] = src[0][2];
	c4[0][2] = src[0][3];
	c4[1][0] = src[1][1];
	c4[1][1] = src[1][2];
	c4[1][2] = src[1][3];
	c4[2][0] = src[2][1];
	c4[2][1] = src[2][2];
	c4[2][2] = src[2][3];

	float disc = (src[0][0]*glmc_mat3f_discriminant(c1))
				-(src[1][0]*glmc_mat3f_discriminant(c2))
				+(src[2][0]*glmc_mat3f_discriminant(c3))
				-(src[3][0]*glmc_mat3f_discriminant(c4));
	return disc;
}

inline void glmc_mat4f_transpose(mat4f dest, mat4f src)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			dest[i][j] = src[j][i];
}

inline void glmc_mat4f_inverse(mat4f dest, mat4f src)
{
	mat4f cofac;
	cofac[0][0] = ((src[1][1]*src[2][2]*src[3][3])
				+ (src[2][1]*src[3][2]*src[1][3])
				+ (src[3][1]*src[1][2]*src[2][3])
				- (src[3][1]*src[2][2]*src[1][3])
				- (src[2][1]*src[1][2]*src[3][3])
				- (src[1][1]*src[3][2]*src[2][3]));
	cofac[1][0] = (-1.0f*(src[1][0]*src[2][2]*src[3][3])
				- (src[2][0]*src[3][2]*src[1][3])
				- (src[3][0]*src[1][2]*src[2][3])
				+ (src[3][0]*src[2][2]*src[1][3])
				+ (src[2][0]*src[1][2]*src[3][3])
				+ (src[1][0]*src[3][2]*src[2][3]));
	cofac[2][0] = ((src[1][0]*src[2][1]*src[3][3])
				+ (src[2][0]*src[3][1]*src[1][3])
				+ (src[3][0]*src[1][1]*src[2][3])
				- (src[3][0]*src[2][1]*src[1][2])
				- (src[2][0]*src[1][1]*src[3][3])
				- (src[1][0]*src[3][1]*src[2][3]));
	cofac[3][0] = ((src[3][0]*src[2][1]*src[1][2])
				+ (src[2][0]*src[1][1]*src[3][2])
				+ (src[1][0]*src[3][1]*src[2][2])
				- (src[1][0]*src[2][1]*src[3][4])
				- (src[2][0]*src[3][1]*src[1][2])
				- (src[3][0]*src[1][1]*src[2][2]));

	cofac[0][1] = ((src[3][1]*src[2][2]*src[0][3])
				+ (src[2][1]*src[0][2]*src[3][3])
				+ (src[0][1]*src[3][2]*src[2][3])
				- (src[0][1]*src[2][2]*src[3][3])
				- (src[2][1]*src[3][2]*src[0][3])
				- (src[3][1]*src[0][2]*src[2][3]));
	cofac[1][1] = ((src[0][0]*src[2][2]*src[3][3])
				+ (src[2][0]*src[3][2]*src[0][3])
				+ (src[3][1]*src[0][2]*src[2][3])
				- (src[3][1]*src[2][2]*src[0][3])
				- (src[2][1]*src[0][2]*src[3][3])
				- (src[0][0]*src[3][2]*src[2][3]));
	cofac[2][1] = ((src[3][0]*src[2][1]*src[0][3])
				+ (src[2][0]*src[0][1]*src[3][3])
				+ (src[0][0]*src[3][1]*src[2][3])
				- (src[0][0]*src[2][1]*src[3][3])
				- (src[2][0]*src[3][1]*src[0][3])
				- (src[3][0]*src[0][1]*src[2][3]));
	cofac[3][1] = ((src[0][0]*src[2][1]*src[3][2])
				+ (src[2][0]*src[3][1]*src[0][2])
				+ (src[3][0]*src[0][1]*src[2][2])
				- (src[3][0]*src[2][1]*src[0][2])
				- (src[2][0]*src[0][1]*src[3][2])
				- (src[0][0]*src[3][1]*src[2][2]));

	cofac[0][2] = ((src[0][1]*src[1][2]*src[3][3])
				+ (src[1][1]*src[3][2]*src[0][3])
				+ (src[3][1]*src[0][2]*src[1][3])
				- (src[3][1]*src[1][2]*src[0][3])
				- (src[1][1]*src[0][2]*src[3][3])
				- (src[0][1]*src[3][2]*src[1][3]));
	cofac[1][2] = ((src[3][0]*src[1][2]*src[0][3])
				+ (src[1][0]*src[0][2]*src[3][3])
				+ (src[0][0]*src[3][2]*src[1][3])
				- (src[0][0]*src[1][2]*src[3][3])
				- (src[1][0]*src[3][2]*src[0][3])
				- (src[3][0]*src[0][2]*src[1][3]));
	cofac[2][2] = ((src[0][0]*src[1][1]*src[3][3])
				+ (src[1][0]*src[3][1]*src[0][3])
				+ (src[3][0]*src[0][1]*src[1][3])
				- (src[3][0]*src[1][1]*src[0][3])
				- (src[1][0]*src[0][1]*src[3][3])
				- (src[0][0]*src[3][1]*src[1][3]));
	cofac[3][2] = ((src[3][0]*src[1][1]*src[0][2])
				+ (src[1][0]*src[0][1]*src[3][2])
				+ (src[0][0]*src[3][1]*src[1][2])
				- (src[0][0]*src[1][1]*src[3][2])
				- (src[1][0]*src[3][1]*src[0][2])
				- (src[3][0]*src[0][1]*src[1][2]));

	cofac[0][3] = ((src[2][1]*src[1][2]*src[0][3])
				+ (src[1][1]*src[0][2]*src[2][3])
				+ (src[0][1]*src[2][2]*src[1][3])
				- (src[0][1]*src[1][2]*src[2][3])
				- (src[1][1]*src[2][2]*src[0][3])
				- (src[2][1]*src[0][2]*src[1][3]));
	cofac[1][3] = ((src[0][0]*src[1][2]*src[2][3])
				+ (src[1][0]*src[2][2]*src[0][3])
				+ (src[2][0]*src[0][2]*src[1][3])
				- (src[2][0]*src[1][2]*src[0][3])
				- (src[1][0]*src[0][2]*src[2][3])
				- (src[0][0]*src[2][2]*src[1][2]));
	cofac[2][3] = ((src[2][0]*src[1][1]*src[0][3])
				+ (src[1][0]*src[0][1]*src[2][3])
				+ (src[0][0]*src[2][1]*src[1][3])
				- (src[0][0]*src[1][1]*src[2][3])
				- (src[1][0]*src[2][1]*src[0][3])
				- (src[2][0]*src[0][1]*src[1][3]));
	cofac[3][3] = ((src[0][0]*src[1][1]*src[2][2])
				+ (src[1][0]*src[2][1]*src[0][2])
				+ (src[2][0]*src[0][1]*src[1][2])
				- (src[2][0]*src[1][1]*src[0][2])
				- (src[1][0]*src[0][1]*src[2][2])
				- (src[0][0]*src[2][1]*src[1][2]));

	glmc_mat4f_div_s(dest, cofac, glmc_mat4f_discriminant(src));
}

inline int glmc_mat4f_is_normalized(mat4f src)
{
	if(glmc_mat4f_discriminant(src) == 1.0)
		return 1;
	else
		return 0;
}

inline void glmc_mat4f_normalized(mat4f dest, mat4f src)
{
	float disc = glmc_mat4f_discriminant(src);
	glmc_mat4f_div_s(dest, src, disc);
}

inline void glmc_mat4f_scale(mat4f dest, vec4f src_vec)
{
	dest[0][0] = src_vec[0];
	dest[0][1] = 0.0;
	dest[0][2] = 0.0;
	dest[0][3] = 0.0;

	dest[1][0] = 0.0;
	dest[1][1] = src_vec[1];
	dest[1][2] = 0.0;
	dest[1][3] = 0.0;

	dest[2][0] = 0.0;
	dest[2][1] = 0.0;
	dest[2][2] = src_vec[2];
	dest[2][3] = 0.0;

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = 0.0;
	dest[3][3] = src_vec[3];
}

inline void glmc_mat4f_translate(mat4f dest, vec3f src_vec);
{
	dest[0][0] = 1.0;
	dest[0][1] = 0.0;
	dest[0][2] = 0.0;
	dest[0][3] = src_vec[0];

	dest[1][0] = 0.0;
	dest[1][1] = 1.0;
	dest[1][2] = 0.0;
	dest[1][3] = src_vec[1];

	dest[2][0] = 0.0;
	dest[2][1] = 0.0;
	dest[2][2] = 1.0;
	dest[2][3] = src_vec[2];

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = 0.0;
	dest[3][3] = 1.0;
}

void glmc_mat4f_rotate(mat4f dest, vec3f src_dir, double src_radians)
{
	glmc_mat4f_normalized_dest(src_dir);
	dest[0][0] = float(cos(src_radians)) + src_dir[0]*src_dir[0]*(1.0 - float(cos(src_radians)));
	dest[0][1] = src_dir[0]*src_dir[1]*(1.0 - float(cos(src_radians))) + src_dir[2]*float(sin(src_radians));
	dest[0][2] = src_dir[0]*src_dir[2]*(1.0 - float(cos(src_radians))) - src_dir[1]*float(sin(src_radians));
	dest[0][3] = 0.0;

	dest[1][0] = src_dir[0]*src_dir[1]*(1.0 - float(cos(src_radians))) - src_dir[2]*float(sin(src_radians));
	dest[1][1] = float(cos(src_radians)) + src_dir[1]*src_dir[1]*(1.0 - float(cos(src_radians)));
	dest[1][2] = src_dir[2]*src_dir[1]*(1.0 - float(cos(src_radians))) + src_dir[0]*float(sin(src_radians));
	dest[1][3] = 0.0;

	dest[2][0] = src_dir[2]*src_dir[0]*(1.0 - float(cos(src_radians))) + src_dir[1]*float(sin(src_radians));
	dest[2][1] = src_dir[2]*src_dir[1]*(1.0 - float(cos(src_radians))) - src_dir[0]*float(sin(src_radians));
	dest[2][2] = float(cos(src_radians)) + src_dir[2]*src_dir[2]*(1.0 - float(cos(src_radians)));
	dest[2][3] = 0.0;

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = 0.0;
	dest[3][3] = 1.0;
}
