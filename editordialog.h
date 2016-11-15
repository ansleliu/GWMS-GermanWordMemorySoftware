#ifndef EDITORDIALOG_H
#define EDITORDIALOG_H

#include <QDialog>

namespace Ui {
class EditorDialog;
}

class EditorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditorDialog(QWidget *parent = 0);
    ~EditorDialog();

public:
    QString getText();
    void setText(const QString &text);
    QString applyChange;

private slots:
    void on_clearButton_clicked();

    void on_applyButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::EditorDialog *ui;
};

#endif // EDITORDIALOG_H
