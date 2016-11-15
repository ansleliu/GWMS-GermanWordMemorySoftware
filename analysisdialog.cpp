#include "analysisdialog.h"
#include "ui_analysisdialog.h"
#include "QDate"
#include "myglobal.h"
#include <QToolTip>

AnalysisDialog::AnalysisDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnalysisDialog)
{
    ui->setupUi(this);

    calendar = NULL;

    record.clear();
    dateList.clear();
    tablenames.clear();
    bookpaths.clear();

    plotInit();
    pieChartInit();
    colorProjectInit();
    getBookList();

    reviewCalculate();
}

AnalysisDialog::~AnalysisDialog()
{
    if(calendar != NULL)
    {
        delete calendar;
        calendar = NULL;
    }
    delete itemModel;
    delete reviewItemModel;
    delete LHLItemModel;
    delete HG5ItemModel;
    delete HG4A3ItemModel;
    delete HGU3ItemModel;
    delete ui;
}

void AnalysisDialog::colorProjectInit()
{
    colorProject.insert(1,Qt::red);
    colorProject.insert(2,Qt::blue);
    colorProject.insert(3,Qt::yellow);
    colorProject.insert(4,Qt::darkRed);
    colorProject.insert(5,Qt::darkMagenta);
    colorProject.insert(6,Qt::black);
    colorProject.insert(7,Qt::darkGray);
    colorProject.insert(8,Qt::darkCyan);
    colorProject.insert(9,Qt::white);
    colorProject.insert(10,Qt::lightGray);
    colorProject.insert(11,Qt::magenta);
    colorProject.insert(12,Qt::darkBlue);
    colorProject.insert(13,Qt::green);
    colorProject.insert(14,Qt::darkYellow);
    colorProject.insert(15,Qt::cyan);
    colorProject.insert(16,Qt::gray);
    colorProject.insert(17,Qt::darkGreen);
}

void AnalysisDialog::plotInit()
{
    /////////////////////////////////////////////////////////
    //
    QLinearGradient bg(0,0,0,1);
    bg.setCoordinateMode(QGradient::ObjectBoundingMode);
    bg.setColorAt(1, Qt::white);
    bg.setColorAt(0.5, QColor(0xccccff));
    bg.setColorAt(0, Qt::white);

    ui->LSpinBox->setValue(150);
    ui->LearnBarChartPlotter->axisY()->setRanges(0, 150);
    ui->LearnBarChartPlotter->axisY()->setTicks(2, 10);
    ui->LearnBarChartPlotter->axisY()->setPen(QPen(Qt::darkGray));
    ui->LearnBarChartPlotter->axisY()->setMinorTicksPen(QPen(Qt::gray));
    ui->LearnBarChartPlotter->axisY()->setMajorTicksPen(QPen(Qt::darkGray));
    ui->LearnBarChartPlotter->axisY()->setMajorGridPen(QPen(Qt::lightGray));
    ui->LearnBarChartPlotter->axisY()->setTextColor(Qt::black);

//    ui->LearnBarChartPlotter->axisX()->setTicks(1,1);
    ui->LearnBarChartPlotter->axisX()->setPen(QPen(Qt::darkGray));
    ui->LearnBarChartPlotter->axisX()->setMinorTicksPen(QPen(Qt::gray));
    ui->LearnBarChartPlotter->axisX()->setMajorTicksPen(QPen(Qt::darkGray));
    ui->LearnBarChartPlotter->axisX()->setMajorGridPen(QPen(Qt::lightGray));
    ui->LearnBarChartPlotter->axisX()->setTextColor(Qt::black);

    ui->LearnBarChartPlotter->setBarSize(32, 128);
    ui->LearnBarChartPlotter->setBarOpacity(0.75);
    ui->LearnBarChartPlotter->setBackground(QBrush(bg));

    ui->RSpinBox->setValue(150);
    ui->ReviewBarChartPlotter->axisY()->setRanges(0, 150);
    ui->ReviewBarChartPlotter->axisY()->setTicks(2, 10);
    ui->ReviewBarChartPlotter->axisY()->setPen(QPen(Qt::darkGray));
    ui->ReviewBarChartPlotter->axisY()->setMinorTicksPen(QPen(Qt::gray));
    ui->ReviewBarChartPlotter->axisY()->setMajorTicksPen(QPen(Qt::darkGray));
    ui->ReviewBarChartPlotter->axisY()->setMajorGridPen(QPen(Qt::lightGray));
    ui->ReviewBarChartPlotter->axisY()->setTextColor(Qt::black);

//    ui->ReviewBarChartPlotter->axisX()->setTicks(1,1);
    ui->ReviewBarChartPlotter->axisX()->setPen(QPen(Qt::darkGray));
    ui->ReviewBarChartPlotter->axisX()->setMinorTicksPen(QPen(Qt::gray));
    ui->ReviewBarChartPlotter->axisX()->setMajorTicksPen(QPen(Qt::darkGray));
    ui->ReviewBarChartPlotter->axisX()->setMajorGridPen(QPen(Qt::lightGray));
    ui->ReviewBarChartPlotter->axisX()->setTextColor(Qt::black);

    ui->ReviewBarChartPlotter->setBarSize(32, 128);
    ui->ReviewBarChartPlotter->setBarOpacity(0.75);
    ui->ReviewBarChartPlotter->setBackground(QBrush(bg));
}

