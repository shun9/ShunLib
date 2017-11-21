//************************************************/
//* @file  :SL_Vec3.h
//* @brief :�R�����x�N�g���p�̃��b�v�N���X
//* @date  :2017/11/14
//* @author:S.Katou
//************************************************/
#pragma once

namespace ShunLib
{
	class Matrix;

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
		//���K��
		static Vec3 Normalize(const Vec3& V);

		//����
		static float Dot(const Vec3& V, const Vec3& V2);

		//�O��
		static Vec3 Cross(const Vec3& V, const Vec3& V2);

		//���
		static Vec3 Larp(const Vec3& start, const Vec3& end, float time,std::function<float(float)> v);

		//��]
		static Vec3 Rotation(const Vec3& V, const Matrix& rot);

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
		Vec3& operator*=(double num);
		Vec3& operator/=(double num);
		Vec3& operator*=(float num);
		Vec3& operator/=(float num);
		Vec3& operator*=(int num);
		Vec3& operator/=(int num);

		Vec3& operator+();
		Vec3 operator-();
	};
}


//���Z�q�̃I�[�o�[���[�h
bool  operator==(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator+(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator-(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);

ShunLib::Vec3 operator*(const ShunLib::Vec3& V, double num);
ShunLib::Vec3 operator*(const ShunLib::Vec3& V, float num);
ShunLib::Vec3 operator*(const ShunLib::Vec3& V, int num);

ShunLib::Vec3 operator/(const ShunLib::Vec3& V, double num);
ShunLib::Vec3 operator/(const ShunLib::Vec3& V, float num);
ShunLib::Vec3 operator/(const ShunLib::Vec3& V, int num);
