#pragma once

#ifdef MATRIXEXPLORER_EXPORTS
#define MATRIXEXPLORER_API __declspec(dllexport) 
#else
#define MATRIXEXPLORER_API __declspec(dllimport) 
#endif
namespace matrix
{
	MATRIXEXPLORER_API void Filing(int n, int[]);
}