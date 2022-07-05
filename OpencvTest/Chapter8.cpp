#include "myopencv.h"

void Chapter8::FaceDetection() {
	string path = "resources/test.png";
	Mat img = imread(path);

	// 添加训练好的模型级联文件
	CascadeClassifier faceCascade;
	faceCascade.load("resources/haarcascade_frontalface_default.xml");

	// 判断是否添加成功
	if (faceCascade.empty()) cout << "XML file not loaded" << endl;

	// 创建矩形的容器，用于标记识别出来的面部
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 10);
	}

	imshow("Image", img);
	waitKey(0);

}