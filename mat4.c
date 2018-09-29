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
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[0][2] = 0.0;
	dest[0][3] = 0.0;

	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	dest[1][2] = 0.0;
	dest[1][3] = 0.0;

	dest[2][0] = 0.0;
	dest[2][1] = 0.0;
	dest[2][2] = 1.0;
	dest[2][3] = 0.0;

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = 0.0;
	dest[3][3] = 1.0;
}

inline void glmc_mat4f_from_3f(mat4f dest, mat3f src)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[0][2] = src[0][2];
	dest[0][3] = 0.0;

	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	dest[1][2] = src[1][2];
	dest[1][3] = 0.0;

	dest[2][0] = src[2][0];
	dest[2][1] = src[2][1];
	dest[2][2] = src[2][2];
	dest[2][3] = 0.0;

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = 0.0;
	dest[3][3] = 1.0;
}

inline void glmc_mat4f_copy(mat4f dest, mat4f src)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[0][2] = src[0][2];
	dest[0][3] = src[0][3];

	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	dest[1][2] = src[1][2];
	dest[1][3] = src[1][3];

	dest[2][0] = src[2][0];
	dest[2][1] = src[2][1];
	dest[2][2] = src[2][2];
	dest[2][3] = src[2][3];

	dest[3][0] = src[3][0];
	dest[3][1] = src[3][1];
	dest[3][2] = src[3][2];
	dest[3][3] = src[3][3];
}

inline void glmc_mat4f_identity(mat4f dest)
{
	dest[0][0] = 1.0;
	dest[0][1] = 0.0;
	dest[0][2] = 0.0;
	dest[0][3] = 0.0;

	dest[1][0] = 0.0;
	dest[1][1] = 1.0;
	dest[1][2] = 0.0;
	dest[1][3] = 0.0;

	dest[2][0] = 0.0;
	dest[2][1] = 0.0;
	dest[2][2] = 1.0;
	dest[2][3] = 0.0;

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = 0.0;
	dest[3][3] = 1.0;
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

inline void glmc_mat4f_normalize(mat4f dest, mat4f src)
{
	if(glmc_mat4f_is_normalized(src) == 0)
	{
		float disc = glmc_mat4f_discriminant(src);
		dest[0][0] = src[0][0]/disc;
		dest[0][1] = src[0][1]/disc;
		dest[0][2] = src[0][2]/disc;
		dest[0][3] = src[0][3]/disc;

		dest[1][0] = src[1][0]/disc;
		dest[1][1] = src[1][1]/disc;
		dest[1][2] = src[1][2]/disc;
		dest[1][3] = src[1][3]/disc;

		dest[2][0] = src[2][0]/disc;
		dest[2][1] = src[2][1]/disc;
		dest[2][2] = src[2][2]/disc;
		dest[2][3] = src[2][3]/disc;

		dest[3][0] = src[3][0]/disc;
		dest[3][1] = src[3][1]/disc;
		dest[3][2] = src[3][2]/disc;
		dest[3][3] = src[3][3]/disc;
	}
	else
	{
		glmc_mat4f_copy(dest, src);
	}	
	
}

inline void glmc_mat4f_normalize_dest(mat4f src_dest)
{
	mat4f temp;
	glmc_mat4f_normalize(temp, src_dest);
	glmc_mat4f_copy(src_dest, temp);
}


inline void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[0][2] = src_a[0][2] + src_b[0][2];
	dest[0][3] = src_a[0][2] + src_b[0][3];

	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[1][1] = src_a[1][1] + src_b[1][1];
	dest[1][2] = src_a[1][2] + src_b[1][2];
	dest[1][3] = src_a[1][3] + src_b[1][3];

	dest[2][0] = src_a[2][0] + src_b[2][0];
	dest[2][1] = src_a[2][1] + src_b[2][1];
	dest[2][2] = src_a[2][2] + src_b[2][2];
	dest[2][3] = src_a[2][3] + src_b[2][3];

	dest[3][0] = src_a[3][0] + src_b[3][0];
	dest[3][1] = src_a[3][1] + src_b[3][1];
	dest[3][2] = src_a[3][2] + src_b[3][2];
	dest[3][3] = src_a[3][3] + src_b[3][3];
}

