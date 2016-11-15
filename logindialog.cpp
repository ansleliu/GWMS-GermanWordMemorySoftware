#include "logindialog.h"
#include "ui_logindialog.h"
#include "creatnewuserdialog.h"
#include "QTimer"
#include "myglobal.h"

loginDialog::loginDialog(QWidget *parent,bool bDisableAutoLogin) :
    QDialog(parent), m_bDisableAutoLogin(bDisableAutoLogin),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
/*
    QImage *userimage= new QImage("./rc/loginuser.png");
    ui->userlabel->setPixmap(QPixmap::fromImage(userimage->scaled(51,51)));
    QImage *mimaimage= new QImage("./rc/mimaicon.png");
    ui->mimalabel->setPixmap(QPixmap::fromImage(mimaimage->scaled(51,51)));
*/
    //初始化ComboBox中的用户列表
    initComboBoxUserList();

    if(ui->remembercheckBox->isChecked())
    {
        ui->forgetPasswordButton->setEnabled(false);
    }

    // 设置最后登录的用户
    QString userName = Global::Conf->getLastLoginUser();
    int index = ui->usernameComboBox->findText(userName);
    if (-1 != index)//用户存在
    {
        ui->usernameComboBox->setCurrentIndex(index);
        on_usernameComboBox_currentIndexChanged(userName);
        // 处理自动登录按钮
        bool bAutoLogin = Global::Conf->getAutoLogin();
        ui->autocheckBox->setCheckState(bAutoLogin ? Qt::Checked : Qt::Unchecked);
        //调用自动登录选择
        on_autocheckBox_clicked(bAutoLogin);

        if (bAutoLogin && !m_bDisableAutoLogin)
        {
            //如果自动登录，一段时间后自动登录
            QTimer::singleShot(1000, this, SLOT(on_loginButton_clicked()));
        }
    }

    ui->passwordlineEdit->setFocus();
}

loginDialog::~loginDialog()
{
    delete ui;
}

bool loginDialog::initComboBoxUserList()
{
    ui->usernameComboBox->clear();
    //获取用户信息
    QStringList userList = Global::UserMag->getUserListOrderById();
    //遍历该表
    QStringListIterator Iterator(userList);
    //向combobox中添加用户
    while(Iterator.hasNext())
    {
        ui->usernameComboBox->addItem(QIcon("./rc/loginuser.png"),Iterator.next());
    }
    return true;
}

void loginDialog::on_creatNewuserButton_clicked()
{
    CreatNewUserDialog newUserDlg(this);
    if (newUserDlg.exec()  == QDialog::Accepted)
    {
        ui->autocheckBox->setCheckState(Qt::Unchecked);
        ui->remembercheckBox->setCheckState(Qt::Unchecked);
        ui->forgetPasswordButton->setEnabled(true);

        ui->passwordlineEdit->setFocus();
    }
    initComboBoxUserList();
}

void loginDialog::on_forgetPasswordButton_clicked()
{
    QString username = ui->usernameComboBox->currentText();
    FindKeyDialog *findkey;
    findkey = new FindKeyDialog(this,username);
    if(findkey->exec() == QDialog::Accepted)
    {
        ui->passwordlineEdit->setFocus();
    }
    findkey->close();
    delete findkey;
    findkey = NULL;
}

void loginDialog::on_remembercheckBox_clicked(bool checked)
{
    QString userName = ui->usernameComboBox->currentText();
    Global::UserMag->updateSavePsw(userName, checked);
    if (!checked)
    {
        ui->autocheckBox->setCheckState(Qt::Unchecked);
        ui->forgetPasswordButton->setEnabled(true);
    }
    else
    {
        ui->forgetPasswordButton->setEnabled(false);
    }
}

void loginDialog::on_autocheckBox_clicked(bool checked)
{
    if (checked)
    {
        ui->remembercheckBox->setCheckState(Qt::Checked);
        ui->forgetPasswordButton->setEnabled(false);
    }

}

void loginDialog::on_loginButton_clicked()
{
    QString userName = ui->usernameComboBox->currentText();
    QString password = ui->passwordlineEdit->text();
    if (Global::UserMag->verifyPsw(userName, password))
    {
        //在配置文件中设置最后登录用户，即当前登录用户
        Global::Conf->setLastLoginUser(userName);
        //在数据库中更新用户的登录时间
        Global::UserMag->updateLoginTime(userName);
        //在数据库中更新密码记录状态
        Global::UserMag->updateSavePsw(userName, ui->remembercheckBox->checkState());
        //在配置文件中设置自动登录状态
        Global::Conf->setAutoLogin(ui->autocheckBox->checkState());
        //在数据库中更新用户登录次数
        Global::UserMag->updateLoginCount(userName);
        //在配置文件中设置当前登录用户
        Global::Conf->setCurrentUser(userName);
        //查看用户是否为新用户
        Global::Conf->setIsNewUser(Global::UserMag->getLoginCount(userName));

        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("错误"), tr("密码错误(注意大小写),请重新输入."));
        ui->passwordlineEdit->setFocus();
    }
}

void loginDialog::on_quitButton_clicked()
{
//    if (QMessageBox::information(this, tr("提示信息"), tr("您确定要退出吗?"),
//                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        QDialog::reject();
    }
}

void loginDialog::on_usernameComboBox_currentIndexChanged(const QString &userName)
{
    bool bSavePsw = Global::UserMag->getUserInfo(QString("savePsw"), userName).toInt();
    if (bSavePsw)
    {
        ui->passwordlineEdit->setText(Global::UserMag->getUserInfo(QString("password"), userName).toString());
        ui->forgetPasswordButton->setEnabled(false);
    }
    else
    {
        ui->passwordlineEdit->setText("");
        ui->forgetPasswordButton->setEnabled(true);
    }
    ui->remembercheckBox->setCheckState(bSavePsw ? Qt::Checked : Qt::Unchecked);
    ui->autocheckBox->setCheckState(Qt::Unchecked);
}
