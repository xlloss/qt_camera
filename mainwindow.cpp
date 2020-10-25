#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QLabel>
#include <QCameraViewfinderSettings>
#include <QDebug>

#define CAM_W 320
#define CAM_H 240

#define CAM0_X 0
#define CAM0_Y 0

#define CAM1_W_OFF 10
#define CAM1_H_OFF 0
#define CAM1_X (CAM0_X + CAM_W ) + CAM1_W_OFF
#define CAM1_Y CAM0_Y + CAM1_H_OFF

#define CAM2_W_OFF 0
#define CAM2_H_OFF 10
#define CAM2_X CAM0_X
#define CAM2_Y (CAM1_Y + CAM_H) + CAM2_H_OFF

#define CAM3_W_OFF 0
#define CAM3_H_OFF 0
#define CAM3_X CAM1_X + CAM3_W_OFF
#define CAM3_Y CAM2_Y + CAM3_H_OFF

#define CAM0_DEV "/dev/video0"
#define CAM1_DEV "/dev/video1"
#define CAM2_DEV "/dev/video3"
#define CAM3_DEV "/dev/video4"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QByteArray> cam_dev_name_list;

    cam_view_f0 = new QCameraViewfinder(this);
    cam_view_f0->setGeometry(CAM0_X, CAM0_Y, CAM_W, CAM_H);

    cam_view_f1 = new QCameraViewfinder(this);
    cam_view_f1->setGeometry(CAM1_X, CAM1_Y, CAM_W, CAM_H);

    cam_view_f2 = new QCameraViewfinder(this);
    cam_view_f2->setGeometry(CAM2_X, CAM2_Y, CAM_W, CAM_H);

    cam_view_f3 = new QCameraViewfinder(this);
    cam_view_f3->setGeometry(CAM3_X, CAM3_Y, CAM_W, CAM_H);


    this->setGeometry(0, 0, 800, 600);
    //this->showFullScreen();
    cam_dev_name_list.append(CAM0_DEV);
    cam_dev_name_list.append(CAM1_DEV);
    cam_dev_name_list.append(CAM2_DEV);
    cam_dev_name_list.append(CAM3_DEV);

    setCamera(&cam_dev_name_list);
}


void MainWindow::setCamera(QList<QByteArray> *devname_list)
{
    qDebug() << "camera 0 device is :" << devname_list->at(0);
    qDebug() << "camera 1 device is :" << devname_list->at(1);
    qDebug() << "camera 2 device is :" << devname_list->at(2);
    qDebug() << "camera 3 device is :" << devname_list->at(3);

    QCameraViewfinderSettings view_settings;
    view_settings.setResolution(320, 240);

    cam0 = new QCamera(devname_list->at(0));
    //connect(camera, QOverload<QCamera::Error>::of(&QCamera::error), this, &Camera::displayCameraError);
    cam0->setViewfinder(cam_view_f0);
    cam0->setViewfinderSettings(view_settings);
    cam_view_f0->show();

    cam1 = new QCamera(devname_list->at(1));
    cam1->setViewfinder(cam_view_f1);
    cam1->setViewfinderSettings(view_settings);
    cam_view_f1->show();

    cam2 = new QCamera(devname_list->at(2));
    cam2->setViewfinder(cam_view_f2);
    cam2->setViewfinderSettings(view_settings);
    cam_view_f2->show();

    cam3 = new QCamera(devname_list->at(3));
    cam3->setViewfinder(cam_view_f3);
    cam3->setViewfinderSettings(view_settings);
    cam_view_f3->show();

    cam0->start();
    cam1->start();
    cam2->start();
    cam3->start();
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

    cam2->setViewfinder(cam_view_f2);
    cam_view_f2->show();
    cam2->start();

    cam3->setViewfinder(cam_view_f3);
    cam_view_f3->show();
    cam3->start();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete cam0;
    delete cam1;
    delete cam2;
    delete cam3;
    delete cam_view_f0;
    delete cam_view_f1;
    delete cam_view_f2;
    delete cam_view_f3;

}

