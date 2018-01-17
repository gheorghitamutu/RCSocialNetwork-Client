#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = new ClientRequests;

    watcher = new ButtonHoverWatcher(this);

    ui->L1StatePost01Button->installEventFilter(watcher);
    ui->L1StatePost02Button->installEventFilter(watcher);
    ui->L1StatePost03Button->installEventFilter(watcher);
    ui->L1StatePost04Button->installEventFilter(watcher);
    ui->L1StatePost05Button->installEventFilter(watcher);
    ui->L1StatePost06Button->installEventFilter(watcher);
    ui->L1StatePost07Button->installEventFilter(watcher);
    ui->L1StatePost08Button->installEventFilter(watcher);
    ui->L1StatePost09Button->installEventFilter(watcher);
    ui->L1StatePost10Button->installEventFilter(watcher);

    ShowR1StateView();
    ShowL1StateView();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::HideRStateView()
{
    ui->RStateVerticalLayoutMain->setEnabled(false);
    ui->R52Widget->hide();
    ui->R53Widget->hide();
    HideR1StateView();
    HideR2StateView();
    HideR3StateView();
    HideR41StateView();
    HideR51StateView();
    HideR42StateView();
    HideR51StateView();
    HideR55StateView();
    HideR54StateView();
    HideR56StateView();
    HideR44StateView();
    HideR593StateView();
}

void MainWindow::HideR1StateView()
{
    ui->R1StateRegisterButton->hide();
    ui->R1StateLoginButton->hide();
    ui->R1ExitButton->hide();
}

void MainWindow::HideR2StateView()
{
    ui->R2StateEmailText->hide();
    ui->R2StatePassText->hide();
    ui->R2StateConfirmLoginButton->hide();
    ui->R2StateConfirmRegistrationButton->hide();
    ui->R2StateGoBackButton->hide();
}

void MainWindow::ShowR1StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R1StateRegisterButton->show();
    ui->R1StateLoginButton->show();
    ui->R1ExitButton->show();
}

void MainWindow::ShowR2StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R2StateEmailText->show();
    ui->R2StatePassText->show();
    ui->R2StateGoBackButton->show();
}

void MainWindow::HideR3StateView()
{
    ui->R3ChatRoomsButton->hide();
    ui->R3LogoutButton->hide();
    ui->R3ManageFriendsButton->hide();
    ui->R3ManagePostsButton->hide();
    ui->R3UserSettingsButton->hide();
    ui->R3StateRefreshFeedButton->hide();
}

void MainWindow::ShowR3StateView()
{
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R3ChatRoomsButton->show();
    ui->R3LogoutButton->show();
    ui->R3ManageFriendsButton->show();
    ui->R3ManagePostsButton->show();
    ui->R3UserSettingsButton->show();
    ui->R3StateRefreshFeedButton->show();
}

void MainWindow::HideR41StateView()
{
    ui->R41AddUserToRoomButton->hide();
    ui->R41CreateRoomButton->hide();
    ui->R41RoomsButton->hide();
    ui->R4XBackButton->hide();
}

void MainWindow::ShowR41StateView()
{
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R41AddUserToRoomButton->show();
    ui->R41CreateRoomButton->show();
    ui->R41RoomsButton->show();
    ui->R4XBackButton->show();
}

void MainWindow::HideR51StateView()
{
    ui->R5XBackButton->hide();
    ui->R51CreateRoomButton->hide();
    ui->R51RoomText->hide();
    ui->R51RoomText->clear();
}

void MainWindow::ShowR51StateView()
{
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R5XBackButton->show();
    ui->R51CreateRoomButton->show();
    ui->R51RoomText->show();
}

void MainWindow::HideR52StateView()
{
    ui->R52Widget->hide();
}

void MainWindow::ShowR52StateView()
{
    // DUMMY SHOW FUNCTION
    HideRStateView();
    ui->R52Widget->show();
}

void MainWindow::HideR53StateView()
{
    ui->R53Widget->hide();
    ui->R53MessagesLabel->clear();
}

void MainWindow::ShowR53StateView()
{
    // DUMMY SHOW FUNCTION
    HideRStateView();
    ui->R53Widget->show();
}

void MainWindow::HideR42StateView()
{
    ui->R42AddFriendButton->hide();
    ui->R42ChangeFriendStatusButton->hide();
    ui->R42BackButton->hide();
}

void MainWindow::ShowR42StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R42AddFriendButton->show();
    ui->R42ChangeFriendStatusButton->show();
    ui->R42BackButton->show();
}

