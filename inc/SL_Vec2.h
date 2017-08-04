//************************************************/
//* @file  :SL_Vec2.h
//* @brief :2�����x�N�g���p�N���X
//* @date  :2017/07/04
//* @author:S.Katou
//************************************************/

// ���d�C���N���[�h�h�~
#pragma once

// ���O��Ԏg�p
namespace ShunLib
{
	// Vec2�N���X
	class Vec2
	{
	public:
		static const Vec2 Zero;	 //(0,0)
		static const Vec2 One;   //(1,1)
		static const Vec2 UnitX; //(1,0)
		static const Vec2 UnitY; //(0,1)

	public:
		float m_x;
		float m_y;

	public:
		Vec2();
		Vec2(float x, float y);
		~Vec2();

		/*--[���Z�q�̃I�[�o�[���[�h]--*/
		Vec2& operator=(const Vec2& V);
		Vec2 operator+ (const Vec2& V);
		Vec2 operator- (const Vec2& V);
		Vec2 operator* (int num      );
		Vec2 operator* (float num    );
		Vec2 operator* (double num   );
	};
}