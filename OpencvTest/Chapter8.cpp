#include "myopencv.h"

void Chapter8::FaceDetection() {
	string path = "resources/test.png";
	Mat img = imread(path);

	// ���ѵ���õ�ģ�ͼ����ļ�
	CascadeClassifier faceCascade;
	faceCascade.load("resources/haarcascade_frontalface_default.xml");

	// �ж��Ƿ���ӳɹ�
	if (faceCascade.empty()) cout << "XML file not loaded" << endl;

	// �������ε����������ڱ��ʶ��������沿
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 10);
	}

	imshow("Image", img);
	waitKey(0);

}