void AnalysisDialog::pieChartInit()
{
    LHLItemModel = new QStandardItemModel(2, 1, NULL);
    LHLItemModel->setHeaderData(0, Qt::Vertical, QColor(170,0,0,255), Qt::BackgroundRole);
    LHLItemModel->setHeaderData(0, Qt::Vertical, QColor(Qt::darkGreen), Qt::ForegroundRole);
    LHLItemModel->setHeaderData(1, Qt::Vertical, QColor(0,170,0,255), Qt::BackgroundRole);
    LHLItemModel->setHeaderData(1, Qt::Vertical, QColor(Qt::darkRed), Qt::ForegroundRole);

    HG5ItemModel = new QStandardItemModel(2, 1, NULL);
    HG5ItemModel->setHeaderData(0, Qt::Vertical, QColor(255,255,0,255), Qt::BackgroundRole);
    HG5ItemModel->setHeaderData(0, Qt::Vertical, QColor(Qt::darkGreen), Qt::ForegroundRole);
    HG5ItemModel->setHeaderData(1, Qt::Vertical, QColor(0,170,0,255), Qt::BackgroundRole);
    HG5ItemModel->setHeaderData(1, Qt::Vertical, QColor(Qt::darkRed), Qt::ForegroundRole);

    HG4A3ItemModel = new QStandardItemModel(2, 1, NULL);
    HG4A3ItemModel->setHeaderData(0, Qt::Vertical, QColor(255,170,0,255), Qt::BackgroundRole);
    HG4A3ItemModel->setHeaderData(0, Qt::Vertical, QColor(Qt::darkGreen), Qt::ForegroundRole);
    HG4A3ItemModel->setHeaderData(1, Qt::Vertical, QColor(0,170,0,255), Qt::BackgroundRole);
    HG4A3ItemModel->setHeaderData(1, Qt::Vertical, QColor(Qt::darkRed), Qt::ForegroundRole);

    HGU3ItemModel = new QStandardItemModel(2, 1, NULL);
    HGU3ItemModel->setHeaderData(0, Qt::Vertical, QColor(85,0,255,255), Qt::BackgroundRole);
    HGU3ItemModel->setHeaderData(0, Qt::Vertical, QColor(Qt::darkGreen), Qt::ForegroundRole);
    HGU3ItemModel->setHeaderData(1, Qt::Vertical, QColor(0,170,0,255), Qt::BackgroundRole);
    HGU3ItemModel->setHeaderData(1, Qt::Vertical, QColor(Qt::darkRed), Qt::ForegroundRole);


    QLinearGradient bg(0,0,0,1);
    bg.setCoordinateMode(QGradient::ObjectBoundingMode);
    bg.setColorAt(1, Qt::white);
    bg.setColorAt(0.5, QColor(0xccccff));
    bg.setColorAt(0, Qt::white);
    QFont pieFont("Arial", 12, QFont::Bold);

    ui->LHLPieChart->setBackground(QBrush(bg));

    ui->LHLPieChart->setHighlightBrush(QBrush(QColor(0xffa500), Qt::Dense4Pattern));
    ui->LHLPieChart->setHighlightAlpha(0.5);
    ui->LHLPieChart->setFont(pieFont);

    ui->HG5PieChart->setBackground(QBrush(bg));

    ui->HG5PieChart->setHighlightBrush(QBrush(QColor(0xffa500), Qt::Dense4Pattern));
    ui->HG5PieChart->setHighlightAlpha(0.5);
    ui->HG5PieChart->setFont(pieFont);

    ui->HG4A3PieChart->setBackground(QBrush(bg));

    ui->HG4A3PieChart->setHighlightBrush(QBrush(QColor(0xffa500), Qt::Dense4Pattern));
    ui->HG4A3PieChart->setHighlightAlpha(0.5);
    ui->HG4A3PieChart->setFont(pieFont);

    ui->HU3PieChart->setBackground(QBrush(bg));

    ui->HU3PieChart->setHighlightBrush(QBrush(QColor(0xffa500), Qt::Dense4Pattern));
    ui->HU3PieChart->setHighlightAlpha(0.5);
    ui->HU3PieChart->setFont(pieFont);
}

