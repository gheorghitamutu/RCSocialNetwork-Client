#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <qdebug.h>
#include "clientrequests.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void HideRightView();

    void HideFirstRightView();

    void HideSecondRightView();

    void ShowFirstRightView();

    void showSecondRightView();

private slots:

    void on_confirmLogin_button_clicked();

    void on_confirmRegistration_button_clicked();

    void on_goback_button_clicked();

    void on_login_button_clicked();

    void on_registerButton_clicked();

private:
    Ui::MainWindow *ui;

    ClientRequests *client;

    bool logged = false;
};

#endif // MAINWINDOW_H
