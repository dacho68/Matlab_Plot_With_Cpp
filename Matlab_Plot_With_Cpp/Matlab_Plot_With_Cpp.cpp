#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

// Make sure you have changed the following settings: 
// Include directory: 
//      C:\Program Files (x86)\MATLAB\R2009a\extern\include
// Lib directory: 
//      C:\Program Files (x86)\MATLAB\R2009a\extern\lib\win32\microsoft
// Linker input: 
//      libmx.lib libmat.lib libeng.lib

// Interface with Matlab
#ifdef _CHAR16T
#define CHAR16_T
#endif

#include "engine.h"

void main()
{
	const int N = 360;
	double x[N], y[N];
	for (int i=0; i<N; i++)
	{
		// we will draw a sine function
		x[i] = i;
		y[i] = sin( x[i] * 3.14 / 180 ); 
	}

	// open matlab engine
	Engine *ep = engOpen(NULL);
	if ( !ep )
	{
		cout << "Can't start Matlab engine!" <<endl;
		exit(1);
	}
	
	// The fundamental type underlying MATLAB data
	mxArray *xx = mxCreateDoubleMatrix(1, N, mxREAL); 
	mxArray *yy = mxCreateDoubleMatrix(1, N, mxREAL); 

	// copy data from c++ to matlab data
	memcpy( mxGetPr(xx), x, N * sizeof(double) ); 
	memcpy( mxGetPr(yy), y, N * sizeof(double) ); 

	// draw the plot
	engPutVariable( ep, "xx", xx ); 
	engPutVariable( ep, "yy", yy ); 
	engEvalString(ep, "plot(xx, yy); ");

	// release data
	mxDestroyArray(xx); 
	mxDestroyArray(yy); 

	system("pause");

	// close matlab window
	engClose(ep); 
}