void AnalysisDialog::BookComboBoxInit()
{
    ui->BookComboBox->clear();
    //获取用户信息
    QStringList bookList;
    for(int i=0; i<bookpaths.size(); i++)
    {
        QString classname = bcMgr->getBookClasse(bookpaths.at(i));
        QString bookname = bcMgr->getBookName(bookpaths.at(i));
        QString bookinfo = classname + "/" + bookname;
        bookList.append(bookinfo);
    }
    //遍历该表
    QStringListIterator Iterator(bookList);
    //向combobox中添加用户
    while(Iterator.hasNext())
    {
        ui->BookComboBox->addItem(QIcon("./rc/book.png"),Iterator.next());
    }
    ui->BookComboBox->setCurrentIndex(0);
}

void AnalysisDialog::getBookList()
{
    bookpaths = bcMgr->getBookPaths();
    for(int i=0; i<bookpaths.size(); i++)
    {
        QFileInfo fd(bookpaths.at(i));
        tablenames << fd.baseName();
    }
    itemModel = new QStandardItemModel(tablenames.size(),30,this);
    itemModel->setVerticalHeaderLabels(tablenames);

    reviewItemModel = new QStandardItemModel(tablenames.size(),30,this);
    reviewItemModel->setVerticalHeaderLabels(tablenames);

    QString currUser = Global::Conf->getCurrentUser();
    QDate createDate = Global::UserMag->getUserInfo("createTime",
                                                    currUser).toDate();
    ui->dateEdit->setDate(createDate);

    ui->LearnBarChartPlotter->setBarType(QSint::BarChartPlotter::Trend);
    ui->LearnBarChartPlotter->repaint();
    ui->ReviewBarChartPlotter->setBarType(QSint::BarChartPlotter::Trend);
    ui->ReviewBarChartPlotter->repaint();
    ui->ReviewBarChartPlotter->setModel(reviewItemModel);
    ui->ReviewBarChartPlotter->repaint();

    int colori = 1;
    for(int i=0; i<tablenames.size(); i++)
    {
        itemModel->setHeaderData(i, Qt::Vertical,
                                     QColor(colorProject.value(colori)),
                                     Qt::BackgroundRole);
        reviewItemModel->setHeaderData(i, Qt::Vertical,
                                       QColor(colorProject.value(colori)),
                                       Qt::BackgroundRole);
        colori++;
        if(colori >= colorProject.size())
        {
            colori = 1;
        }
    }
    ///////////////////////////////////////////////////////////////
    //
    BookComboBoxInit();
}

