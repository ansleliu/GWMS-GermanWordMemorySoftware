#include "learnstartdialog.h"
#include "ui_learnstartdialog.h"
#include "qmath.h"

LearnStartDialog::LearnStartDialog(QWidget *parent,const QString &bookpath) :
    QDialog(parent),
    ui(new Ui::LearnStartDialog)
{
    itemModel = new QStandardItemModel(2, 1, NULL);
    itemModel->setHeaderData(0, Qt::Vertical, QColor(Qt::green), Qt::BackgroundRole);
    itemModel->setHeaderData(0, Qt::Vertical, QColor(Qt::darkGreen), Qt::ForegroundRole);
    itemModel->setHeaderData(1, Qt::Vertical, QColor(Qt::yellow), Qt::BackgroundRole);
    itemModel->setHeaderData(1, Qt::Vertical, QColor(Qt::darkRed), Qt::ForegroundRole);

    ui->setupUi(this);
    bookPath = bookpath;

    //////////////////////////////////////////////////////////////////
    //获取词库管理器来取得词库中的信息
    if(userBookDBMgr)
    {
        delete userBookDBMgr;
    }
    userBookDBMgr = new UserBookDBMgr(bookPath,bcMgr->getBookName(bookPath));

    QStringList lektionList = userBookDBMgr->getLektionList();
    QStringListIterator Iterator(lektionList);
    //向combobox中添加单元
    while(Iterator.hasNext())
    {
        ui->LektionComboBox->addItem(QIcon("./rc/list.png"),Iterator.next());
    }

    for(int i=0;i<lektionList.size();i++)
    {
        QString currLlektion = lektionList.at(i);
        int reviewCount = learnMgr->getReviewWordIDByLektion("StateTable",
                                                             bookPath,
                                                             currLlektion.toInt()
                                                             ).count();
        if(reviewCount > 0)
        {
            //向combobox中添加单元
            ui->ReviewLektionComboBox->addItem(QIcon("./rc/list.png"),
                                               currLlektion + QString(" %1").arg(reviewCount));
        }
    }


    /////////////////////////////////////////////////////////
    //词库信息
    ui->InfoTextBrowser->clear();
    infolist.clear();
    infolist << bcMgr->getBookClasse(bookPath)
             << bcMgr->getBookName(bookPath)
             << QString::number(userBookDBMgr->getWortCount(),'i',0)
             << QString::number(bcMgr->getHaveLearnedNum(bookPath),'i',0);

    ui->InfoTextBrowser->addItem(QString(tr("1.词库所属类：%1")).arg(infolist.at(0)));
    ui->InfoTextBrowser->addItem(QString(tr("2.词库名：%1")).arg(infolist.at(1)));
    ui->InfoTextBrowser->addItem(QString(tr("3.总词汇量：%1")).arg(infolist.at(2)));
    ui->InfoTextBrowser->addItem(QString(tr("4.共学习：%1")).arg(infolist.at(3)));

    if(ui->ChoiceCheckBox->isChecked())
    {
        wordCount = learnMgr->getReviewWordID("StateTable",bookPath).count();
        infolist.append(QString::number(wordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("5.本词库须复习：%1"))
                                    .arg(infolist.at(4)));

        int lektionWordCount = userBookDBMgr->getWordCountByLektion(lektion);
        infolist.append(QString::number(lektionWordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("6.本单元词汇量：%1"))
                                    .arg(infolist.at(5)));

        int lektionWordLearned = learnMgr->getHaveLearnedWordCountByLektion(bookPath,lektion);
        infolist.append(QString::number(lektionWordLearned,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("7.本单元已学习：%1"))
                                    .arg(infolist.at(6)));

        wordCount = learnMgr->getReviewWordIDByLektion("StateTable",bookPath,lektion).count();
        infolist.append(QString::number(wordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("8.本单元须复习：%1"))
                                    .arg(infolist.at(7)));
        itemModel->setData(itemModel->index(0,0),lektionWordLearned);
        itemModel->setData(itemModel->index(1,0),lektionWordCount-lektionWordLearned);

        if(lektionWordCount == lektionWordLearned)
        {
            ui->LearnPushButton->setEnabled(false);
        }
        else
        {
            ui->LearnPushButton->setEnabled(true);
        }
    }
    else
    {
        wordCount = learnMgr->getReviewWordID("StateTable",bookPath).count();
        infolist.append(QString::number(wordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("5.须复习：%1"))
                                    .arg(infolist.at(4)));
        int Learnedcount = infolist.at(3).toInt();
        int Count = infolist.at(2).toInt();
        itemModel->setData(itemModel->index(0,0),Learnedcount);
        itemModel->setData(itemModel->index(1,0),Count-Learnedcount);

        if(userBookDBMgr->getWortCount() == bcMgr->getHaveLearnedNum(bookPath))
        {
            ui->LearnPushButton->setEnabled(false);
        }
        else
        {
            ui->LearnPushButton->setEnabled(true);
        }
    }

    QLinearGradient bg(0,0,0,1);
    bg.setCoordinateMode(QGradient::ObjectBoundingMode);
    bg.setColorAt(0.0,QColor(255,255,255,255));
    bg.setColorAt(0.5,QColor(232,232,232,255));
    bg.setColorAt(1.0,QColor(255,255,255,255));

    ui->PieChart->setBackground(QBrush(bg));
    ui->PieChart->setModel(itemModel);
    ui->PieChart->setHighlightBrush(QBrush(QColor(0xffa500), Qt::Dense4Pattern));
    ui->PieChart->setHighlightAlpha(0.5);
    QFont pieFont("Arial", 12, QFont::Bold);
    ui->PieChart->setFont(pieFont);

    if(wordCount <= 0)
    {
        ui->ReviewPushButton->setEnabled(false);
    }
    else
    {
        ui->ReviewPushButton->setEnabled(true);
    }
/*
    mainLayout=new QVBoxLayout();
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
//    layout=new QHBoxLayout();
//    layout->setSpacing(0);
//    layout->setContentsMargins(0,0,0,0);

/*
    learnGauge = new LearnGaugeDisplayer(ui->InfoDisplyWidget);

    mainLayout->addWidget(learnGauge);
    ui->InfoDisplyWidget->setLayout(mainLayout);

    learnGauge->setVisible(true);
    if(haveLearnedcount == 0)
    {
        learnGauge->setValue(0);
    }
    else
    {
        qreal haveLearnProtent = (Learnedcount*100)/Count;
//        int protent = qCeil(haveLearnProtent);
        learnGauge->setValue(haveLearnProtent);
    }
/*
    totalPercent=new GaugeDisplayer(ui->InfoDisplyWidget);
    QColor red(150,0,0,200);
    totalPercent->SetGraphColor(red);
    haveLearnedPercent=new GaugeDisplayer(ui->InfoDisplyWidget);
    haveLearnedPercent->SetGraphColor(Qt::green);
    needReviewPercent=new GaugeDisplayer(ui->InfoDisplyWidget);
    needReviewPercent->SetGraphColor(Qt::blue);

    mainLayout->addLayout(layout);
    layout->addWidget(totalPercent);
    layout->addWidget(haveLearnedPercent);
    layout->addWidget(needReviewPercent);
    ui->InfoDisplyWidget->setLayout(mainLayout);

    totalPercent->setVisible(true);
    haveLearnedPercent->setVisible(true);
    needReviewPercent->setVisible(true);
*/
}

