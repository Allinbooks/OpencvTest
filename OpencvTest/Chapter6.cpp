#include "myopencv.h"

int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

void Chapter6::ColorDetection() {
	//string path = "resources/lambo.png";
	string path = "resources/shapes.png";
	Mat img = imread(path);
	Mat imgHSV;
	Mat Mask;

	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	// 灵活改变hmin等值
	namedWindow("Trackbars");
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);


	while (true) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHSV, lower, upper, Mask);


		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", Mask);
		waitKey(1);
	}
}