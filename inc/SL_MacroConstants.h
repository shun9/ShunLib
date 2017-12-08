//************************************************/
//* @file  :MacroConstants.h
//* @brief :自作マクロ定数まとめ
//* @date  :2017/05/10
//* @author:S.Katou
//************************************************/
#pragma once
	
//ポインター消去用
#define DELETE_POINTER(p)    if (p!=nullptr){delete p; p = nullptr;}
#define DELETE_ARRAY(p)      if (p!=nullptr){delete[] p; p = nullptr;}

#define SAFE_DELETE(p)       if (p!=nullptr){delete p; p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if (p!=nullptr){delete[] p; p = nullptr;}
#define SAFE_RELEASE(x)      if (x!=nullptr){x->Release(); x = nullptr;}

//配列やコンテナに入っているポインタを削除
#define SAFE_DELETE_INSIDE(c) 	for (auto& v : c){ SAFE_DELETE(v);}