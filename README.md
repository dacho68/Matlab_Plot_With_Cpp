Use Matlab frunction to draw a plot using C++
====================

This is a extremely easy demo showing you how to use Matlab function to draw a plot using c++. You will be able to visualize the plot without even opening Matlab window. It will just run in background and show you the plot you need. 

====================

Motivation of doing this: 
I am using OpenCV and C++ for most of my vision projects because of running speed. However, I really want to utilize Matlab to visualize some of my results, e.g. the histogram of an image. This piece of code become very handy to use because I cam just call Matlab functions from within my C++ project. 

====================

This project is build on the following platform: 
 - Microsoft Visual Studio 2010
 - Matlab 2009b

====================

Configuration:

As an example, I am intalled a 32-bit Matlab under location 'C:\Program Files (x86)'.

In Visual Studio, go to <strong>Project > Configuration Properties > C/C++ > General Addtional Include Directories</strong> and add the following: 

    C:\Program Files (x86)\MATLAB\R2009a\extern\include
    
Go to <strong>Project > Configuration Properties > C/C++ > General > Addtional Library Directories</strong> and add the following:

    C:\Program Files (x86)\MATLAB\R2009a\extern\lib\win32\microsoft
    
Go to <strong>Project > Configuration Properties > C/C++ > Input > Addtional Dependencies</strong> and add the following static libraries:

    libmx.lib libmat.lib libeng.lib
