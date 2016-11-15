#include "editordialog.h"
#include "ui_editordialog.h"

EditorDialog::EditorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditorDialog)
{
    ui->setupUi(this);
    applyChange = "FALSE";

    ui->applyButton->setFocus();
}

EditorDialog::~EditorDialog()
{
    delete ui;
}

QString EditorDialog::getText()
{
    QString getTheText;
    if(applyChange == "TRUE")
    {
        getTheText = ui->textEdit->toPlainText();
        applyChange == "FALSE";
    }
    return getTheText;
}

void EditorDialog::setText(const QString &text)
{
    ui->textEdit->update();
    ui->textEdit->setText(text);
}

void EditorDialog::on_clearButton_clicked()
{
    ui->textEdit->clear();
}

void EditorDialog::on_applyButton_clicked()
{
    this->close();
    applyChange = "TRUE";
}

void EditorDialog::on_closeButton_clicked()
{
    this->close();
    applyChange = "FALSE";
}
