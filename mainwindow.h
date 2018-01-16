#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <qdebug.h>
#include "clientrequests.h"
#include "buttonhoverwatcher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void HideRStateView();

    void HideR1StateView();

    void ShowR1StateView();

    void HideR2StateView();

    void ShowR2StateView();

    void HideR3StateView();

    void ShowR3StateView();

private slots:

    void on_R2StateGoBackButton_clicked();

    void on_R1StateLoginButton_clicked();

    void on_R2StateConfirmLoginButton_clicked();

    void on_R1StateRegisterButton_clicked();

    void on_R2StateConfirmRegistrationButton_clicked();

    void on_R3ChatRoomsButton_clicked();

    void on_R3ManagaFriendsButton_clicked();

    void on_R3ManagePostsButton_clicked();

    void on_R3UserSettingsButton_clicked();

    void on_R3LogoutButton_clicked();

    void on_TestAction01_triggered();

    void on_TestAction02_triggered();

private:
    Ui::MainWindow *ui;

    ButtonHoverWatcher * watcher;

    ClientRequests *client;

    bool logged = false;
};

#endif // MAINWINDOW_H
