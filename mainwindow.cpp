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
void MainWindow::HideRightView()
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

void MainWindow::showSecondRightView()
{
    HideFirstRightView();
    ui->email_text->show();
    ui->pass_text->show();
    ui->goback_button->show();
}

void MainWindow::on_confirmLogin_button_clicked()
{
    printf("%s\n", (char*)(ui->email_text->text().toLatin1().data()));
    printf("%s\n", (char*)(ui->pass_text->text().toLatin1().data()));
    fflush(stdout);

    if(logged)
    {
        // show user chat
        ui->email_text->clear();
        ui->pass_text->clear();
    }
    else
    {
        // make text to appear
    }
}

void MainWindow::on_confirmRegistration_button_clicked()
{
    // TO DO: send data to server

    printf("%s\n", (char*)(ui->email_text->text().toLatin1().data()));
    printf("%s\n", (char*)(ui->pass_text->text().toLatin1().data()));
    fflush(stdout);

    ui->email_text->clear();
    ui->pass_text->clear();
    showSecondRightView();
}

void MainWindow::on_goback_button_clicked()
{
    ui->email_text->clear();
    ui->pass_text->clear();
    ShowFirstRightView();
}

void MainWindow::on_login_button_clicked()
{
    showSecondRightView();
    ui->confirmLogin_button->show();
}

void MainWindow::on_registerButton_clicked()
{
    showSecondRightView();
    ui->confirmRegistration_button->show();
}
