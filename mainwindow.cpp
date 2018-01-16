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

    HideRStateView();
    ShowR1StateView();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::HideRStateView()
{
    HideR1StateView();
    HideR2StateView();
    HideR3StateView();
}

void MainWindow::HideR1StateView()
{
    ui->R1StateRegisterButton->hide();
    ui->R1StateLoginButton->hide();
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
    HideR2StateView();
    ui->R1StateRegisterButton->show();
    ui->R1StateLoginButton->show();
}

void MainWindow::ShowR2StateView()
{
    HideR1StateView();
    ui->R2StateEmailText->show();
    ui->R2StatePassText->show();
    ui->R2StateGoBackButton->show();
}

void MainWindow::HideR3StateView()
{
    ui->R3ChatRoomsButton->hide();
    ui->R3LogoutButton->hide();
    ui->R3ManagaFriendsButton->hide();
    ui->R3ManagePostsButton->hide();
    ui->R3UserSettingsButton->hide();
}

void MainWindow::ShowR3StateView()
{
    ui->R3ChatRoomsButton->show();
    ui->R3LogoutButton->show();
    ui->R3ManagaFriendsButton->show();
    ui->R3ManagePostsButton->show();
    ui->R3UserSettingsButton->show();
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

}

void MainWindow::on_R3ManagaFriendsButton_clicked()
{

}

void MainWindow::on_R3ManagePostsButton_clicked()
{

}

void MainWindow::on_R3UserSettingsButton_clicked()
{

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
}

void MainWindow::on_TestAction01_triggered()
{
    QMessageBox::information(this, tr("TestAction01"), tr("Example TestAction01!") );
}

void MainWindow::on_TestAction02_triggered()
{
    QMessageBox::information(this, tr("TestAction02"), tr("Example TestAction02!") );
}
