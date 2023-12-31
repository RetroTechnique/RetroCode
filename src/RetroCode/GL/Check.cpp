/**
 *
 * Retro Code
 *
 * MIT License
 *
 * Copyright(c) 2014-2023 Retro Technique
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions :
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "pch.h"

namespace retro
{
	namespace gl
	{

		HRESULT GetOpenGLError()
		{
			const GLenum uCode = glGetError();

			switch (uCode)
			{
				case GL_INVALID_ENUM:
					return RC_GL_INVALID_ENUM;
				case GL_INVALID_VALUE:
					return RC_GL_INVALID_VALUE;
				case GL_INVALID_OPERATION:
					return RC_GL_INVALID_OPERATION;
				case GL_STACK_OVERFLOW:
					return RC_GL_STACK_OVERFLOW;
				case GL_STACK_UNDERFLOW:
					return RC_GL_STACK_UNDERFLOW;
				case GL_OUT_OF_MEMORY:
					return RC_GL_OUT_OF_MEMORY;
				case GL_NO_ERROR:
					[[fallthrough]];
				default:
					break;
			}

			return S_OK;
		}

	}
}