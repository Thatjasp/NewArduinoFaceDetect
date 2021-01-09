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
		// detect(frame,face,eyes);
	}
	
	return 0;
}
winrt::guid createGuid(){
	winrt::guid guid;

	return guid;
}

