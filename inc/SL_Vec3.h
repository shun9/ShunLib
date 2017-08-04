//************************************************/
//* @file  :SL_Vec3.h
//* @brief :�R�����x�N�g���p�̃��b�v�N���X
//* @date  :2017/07/04
//* @author:S.Katou
//************************************************/
#pragma once

namespace ShunLib
{
	class Vec3
	{
		/*--[�ÓI�ϐ�]--*/
	public:
		static const Vec3 Zero;			// �O  �O  �O
		static const Vec3 One;			// �P  �P  �P
		static const Vec3 UnitX;		// �P  �O  �O
		static const Vec3 UnitY;		// �O  �P  �O
		static const Vec3 UnitZ;		// �O  �O  �P
		static const Vec3 Up;			// �O  �P  �O
		static const Vec3 Down;			// �O -�P  �O
		static const Vec3 Right;		// �P  �O  �O
		static const Vec3 Left;			//-�P  �O  �O
		static const Vec3 Forward;		// �O  �O -�P
		static const Vec3 Backward;		// �O  �O  �P

	public:
		//����
		static float Dot(const Vec3& V, const Vec3& V2);

		//�O��
		static Vec3 Cross(const Vec3& V, const Vec3& V2);

	public:
		float m_x;
		float m_y;
		float m_z;

	public:
		Vec3();
		Vec3(float x, float y, float z);
		Vec3(float num);
		Vec3(const Vec3& vec);
		~Vec3();

		//���K��
		Vec3 Normalize();

		//�傫����Ԃ�
		float Length();

		/*--[���Z�q�̃I�[�o�[���[�h]--*/
		Vec3& operator= (const Vec3& V);
		Vec3& operator+=(const Vec3& V);
		Vec3& operator-=(const Vec3& V);
		Vec3& operator*=(float num);
		Vec3& operator/=(float num);

		Vec3& operator+();
		Vec3 operator-();
	};
}


//���Z�q�̃I�[�o�[���[�h
bool  operator==(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator+(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator-(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator*(const ShunLib::Vec3& V, float num);
ShunLib::Vec3 operator/(const ShunLib::Vec3& V, float num);
