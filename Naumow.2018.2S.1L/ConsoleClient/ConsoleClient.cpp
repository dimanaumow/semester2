// ConsoleClient.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Matrixexplorer.h"
#include <iostream>


using namespace matrix; 
using namespace std;

int main()
{
	int size; 
	cin >> size; 
	int *arr = AllocateMemory(size); 
	InitArray(arr, size);
	DisplayArray(arr, size);
	std::cout << "\n\n"; 
	BubleSort(arr, size);
	FreeMemory(arr);
	cin >> size; 
    return 0;
}

