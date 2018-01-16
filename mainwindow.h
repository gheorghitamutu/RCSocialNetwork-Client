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

    void HideR41StateView();
    void ShowR41StateView();

    void HideR51StateView();
    void ShowR51StateView();

    void HideR52StateView();
    void ShowR52StateView();

    void HideR53StateView();
    void ShowR53StateView();

    void HideR42StateView();
    void ShowR42StateView();

    void HideR55StateView();
    void ShowR55StateView();

    void HideR54StateView();
    void ShowR54StateView();

    void HideR56StateView();
    void ShowR56StateView();

    void HideR44StateView();
    void ShowR44StateView();

    void HideR593StateView();
    void ShowR593StateView();

    void HideLStateView();

    void HideL1StateView();
    void ShowL1StateView();

    void HideL2StateView();
    void ShowL2StateView();

    void DummyFunctionForPosts();

private slots:

    void on_R2StateGoBackButton_clicked();

    void on_R1StateLoginButton_clicked();

    void on_R2StateConfirmLoginButton_clicked();

    void on_R1StateRegisterButton_clicked();

    void on_R2StateConfirmRegistrationButton_clicked();

    void on_R3ChatRoomsButton_clicked();

    void on_R3ManageFriendsButton_clicked();

    void on_R3ManagePostsButton_clicked();

    void on_R3UserSettingsButton_clicked();

    void on_R3LogoutButton_clicked();

    void on_TestAction01_triggered();

    void on_TestAction02_triggered();

    void on_R3StateRefreshFeedButton_clicked();

    void on_R41CreateRoomButton_clicked();

    void on_R41AddUserToRoomButton_clicked();

    void on_R4XBackButton_clicked();

    void on_R41RoomsButton_clicked();

    void on_R1ExitButton_clicked();

    void on_R51CreateRoomButton_clicked();

    void on_R5XBackButton_clicked();

    void on_R52BackButton_clicked();

    void on_R53BackButton_clicked();

    void on_R53SendMessageButton_clicked();

    void on_R52Room01Button_clicked();

    void on_R42BackButton_clicked();

    void on_R42AddFriendButton_clicked();

    void on_R42ChangeFriendStatusButton_clicked();

    void on_R55BackButton_clicked();

    void on_R55AddFriendButton_clicked();

    void on_R54BackButton_clicked();

    void on_R54AddUserButton_clicked();

    void on_R56BackButton_clicked();

    void on_R56CloseFriendButton_clicked();

    void on_R56FriendButton_clicked();

    void on_R56DeleteFriendButton_clicked();

    void on_R43BackButton_clicked();
    
    void on_R44BackButton_clicked();

    void on_R44ChangeUserButton_clicked();

    void on_R593ChangeButton_clicked();

    void on_R593BackButton_clicked();

    void on_L1StatePost01Button_clicked();

    void on_L1StatePost02Button_clicked();

    void on_L1StatePost03Button_clicked();

    void on_L1StatePost04Button_clicked();

    void on_L1StatePost05Button_clicked();

    void on_L1StatePost06Button_clicked();

    void on_L1StatePost07Button_clicked();

    void on_L1StatePost08Button_clicked();

    void on_L1StatePost09Button_clicked();

    void on_L1StatePost10Button_clicked();

private:
    Ui::MainWindow *ui;

    ButtonHoverWatcher * watcher;

    ClientRequests *client;

    bool logged = false;
};

#endif // MAINWINDOW_H
