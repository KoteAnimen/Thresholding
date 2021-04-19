#ifndef HOUGHCIRCLE_H
#define HOUGHCIRCLE_H

#include "cameraconnection.h"


class HoughCircle : public QObject
{
    Q_OBJECT
public:
    HoughCircle();

public slots:
    void workHoughCircle(cv::Mat);

signals:
    void setCircleImage(cv::Mat);
};

#endif // HOUGHCIRCLE_H
