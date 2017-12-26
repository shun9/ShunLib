//************************************************/
//* @file  :SingletonDestroyer.h
//* @brief :�V���O���g�����܂Ƃ߂ď����Ă����N���X
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
		//�폜����V���O���g���ꗗ
		static std::vector<ISingleton*> m_singletonList;

	public:
		//�V���O���g���̒ǉ�
		static void AddSingleton(ISingleton* s);

		//�V���O���g���̍폜
		static void DestoroySingleton();

	private:
		SingletonDestroyer() {}
		~SingletonDestroyer() {}
	};
}