inline void glmc_mat4f_add_dest(mat4f src_dest, mat4f src_b)
{
	src_dest[0][0] += src_b[0][0];
	src_dest[0][1] += src_b[0][1];
	src_dest[0][2] += src_b[0][2];
	src_dest[0][3] += src_b[0][3];

	src_dest[1][0] += src_b[1][0];
	src_dest[1][1] += src_b[1][1];
	src_dest[1][2] += src_b[1][2];
	src_dest[1][3] += src_b[1][3];

	src_dest[2][0] += src_b[2][0];
	src_dest[2][1] += src_b[2][1];
	src_dest[2][2] += src_b[2][2];
	src_dest[2][3] += src_b[2][3];

	src_dest[3][0] += src_b[3][0];
	src_dest[3][1] += src_b[3][1];
	src_dest[3][2] += src_b[3][2];
	src_dest[3][3] += src_b[3][3];
}

inline void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[0][2] = src_a[0][2] - src_b[0][2];
	dest[0][3] = src_a[0][2] - src_b[0][3];

	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[1][1] = src_a[1][1] - src_b[1][1];
	dest[1][2] = src_a[1][2] - src_b[1][2];
	dest[1][3] = src_a[1][3] - src_b[1][3];

	dest[2][0] = src_a[2][0] - src_b[2][0];
	dest[2][1] = src_a[2][1] - src_b[2][1];
	dest[2][2] = src_a[2][2] - src_b[2][2];
	dest[2][3] = src_a[2][3] - src_b[2][3];

	dest[3][0] = src_a[3][0] - src_b[3][0];
	dest[3][1] = src_a[3][1] - src_b[3][1];
	dest[3][2] = src_a[3][2] - src_b[3][2];
	dest[3][3] = src_a[3][3] - src_b[3][3];	
}

inline void glmc_mat4f_sub_dest(mat4f src_dest, mat4f src_b)
{
	src_dest[0][0] -= src_b[0][0];
	src_dest[0][1] -= src_b[0][1];
	src_dest[0][2] -= src_b[0][2];
	src_dest[0][3] -= src_b[0][3];

	src_dest[1][0] -= src_b[1][0];
	src_dest[1][1] -= src_b[1][1];
	src_dest[1][2] -= src_b[1][2];
	src_dest[1][3] -= src_b[1][3];

	src_dest[2][0] -= src_b[2][0];
	src_dest[2][1] -= src_b[2][1];
	src_dest[2][2] -= src_b[2][2];
	src_dest[2][3] -= src_b[2][3];

	src_dest[3][0] -= src_b[3][0];
	src_dest[3][1] -= src_b[3][1];
	src_dest[3][2] -= src_b[3][2];
	src_dest[3][3] -= src_b[3][3];	
}

inline void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] + src_a[3][0]*src_b[0][3];
	dest[1][0] = src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] + src_a[3][0]*src_b[1][3];
	dest[2][0] = src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] + src_a[3][0]*src_b[2][3];
	dest[3][0] = src_a[0][0]*src_b[3][0] + src_a[1][0]*src_b[3][1] + src_a[2][0]*src_b[3][2] + src_a[3][0]*src_b[3][3];

	dest[0][1] = src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] + src_a[3][1]*src_b[0][3];
	dest[1][1] = src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] + src_a[3][1]*src_b[1][3];
	dest[2][1] = src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] + src_a[3][1]*src_b[2][3];
	dest[3][1] = src_a[0][1]*src_b[3][0] + src_a[1][1]*src_b[3][1] + src_a[2][1]*src_b[3][2] + src_a[3][1]*src_b[3][3];

	dest[0][2] = src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] + src_a[3][2]*src_b[0][3];
	dest[1][2] = src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] + src_a[3][2]*src_b[1][3];
	dest[2][2] = src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] + src_a[3][2]*src_b[2][3];
	dest[3][2] = src_a[0][2]*src_b[3][0] + src_a[1][2]*src_b[3][1] + src_a[2][2]*src_b[3][2] + src_a[3][2]*src_b[3][3];

	dest[0][3] = src_a[0][3]*src_b[0][0] + src_a[1][3]*src_b[0][1] + src_a[2][3]*src_b[0][2] + src_a[3][3]*src_b[0][3];
	dest[1][3] = src_a[0][3]*src_b[1][0] + src_a[1][3]*src_b[1][1] + src_a[2][3]*src_b[1][2] + src_a[3][3]*src_b[1][3];
	dest[2][3] = src_a[0][3]*src_b[2][0] + src_a[1][3]*src_b[2][1] + src_a[2][3]*src_b[2][2] + src_a[3][3]*src_b[2][3];
	dest[3][3] = src_a[0][3]*src_b[3][0] + src_a[1][3]*src_b[3][1] + src_a[2][3]*src_b[3][2] + src_a[3][3]*src_b[3][3];	
}

