#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddBookDialog(QWidget *parent = 0);
    ~AddBookDialog();

public:
    QString getClassName();
    QString getBookName();
    QString getBookPath();
    void setClassName(const QString &bookclass);
    void setBookName(const QString &bookname);
    QString bookName;
    QString bookPath;

private slots:
    void on_pushButton_clicked();

    void on_OKButton_clicked();

    void on_QuitButton_clicked();

private:
    Ui::AddBookDialog *ui;
};

#endif // ADDBOOKDIALOG_H
