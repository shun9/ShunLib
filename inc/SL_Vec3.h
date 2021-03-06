//************************************************/
//* @file  :SL_Vec3.h
//* @brief :３次元ベクトル用のラップクラス
//* @date  :2017/11/14
//* @author:S.Katou
//************************************************/
#pragma once
#include <functional>

namespace ShunLib
{
	class Matrix;

	class Vec3
	{
		/*--[静的変数]--*/
	public:
		static const Vec3 Zero;			// ０  ０  ０
		static const Vec3 One;			// １  １  １
		static const Vec3 UnitX;		// １  ０  ０
		static const Vec3 UnitY;		// ０  １  ０
		static const Vec3 UnitZ;		// ０  ０  １
		static const Vec3 Up;			// ０  １  ０
		static const Vec3 Down;			// ０ -１  ０
		static const Vec3 Right;		// １  ０  ０
		static const Vec3 Left;			//-１  ０  ０
		static const Vec3 Forward;		// ０  ０ -１
		static const Vec3 Backward;		// ０  ０  １

	public:
		//正規化
		static Vec3 Normalize(const Vec3& V);

		//内積
		static float Dot(const Vec3& V, const Vec3& V2);

		//外積
		static Vec3 Cross(const Vec3& V, const Vec3& V2);

		//補間
		static Vec3 Larp(const Vec3& start, const Vec3& end, float time,std::function<float(float)> v);

		//回転
		static Vec3 Rotation(const Vec3& V, const Matrix& rot);

		//2つのベクトルのなす角を返す
		static float Vec3::Degree(const Vec3 & V, const Vec3 & V2);
		
		//2つのベクトルの軸ごとのなす角を返す
		static Vec3 Vec3::DegreeEachAxis(const Vec3 & V, const Vec3 & V2);
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

		//正規化
		Vec3 Normalize();

		//大きさを返す
		float Length()const;

		/*--[演算子のオーバーロード]--*/
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


//演算子のオーバーロード
bool  operator==(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator+(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator-(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);

ShunLib::Vec3 operator*(const ShunLib::Vec3& V, double num);
ShunLib::Vec3 operator*(const ShunLib::Vec3& V, float num);
ShunLib::Vec3 operator*(const ShunLib::Vec3& V, int num);

ShunLib::Vec3 operator/(const ShunLib::Vec3& V, double num);
ShunLib::Vec3 operator/(const ShunLib::Vec3& V, float num);
ShunLib::Vec3 operator/(const ShunLib::Vec3& V, int num);
