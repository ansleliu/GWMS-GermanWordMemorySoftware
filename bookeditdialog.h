#ifndef BOOKEDITDIALOG_H
#define BOOKEDITDIALOG_H

#include <QDialog>
#include <QString>
#include <QSqlTableModel>
#include "editordialog.h"
#include "bookedit.h"

namespace Ui {
class BookEditDialog;
}

class BookEditDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BookEditDialog(QWidget *parent = 0,const QString &BookPath = NULL);
    ~BookEditDialog();

private slots:
    void displayTime();

    void on_newRecordButton_clicked();

    void on_deleteRecordButton_clicked();

    void on_showAllButton_clicked();

    void on_ascendingOrderButton_clicked();

    void on_descendingOrderButton_clicked();

    void on_idSelectradioButton_clicked();

    void on_wortSelectradioButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_goTolineEdit_textChanged(const QString &keyWort);

private:
    void updateWordCount();

    QString asIdSelect;
    QString asWortSelect;
    QString deleteMethode;
    QString descendingOrder;

private:
    Ui::BookEditDialog *ui;
    QString tableName;
    QSqlTableModel *model;
    BookEdit *bookEdit;
    QString bookpath;
};

#endif // BOOKEDITDIALOG_H