void MainWindow::HideR55StateView()
{
    ui->R55AddFriendButton->hide();
    ui->R55BackButton->hide();
    ui->R55EmailText->clear();
    ui->R55EmailText->hide();
}

void MainWindow::ShowR55StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R55AddFriendButton->show();
    ui->R55BackButton->show();
    ui->R55EmailText->show();
}

void MainWindow::HideR54StateView()
{
    ui->R54AddUserButton->hide();
    ui->R54BackButton->hide();
    ui->R54EmailText->clear();
    ui->R54EmailText->hide();
}

void MainWindow::ShowR54StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R54AddUserButton->show();
    ui->R54BackButton->show();
    ui->R54EmailText->show();
}

void MainWindow::HideR56StateView()
{
    ui->R56BackButton->hide();
    ui->R56CloseFriendButton->hide();
    ui->R56DeleteFriendButton->hide();
    ui->R56EmailText->clear();
    ui->R56EmailText->hide();
    ui->R56FriendButton->hide();
}

void MainWindow::ShowR56StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R56BackButton->show();
    ui->R56CloseFriendButton->show();
    ui->R56DeleteFriendButton->show();
    ui->R56EmailText->show();
    ui->R56FriendButton->show();
}

void MainWindow::HideR44StateView()
{
    ui->R44BackButton->hide();
    ui->R44ChangeUserButton->hide();
}

void MainWindow::ShowR44StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R44BackButton->show();
    ui->R44ChangeUserButton->show();
}

void MainWindow::HideR593StateView()
{
    ui->R593BackButton->hide();
    ui->R593ChangeButton->hide();
    ui->R593NameText->clear();
    ui->R593NameText->hide();
}

void MainWindow::ShowR593StateView()
{
    HideRStateView();
    ui->RStateVerticalLayoutMain->setEnabled(true);
    ui->R593BackButton->show();
    ui->R593ChangeButton->show();
    ui->R593NameText->show();
}

void MainWindow::HideLStateView()
{
    HideL1StateView();
    HideL2StateView();
}

void MainWindow::HideL1StateView()
{
    ui->L1StatePost01Button->hide();
    ui->L1StatePost02Button->hide();
    ui->L1StatePost03Button->hide();
    ui->L1StatePost04Button->hide();
    ui->L1StatePost05Button->hide();
    ui->L1StatePost06Button->hide();
    ui->L1StatePost07Button->hide();
    ui->L1StatePost08Button->hide();
    ui->L1StatePost09Button->hide();
    ui->L1StatePost10Button->hide();
}

void MainWindow::ShowL1StateView()
{
    ui->L1StatePost01Button->show();
    ui->L1StatePost02Button->show();
    ui->L1StatePost03Button->show();
    ui->L1StatePost04Button->show();
    ui->L1StatePost05Button->show();
    ui->L1StatePost06Button->show();
    ui->L1StatePost07Button->show();
    ui->L1StatePost08Button->show();
    ui->L1StatePost09Button->show();
    ui->L1StatePost10Button->show();
}

void MainWindow::HideL2StateView()
{
    ui->L2BackButton->hide();
    ui->L2PostButton->hide();
    ui->L2PrivatePostButton->hide();
    ui->L2PostText->hide();
    ui->L2PostText->clear();
}

void MainWindow::ShowL2StateView()
{
    HideLStateView();
    ui->L2PrivatePostButton->show();
    ui->L2BackButton->show();
    ui->L2PostButton->show();
    ui->L2PostText->show();
}

void MainWindow::DummyFunctionForPosts()
{
    if(this->logged)
    {
        QMessageBox::information(this, tr("Coming Soon"), tr("Feature Coming Soon!") );
    }
    else
    {
        QMessageBox::information(this, tr("Access Denied"), tr("Please login in order to see more details about this post!") );
    }
}

void MainWindow::on_R2StateConfirmLoginButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = LOGIN;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->R2StateEmailText->text().toLatin1().data()));
    strcat(temp, ",");
    strcat(temp, (char*)(ui->R2StatePassText->text().toLatin1().data()));

    this->logged = client->ParseActions(code_request, temp);

    if(logged)
    {
        // show state 3
        ui->R2StateEmailText->clear();
        ui->R2StatePassText->clear();
        HideRStateView();
        ShowR3StateView();
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Error"), tr("Wrong info!") );

    }

    delete temp;
}

