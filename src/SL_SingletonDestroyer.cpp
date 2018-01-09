//************************************************/
//* @file  :SingletonDestroyer.cpp
//* @brief :シングルトンをまとめて消してくれるクラス
//* @date  :2017/12/21
//* @author:S.Katou
//************************************************/
#include <SL_SingletonDestroyer.h>
#include <SL_Singleton.h>
#include <algorithm>

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
/// シングルトンを除外
/// </summary>
void ShunLib::SingletonDestroyer::RemoveSingleton(ISingleton * s)
{
	auto singleton = std::find(m_singletonList.begin(), m_singletonList.end(), s);

	if (singleton != m_singletonList.end()){
		m_singletonList.erase(singleton);
	}
}

/// <summary>
/// シングルトンの削除
/// </summary>
void SingletonDestroyer::DestoroySingleton()
{
	//削除
	for (int i = 0; i < (int)m_singletonList.size(); i++)
	{
		m_singletonList[i]->DestroyInstance();
	}

	//リストをクリア
	m_singletonList.clear();
}
