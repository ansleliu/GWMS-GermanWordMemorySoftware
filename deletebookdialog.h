#ifndef DELETEBOOKDIALOG_H
#define DELETEBOOKDIALOG_H

#include <QDialog>
#include <QString>
#include "QMessageBox"
#include "QFileDialog"
#include "QFileInfo"
#include "pathmanage.h"
#include "myglobal.h"

namespace Ui {
class DeleteBookDialog;
}

class DeleteBookDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DeleteBookDialog(QWidget *parent = 0);
    ~DeleteBookDialog();

public:
    QString getClassName();
    QString getBookName();
    QString getBookPath();
    void setClassName(const QString &bookclass);
    void setBookName(const QString &bookname);
    QString bookName;
    QString bookPath;

private slots:
    void on_OKButton_clicked();

    void on_QuitButton_clicked();

private:
    Ui::DeleteBookDialog *ui;
};

#endif // DELETEBOOKDIALOG_H