void MainWindow::on_R2StateConfirmRegistrationButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = REGISTER;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->R2StateEmailText->text().toLatin1().data()));
    strcat(temp, ",");
    strcat(temp, (char*)(ui->R2StatePassText->text().toLatin1().data()));

    if(client->ParseActions(code_request, temp))
    {
        ui->R2StateEmailText->clear();
        ui->R2StatePassText->clear();
        ShowR1StateView();
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Error"), tr("This email address exists!") );
    }


    delete temp;
}

void MainWindow::on_R2StateGoBackButton_clicked()
{
    ui->R2StateEmailText->clear();
    ui->R2StatePassText->clear();
    ShowR1StateView();
}

void MainWindow::on_R1StateLoginButton_clicked()
{
    if(!client->GetConnectionStatus())
    {
        if(!client->ConnectToServer()) // try again connecting
        {
            // error message appears
            QMessageBox::information(this, tr("Error"), tr("Can't connect to server!") );
            return;
        }
    }
    ShowR2StateView();
    ui->R2StateConfirmLoginButton->show();
}

void MainWindow::on_R1StateRegisterButton_clicked()
{
    if(!client->GetConnectionStatus())
    {
        if(!client->ConnectToServer()) // try again connecting
        {
            // error message appears
            QMessageBox::information(this, tr("Error"), tr("Can't connect to server!") );
            return;
        }
    }
    ShowR2StateView();
    ui->R2StateConfirmRegistrationButton->show();
}

void MainWindow::on_R3ChatRoomsButton_clicked()
{
    HideR3StateView();
    ShowR41StateView();
}

void MainWindow::on_R3ManageFriendsButton_clicked()
{
    HideRStateView();
    ShowR42StateView();
}

void MainWindow::on_R3ManagePostsButton_clicked()
{
    HideL1StateView();
    ShowL2StateView();
}

void MainWindow::on_R3UserSettingsButton_clicked()
{
    HideRStateView();
    ShowR44StateView();
}

void MainWindow::on_R3LogoutButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = LOGOUT;
    memcpy(temp, &code_request, sizeof(int));

    this->logged = !client->ParseActions(code_request, temp);

    if(!logged)
    {
        // show state 1
        HideRStateView();
        ShowR1StateView();
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Error"), tr("Logout error!") );

    }

    delete temp;
}

void MainWindow::on_TestAction01_triggered()
{
    QMessageBox::information(this, tr("TestAction01"), tr("Example TestAction01!") );
}

void MainWindow::on_TestAction02_triggered()
{
    QMessageBox::information(this, tr("TestAction02"), tr("Example TestAction02!") );
}

void MainWindow::on_R3StateRefreshFeedButton_clicked()
{
    HideLStateView();
    ShowL1StateView();
    QMessageBox::information(this, tr("News Feed"), tr("Feeds Refreshed!") );
}

void MainWindow::on_R41CreateRoomButton_clicked()
{
    HideRStateView();
    ShowR51StateView();
}

void MainWindow::on_R41AddUserToRoomButton_clicked()
{
    HideRStateView();
    ShowR54StateView();
}

void MainWindow::on_R4XBackButton_clicked()
{
    HideRStateView();
    ShowR3StateView();
}

void MainWindow::on_R41RoomsButton_clicked()
{
    ShowR52StateView();
}

void MainWindow::on_R1ExitButton_clicked()
{
    exit(1);
}

void MainWindow::on_R51CreateRoomButton_clicked()
{
    HideRStateView();
    ShowR51StateView();
}

void MainWindow::on_R5XBackButton_clicked()
{
    HideRStateView();
    ShowR41StateView();
}

void MainWindow::on_R52BackButton_clicked()
{
    on_R5XBackButton_clicked();
}

void MainWindow::on_R53BackButton_clicked()
{
    HideRStateView();
    ShowR52StateView();
}

void MainWindow::on_R53SendMessageButton_clicked()
{

}

void MainWindow::on_R52Room01Button_clicked()
{
    HideRStateView();
    ShowR53StateView();
}

void MainWindow::on_R42BackButton_clicked()
{
    on_R4XBackButton_clicked();
}

void MainWindow::on_R42AddFriendButton_clicked()
{
    HideRStateView();
    ShowR55StateView();
}

void MainWindow::on_R42ChangeFriendStatusButton_clicked()
{
    HideRStateView();
    ShowR56StateView();
}

void MainWindow::on_R55BackButton_clicked()
{
    ui->R55EmailText->clear();
    HideRStateView();
    ShowR42StateView();
}

