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

#pragma once

namespace retro
{
	namespace gl
	{

		HRESULT AFX_EXT_API GetOpenGLError();

	}
}

#ifdef _DEBUG
#define glCheck(glfunction) glfunction;{ HRESULT hr = retro::gl::GetOpenGLError(); if (FAILED(hr)) { retro::core::LogInterfaceError(_T("[OPENGL] "), hr, retro::core::ELogLevel_Error); } }
#define wglCheck(wglfunction) wglfunction; { BOOL bRet = wglfunction; if (!bRet) { retro::core::LogWinError(_T("[WGL] "), GetLastError(), retro::core::ELogLevel_Error); } }
#else
#define glCheck(glfunction) glfunction;
#define wglCheck(wglfunction) wglfunction;
#endif