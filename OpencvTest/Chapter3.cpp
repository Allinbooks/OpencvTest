#include "myopencv.h"

void Chapter3::Resize() {
	string path = "resources/test.png";
	Mat img = imread(path);
	Mat imgResize;

	cout << img.size() << endl;
	// 三个参数的时候可以在size中设置resize的大小
	// 五个参数后两个分别为x，y的比例
	resize(img, imgResize, Size(), 0.9, 0.5);

	imshow("Image", img);
	imshow("Image Resize", imgResize);

	waitKey(0);
}

void Chapter3::Crop() {
	string path = "resources/test.png";
	Mat img = imread(path);
	Mat imgCrop;

	// 从点（100，100）开始，向右300个单位，向下250个单位
	// 截取是图像大小为 300 * 250
	Rect roi(100, 100, 300, 250);

	imgCrop = img(roi);
	cout << imgCrop.size() << endl;
	imshow("Image", img);
	imshow("Image Crop", imgCrop);

	waitKey(0);
}