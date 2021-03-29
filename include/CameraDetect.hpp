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
/***
 * Displays the Mat frame given
 * @param frame The frame that will be displayed
 */
void display(Mat& frame); 
/***
 * The frame will create a subframe depending
 * if topLayer classifer detects something in frame
 * if so then a subframe will be created around the detection
 * in which will be analyzed by the bottomLayer which will 
 * create a rectangle if anything is detected.
 */
Mat detect(Mat& frame,CascadeClassifier& topLayer,
					CascadeClassifier& bottomLayer);
/***
 * Will check if the classifier detects anything
 * inside of the copyFrame.
 */
Rect cascadeDetect(Mat& copyFrame, CascadeClassifier& cascade);







