//************************************************/
//* @file  :SL_Vec3.h
//* @brief :‚RŸŒ³ƒxƒNƒgƒ‹—p‚Ìƒ‰ƒbƒvƒNƒ‰ƒX
//* @date  :2017/11/14
//* @author:S.Katou
//************************************************/
#pragma once

namespace ShunLib
{
	class Matrix;

	class Vec3
	{
		/*--[Ã“I•Ï”]--*/
	public:
		static const Vec3 Zero;			// ‚O  ‚O  ‚O
		static const Vec3 One;			// ‚P  ‚P  ‚P
		static const Vec3 UnitX;		// ‚P  ‚O  ‚O
		static const Vec3 UnitY;		// ‚O  ‚P  ‚O
		static const Vec3 UnitZ;		// ‚O  ‚O  ‚P
		static const Vec3 Up;			// ‚O  ‚P  ‚O
		static const Vec3 Down;			// ‚O -‚P  ‚O
		static const Vec3 Right;		// ‚P  ‚O  ‚O
		static const Vec3 Left;			//-‚P  ‚O  ‚O
		static const Vec3 Forward;		// ‚O  ‚O -‚P
		static const Vec3 Backward;		// ‚O  ‚O  ‚P

	public:
		//³‹K‰»
		static Vec3 Normalize(const Vec3& V);

		//“àÏ
		static float Dot(const Vec3& V, const Vec3& V2);

		//ŠOÏ
		static Vec3 Cross(const Vec3& V, const Vec3& V2);

		//•âŠÔ
		static Vec3 Larp(const Vec3& start, const Vec3& end, float time,std::function<float(float)> v);

		//‰ñ“]
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

		//³‹K‰»
		Vec3 Normalize();

		//‘å‚«‚³‚ğ•Ô‚·
		float Length();

		/*--[‰‰Zq‚ÌƒI[ƒo[ƒ[ƒh]--*/
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


//‰‰Zq‚ÌƒI[ƒo[ƒ[ƒh
bool  operator==(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator+(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);
ShunLib::Vec3 operator-(const ShunLib::Vec3& V, const ShunLib::Vec3& V2);

ShunLib::Vec3 operator*(const ShunLib::Vec3& V, double num);
ShunLib::Vec3 operator*(const ShunLib::Vec3& V, float num);
ShunLib::Vec3 operator*(const ShunLib::Vec3& V, int num);

ShunLib::Vec3 operator/(const ShunLib::Vec3& V, double num);
ShunLib::Vec3 operator/(const ShunLib::Vec3& V, float num);
ShunLib::Vec3 operator/(const ShunLib::Vec3& V, int num);
