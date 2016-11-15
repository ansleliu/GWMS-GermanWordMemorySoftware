#include "SpeakDialog.h"
#include "ui_SpeakDialog.h"

SpeakDialog::SpeakDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpeakDialog)
{
    ui->setupUi(this);
}

SpeakDialog::~SpeakDialog()
{
    delete ui;
}
