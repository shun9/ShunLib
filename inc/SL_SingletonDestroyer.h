//************************************************/
//* @file  :SingletonDestroyer.h
//* @brief :シングルトンをまとめて消してくれるクラス
//* @date  :2017/12/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <vector>


namespace ShunLib {
	class ISingleton;
	class SingletonDestroyer
	{
	private:
		//削除するシングルトン一覧
		static std::vector<ISingleton*> m_singletonList;

	public:
		//シングルトンの追加
		static void AddSingleton(ISingleton* s);

		//シングルトンの削除
		static void DestoroySingleton();

	private:
		SingletonDestroyer() {}
		~SingletonDestroyer() {}
	};
}