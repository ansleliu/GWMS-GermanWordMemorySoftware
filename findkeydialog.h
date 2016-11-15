#ifndef FINDKEYDIALOG_H
#define FINDKEYDIALOG_H

#include <QDialog>
#include "myglobal.h"

namespace Ui {
class FindKeyDialog;
}

class FindKeyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FindKeyDialog(QWidget *parent = 0, const QString &username = NULL);
    ~FindKeyDialog();
    
private slots:
    void on_GoBackButton_clicked();

private:
    Ui::FindKeyDialog *ui;
};

#endif // FINDKEYDIALOG_H
