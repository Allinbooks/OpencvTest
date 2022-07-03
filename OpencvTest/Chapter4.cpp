#include "myopencv.h"

void Chapter4::DrawShape() {
	// 空白图像
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// 画一个圆
	// 图像，圆心，半径，颜色，线条宽度（FILLED表示充满）
	circle(img, Point(256, 256), 155, Scalar(255, 0, 0), FILLED);

	// 画一个矩形
	// 与circle类似，其中rec可以换成对脚的两个点，point类型
	Rect rec(100, 100, 30, 200);
	rectangle(img, rec, Scalar(255, 128, 128));

	// 画一条线
	line(img, Point(123, 326), Point(236, 64), Scalar(0, 25, 25), 3);

	imshow("Image", img);
	waitKey(0);
}

void Chapter4::PutTest() {
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	putText(img, "xiaoming", Point(123, 256), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 69, 255), 2);

	imshow("Image", img);
	waitKey(0);
}