inline void glmc_mat4f_mul_dest(mat4f src_dest, mat4f src_b)
{
	mat4f temp;
	glmc_mat4f_mul(temp, src_dest, src_b);
	glmc_mat4f_copy(src_dest, temp);		
}

inline void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] * src_b;
	dest[0][1] = src_a[0][1] * src_b;
	dest[0][2] = src_a[0][2] * src_b;
	dest[0][3] = src_a[0][2] * src_b;

	dest[1][0] = src_a[1][0] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
	dest[1][2] = src_a[1][2] * src_b;
	dest[1][3] = src_a[1][3] * src_b;

	dest[2][0] = src_a[2][0] * src_b;
	dest[2][1] = src_a[2][1] * src_b;
	dest[2][2] = src_a[2][2] * src_b;
	dest[2][3] = src_a[2][3] * src_b;

	dest[3][0] = src_a[3][0] * src_b;
	dest[3][1] = src_a[3][1] * src_b;
	dest[3][2] = src_a[3][2] * src_b;
	dest[3][3] = src_a[3][3] * src_b;	
}

inline void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b)
{
	mat4f src_b_inv; 
	glmc_mat4f_inverse(src_b_inv, src_b);
	glmc_mat4f_mul(dest, src_a, src_b_inv);	
}

inline void glmc_mat4f_div_dest(mat4f src_dest, mat4f src_b)
{
	mat4f src_b_inv; 
	glmc_mat4f_inverse(src_b_inv, src_b);
	glmc_mat4f_mul_dest(src_dest, src_b_inv);	
}

inline void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] / src_b;
	dest[0][1] = src_a[0][1] / src_b;
	dest[0][2] = src_a[0][2] / src_b;
	dest[0][3] = src_a[0][2] / src_b;

	dest[1][0] = src_a[1][0] / src_b;
	dest[1][1] = src_a[1][1] / src_b;
	dest[1][2] = src_a[1][2] / src_b;
	dest[1][3] = src_a[1][3] / src_b;

	dest[2][0] = src_a[2][0] / src_b;
	dest[2][1] = src_a[2][1] / src_b;
	dest[2][2] = src_a[2][2] / src_b;
	dest[2][3] = src_a[2][3] / src_b;

	dest[3][0] = src_a[3][0] / src_b;
	dest[3][1] = src_a[3][1] / src_b;
	dest[3][2] = src_a[3][2] / src_b;
	dest[3][3] = src_a[3][3] / src_b;	
}

inline void glmc_mat4f_addadd(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] += src_a[0][0] + src_b[0][0];
	dest[0][1] += src_a[0][1] + src_b[0][1];
	dest[0][2] += src_a[0][2] + src_b[0][2];
	dest[0][3] += src_a[0][2] + src_b[0][3];

	dest[1][0] += src_a[1][0] + src_b[1][0];
	dest[1][1] += src_a[1][1] + src_b[1][1];
	dest[1][2] += src_a[1][2] + src_b[1][2];
	dest[1][3] += src_a[1][3] + src_b[1][3];

	dest[2][0] += src_a[2][0] + src_b[2][0];
	dest[2][1] += src_a[2][1] + src_b[2][1];
	dest[2][2] += src_a[2][2] + src_b[2][2];
	dest[2][3] += src_a[2][3] + src_b[2][3];

	dest[3][0] += src_a[3][0] + src_b[3][0];
	dest[3][1] += src_a[3][1] + src_b[3][1];
	dest[3][2] += src_a[3][2] + src_b[3][2];
	dest[3][3] += src_a[3][3] + src_b[3][3];	
}