LearnStartDialog::~LearnStartDialog()
{
    delete itemModel;
    delete ui;
}

bool LearnStartDialog::getLearnByLektion()
{
    if(ui->ChoiceCheckBox->isChecked())
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString LearnStartDialog::learnOrReview()
{
    return LearnOrReview;
}

int LearnStartDialog::getLektion()
{
    return lektion;
}

void LearnStartDialog::on_ChoiceCheckBox_clicked(bool checked)
{
    if(!checked)
    {
        ui->InfoTextBrowser->clear();
        infolist.clear();
        infolist << bcMgr->getBookClasse(bookPath)
                 << bcMgr->getBookName(bookPath)
                 << QString::number(userBookDBMgr->getWortCount(),'i',0)
                 << QString::number(bcMgr->getHaveLearnedNum(bookPath),'i',0);
        ui->InfoTextBrowser->addItem(QString(tr("1.词库所属类：%1")).arg(infolist.at(0)));
        ui->InfoTextBrowser->addItem(QString(tr("2.词库名：%1")).arg(infolist.at(1)));
        ui->InfoTextBrowser->addItem(QString(tr("3.总词汇量：%1")).arg(infolist.at(2)));
        ui->InfoTextBrowser->addItem(QString(tr("4.共学习：%1")).arg(infolist.at(3)));
        wordCount = learnMgr->getReviewWordID("StateTable",bookPath).count();
        infolist.append(QString::number(wordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("5.须复习：%1"))
                                    .arg(infolist.at(4)));
        ui->LektionComboBox->setEnabled(false);
        itemModel->setData(itemModel->index(0,0),bcMgr->getHaveLearnedNum(bookPath));
        itemModel->setData(itemModel->index(1,0),userBookDBMgr->getWortCount()
                           -bcMgr->getHaveLearnedNum(bookPath));
        ui->PieChart->update();
        if(wordCount <= 0)
        {
            ui->ReviewPushButton->setEnabled(false);
        }
        else
        {
            ui->ReviewPushButton->setEnabled(true);
        }

        if(userBookDBMgr->getWortCount() == bcMgr->getHaveLearnedNum(bookPath))
        {
            ui->LearnPushButton->setEnabled(false);
        }
        else
        {
            ui->LearnPushButton->setEnabled(true);
        }
    }
    else
    {
        ui->InfoTextBrowser->clear();
        infolist.clear();
        infolist << bcMgr->getBookClasse(bookPath)
                 << bcMgr->getBookName(bookPath)
                 << QString::number(userBookDBMgr->getWortCount(),'i',0)
                 << QString::number(bcMgr->getHaveLearnedNum(bookPath),'i',0);
        ui->InfoTextBrowser->addItem(QString(tr("1.词库所属类：%1")).arg(infolist.at(0)));
        ui->InfoTextBrowser->addItem(QString(tr("2.词库名：%1")).arg(infolist.at(1)));
        ui->InfoTextBrowser->addItem(QString(tr("3.总词汇量：%1")).arg(infolist.at(2)));
        ui->InfoTextBrowser->addItem(QString(tr("4.共学习：%1")).arg(infolist.at(3)));

        wordCount = learnMgr->getReviewWordID("StateTable",bookPath).count();
        infolist.append(QString::number(wordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("5.本词库须复习：%1"))
                                    .arg(infolist.at(4)));

        int lektionWordCount = userBookDBMgr->getWordCountByLektion(lektion);
        infolist.append(QString::number(lektionWordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("6.本单元词汇量：%1"))
                                    .arg(infolist.at(5)));

        int lektionWordLearned = learnMgr->getHaveLearnedWordCountByLektion(bookPath,lektion);
        infolist.append(QString::number(lektionWordLearned,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("7.本单元已学习：%1"))
                                    .arg(infolist.at(6)));

        wordCount = learnMgr->getReviewWordIDByLektion("StateTable",bookPath,lektion).count();
        infolist.append(QString::number(wordCount,'i',0));
        ui->InfoTextBrowser->addItem(QString(tr("8.本单元须复习：%1"))
                                    .arg(infolist.at(7)));

        ui->LektionComboBox->setEnabled(true);

        itemModel->setData(itemModel->index(0,0),lektionWordLearned);
        itemModel->setData(itemModel->index(1,0),lektionWordCount-lektionWordLearned);
        ui->PieChart->setActiveIndex(ui->LektionComboBox->currentIndex());

        if(lektionWordCount == lektionWordLearned)
        {
            ui->LearnPushButton->setEnabled(false);
        }
        else
        {
            ui->LearnPushButton->setEnabled(true);
        }

        if(wordCount <= 0)
        {
            ui->ReviewPushButton->setEnabled(false);
        }
        else
        {
            ui->ReviewPushButton->setEnabled(true);
        }
    }
}

void LearnStartDialog::on_LearnPushButton_clicked()
{
    LearnOrReview = "Learn";
    accept();
}

void LearnStartDialog::on_ReviewPushButton_clicked()
{
    LearnOrReview = "Review";
    accept();
}

void LearnStartDialog::on_LektionComboBox_currentIndexChanged(const QString &Lektion)
{
    lektion = Lektion.toInt();
    ui->InfoTextBrowser->clear();
    infolist.clear();
    infolist << bcMgr->getBookClasse(bookPath)
             << bcMgr->getBookName(bookPath)
             << QString::number(userBookDBMgr->getWortCount(),'i',0)
             << QString::number(bcMgr->getHaveLearnedNum(bookPath),'i',0);
    ui->InfoTextBrowser->addItem(QString(tr("1.词库所属类：%1")).arg(infolist.at(0)));
    ui->InfoTextBrowser->addItem(QString(tr("2.词库名：%1")).arg(infolist.at(1)));
    ui->InfoTextBrowser->addItem(QString(tr("3.词汇量：%1")).arg(infolist.at(2)));
    ui->InfoTextBrowser->addItem(QString(tr("4.已学习：%1")).arg(infolist.at(3)));

    wordCount = learnMgr->getReviewWordID("StateTable",bookPath).count();
    infolist.append(QString::number(wordCount,'i',0));
    ui->InfoTextBrowser->addItem(QString(tr("5.本词库须复习：%1"))
                                .arg(infolist.at(4)));

    int lektionWordCount = userBookDBMgr->getWordCountByLektion(lektion);
    infolist.append(QString::number(lektionWordCount,'i',0));
    ui->InfoTextBrowser->addItem(QString(tr("6.本单元词汇量：%1"))
                                .arg(infolist.at(5)));

    int lektionWordLearned = learnMgr->getHaveLearnedWordCountByLektion(bookPath,lektion);
    infolist.append(QString::number(lektionWordLearned,'i',0));
    ui->InfoTextBrowser->addItem(QString(tr("7.本单元已学习：%1"))
                                .arg(infolist.at(6)));

    wordCount = learnMgr->getReviewWordIDByLektion("StateTable",bookPath,lektion).count();
    infolist.append(QString::number(wordCount,'i',0));
    ui->InfoTextBrowser->addItem(QString(tr("8.本单元须复习：%1"))
                                .arg(infolist.at(7)));

    ui->LektionComboBox->setEnabled(true);
    itemModel->setData(itemModel->index(0,0),lektionWordLearned);
    itemModel->setData(itemModel->index(1,0),lektionWordCount-lektionWordLearned);

    if(lektionWordCount == lektionWordLearned)
    {
        ui->LearnPushButton->setEnabled(false);
    }
    else
    {
        ui->LearnPushButton->setEnabled(true);
    }

    if(wordCount <= 0)
    {
        ui->ReviewPushButton->setEnabled(false);
    }
    else
    {
        ui->ReviewPushButton->setEnabled(true);
    }
}

void LearnStartDialog::on_InfoListWidget_clicked(const QModelIndex &/*index*/)
{
//    ui->PieChart->setActiveIndex(index);
}

void LearnStartDialog::on_LektionComboBox_currentIndexChanged(int index)
{
    ui->PieChart->setActiveIndex(index);

    QString currLektion = QString::number(index+1,'i',0);
    if(currLektion != ui->LektionLineEdit->text())
    {
        ui->LektionLineEdit->setText(currLektion);
    }
    int reviewCount = learnMgr->getReviewWordIDByLektion("StateTable",
                                                         bookPath,
                                                         currLektion.toInt()
                                                         ).count();
    if(reviewCount > 0)
    {
        QString reviewLek = QString("%1 %2").arg(currLektion).arg(reviewCount);
        int currIndex = ui->ReviewLektionComboBox->findText(reviewLek);
        ui->ReviewLektionComboBox->setCurrentIndex(currIndex);
    }
}

void LearnStartDialog::on_ReviewLektionComboBox_currentIndexChanged(const QString &lektion)
{
    QStringList lektionsplit = lektion.split(" ");
    QString currLektion = lektionsplit.at(0);
    int index = ui->LektionComboBox->findText(currLektion);
    ui->LektionComboBox->setCurrentIndex(index);
}

void LearnStartDialog::on_LektionLineEdit_textChanged(const QString &lektionNum)
{
    int index = 0;
    int maxLektion = ui->LektionComboBox->count();

    if(lektionNum.toInt() > maxLektion)
    {
        ui->LektionLineEdit->setText(QString::number(maxLektion,'i',0));
        index = maxLektion-1;
    }
    else
    {
        index = lektionNum.toInt()-1;
    }

    if(index < 0)
    {
        index = 0;
    }

    if(index != ui->LektionComboBox->currentIndex())
    {
        ui->LektionComboBox->setCurrentIndex(index);
    }
}
