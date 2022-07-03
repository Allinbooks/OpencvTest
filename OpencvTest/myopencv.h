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

	/*   显示图片   */
	void ShowImage();

	/*   显示视频   */
	void ShowVideo();

	/*   显示摄像头视频   */
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
	// 裁剪
	void Crop();


};