inline void glmc_mat4f_subadd(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] += src_a[0][0] - src_b[0][0];
	dest[0][1] += src_a[0][1] - src_b[0][1];
	dest[0][2] += src_a[0][2] - src_b[0][2];
	dest[0][3] += src_a[0][2] - src_b[0][3];

	dest[1][0] += src_a[1][0] - src_b[1][0];
	dest[1][1] += src_a[1][1] - src_b[1][1];
	dest[1][2] += src_a[1][2] - src_b[1][2];
	dest[1][3] += src_a[1][3] - src_b[1][3];

	dest[2][0] += src_a[2][0] - src_b[2][0];
	dest[2][1] += src_a[2][1] - src_b[2][1];
	dest[2][2] += src_a[2][2] - src_b[2][2];
	dest[2][3] += src_a[2][3] - src_b[2][3];

	dest[3][0] += src_a[3][0] - src_b[3][0];
	dest[3][1] += src_a[3][1] - src_b[3][1];
	dest[3][2] += src_a[3][2] - src_b[3][2];
	dest[3][3] += src_a[3][3] - src_b[3][3];
}

inline void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] += src_a[0][0] * src_b[0][0];
	dest[0][1] += src_a[0][1] * src_b[0][1];
	dest[0][2] += src_a[0][2] * src_b[0][2];
	dest[0][3] += src_a[0][2] * src_b[0][3];

	dest[1][0] += src_a[1][0] * src_b[1][0];
	dest[1][1] += src_a[1][1] * src_b[1][1];
	dest[1][2] += src_a[1][2] * src_b[1][2];
	dest[1][3] += src_a[1][3] * src_b[1][3];

	dest[2][0] += src_a[2][0] * src_b[2][0];
	dest[2][1] += src_a[2][1] * src_b[2][1];
	dest[2][2] += src_a[2][2] * src_b[2][2];
	dest[2][3] += src_a[2][3] * src_b[2][3];

	dest[3][0] += src_a[3][0] * src_b[3][0];
	dest[3][1] += src_a[3][1] * src_b[3][1];
	dest[3][2] += src_a[3][2] * src_b[3][2];
	dest[3][3] += src_a[3][3] * src_b[3][3];	
}

inline void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] -= src_a[0][0] * src_b[0][0];
	dest[0][1] -= src_a[0][1] * src_b[0][1];
	dest[0][2] -= src_a[0][2] * src_b[0][2];
	dest[0][3] -= src_a[0][2] * src_b[0][3];

	dest[1][0] -= src_a[1][0] * src_b[1][0];
	dest[1][1] -= src_a[1][1] * src_b[1][1];
	dest[1][2] -= src_a[1][2] * src_b[1][2];
	dest[1][3] -= src_a[1][3] * src_b[1][3];

	dest[2][0] -= src_a[2][0] * src_b[2][0];
	dest[2][1] -= src_a[2][1] * src_b[2][1];
	dest[2][2] -= src_a[2][2] * src_b[2][2];
	dest[2][3] -= src_a[2][3] * src_b[2][3];

	dest[3][0] -= src_a[3][0] * src_b[3][0];
	dest[3][1] -= src_a[3][1] * src_b[3][1];
	dest[3][2] -= src_a[3][2] * src_b[3][2];
	dest[3][3] -= src_a[3][3] * src_b[3][3];	
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

inline void glmc_mat4f_translate(mat4f dest, vec3f src_vec)
{
	dest[0][0] = 1.0;
	dest[0][1] = 0.0;
	dest[0][2] = 0.0;
	dest[0][3] = 0.0;

	dest[1][0] = 0.0;
	dest[1][1] = 1.0;
	dest[1][2] = 0.0;
	dest[1][3] = 0.0;

	dest[2][0] = 0.0;
	dest[2][1] = 0.0;
	dest[2][2] = 1.0;
	dest[2][3] = 0.0;

	dest[3][0] = src_vec[0];
	dest[3][1] = src_vec[1];
	dest[3][2] = src_vec[2];
	dest[3][3] = 1.0;	
}

