//************************************************/
//* @file  :Matrix.cpp
//* @brief :�s��p�̃��b�v�N���X
//* @date  :2017/02/22
//* @author:S.Katou
//************************************************/
#include "SL_Matrix.h"

#include <cmath>
#include <functional>

#include <d3d11.h>
#include <DirectXMath.h>
#include <SL_Conversion.h>

using namespace ShunLib;

Matrix Matrix::Identity;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :���s�ړ��s��̍쐬
//�b����  :�ړ���̈ʒu(Vec3)
//�b�߂�l:�s��(Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateTranslation(const Vec3& pos)
{
	Matrix matrix;
	matrix.m_value[3][0] += pos.m_x;
	matrix.m_value[3][1] += pos.m_y;
	matrix.m_value[3][2] += pos.m_z;

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�w����]�s��̍쐬
//�b����  :�p�x(float)
//�b�߂�l:�s��(Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateRotationX(float angle)
{

	Matrix matrix;
	matrix.m_value[1][1] =  cos(ToRadian(angle));
	matrix.m_value[1][2] = -sin(ToRadian(angle));
	matrix.m_value[2][1] =  sin(ToRadian(angle));
	matrix.m_value[2][2] =  cos(ToRadian(angle));

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�x����]�s��̍쐬
//�b����  :�p�x(float)
//�b�߂�l:�s��(Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateRotationY(float angle)
{
	Matrix matrix;
	matrix.m_value[0][0] =  cos(ToRadian(angle));
	matrix.m_value[0][2] =  sin(ToRadian(angle));
	matrix.m_value[2][0] = -sin(ToRadian(angle));
	matrix.m_value[2][2] =  cos(ToRadian(angle));

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�y����]�s��̍쐬
//�b����  :�p�x(float)
//�b�߂�l:�s��(Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateRotationZ(float angle)
{
	Matrix matrix;
	matrix.m_value[0][0] =  cos(ToRadian(angle));
	matrix.m_value[0][1] = -sin(ToRadian(angle));
	matrix.m_value[1][0] =  sin(ToRadian(angle));
	matrix.m_value[1][1] =  cos(ToRadian(angle));

	return matrix;
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�g��k���s��̍쐬
//�b����  :�g�嗦(Vec3)
//�b�߂�l:�s��(Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateScale(const Vec3& scale)
{

	Matrix matrix;
	matrix.m_value[0][0] *= scale.m_x;
	matrix.m_value[1][1] *= scale.m_y;
	matrix.m_value[2][2] *= scale.m_z;

	return matrix;
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�g��k���s��̍쐬
//�b����  :�g�嗦(float)
//�b�߂�l:�s��(Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateScale(float scale)
{
	Matrix matrix;
	matrix.m_value[0][0] *= scale;
	matrix.m_value[1][1] *= scale;
	matrix.m_value[2][2] *= scale;

	return matrix;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�ˉe�s��̍쐬
//�b����  :����p�@�@�@�@�@�@(float)
//�b����  :�A�X�y�N�g��@�@�@(float)
//�b����  :�߃N���b�v�ʂ̋���(float)
//�b����  :���N���b�v�ʂ̋���(float)
//�b�߂�l:�ˉe�s��(Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix Matrix::CreateProj(float fov, float aspectRatio, float nearPlane, float farPlane)
{
	using namespace DirectX;

	Matrix proj;

	auto projD = XMMatrixPerspectiveFovRH(fov, aspectRatio, nearPlane, farPlane);

	std::function<float(XMVECTOR)> GetX = XMVectorGetX;
	std::function<float(XMVECTOR)> GetY = XMVectorGetY;
	std::function<float(XMVECTOR)> GetZ = XMVectorGetZ;
	std::function<float(XMVECTOR)> GetW = XMVectorGetW;

	proj.m_value[0][0] = GetX(projD.r[0]);	proj.m_value[1][0] = GetX(projD.r[1]);	proj.m_value[2][0] = GetX(projD.r[2]);	proj.m_value[3][0] = GetX(projD.r[3]);
	proj.m_value[0][1] = GetY(projD.r[0]);	proj.m_value[1][1] = GetY(projD.r[1]);	proj.m_value[2][1] = GetY(projD.r[2]);	proj.m_value[3][1] = GetY(projD.r[3]);
	proj.m_value[0][2] = GetZ(projD.r[0]);	proj.m_value[1][2] = GetZ(projD.r[1]);	proj.m_value[2][2] = GetZ(projD.r[2]);	proj.m_value[3][2] = GetZ(projD.r[3]);
	proj.m_value[0][3] = GetW(projD.r[0]);	proj.m_value[1][3] = GetW(projD.r[1]);	proj.m_value[2][3] = GetW(projD.r[2]);	proj.m_value[3][3] = GetW(projD.r[3]);

	return proj;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�r���[�s��̍쐬
//�b����  :�J�����̈ʒu�@�@�@(Vec3)
//�b����  :�J�����̒����_�@�@(Vec3)
//�b����  :�J�����̏����    (Vec3)
//�b�߂�l:�r���[�s��		 (Matrix)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix ShunLib::Matrix::CreateLookAt(const Vec3& eye, const Vec3& target, const Vec3& up)
{
	Vec3 x;
	Vec3 y;
	Vec3 z = eye - target;

	//�����̐��K��
	z = z.Normalize();

	//x�������߂�
	x = Vec3::Cross(up, z);
	x = x.Normalize();

	//y�������߂�
	y = Vec3::Cross(z, x);

	Vec3 negEye = eye * -1;

	float tx = Vec3::Dot(x, negEye);
	float ty = Vec3::Dot(y, negEye);
	float tz = Vec3::Dot(z, negEye);

	Matrix view;
	view.m_value[0][0] = x.m_x;	view.m_value[1][0] = x.m_y;	view.m_value[2][0] = x.m_z;	view.m_value[3][0] = tx;
	view.m_value[0][1] = y.m_x;	view.m_value[1][1] = y.m_y;	view.m_value[2][1] = y.m_z;	view.m_value[3][1] = ty;
	view.m_value[0][2] = z.m_x;	view.m_value[1][2] = z.m_y;	view.m_value[2][2] = z.m_z;	view.m_value[3][2] = tz;
	view.m_value[0][3] = 0    ;	view.m_value[1][3] = 0;		view.m_value[2][3] = 0;		view.m_value[3][3] = 1;

	return view;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�t�H���g�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix::Matrix()
{

	float matrix[4][4] =
	{
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
	};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_value[i][j] = matrix[i][j];
		}
	}

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R�s�[�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix::Matrix(const Matrix& M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_value[i][j] = M.m_value[i][j];
		}
	}
}



//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Matrix::~Matrix()
{

}


/*--[�ȉ����Z�q�̃I�[�o�[���[�h]--*/

Matrix& Matrix::operator=(const Matrix& M)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->m_value[i][j] = M.m_value[i][j];
		}
	}

	return *this;
}


Matrix Matrix::operator+(const Matrix& M)
{
	Matrix m;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m.m_value[i][j] = this->m_value[i][j] + M.m_value[i][j];
		}
	}

	return m;

	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
}

