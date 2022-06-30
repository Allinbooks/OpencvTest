#include "myopencv.h"

/*   ��ʾͼƬ   */
void Chapter1::ShowImage() {
	// ����ͼƬ·��
	string path = "resources/test.png";
	// ��ͼ�����������������ΪMat���������д��
	Mat img = imread(path);
	// ��ʾͼƬ
	imshow("Image", img);

	// �����ӳ٣�����Ļ�����ʾͼ��������˳�(0�������ޣ���λ�Ǻ���)
	waitKey(0);
}

/*   ��ʾ��Ƶ   */
void Chapter1::ShowVideo() {

	string path = "resources/test_video.mp4";

	// ��ȡ��Ƶ֡
	VideoCapture cap(path);
	Mat img;

	// ͼ�����ʾ��Ҫ��ÿһ֡ͼ�񲶻���ʾ
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(20);
	}
}

/*   ��ʾ����ͷ��Ƶ   */
void Chapter1::ShowWebcam() {

	// ��ȡ��Ƶ֡
	VideoCapture cap(0);
	Mat img;

	// ͼ�����ʾ��Ҫ��ÿһ֡ͼ�񲶻���ʾ
	while (true) {
		cap.read(img);
		imshow("Image", img);
		waitKey(1);
	}
}
