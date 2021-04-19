#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cameraconnection.h"
#include "QThread"
#include "threshold.h"
#include "houghcircle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CameraConnection *camera;
    Threshold *thresh;
    HoughCircle *circleImage;
    QThread *thread_cam;
    QThread *thread_thresh;
    QThread *thread_circle;


private:
    Ui::MainWindow *ui;

signals:
    void getFrame();

public slots:
   void Paint(cv::Mat);
   void ThresholdPaint(cv::Mat);
   void CirclesPaint(cv::Mat);
private slots:
   void on_slider_valueChanged(int value);
};
#endif // MAINWINDOW_H