Matrix Matrix::operator-(const Matrix& M)
{
	Matrix m;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m.m_value[i][j]=this->m_value[i][j] - M.m_value[i][j];
		}
	}
	return m;
}

Matrix Matrix::operator*(const Matrix& M)
{
	Matrix m;

	// �P�s�ڂ̌v�Z
	float x = this->m_value[0][0];
	float y = this->m_value[0][1];
	float z = this->m_value[0][2];
	float w = this->m_value[0][3];
	m.m_value[0][0] = (M.m_value[0][0] * x) + (M.m_value[1][0] * y) + (M.m_value[2][0] * z) + (M.m_value[3][0] * w);
	m.m_value[0][1] = (M.m_value[0][1] * x) + (M.m_value[1][1] * y) + (M.m_value[2][1] * z) + (M.m_value[3][1] * w);
	m.m_value[0][2] = (M.m_value[0][2] * x) + (M.m_value[1][2] * y) + (M.m_value[2][2] * z) + (M.m_value[3][2] * w);
	m.m_value[0][3] = (M.m_value[0][3] * x) + (M.m_value[1][3] * y) + (M.m_value[2][3] * z) + (M.m_value[3][3] * w);

	// �Q�s�ڂ̌v�Z
	x = this->m_value[1][0];
	y = this->m_value[1][1];
	z = this->m_value[1][2];
	w = this->m_value[1][3];
	m.m_value[1][0] = (M.m_value[0][0] * x) + (M.m_value[1][0] * y) + (M.m_value[2][0] * z) + (M.m_value[3][0] * w);
	m.m_value[1][1] = (M.m_value[0][1] * x) + (M.m_value[1][1] * y) + (M.m_value[2][1] * z) + (M.m_value[3][1] * w);
	m.m_value[1][2] = (M.m_value[0][2] * x) + (M.m_value[1][2] * y) + (M.m_value[2][2] * z) + (M.m_value[3][2] * w);
	m.m_value[1][3] = (M.m_value[0][3] * x) + (M.m_value[1][3] * y) + (M.m_value[2][3] * z) + (M.m_value[3][3] * w);

	// �R�s�ڂ̌v�Z
	x = this->m_value[2][0];
	y = this->m_value[2][1];
	z = this->m_value[2][2];
	w = this->m_value[2][3];
	m.m_value[2][0] = (M.m_value[0][0] * x) + (M.m_value[1][0] * y) + (M.m_value[2][0] * z) + (M.m_value[3][0] * w);
	m.m_value[2][1] = (M.m_value[0][1] * x) + (M.m_value[1][1] * y) + (M.m_value[2][1] * z) + (M.m_value[3][1] * w);
	m.m_value[2][2] = (M.m_value[0][2] * x) + (M.m_value[1][2] * y) + (M.m_value[2][2] * z) + (M.m_value[3][2] * w);
	m.m_value[2][3] = (M.m_value[0][3] * x) + (M.m_value[1][3] * y) + (M.m_value[2][3] * z) + (M.m_value[3][3] * w);

	// �S�s�ڂ̌v�Z
	x = this->m_value[3][0];
	y = this->m_value[3][1];
	z = this->m_value[3][2];
	w = this->m_value[3][3];
	m.m_value[3][0] = (M.m_value[0][0] * x) + (M.m_value[1][0] * y) + (M.m_value[2][0] * z) + (M.m_value[3][0] * w);
	m.m_value[3][1] = (M.m_value[0][1] * x) + (M.m_value[1][1] * y) + (M.m_value[2][1] * z) + (M.m_value[3][1] * w);
	m.m_value[3][2] = (M.m_value[0][2] * x) + (M.m_value[1][2] * y) + (M.m_value[2][2] * z) + (M.m_value[3][2] * w);
	m.m_value[3][3] = (M.m_value[0][3] * x) + (M.m_value[1][3] * y) + (M.m_value[2][3] * z) + (M.m_value[3][3] * w);

	return m;
}

Matrix Matrix::operator*(int num)
{
	Matrix m;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j  < 4; j ++)
		{
			m.m_value[i][j]=this->m_value[i][j] * num;
		}
	}

	return m;
}
