#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
// include directory: E:\Program Files\MATLAB\R2009a\extern\include
// include directory: C:\Program Files (x86)\MATLAB\R2009a\extern\include
// lib directory: E:\Program Files\MATLAB\R2009a\extern\lib\win32\microsoft
// lib directory: C:\Program Files (x86)\MATLAB\R2009a\extern\lib\win32\microsoft
// linker input: libmx.lib libmat.lib libeng.lib

// Interface with Matlab
#ifdef _CHAR16T
#define CHAR16_T
#endif

#include "engine.h"

void main()
{
	const int N = 50;
	double x[N],y[N];
	int j = 1;
	for (int i=0; i<N; i++)
	{
		x[i] = (i+1);
		y[i] = sin(x[i]) + j * log(x[i]);
		j *= -1;
	}

	Engine *ep;
	if (!(ep=engOpen(NULL)))
	{
		cout <<"Can't start Matlab engine!" <<endl;
		exit(1);
	}
	
	mxArray *xx = mxCreateDoubleMatrix(1,N, mxREAL); 
	mxArray *yy = mxCreateDoubleMatrix(1,N, mxREAL); 
	memcpy(mxGetPr(xx), x, N*sizeof(double)); 
	memcpy(mxGetPr(yy), y, N*sizeof(double)); 
	engPutVariable(ep, "xx",xx); 
	engPutVariable(ep, "yy",yy); 
	
	engEvalString(ep, "plot(xx, yy); ");
	mxDestroyArray(xx); 
	mxDestroyArray(yy); 

	cout <<"Press any key to exit!" <<endl;
	cin.get();
	engClose(ep); 
}
