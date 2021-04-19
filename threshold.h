#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "cameraconnection.h"

//https://docs.opencv.org/4.5.2/d7/d4d/tutorial_py_thresholding.html - информация о пороговых значениях.

class Threshold : public QObject
{
    Q_OBJECT
public:
    Threshold();    

signals:
    void setImage(cv::Mat);

public slots:
    void workThresholding(cv::Mat);

};

#endif // THRESHOLD_H