void AnalysisDialog::reviewCalculate()
{
    for(int i=0; i<tablenames.size(); i++)
    {
        for(int j=0; j<30; j++)
        {
            int count = learnMgr->getReviewCountInfo(bookpaths.at(i),j+1);
            reviewItemModel->setData(reviewItemModel->index(i,j),count);
        }
    }

    connect(ui->ReviewBarChartPlotter, SIGNAL(entered(const QModelIndex&)),
            this, SLOT(reviewShowToolTip(const QModelIndex&)));
}

void AnalysisDialog::on_ChoiceListWidget_currentRowChanged(int currentRow)
{
    ui->tabWidget->setCurrentIndex(currentRow);
}

void AnalysisDialog::on_LBarRadioButton_clicked()
{
    ui->LearnBarChartPlotter->setBarType(QSint::BarChartPlotter::Columns);
    ui->LearnBarChartPlotter->repaint();
}

void AnalysisDialog::on_LLineRadioButton_clicked()
{
    ui->LearnBarChartPlotter->setBarType(QSint::BarChartPlotter::Trend);
    ui->LearnBarChartPlotter->repaint();
}

void AnalysisDialog::on_tabWidget_currentChanged(int index)
{
    ui->ChoiceListWidget->setCurrentRow(index);
}

void AnalysisDialog::on_dateEdit_dateChanged(const QDate &date)
{
    record.clear();
    dateList.clear();
    for(int i=0; i<30; i++)
    {
        QDate currDate = date.addDays(i);
        QString currDateStr = currDate.toString("yyyy-MM-dd");
        dateList.append(currDateStr);

    }
    itemModel->setHorizontalHeaderLabels(dateList);

    QMap<QString,QList<int> >book;
    QList<int> bookLRecord;
    QList<int> bookRRecord;
    for (int i=0; i<tablenames.size(); i++)
    {
        book.clear();
        bookLRecord.clear();
        bookRRecord.clear();
        for (int j=0; j<30; j++)
        {
            int learnRecord = bcMgr->getDayLearnRecord(bookpaths.at(i),
                                                       dateList.at(j));
            bookLRecord.append(learnRecord);
            int reviewRecord = bcMgr->getDayReviewRecord(bookpaths.at(i),
                                                         dateList.at(j));
            bookRRecord.append(reviewRecord);
            //////////////////////////////////////////////////////////////
            //
            itemModel->setData(itemModel->index(i,j), learnRecord);

        }
        book.insert("learn",bookLRecord);
        book.insert("review",bookRRecord);
        record.append(book);
    }

    ui->LearnBarChartPlotter->setModel(itemModel);
    ui->LearnBarChartPlotter->repaint();
    ui->LRadioButton->setChecked(true);
    connect(ui->LearnBarChartPlotter, SIGNAL(entered(const QModelIndex&)),
            this, SLOT(learnShowToolTip(const QModelIndex&)));
}

void AnalysisDialog::on_LRadioButton_clicked()
{
    for (int i=0; i<tablenames.size(); i++)
    {
        for (int j=0; j<30; j++)
        {
            int learnRecord = record.at(i).value("learn").at(j);
            itemModel->setData(itemModel->index(i,j), learnRecord);

        }
    }
    ui->LearnBarChartPlotter->repaint();
}

void AnalysisDialog::on_RRadioButton_clicked()
{
    for (int i=0; i<tablenames.size(); i++)
    {
        for (int j=0; j<30; j++)
        {
            int reviewRecord = record.at(i).value("review").at(j);
            itemModel->setData(itemModel->index(i,j), reviewRecord);

        }
    }
    ui->LearnBarChartPlotter->repaint();
}

void AnalysisDialog::on_RBarRadioButton_clicked()
{
    ui->ReviewBarChartPlotter->setBarType(QSint::BarChartPlotter::Columns);
    ui->ReviewBarChartPlotter->repaint();
}

void AnalysisDialog::on_RLineRadioButton_clicked()
{
    ui->ReviewBarChartPlotter->setBarType(QSint::BarChartPlotter::Trend);
    ui->ReviewBarChartPlotter->repaint();
}

