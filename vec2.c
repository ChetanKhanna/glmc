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

inline void glmc_vec2f_from_3f(vec2f dest, vec3f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
}

inline void glmc_vec2f_from_4f(vec2f dest, vec4f src)
{
	dest[0] = src[0];
	dest[1] = src[1];	
}

inline void glmc_vec2f_copy(vec2f dest, vec2f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
}

inline float glmc_vec2f_sqrlength(vec2f vec)
{
	return (vec[0]*vec[0] + vec[1]*vec[1]);
}

inline float glmc_vec2f_length(vec2f vec)
{
	return sqrt(glmc_vec2f_sqrlength(vec));
}

inline int  glmc_vec2f_is_normalized(vec2f src)
{
	if(glmc_vec2f_sqrlength(src) == 1.0)				
		return 1;
	else
		return 0;
}

inline void glmc_vec2f_normlize(vec2f dest, vec2f src)
{
	if(glmc_vec2f_is_normalized(src) == 1) 				
	{
		dest[0] = src[0];
		dest[1] = src[1];
	}
	else
	{
		float len = glmc_vec4f_length(src);
		for(int i = 0; i < 2; i++)
		{
			dest[i] = src[i]/len;
		}	
	}	
}

inline void glmc_vec2f_normlize_dest(vec2f src_dest)
{
	if(glmc_vec2f_is_normalized(src_dest) == 0)
	{
		vec2f temp;
		temp[0] = src_dest[0];
		temp[1] = src_dest[1];
		float len = glmc_vec2f_length(src_dest);
		src_dest[0] = temp[0]/len;
		src_dest[1] = temp[1]/len;
	}
	
}

inline void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] + src_b[i];
	}
}

inline void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] += src_b[i];
	}
}

inline void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] - src_b[i];
	}	
}

inline void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] -= src_b[i];
	}
}

inline void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] * src_b[i];
	}	
}

inline void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] *= src_b[i];
	}	
}

inline void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b)
{
	for(int i =0; i < 2; i++)
	{
		dest[i] = src_a[i] * src_b;
	}
}

inline void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] / src_b[i];
	}
}

inline void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		src_dest[i] /= src_b[i];
	}
}

inline void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] = src_a[i] / src_b;
	}

}

inline void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] += src_a[i] + src_b[i];
	}	
}

inline void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b){
	for(int i = 0; i < 2; i++)
	{
		dest[i] += src_a[i] - src_b[i];
	}	
}

inline void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] += src_a[i] * src_b[i];
	}	
}

inline void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b)
{
	for(int i = 0; i < 2; i++)
	{
		dest[i] -= src_a[i] * src_b[i];
	}	
}

inline float glmc_vec2f_dot(vec2f src_a, vec2f src_b)
{
	float dot = 0.0;
	for(int i = 0; i < 2; i++)
	{
		dot += src_a[i] * src_b[i];
	}
	return dot;
}

inline void glmc_vec2f_glsl_1d(float dest[], vec2f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
}
