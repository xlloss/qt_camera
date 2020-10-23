#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QDebug>

#define CAM_W 320
#define CAM_H 240

#define CAM1_X 0
#define CAM1_Y 0

#define CAM2_W_OFF 10
#define CAM2_X CAM1_X + CAM_W + CAM2_W_OFF
#define CAM2_Y CAM1_Y

#define CAM0_DEV "/dev/video0"
#define CAM1_DEV "/dev/video1"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QByteArray> cam_dev_name_list;

    cam_view_f0 = new QCameraViewfinder(this);
    cam_view_f0->setGeometry(CAM1_X, CAM1_Y, CAM_W, CAM_H);

    cam_view_f1 = new QCameraViewfinder(this);
    cam_view_f1->setGeometry(CAM2_X, CAM2_Y, CAM_W, CAM_H);

    cam_dev_name_list.append(CAM0_DEV);
    cam_dev_name_list.append(CAM1_DEV);

    setCamera(&cam_dev_name_list);
}


void MainWindow::setCamera(QList<QByteArray> *devname_list)
{
    qDebug() << "camera 0 device is :" << devname_list->at(0);
    qDebug() << "camera 1 device is :" << devname_list->at(1);

    cam0 = new QCamera(devname_list->at(0));
    //connect(camera, QOverload<QCamera::Error>::of(&QCamera::error), this, &Camera::displayCameraError);
    cam0->setViewfinder(cam_view_f0);
    cam_view_f0->show();

    cam1 = new QCamera(devname_list->at(1));
    cam1->setViewfinder(cam_view_f1);
    cam_view_f1->show();

    cam0->start();
    cam1->start();
}

void MainWindow::setCamera(QByteArray devicename)
{
    //delete cam0;
    qDebug() << "camera device is :" << devicename.data();


    //connect(camera, QOverload<QCamera::Error>::of(&QCamera::error), this, &Camera::displayCameraError);
    cam0->setViewfinder(cam_view_f0);
    cam_view_f0->show();
    cam0->start();

    cam1->setViewfinder(cam_view_f1);
    cam_view_f1->show();
    cam1->start();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete cam0;
    delete cam1;
    delete cam_view_f0;
    delete cam_view_f1;

}

