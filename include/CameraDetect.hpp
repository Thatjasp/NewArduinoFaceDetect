#pragma once 
#include <opencv2/opencv.hpp>
#include <opencv2/core/types.hpp> 
#include<vector>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using cv::Mat;
using cv::rectangle;
using rectVec = std::vector<cv::Rect>;
using Rect = cv::Rect;
using Point = cv::Point;
using cv::CascadeClassifier;
using cv::Scalar;

void display(Mat& frame); 

Mat detect(Mat& frame,CascadeClassifier& topLayer,
					CascadeClassifier& bottomLayer);

Rect cascadeDetect(Mat& copyFrame, CascadeClassifier& cascade);







