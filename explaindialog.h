#ifndef EXPLAINDIALOG_H
#define EXPLAINDIALOG_H

#include <QDialog>

namespace Ui {
class ExplainDialog;
}

class ExplainDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ExplainDialog(QWidget *parent = 0);
    ~ExplainDialog();
    
private:
    Ui::ExplainDialog *ui;
};

#endif // EXPLAINDIALOG_H
