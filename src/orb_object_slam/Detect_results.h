#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>
#include <sstream>

namespace ORB_SLAM2
{
class detect_result
{
public:
    int classId;
    float confidence;
    cv::Rect_<float> box;
};
}//namespace ORB_SLAM2