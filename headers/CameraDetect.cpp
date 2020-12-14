#include "CameraDetect.hpp"

void display(Rect x, Point point){
	

}

void detect(Mat& frame, CascadeClassifier& topLayer,
				CascadeClassifier& bottomLayer){
	Mat grayCopy;
	cv::cvtColor(grayCopy,frame,cv::COLOR_BGR2GRAY);
	cv::equalizeHist(grayCopy,grayCopy);
	Rect subRect = cascadeDetect(grayCopy,topLayer);
	Mat subFrame = grayCopy.submat(subRect);
	Rect subRect2 = cascadeDetect(subFrame, bottomLayer); 
	rectangle(frame, Point(subRec2 -> x,SubRect2 ->y ), 
				Point(subRec2 -> x + subRec2 -> width, subRec2 -> y + subRec2 -> height));
}

Rect cascadeDetect(Mat& copyFrame, 
		CascadeClassifier& cascade){
	rectVec top;
	Rect max;
	int maxSize = -1 , size;
	cascade.detectMultiScale(copyFrame,top);

	for (Rect faces: top) {
		size = faces -> width * faces -> height;
		if (size > maxSize){
			maxSize = size;
			max = faces;
		}
	}

	return max;
}

