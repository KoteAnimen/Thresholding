#ifndef HOUGHCIRCLE_H
#define HOUGHCIRCLE_H

#include "cameraconnection.h"


class HoughCircle : public QObject
{
    Q_OBJECT
public:
    HoughCircle();
    int distantCircle = 2;
    int minRadius = 100;
    int maxRadius = 200;


public slots:
    void workHoughCircle(cv::Mat);

signals:
    void setCircleImage(cv::Mat);
};

#endif // HOUGHCIRCLE_H
