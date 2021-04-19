#include "threshold.h"

Threshold::Threshold()
{
   int metatype_id = qRegisterMetaType<cv::Mat>("cv::Mat");
}

void Threshold::workThresholding(cv::Mat src)
{
    cv::Mat threshImage;
    cv::Mat blur;
    cv::GaussianBlur(src, blur, {5,5}, 0);
    cv::threshold(blur, threshImage,0,255,cv::THRESH_BINARY+cv::THRESH_OTSU);
    emit setImage(threshImage);
}