void AnalysisDialog::on_BookComboBox_currentIndexChanged(int index)
{
    QString classname = bcMgr->getBookClasse(bookpaths.at(index));
    QString bookname = bcMgr->getBookName(bookpaths.at(index));

    int wordCount = bcMgr->getTotalNumb(classname,bookname);
    int haveLearnd = bcMgr->getHaveLearnedNum(bookpaths.at(index));

    int wordCountG5 = learnMgr->getWordCountG5(bookpaths.at(index));
    int wordCountG4A3 = learnMgr->getWordCountG4A3(bookpaths.at(index));
    int wordCountGU3 =learnMgr->getWordCountGU3(bookpaths.at(index));
    /////////////////////////////////////////////////////////////////////
    //
    LHLItemModel->setData(LHLItemModel->index(0,0),wordCount-haveLearnd);
    LHLItemModel->setData(LHLItemModel->index(1,0),haveLearnd);
    ui->LHLPieChart->setModel(LHLItemModel);

    HG5ItemModel->setData(HG5ItemModel->index(0,0),wordCountG5);
    HG5ItemModel->setData(HG5ItemModel->index(1,0),haveLearnd);
    ui->HG5PieChart->setModel(HG5ItemModel);

    HG4A3ItemModel->setData(HG4A3ItemModel->index(0,0),wordCountG4A3);
    HG4A3ItemModel->setData(HG4A3ItemModel->index(1,0),haveLearnd);
    ui->HG4A3PieChart->setModel(HG4A3ItemModel);

    HGU3ItemModel->setData(HGU3ItemModel->index(0,0),wordCountGU3);
    HGU3ItemModel->setData(HGU3ItemModel->index(1,0),haveLearnd);
    ui->HU3PieChart->setModel(HGU3ItemModel);

    ui->LHLPieChart->setActiveIndex(index);
    ui->HG5PieChart->setActiveIndex(index);
    ui->HG4A3PieChart->setActiveIndex(index);
    ui->HU3PieChart->setActiveIndex(index);
}

void AnalysisDialog::learnShowToolTip(const QModelIndex &index)
{
    if (index.isValid())
    {
        QToolTip::showText(
                ui->LearnBarChartPlotter->globalMousePos(),
                QString("%1").arg(tablenames.at(index.row()))
                );
    }
    else
        QToolTip::hideText();
}

void AnalysisDialog::reviewShowToolTip(const QModelIndex &index)
{
    if (index.isValid())
    {
        QToolTip::showText(
                ui->ReviewBarChartPlotter->globalMousePos(),
                QString("%1").arg(tablenames.at(index.row()))
                );
    }
    else
        QToolTip::hideText();
}

void AnalysisDialog::pieShowToolTip(const QModelIndex & /*index*/)
{
}

void AnalysisDialog::on_DataPushButton_clicked()
{
    if(calendar != NULL)
    {
        delete calendar;
        calendar = NULL;
    }
    calendar = new QCalendarWidget(ui->LearnRecordTab);

    calendar->setMinimumSize(350,220);
    calendar->show();
    calendar->setGridVisible(true);
    calendar->setSelectionMode(QCalendarWidget::SingleSelection);
    connect(calendar,SIGNAL(clicked(const QDate &)),this,SLOT(setdate()));
}

void AnalysisDialog::setdate()
{
    ui->dateEdit->setDate(calendar->selectedDate());
//    disconnect(calendar,SIGNAL(clicked(const QDate &)),this,SLOT(setdate()));
    calendar->close();
}

void AnalysisDialog::on_LSpinBox_valueChanged(int arg1)
{
    ui->LearnBarChartPlotter->axisY()->setRanges(0, arg1);
    ui->LearnBarChartPlotter->repaint();
}

void AnalysisDialog::on_RSpinBox_valueChanged(int arg1)
{
    ui->ReviewBarChartPlotter->axisY()->setRanges(0, arg1);
    ui->ReviewBarChartPlotter->repaint();
}
