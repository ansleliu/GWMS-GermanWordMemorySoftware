#ifndef ADDROOTDIALOG_H
#define ADDROOTDIALOG_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class AddRootDialog;
}

class AddRootDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddRootDialog(QWidget *parent = 0);
    ~AddRootDialog();

public:
    QString getNewRoot();

private slots:
    void on_OKPushButton_clicked();

    void on_NOPushButton_clicked();

private:
    Ui::AddRootDialog *ui;
};

#endif // ADDROOTDIALOG_H
