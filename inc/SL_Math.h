//************************************************/
//* @file  :SL_Math.h
//* @brief :算術ライブラリをまとめたもの
//* @date  :2017/10/27
//* @author:S.Katou
//************************************************/
#pragma once

#include <SL_Vec2.h>
#include <SL_Vec3.h>
#include <SL_Vec4.h>
#include <SL_Matrix.h>
#include <SL_ConstantNumber.h>

namespace ShunLib
{
	/// <summary>
	/// 値を範囲内に制限する
	/// </summary>
	template <class T>
	T Clamp(T max, T min, T num) {
		T result = num;
		if (max < num) {
			result = max;
		}

		if (min > num) {
			result = min;
		}
		return result;
	}

	/// <summary>
	/// ２つの値のうち大きい方を返す
	/// </summary>
	template <class T>
	T Max(T num, T num2) {
		T result = num;
		if (num2 > num) {
			result = num2;
		}

		return result;
	}

	/// <summary>
	/// ２つの値のうち小さい方を返す
	/// </summary>
	template <class T>
	T Min(T num, T num2) {
		T result = num;
		if (num2 < num) {
			result = num2;
		}

		return result;
	}
}