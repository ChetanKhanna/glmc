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

inline void glmc_vec4f_from_2f(vec4f dest, vec2f src_a, float src_b, float src_c)
{
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_b;
	dest[3] = src_c;
}

inline void glmc_vec4f_from_3f(vec4f dest, vec3f src_a, float src_b)
{
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_a[2];
	dest[3] = src_b;
}

inline void glmc_vec4f_copy(vec4f dest, vec4f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	dest[3] = src[3];
}

inline float glmc_vec4f_sqrlength(vec4f vec)
{
	return (vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2] + vec[3]*vec[3]);
}

inline float glmc_vec4f_length(vec4f vec)
{
	float sq_len = glmc_vec4f_sqrlength(vec);
	return sqrt(sq_len);
}

inline int glmc_vec4f_is_normalized(vec4f src)
{
	if (glmc_vec4f_sqrlength(src) == 1)
		return 1;
	else
		return 0;
}

inline void glmc_vec4f_normlize(vec4f dest, vec4f src)
{
	float len = glmc_vec4f_length(src);
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src[i]/len;
	}
}

inline void glmc_vec4f_normlize_dest(vec4f src_dest)
{
	if(glmc_vec4f_is_normalized(src_dest) == 0)
	{
		vec4f temp;
		temp[0] = src_dest[0];
		temp[1] = src_dest[1];
		temp[2] = src_dest[2];
		temp[3] = src_dest[3];
		float len = glmc_vec4f_length(src_dest);
		src_dest[0] = temp[0]/len;
		src_dest[1] = temp[1]/len;
		src_dest[2] = temp[2]/len;
		src_dest[3] = temp[3]/len;
	}
}

inline void glmc_vec4f_add(vec3f dest, vec3f src_a, vec3f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] + src_b[i];
	}
}

inline void glmc_vec4f_add_dest(vec3f src_dest, vec3f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] += src_b[i];
	}
}

inline void glmc_vec4f_sub(vec3f dest, vec3f src_a, vec3f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] - src_b[i];
	}	
}

inline void glmc_vec4f_sub_dest(vec3f src_dest, vec3f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] -= src_b[i];
	}
}

inline void glmc_vec4f_mul(vec3f dest, vec3f src_a, vec3f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] * src_b[i];
	}	
}

inline void glmc_vec4f_mul_dest(vec3f src_dest, vec3f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] *= src_b[i];
	}	
}

inline void glmc_vec4f_mul_s(vec3f dest, vec3f src_a, float src_b)
{
	for(int i =0; i < 4; i++)
	{
		dest[i] = src_a[i] * src_b;
	}
}

inline void glmc_vec4f_div(vec4f dest, vec4f src_a, vec4f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] / src_b[i];
	}
}

inline void glmc_vec4f_div_dest(vec4f src_dest, vec4f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		src_dest[i] /= src_b[i];
	}
}

inline void glmc_vec4f_div_s(vec4f dest, vec4f src_a, float src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] = src_a[i] / src_b;
	}

}

inline void glmc_vec4f_addadd(vec4f dest, vec4f src_a, vec4f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] += src_a[i] + src_b[i];
	}	
}

inline void glmc_vec4f_subadd(vec4f dest, vec4f src_a, vec4f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] += src_a[i] - src_b[i];
	}	
}

inline void glmc_vec4f_madd(vec4f dest, vec4f src_a, vec4f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] += src_a[i] * src_b[i];
	}	
}

inline void glmc_vec4f_msub(vec4f dest, vec4f src_a, vec4f src_b)
{
	for(int i = 0; i < 4; i++)
	{
		dest[i] -= src_a[i] * src_b[i];
	}	
}

inline float glmc_vec4f_dot(vec4f src_a, vec4f src_b)
{
	float dot = 0.0;
	for(int i = 0; i < 4; i++)
	{
		dot += src_a[i] * src_b[i];
	}
	return dot;
}

inline void glmc_vec4f_glsl_1d(float dest[], vec4f src)
{
	dest[0] = src[0];
	dest[1] = src[1]; 
	dest[2] = src[2];
	dest[3] = src[3];
}
