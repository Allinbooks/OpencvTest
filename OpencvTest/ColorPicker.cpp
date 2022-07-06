#pragma once
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
// face detection
#include <opencv2/objdetect.hpp>

#include <iostream>

using namespace std;
using namespace cv;

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

void main() {
	
	// string path = "resources/shapes.png";
	// Mat img = imread(path);
	VideoCapture cap(0);
	Mat img;
	Mat imgHSV;
	Mat Mask;

	// 灵活改变hmin等值
	namedWindow("Trackbars", WINDOW_AUTOSIZE);
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);


	while (true) {
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, Mask);

		cout << hmin << ", " << smin << ", " << vmin << ", " << hmax << ", " << smax << ", " << vmax << endl;

		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", Mask);

		cout << 
		waitKey(1);
	}
}