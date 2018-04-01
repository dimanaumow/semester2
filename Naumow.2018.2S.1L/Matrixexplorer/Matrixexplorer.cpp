// Matrixexplorer.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "Matrixexplorer.h"

using namespace matrix;

Matrixexplorer_API int* matrix::AllocateMemory(int size)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}
	int* arr = new int[size]; 
	return arr; 
}

Matrixexplorer_API void matrix::InitArray(int * arr, int size)
{ 
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (arr == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}
	for(int* ptr = arr; ptr < arr + size; ptr++)
	{
		std::cin >> *ptr; 
	}
}

Matrixexplorer_API void matrix::DisplayArray(int * arr, int size)
{
	if (size <= 0)
	{
		throw std::out_of_range("Dimension of array must be more zero!");
	}

	if (arr == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}
	for (const int * ptr = arr; ptr < arr + size; ptr++)
	{
		std::cout << *ptr << " "; 
	}
}

Matrixexplorer_API int matrix::SearchMax(int *arr, int size)
{
	int imax = 0; 
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[imax])
			imax = i; 
	}
	return imax;
}

Matrixexplorer_API int matrix::SizeToArrayB(int * arr, int size)
{
	int max = SearchMax(arr, size);
	int sizeB = 0; 
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0 && arr[max] % arr[i] == 0 && i != (size - 1))
			sizeB++; 
	}
	return sizeB;
}



Matrixexplorer_API void matrix::InitArrayB(int* arr, int size, int* arrb, int sizeB)
{
	int sum = 0; 
	int max = SearchMax(arr, size);

	for (int i = 0; i < size; i++)
	{
		if(arr[i] != 0 && arr[max] % arr[i] == 0)
		{
			arrb[sum] = arr[i]; 
			sum++;
		}
	}
}


Matrixexplorer_API void matrix::PopElement(int *arr, int &size, int pos)
{
	for (int i = pos; i < (size - 1); i++)
	{
		arr[i] = arr[i + 1]; 
	}
	size--; 
}

Matrixexplorer_API void matrix::BubleSort(int *arr, int size)
{
	int sizeB = SizeToArrayB(arr, size);
	int *arrb = AllocateMemory(sizeB);
	InitArrayB(arr, size, arrb, sizeB);

	int max = SearchMax(arr, size);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != 0 && arr[max] % arr[i] == 0)
		{
			PopElement(arr, size, i); 
		}
	}

	for (int i = 0; i < sizeB - 1; i++)
	{
		bool change = false; 
		for (int j = 0; i < sizeB - j - 1; j++)
		{
			if (arrb[j] < arrb[j + 1])
			{
				int temp = arrb[j]; 
				arrb[j] = arrb[j + 1]; 
				arrb[j + 1] = temp; 
				change = true; 
			}
		}
		if (!change)
			break; 
	}
	DisplayArray(arr, size);
	std::cout << std::endl;
	DisplayArray(arrb, sizeB); 
	FreeMemory(arrb); 
}



Matrixexplorer_API void matrix::FreeMemory(int* const arr)
{
	if (arr == nullptr)
	{
		throw std::invalid_argument("Argument is null!");
	}

	delete[] arr; 
}