void glmc_mat4f_rotate(mat4f dest, vec3f src_dir, double src_radians)
{
	glmc_vec3f_normalize_dest(src_dir);
	float c = (cos(src_radians));
	float s = (sin(src_radians));

	dest[0][0] = c + src_dir[0]*src_dir[0]*(1.0 - c);
	dest[0][1] = src_dir[0]*src_dir[1]*(1.0 - c) + src_dir[2]*s;
	dest[0][2] = src_dir[0]*src_dir[2]*(1.0 - c) - src_dir[1]*s;
	dest[0][3] = 0.0;

	dest[1][0] = src_dir[0]*src_dir[1]*(1.0 - c) - src_dir[2]*s;
	dest[1][1] = c + src_dir[1]*src_dir[1]*(1.0 - c);
	dest[1][2] = src_dir[2]*src_dir[1]*(1.0 - c) + src_dir[0]*s;
	dest[1][3] = 0.0;

	dest[2][0] = src_dir[2]*src_dir[0]*(1.0 - c) + src_dir[1]*s;
	dest[2][1] = src_dir[2]*src_dir[1]*(1.0 - c) - src_dir[0]*s;
	dest[2][2] = c + src_dir[2]*src_dir[2]*(1.0 - c);
	dest[2][3] = 0.0;

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = 0.0;
	dest[3][3] = 1.0;
}

inline void glmc_mat4f_ortho_projection(mat4f dest, float src_left, float src_right,
									float src_top, float src_bottom, 
									float src_far, float src_near)
{
	dest[0][0] = 2/(src_right - src_left);
	dest[0][1] = 0.0;
	dest[0][2] = 0.0;
	dest[0][3] = 0.0;

	dest[1][0] = 0.0;
	dest[1][1] = 2/(src_right - src_bottom);
	dest[1][2] = 0.0;
	dest[1][3] = 0.0;

	dest[2][0] = 0.0;
	dest[2][1] = 0.0;
	dest[2][2] = -2/(src_far - src_near);
	dest[2][3] = 0.0;

	dest[3][0] = -(src_right + src_left)/(src_right - src_left);
	dest[3][1] = -(src_top + src_bottom)/(src_top - src_bottom);
	dest[3][2] = -(src_far + src_near)/(src_far - src_near);
	dest[3][3] = 1.0;
}

void glmc_mat4f_perspective_projection(mat4f dest, float src_left, float src_right,
									float src_top, float src_bottom, 
									float src_far, float src_near)
{
	dest[0][0] = 2/(src_right - src_left);
	dest[0][1] = 0.0;
	dest[0][2] = 0.0;
	dest[0][3] = 0.0;

	dest[1][0] = 0.0;
	dest[1][1] = 2/(src_right - src_bottom);
	dest[1][2] = 0.0;
	dest[1][3] = 0.0;

	dest[2][0] = (src_right + src_left)/(src_right - src_left);
	dest[2][1] = (src_top + src_bottom)/(src_top - src_bottom);
	dest[2][2] = -(src_far + src_near)/(src_far - src_near);
	dest[2][3] = -1.0;

	dest[3][0] = 0.0;
	dest[3][1] = 0.0;
	dest[3][2] = -(2.0 * src_far * src_near)/(src_far - src_near);
	dest[3][3] = 0.0;
}

void glmc_mat4f_mat_input(mat4f dest, int flag)
{
	float in;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			scanf("%f", &in);
			dest[i][j] = in;
		}
	}

	if(flag != 0)
		glmc_mat4f_normalize_dest(dest);
}

inline void glmc_mat4f_glsl_1d(float dest[], mat4f src)
{
	dest[0] = src[0][0];
	dest[1] = src[0][1];
	dest[2] = src[0][2];
	dest[3] = src[0][3];

	dest[4] = src[1][0];
	dest[5] = src[1][1];
	dest[6] = src[1][2];
	dest[7] = src[1][3];

	dest[8] = src[2][0];
	dest[9] = src[2][1];
	dest[10] = src[2][2];
	dest[11] = src[2][3];

	dest[12] = src[3][0];
	dest[13] = src[3][1];
	dest[14] = src[3][2];
	dest[15] = src[3][3];
}
