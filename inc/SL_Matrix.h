//************************************************/
//* @file  :Matrix.h
//* @brief :�s��p�̃��b�v�N���X
//* @date  :2017/02/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_Vec3.h>

namespace ShunLib
{
	class Matrix
	{
		/*--[�ÓI�Ȃ��]--*/
	public:
		//�P�ʍs��
		static Matrix Identity;

	public:
		//���s�ړ��s��
		static Matrix CreateTranslation(const Vec3& pos);

		//��]�s��
		static Matrix CreateRotationX(float angle);
		static Matrix CreateRotationY(float angle);
		static Matrix CreateRotationZ(float angle);

		//�g��k���s��
		static Matrix CreateScale(const Vec3& scale);
		static Matrix CreateScale(float scale);

		//�]�u�s���Ԃ�
		static Matrix Transpose(const Matrix& m);

		//�ˉe�s��
		static Matrix CreateProj(float fov,
								 float aspectRatio,
							     float nearPlane,
							     float farPlane);

		// �r���[�s��̍쐬
		static Matrix CreateLookAt(
			const Vec3& eye,
			const Vec3& target,
			const Vec3& up);


		/*--[�ÓI�ł͂Ȃ����]--*/
	public:
		float m_value[4][4];

	public:
		Matrix();
		Matrix(const Matrix& M);
		~Matrix();


		/*--[���Z�q�̃I�[�o�[���[�h]--*/
		Matrix& operator=(const Matrix& M);
		Matrix operator+(const Matrix& M);
		Matrix operator-(const Matrix& M);
		Matrix operator*(const Matrix& M);
		Matrix operator*(int num);
	};
}