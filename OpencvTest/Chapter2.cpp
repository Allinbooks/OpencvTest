#include "myopencv.h"

void Chapter2::BaseFunction() {
	string path = "resources/test.png";
	Mat img = imread(path);

	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;
	Mat imgDilation;
	Mat imgErode;

	// �Ҷ�ת��,�ڶ����������ڴ��ת�����ͼ��
	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	// ��˹�˲�,ͼ��ģ��
	GaussianBlur(img, imgBlur, Size(1, 1), 5, 0);
	
	// ͼ���Ե
	Canny(img, imgCanny, 50, 150);

	// ͼ���Ե����
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilation, kernel);

	// ͼ����ʴ
	erode(imgDilation, imgErode, kernel);
	
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image GaussianBlur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDilation);
	imshow("Image Erode", imgErode);

	waitKey(0);

}