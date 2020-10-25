#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraViewfinder>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setCamera(QByteArray devicename);
    void setCamera(QList<QByteArray> *devname_list);

private:
    Ui::MainWindow *ui;
    class QCamera *cam0, *cam1, *cam2, *cam3;
    QCameraViewfinder *cam_view_f0, *cam_view_f1, *cam_view_f2, *cam_view_f3;
};
#endif // MAINWINDOW_H
