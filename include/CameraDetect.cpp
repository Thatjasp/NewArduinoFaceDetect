#include "CameraDetect.hpp"


void display(Mat& frame){
	cv::imshow();

}

Mat detect(Mat& frame, CascadeClassifier& topLayer,
				CascadeClassifier& bottomLayer){
	Mat grayCopy;
	cv::cvtColor(grayCopy,frame,cv::COLOR_BGR2GRAY);
	cv::equalizeHist(grayCopy,grayCopy);
	Rect subRect = cascadeDetect(grayCopy,topLayer);
	Mat subFrame = grayCopy(subRect);
	Rect subRect2 = cascadeDetect(subFrame, bottomLayer); 
	rectangle(frame,subRect,Scalar(0,0,255),1,8,0);
	rectangle(frame,subRect,Scalar(0,0,255),1,8,0);
	return frame;
}

Rect cascadeDetect(Mat& copyFrame, 
		CascadeClassifier& cascade){
	rectVec top;
	Rect max;
	int maxSize = -1 , size;
	cascade.detectMultiScale(copyFrame,top);

	for (Rect faces: top) {
		size = faces.width * faces.height;
		if (size > maxSize){
			maxSize = size;
			max = faces;
		}
	}

	return max;
}

