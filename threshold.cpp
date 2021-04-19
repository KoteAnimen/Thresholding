#include "threshold.h"

Threshold::Threshold()
{
   int metatype_id = qRegisterMetaType<cv::Mat>("cv::Mat");
}

void Threshold::workThresholding(cv::Mat src)
{
    cv::Mat threshImage;
    cv::adaptiveThreshold(src, threshImage, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);
    emit setImage(threshImage);
}
