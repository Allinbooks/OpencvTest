#include "myopencv.h"

void Chapter2::BaseFunction() {
	string path = "resources/test.png";
	Mat img = imread(path);

	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;
	Mat imgDilation;
	Mat imgErode;

	// 灰度转换,第二个变量用于存放转换后的图像
	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	// 高斯滤波,图像模糊
	GaussianBlur(img, imgBlur, Size(1, 1), 5, 0);
	
	// 图像边缘
	Canny(img, imgCanny, 50, 150);

	// 图像边缘膨胀
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilation, kernel);

	// 图像侵蚀
	erode(imgDilation, imgErode, kernel);
	
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image GaussianBlur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDilation);
	imshow("Image Erode", imgErode);

	waitKey(0);

}