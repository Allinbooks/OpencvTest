#include "myopencv.h"

void Chapter3::Resize() {
	string path = "resources/test.png";
	Mat img = imread(path);
	Mat imgResize;

	cout << img.size() << endl;
	// ����������ʱ�������size������resize�Ĵ�С
	// ��������������ֱ�Ϊx��y�ı���
	resize(img, imgResize, Size(), 0.9, 0.5);

	imshow("Image", img);
	imshow("Image Resize", imgResize);

	waitKey(0);
}

void Chapter3::Crop() {
	string path = "resources/test.png";
	Mat img = imread(path);
	Mat imgCrop;

	// �ӵ㣨100��100����ʼ������300����λ������250����λ
	// ��ȡ��ͼ���СΪ 300 * 250
	Rect roi(100, 100, 300, 250);

	imgCrop = img(roi);
	cout << imgCrop.size() << endl;
	imshow("Image", img);
	imshow("Image Crop", imgCrop);

	waitKey(0);
}