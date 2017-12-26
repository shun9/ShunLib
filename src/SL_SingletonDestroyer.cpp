//************************************************/
//* @file  :SingletonDestroyer.cpp
//* @brief :�V���O���g�����܂Ƃ߂ď����Ă����N���X
//* @date  :2017/12/21
//* @author:S.Katou
//************************************************/
#include <SL_SingletonDestroyer.h>
#include <SL_Singleton.h>

using namespace ShunLib;

//�폜����V���O���g���ꗗ
std::vector<ISingleton*> SingletonDestroyer::m_singletonList;

/// <summary>
/// �V���O���g���̒ǉ�
/// </summary>
void SingletonDestroyer::AddSingleton(ISingleton * s)
{
	//�ŏ��ɓ������Ƃ��ɗ̈���m�ۂ���
	if (m_singletonList.capacity() <= 0){
		m_singletonList.reserve(100);
	}

	//�ǉ�
	m_singletonList.push_back(s);
}

/// <summary>
/// �V���O���g���̍폜
/// </summary>
void SingletonDestroyer::DestoroySingleton()
{
	//�폜
	for (ISingleton*s : m_singletonList) {
		s->DestroyInstance();
	}

	//���X�g���N���A
	m_singletonList.clear();
}
