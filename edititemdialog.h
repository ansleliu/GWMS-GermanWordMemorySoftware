#ifndef EDITITEMDIALOG_H
#define EDITITEMDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class editItemDialog;
}

class editItemDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit editItemDialog(QWidget *parent = 0);
    ~editItemDialog();

public:
    QString getNewItemText();
    void setGroupText(const QString &text);

private slots:
    void on_OKPushButton_clicked();

    void on_NOPushButton_clicked();

private:
    Ui::editItemDialog *ui;
};

#endif // EDITITEMDIALOG_H
