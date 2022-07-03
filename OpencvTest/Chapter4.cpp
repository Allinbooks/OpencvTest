#include "myopencv.h"

void Chapter4::DrawShape() {
	// �հ�ͼ��
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	// ��һ��Բ
	// ͼ��Բ�ģ��뾶����ɫ��������ȣ�FILLED��ʾ������
	circle(img, Point(256, 256), 155, Scalar(255, 0, 0), FILLED);

	// ��һ������
	// ��circle���ƣ�����rec���Ի��ɶԽŵ������㣬point����
	Rect rec(100, 100, 30, 200);
	rectangle(img, rec, Scalar(255, 128, 128));

	// ��һ����
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
