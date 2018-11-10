#pragma once

#ifdef NN_DLL
#define NN_API __declspec(dllexport)
#else
#define NN_API __declspec(dllimport)
#endif // 
