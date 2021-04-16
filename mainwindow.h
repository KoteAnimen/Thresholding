#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cameraconnection.h"
#include "QThread"

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
    QThread *thread_cam;

private:
    Ui::MainWindow *ui;

signals:
    void getFrame();

public slots:
   void Paint(cv::Mat);
};
#endif // MAINWINDOW_H
