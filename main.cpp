#include <iostream>
#include <opencv2/opencv.hpp>
#include "include/CameraDetect.hpp"
#include "include/Bluetooth.hpp"
using cv::VideoCapture;

int main(int argc, char** argv) {
	std::string path = argv[0];
	std::string facePath = path + 
		 "//data//haarcascade_frontalface_default.xml";
	std::string eyePath = path + 
		"//data//haarcascade_righteye_2splits.xml";
	CascadeClassifier face(facePath);
	CascadeClassifier eyes(eyePath);
	if (!face.empty() || !eyes.empty()) {
		std::cerr << "One of the Classifiers was not loaded"
			<< std::endl;
		return -1;
	}
	std::array<uint8_t,8> ar = {17,17,17,17,17,17,17,17};
	std::array<uint8_t,8> ar2 = {34,34,34,34,34,34,34,34};

	winrt::guid serviceGuid((uint32_t) 0x111111111,(uint16_t)0x1111,
			(uint16_t)0x1111,ar);
	winrt::guid charXGuid((uint32_t)0x22222222,(uint16_t)0x2222,
			(uint16_t)0x2222,ar2);
	winrt::guid charYGuid((uint32_t)0x111111111,(uint16_t)0x1111,(uint16_t)0x1111,ar2);
	BLEClient controller((uint64_t)0xd58d10fc1f39,serviceGuid,charXGuid);
	controller.addLocalChar(charYGuid);
	Mat frame;
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened()){
		std::cerr << "Video Capture was not able to be initialized"
			<< std::endl;
		return -1;
	}
	while(cv::waitKey() == -1) {
		cap >> frame;
		frame = detect(frame,face,eyes);
		display(frame);
	}
	
	return 0;
}


