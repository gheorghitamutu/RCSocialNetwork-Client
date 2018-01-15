#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = new ClientRequests;

    HideSecondRightView();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::HideRightState2View()
{
    HideFirstRightView();
    HideSecondRightView();
}

void MainWindow::HideFirstRightView()
{
    ui->registerButton->hide();
    ui->login_button->hide();
}

void MainWindow::HideSecondRightView()
{
    ui->email_text->hide();
    ui->pass_text->hide();
    ui->confirmLogin_button->hide();
    ui->confirmRegistration_button->hide();
    ui->goback_button->hide();
}

void MainWindow::ShowFirstRightView()
{
    HideSecondRightView();
    ui->registerButton->show();
    ui->login_button->show();
}

void MainWindow::ShowSecondRightView()
{
    HideFirstRightView();
    ui->email_text->show();
    ui->pass_text->show();
    ui->goback_button->show();
}

void MainWindow::on_confirmLogin_button_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = LOGIN;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->email_text->text().toLatin1().data()));
    strcat(temp, ",");
    strcat(temp, (char*)(ui->pass_text->text().toLatin1().data()));

    this->logged = client->ParseActions(code_request, temp);

    if(logged)
    {
        // show state 3
        ui->email_text->clear();
        ui->pass_text->clear();
        HideRightState2View();
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Error"), tr("Wrong info!") );

    }
}

void MainWindow::on_confirmRegistration_button_clicked()
{
    char* temp = new char[MAX_INPUT];
    bzero(temp, MAX_INPUT);
    int code_request = REGISTER;
    memcpy(temp, &code_request, sizeof(int));
    strcat(temp, (char*)(ui->email_text->text().toLatin1().data()));
    strcat(temp, ",");
    strcat(temp, (char*)(ui->pass_text->text().toLatin1().data()));

    if(client->ParseActions(code_request, temp))
    {
        ui->email_text->clear();
        ui->pass_text->clear();
        ShowFirstRightView();
    }
    else
    {
        // error message appears
        QMessageBox::information(this, tr("Error"), tr("This email address exists!") );
    }


    delete temp;
}

void MainWindow::on_goback_button_clicked()
{
    ui->email_text->clear();
    ui->pass_text->clear();
    ShowFirstRightView();
}

void MainWindow::on_login_button_clicked()
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
    ShowSecondRightView();
    ui->confirmLogin_button->show();
}

void MainWindow::on_registerButton_clicked()
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
    ShowSecondRightView();
    ui->confirmRegistration_button->show();
}
