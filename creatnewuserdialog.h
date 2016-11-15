#ifndef CREATNEWUSERDIALOG_H
#define CREATNEWUSERDIALOG_H

#include <QDialog>

namespace Ui {
class CreatNewUserDialog;
}

class CreatNewUserDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CreatNewUserDialog(QWidget *parent = 0);
    ~CreatNewUserDialog();
    
private slots:
    void on_YesButton_clicked();

    void on_NoButton_clicked();

private:
    Ui::CreatNewUserDialog *ui;
};

#endif // CREATNEWUSERDIALOG_H
