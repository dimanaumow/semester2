#pragma once

#ifdef Matrixexplorer_EXPORTS
#define Matrixexplorer_API __declspec(dllexport) 
#else
#define Matrixexplorer_API __declspec(dllimport) 
#endif

namespace matrix
{
	Matrixexplorer_API int* AllocateMemory(int size);
	Matrixexplorer_API void InitArray(int* arr, int size);
	Matrixexplorer_API void DisplayArray(int* arr, int size);
	Matrixexplorer_API int  SearchMax(int* arr, int size);
	Matrixexplorer_API int  SizeToArrayB(int* arr, int size);
	Matrixexplorer_API void InitArrayB(int* arr, int size, int* arrb, int sizeB);
	Matrixexplorer_API void PopElement(int* arr,int &size, int pos);
	Matrixexplorer_API void BubleSort(int* arr, int n);
	Matrixexplorer_API void FreeMemory(int* const arr);
}