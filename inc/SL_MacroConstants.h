//************************************************/
//* @file  :MacroConstants.h
//* @brief :����}�N���萔�܂Ƃ�
//* @date  :2017/05/10
//* @author:S.Katou
//************************************************/
#pragma once
	
//�|�C���^�[�����p
#define DELETE_POINTER(p)    if (p!=nullptr){delete p; p = nullptr;}
#define DELETE_ARRAY(p)      if (p!=nullptr){delete[] p; p = nullptr;}

#define SAFE_DELETE(p)       if (p!=nullptr){delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if (p!=nullptr){delete[] p; p = nullptr;}
#define SAFE_RELEASE(x)      if (x!=nullptr){x->Release(); x = nullptr;}

//�z���R���e�i�ɓ����Ă���|�C���^���폜
#define SAFE_DELETE_INSIDE(c) 	for (auto& v : c){ SAFE_DELETE(v);}