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

		class AFX_EXT_API CRenderContext
		{
		public:

			enum EQueryString : UINT
			{
				EQueryString_Vendor,
				EQueryString_Renderer,
				EQueryString_Version,
				EQueryString_Extensions,

				EQueryString_COUNT
			};

			enum EMatrixMode : UINT
			{
				EMatrixMode_ModelView,
				EMatrixMode_Projection,
				EMatrixMode_Texture,

				EMatrixMode_COUNT
			};

#pragma region Constructors

		public:

			CRenderContext();
			~CRenderContext();

#pragma endregion
#pragma region Attributes

		private:

			BOOL m_bGLEXTInitialized;

		public:

			BOOL IsGLEXTPrototypesInitialized() const;

#pragma endregion
#pragma region Operations

		public:

			HRESULT InitializeGLEXTPrototypes();
			CString GetString(EQueryString eQueryString) const;
			void Clear() const;
			void ClearColor(const core::TColorRGBA& clrClear) const;
			void Flush() const;
			void Viewport(const core::TIntRect& rcViewport) const;
			void MatrixMode(EMatrixMode eMatrixMode) const;
			void LoadIdentity() const;
			void LoadMatrix(const C3x3Matrix& mMatrix) const;
			void PushMatrix() const;
			void MultMatrix(const C3x3Matrix& mMatrix) const;
			void PopMatrix() const;
			void PointSize(FLOAT fSize) const;
			void LineWidth(FLOAT fWidth) const;
			void UseProgramARB(UINT uHandleARB) const;
			void Uniform1iARB(INT nLocation, INT nV0) const;

#pragma endregion

		};

	}
}