void MainWindow::on_R55AddFriendButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = FRIEND;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->R55EmailText->text().toLatin1().data()));
    strcat(temp, "||0"); // friend

    if(client->ParseActions(code_request, temp))
    {
        ui->R55EmailText->clear();
        QMessageBox::information(this, tr("Adding friend"), tr("Friend Added!") );
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Adding friend"), tr("There's no such email address!") );

    }

    delete temp;
}

void MainWindow::on_R54BackButton_clicked()
{
    on_R5XBackButton_clicked();
}

void MainWindow::on_R54AddUserButton_clicked()
{
    if(true) // obviously not, dummy bool
    {
        ui->R54EmailText->clear();
        QMessageBox::information(this, tr("Adding user"), tr("User Added!") );
    }
    else
    {
        QMessageBox::information(this, tr("Adding user"), tr("There's no such email address!") );
    }
}

void MainWindow::on_R56BackButton_clicked()
{
    ui->R56EmailText->clear();
    HideRStateView();
    ShowR42StateView();
}

void MainWindow::on_R56CloseFriendButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = FRIEND;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->R56EmailText->text().toLatin1().data()));
    strcat(temp, "||11"); // friend

    if(client->ParseActions(code_request, temp))
    {
        ui->R56EmailText->clear();
        QMessageBox::information(this, tr("Adding friend"), tr("Friend Added!") );
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Adding friend"), tr("There's no such email address!") );

    }

    delete temp;
}

void MainWindow::on_R56FriendButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = FRIEND;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->R56EmailText->text().toLatin1().data()));
    strcat(temp, "||10"); // friend

    if(client->ParseActions(code_request, temp))
    {
        ui->R56EmailText->clear();
        QMessageBox::information(this, tr("Adding friend"), tr("Friend Added!") );
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Adding friend"), tr("There's no such email address!") );

    }

    delete temp;
}

void MainWindow::on_R56DeleteFriendButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = FRIEND;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->R56EmailText->text().toLatin1().data()));
    strcat(temp, "||2"); // friend

    if(client->ParseActions(code_request, temp))
    {
        ui->R56EmailText->clear();
        QMessageBox::information(this, tr("Adding friend"), tr("Friend Added!") );
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Adding friend"), tr("There's no such email address!") );

    }

    delete temp;
}

void MainWindow::on_R44BackButton_clicked()
{
    on_R4XBackButton_clicked();
}

void MainWindow::on_R44ChangeUserButton_clicked()
{
    HideRStateView();
    ShowR593StateView();
}

void MainWindow::on_R593ChangeButton_clicked()
{
    if(true) // obviously not, dummy bool
    {
        ui->R593NameText->clear();
        QMessageBox::information(this, tr("Change Name"), tr("Name Changed!") );
    }
    else
    {
        QMessageBox::information(this, tr("Change Name"), tr("Failed to change your name!") );
    }
}

void MainWindow::on_R593BackButton_clicked()
{
    HideRStateView();
    ui->R593NameText->clear();
    ShowR44StateView();
}

void MainWindow::on_L1StatePost01Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost02Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost03Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost04Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost05Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost06Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost07Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost08Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost09Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L1StatePost10Button_clicked()
{
    DummyFunctionForPosts();
}

void MainWindow::on_L2BackButton_clicked()
{
    HideLStateView();
    ui->L2PostText->clear();
    ShowL1StateView();
}

void MainWindow::on_L2PostButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = POST;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->L2PostText->toPlainText().toLatin1().data()));

    strcat(temp, "||00"); // public

    if(client->ParseActions(code_request, temp)) // obviously not, dummy bool
    {
        ui->L2PostText->clear();
        HideLStateView();
        ShowL1StateView();
        QMessageBox::information(this, tr("Post"), tr("Posted!") );

    }
    else
    {
        QMessageBox::information(this, tr("Post"), tr("Failed to post!") );
    }

    delete temp;
}

void MainWindow::on_L2PrivatePostButton_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = POST;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->L2PostText->toPlainText().toLatin1().data()));
    strcat(temp, "||01"); // private

    if(client->ParseActions(code_request, temp)) // obviously not, dummy bool
    {
        ui->L2PostText->clear();
        HideLStateView();
        ShowL1StateView();
        QMessageBox::information(this, tr("Post"), tr("Posted!") );

    }
    else
    {
        QMessageBox::information(this, tr("Post"), tr("Failed to post!") );
    }

    delete temp;
}
