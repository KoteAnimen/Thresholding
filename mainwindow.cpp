#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int metatype_id = qRegisterMetaType<cv::Mat>("cv::Mat");
    camera = new CameraConnection();
    thresh = new Threshold();
    thread_cam = new QThread();
    thread_thresh = new QThread();
    camera->moveToThread(thread_cam);
    thresh->moveToThread(thread_thresh);
    connect(camera, &CameraConnection::FrameReady, this, &MainWindow::Paint);
    connect(camera, &CameraConnection::FrameReady, thresh, &Threshold::workThresholding);
    connect(thresh, &Threshold::setImage, this, &MainWindow::ThresholdPaint);
    connect(this, &MainWindow::getFrame, camera, &CameraConnection::Grab);
    connect(thread_cam, &QThread::started, camera, &CameraConnection::Grab);
    connect(thread_thresh, &QThread::started, camera, &CameraConnection::Grab);
    thread_cam->start();
    thread_thresh->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Paint(cv::Mat src)
{
    QImage *CamImg = new QImage(src.data, src.cols, src.rows, src.step,QImage::Format_Grayscale8);
    ui->screen1->setPixmap(QPixmap::fromImage(*CamImg).scaled(ui->screen1->size()));
    ui->screen1->update();
    emit getFrame();
    delete CamImg;
}

void MainWindow::ThresholdPaint(cv::Mat src)
{
    QImage *CamImg = new QImage(src.data, src.cols, src.rows, src.step,QImage::Format_Grayscale8);
    ui->screen2->setPixmap(QPixmap::fromImage(*CamImg).scaled(ui->screen2->size()));
    ui->screen2->update();
    emit getFrame();
    delete CamImg;
}

