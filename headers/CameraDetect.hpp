#pragma once 
#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp> 
#include<vector>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>

using cv::Mat;
using cv::rectangle;
using rectVec = std::vector<cv::Rect>;
using Rect = cv::Rect;
using Point = cv::Point;
using cv::CascadeClassifier;

void display(Rect& x, Point& point); 

Point detect(Mat& frame,CascadeClassifier& topLayer,
					CascadeClassifier& bottomLayer);

Rect cascadeDetect(rectVec& top, CascadeClassifier& cascade);







