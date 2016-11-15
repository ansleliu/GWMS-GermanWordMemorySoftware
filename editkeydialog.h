#ifndef EDITKEYDIALOG_H
#define EDITKEYDIALOG_H

#include <QDialog>
#include "myglobal.h"

namespace Ui {
class EditKeyDialog;
}

class EditKeyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditKeyDialog(QWidget *parent = 0, const QString &userName = NULL);
    ~EditKeyDialog();
    
private slots:
    void on_OKButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::EditKeyDialog *ui;
    QString currUserName;
};

#endif // EDITKEYDIALOG_H
