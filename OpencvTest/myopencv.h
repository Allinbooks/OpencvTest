#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

class Chapter1
{
public:

	/*   œ‘ æÕº∆¨   */
	void ShowImage();

	/*   œ‘ æ ”∆µ   */
	void ShowVideo();

	/*   œ‘ æ…„œÒÕ∑ ”∆µ   */
	void ShowWebcam();

};

class Chapter2
{
public:
	void BaseFunction();

private:

};

class Chapter3
{
public:
	void Resize();
	// ≤√ºÙ
	void Crop();
};

class Chapter4
{
public:
	void DrawShape();
	void PutTest();
};

class Chapter5
{
public:
	void WarpPerspective();
};




