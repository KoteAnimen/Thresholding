#include "houghcircle.h"

HoughCircle::HoughCircle()
{
    int metatype_id = qRegisterMetaType<cv::Mat>("cv::Mat");
}

void HoughCircle::workHoughCircle(cv::Mat src)
{

    cv::Mat dst=src.clone();

    cv::medianBlur(dst, dst, 5);

    vector<cv::Vec3f> circles;
    cv::HoughCircles(dst, circles, cv::HOUGH_GRADIENT, 1, dst.rows/16, 100, 30, 200, 300);

    for( size_t i = 0; i < circles.size(); i++ )
        {
            cv::Vec3i c = circles[i];
            cv::Point center =  cv::Point(c[0], c[1]);
            // circle outline
            int radius = c[2];
            cv::circle( dst, center, radius, cv::Scalar(255,0,255), 3, cv::LINE_AA);
        }
    emit setCircleImage(dst);
}
