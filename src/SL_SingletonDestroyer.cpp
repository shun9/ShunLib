//************************************************/
//* @file  :SingletonDestroyer.cpp
//* @brief :シングルトンをまとめて消してくれるクラス
//* @date  :2017/12/21
//* @author:S.Katou
//************************************************/
#include <SL_SingletonDestroyer.h>
#include <SL_Singleton.h>

using namespace ShunLib;

//削除するシングルトン一覧
std::vector<ISingleton*> SingletonDestroyer::m_singletonList;

/// <summary>
/// シングルトンの追加
/// </summary>
void SingletonDestroyer::AddSingleton(ISingleton * s)
{
	//最初に入ったときに領域を確保する
	if (m_singletonList.capacity() <= 0){
		m_singletonList.reserve(100);
	}

	//追加
	m_singletonList.push_back(s);
}

/// <summary>
/// シングルトンの削除
/// </summary>
void SingletonDestroyer::DestoroySingleton()
{
	//削除
	for (ISingleton*s : m_singletonList) {
		s->DestroyInstance();
	}

	//リストをクリア
	m_singletonList.clear();
}
