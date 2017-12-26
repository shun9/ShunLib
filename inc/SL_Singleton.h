//************************************************/
//* @file  :Singleton.h
//* @brief :シングルトン
//* @date  :2017/06/26
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_MacroConstants.h>
#include <SL_SingletonDestroyer.h>

namespace ShunLib
{
	class ISingleton
	{
	public:
		//実体削除
		virtual void DestroyInstance() = 0;

	protected:
		//派生クラス以外から作成できないようにする
		ISingleton() { SingletonDestroyer::AddSingleton(this); }
		virtual ~ISingleton() {}

		//コピーできないように
		ISingleton(const ISingleton& single) = delete;

		//代入できないように
		const ISingleton& operator = (const ISingleton& single) = delete;
	};

	template<class T>
	class Singleton : public ISingleton
	{
	private:
		//実体
		static T* m_instance;

	public:
		/// <summary>
		/// 実体の取得
		/// </summary>
		/// <returns>実体</returns>
		static T* GetInstance() {
			//無ければ作成
			if (m_instance == nullptr) {
				m_instance = new T();
			}
			return m_instance;
		}


		/// /// <summary>
		/// 実体の破棄
		/// </summary>
		static void Destroy() {
			DELETE_POINTER(m_instance);
		}

	public:
		//実体削除
		virtual void DestroyInstance() {
			DELETE_POINTER(m_instance);
		}

	protected:
		//派生クラス以外から作成できないようにする
		Singleton() {}
		virtual ~Singleton() {}
	};

	template<class T>
	T* ShunLib::Singleton<T>::m_instance = nullptr;
}
