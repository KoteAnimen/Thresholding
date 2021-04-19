#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cameraconnection.h"
#include "QThread"
#include "threshold.h"

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
    QThread *thread_cam;
    QThread *thread_thresh;

private:
    Ui::MainWindow *ui;

signals:
    void getFrame();

public slots:
   void Paint(cv::Mat);
   void ThresholdPaint(cv::Mat);
};
#endif // MAINWINDOW_H
