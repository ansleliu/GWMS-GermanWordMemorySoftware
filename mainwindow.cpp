#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QStringList"
#include "QFile"
#include "QTreeWidget"
#include "QTableWidget"
#include "QTimer"
#include "QProcess"
#include "QSound"
#include "helpdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    QSound::play("./Sound/Windows XP.wav");
    Global::init();
    ui->setupUi(this);

    QString title = QString(tr("  德语背单词 -- 当前用户："));
    this->setWindowTitle(title);

    QIcon icon = QIcon("./rc/ansle.png");
    this->setWindowIcon(icon);
    //创建托盘图标
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);

    QString titlec=tr("德语背单词");
    QString textc=tr("德语背单词：快速长时间重复记忆德语单词");
    trayIcon->show();

    //弹出气泡提示
    trayIcon->showMessage(titlec,textc,QSystemTrayIcon::Information,5000);

    //添加单/双击鼠标相应
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,SLOT(trayiconActivated(QSystemTrayIcon::ActivationReason)));

    //创建监听行为
    minimizeAction = new QAction(tr("最小化 (&I)"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
    restoreAction = new QAction(tr("还原 (&R)"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    quitAction = new QAction(tr("退出 (&Q)"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    //创建右键弹出菜单
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayIconMenu);
/*
    QSplitter *splitter = new QSplitter(Qt::Horizontal,ui->frame);
    splitter->addWidget(ui->treeWidget);
    splitter->addWidget(ui->tableWidget);
    splitter->setSizes(QList<int>() << 175 << 360);
    splitter->setStretchFactor(0,1);
    splitter->setStretchFactor(1,1);
    splitter->setHandleWidth(3);

    QGridLayout *mainLayout = new QGridLayout(ui->frame);
    mainLayout->addWidget(splitter);
*/

    ui->statusBar->showMessage(tr("欢迎您使用德语背单词软件！ -- ansleliu"), 8000);
    QLabel *per = new QLabel("了解更多信息请访问：<a href = http://hi.baidu.com/ansleliu>我的百度空间主页</a>",this);
    per->openExternalLinks();
    connect(per,SIGNAL(linkActivated(QString)),this,SLOT(openUrl(QString)));
    ui->statusBar->addPermanentWidget(per); //现实永久信息

    QTimer::singleShot(200, this, SLOT(display()));
}

MainWindow::~MainWindow()
{
    if(bcMgr != NULL)
    {
        bcMgr->deleteLater();
        bcMgr = NULL;
        qDebug() << QString("主程序关闭-bcMgr-成功");
    }
    if(userBookDBMgr != NULL)
    {
        delete userBookDBMgr;
        userBookDBMgr = NULL;
        qDebug() << QString("主程序关闭-userBookDBMgr-成功");
    }
    if(learnMgr != NULL)
    {
        learnMgr->deleteLater();
        learnMgr = NULL;
        qDebug() << QString("主程序关闭-learnMgr-成功");
    }
    /////////////////////////////////////
    //
    trayIcon->deleteLater();
    trayIcon = NULL;
    minimizeAction->deleteLater();
    minimizeAction = NULL;
    restoreAction->deleteLater();
    restoreAction = NULL;
    quitAction->deleteLater();
    quitAction = NULL;
    trayIconMenu->deleteLater();
    trayIconMenu = NULL;
    delete ui;
    qDebug() << QString("主程序关闭清除各指针成功");
    ///////////////////////////////////
    //
    Global::uninit();
    qDebug() << QString("主程序安全退出");
}

void MainWindow::display(bool bDisableAutoLogin)
{
    loginDialog *login;
    login = new loginDialog(this,bDisableAutoLogin);

    if(login->exec() == QDialog::Accepted)
    {
        QString currentUser = Global::Conf->getCurrentUser();

        QString title = QString(tr("  德语背单词 -- 当前用户：%1 ")).arg(currentUser);
        this->setWindowTitle(title);

        QString tip = QString(tr("德语背单词\n当前用户：%1")).arg(currentUser);
        trayIcon->setToolTip(tip);

        if(bcMgr != NULL)
        {
            delete bcMgr;
        }
        bcMgr = new BCMgr(this,currentUser);

        if(learnMgr != NULL)
        {
            delete learnMgr;
        }
        learnMgr = new LearnMgr(this,currentUser);

        ui->treeWidget->clear();
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setColumnCount(0);

        bcMgr->showBookList(ui->treeWidget);
        login->close();
        delete login;
        login = NULL;
    }
    else
    {
        on_action_Quit_triggered();
        login->close();
        delete login;
        login = NULL;
    }
}

void MainWindow::redisplay()
{
    //切换用户前要把之前的用户数据保存

    //切换用户
    display(true);
}

void MainWindow::on_action_ChgUser_triggered()
{
    redisplay();
}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    QString text = "";
    if(item->parent() == NULL)
    {
        ui->tableWidget->setColumnCount(5);
        QStringList headers;
        headers<<tr("分类")<<tr("词库名")<<tr("词汇量")<<tr("已背单词")<<tr("须复习");
        ui->tableWidget->setHorizontalHeaderLabels(headers);

        text = item->text(column);
        QStringList bookList;
        bookList = bcMgr->getBookNames(text);

        ui->tableWidget->setRowCount(bookList.size());
        for(int i=0; i<bookList.size(); i++)
        {
            bookPath = bcMgr->getBookPaths(text,bookList.at(i));
            if(userBookDBMgr != NULL)
            {
                delete userBookDBMgr;
            }
            userBookDBMgr = new UserBookDBMgr(bookPath,bcMgr->getBookName(bookPath));
            int wordNum = userBookDBMgr->getWortCount();
            bcMgr->updateTotalNumb(bookPath,wordNum);

            ui->tableWidget->setItem(i,0,new QTableWidgetItem(text));
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(bookList.at(i)));

            int totalNumb = bcMgr->getTotalNumb(text,bookList.at(i));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(totalNumb,'i',0)));

            int learnedNumb = bcMgr->getHaveLearnedNum(text,bookList.at(i));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(learnedNumb,'i',0)));

            QString bookpath = bcMgr->getBookPaths(text,bookList.at(i));
            int needReview = learnMgr->getReviewWordID("StateTable",bookpath).count();
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(needReview,'i',0)));
        }
    }
    else
    {
        ui->tableWidget->clear();
        ui->tableWidget->setColumnCount(5);
        QStringList headers;
        headers<<tr("词库名")<<tr("用户名")<<tr("词汇量")<<tr("已背单词")<<tr("须复习");
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        ui->tableWidget->setRowCount(1);

        text = item->text(column);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(text));

        QString userName = bcMgr->getUserName();
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(userName));

        QTreeWidgetItem *bookClass = item->parent();
        QString rootName = bookClass->text(column);

        bookPath = bcMgr->getBookPaths(rootName,text);
        if(userBookDBMgr != NULL)
        {
            delete userBookDBMgr;
        }
        userBookDBMgr = new UserBookDBMgr(bookPath,bcMgr->getBookName(bookPath));
        int wordNum = userBookDBMgr->getWortCount();
        bcMgr->updateTotalNumb(bookPath,wordNum);

        int totalNumb = bcMgr->getTotalNumb(rootName,text);
        ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(totalNumb,'i',0)));

        int learnedNumb = bcMgr->getHaveLearnedNum(rootName,text);
        ui->tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(learnedNumb,'i',0)));

        QString bookpath = bcMgr->getBookPaths(rootName,text);
        int needReview = learnMgr->getReviewWordID("StateTable",bookpath).count();
        ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::number(needReview,'i',0)));
    }
}

void MainWindow::on_action_Add_triggered()
{
    AddBookDialog *addDiag;
    addDiag = new AddBookDialog(this);
    if(addDiag->exec() == QDialog::Accepted)
    {
//        if (QMessageBox::information(this, tr("提示信息"), tr("您确定要添加新词库吗?"),
//                                     QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        {
            QString bookName = addDiag->getBookName();
            QString className = addDiag->getClassName();
            bookPath = addDiag->getBookPath();

            if(userBookDBMgr != NULL)
            {
                delete userBookDBMgr;
            }
            userBookDBMgr = new UserBookDBMgr(bookPath,bcMgr->getBookName(bookPath));
            int wordNum = userBookDBMgr->getWortCount();

            if(bcMgr->addNewBook(className,bookName,bookPath,wordNum))
            {
                bookPath = "";
                bcMgr->addChildItem(ui->treeWidget,className,bookName);
                addDiag->close();
                delete addDiag;
                addDiag = NULL;
            }
            else
            {
                QMessageBox::warning(this,tr("错误"),tr("\n该词库已经存在!"));
                addDiag->close();
                delete addDiag;
                addDiag = NULL;
            }
        }
    }
    else
    {
        addDiag->close();
        delete addDiag;
        addDiag = NULL;
    }
}

void MainWindow::on_action_About_triggered()
{
    aboutDialog *aboutD = new aboutDialog(this);
    if(aboutD->exec() == QDialog::Rejected)
    {
        aboutD->close();
        delete aboutD;
        aboutD = NULL;
    }
    else
    {
        aboutD->close();
        delete aboutD;
        aboutD = NULL;
    }
}

void MainWindow::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    QTreeWidgetItem* curItem = ui->treeWidget->itemAt(pos);//获取当前被点击的节点

    if(curItem == NULL)//这种情况是右键的位置不在treeItem的范围内，即在空白位置右击
    {
        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
        popMenu->addAction(ui->action_refresh);
        popMenu->addAction(ui->action_addClass);
        popMenu->addAction(ui->action_Add);
        popMenu->addAction(ui->action_Delete);
        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
        delete popMenu;
    }
    else
    {
        if (curItem->parent() == NULL)
        {
            QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
            popMenu->addAction(ui->action_addNewBook);
            popMenu->addAction(ui->action_deleteClass);
            popMenu->addAction(ui->action_editItem);
            popMenu->addAction(ui->action_addClass);

            popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
            delete popMenu;
        }
        else
        {
            QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
            popMenu->addAction(ui->action_Learn);
            popMenu->addAction(ui->action_Analysis);
            popMenu->addAction(ui->action_deleteBook);
            popMenu->addAction(ui->action_Edit);
            popMenu->addAction(ui->action_editItem);
            popMenu->addAction(ui->action_addNewBook);

            popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
            delete popMenu;
        }
    }
}

void MainWindow::on_action_Delete_triggered()
{
    QTreeWidgetItem* currItem = ui->treeWidget->currentItem();
    if(currItem != NULL)
    {
        if(currItem->parent() == NULL)
        {
            QMessageBox::warning(this, tr("注意"),tr("请选择要移除的词库"));
        }
        else
        {
            DeleteBookDialog *deleteDiag;
            deleteDiag = new DeleteBookDialog(this);

            deleteDiag->setClassName(currItem->parent()->text(0));
            deleteDiag->setBookName(currItem->text(0));

            if(deleteDiag->exec() == QDialog::Accepted)
            {
                if (QMessageBox::information(this, tr("提示信息"), tr("您确定要删除这个词库吗?"),
                                             QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
                {
                    QString bookpath = bcMgr->getBookPaths(currItem->parent()->text(0),currItem->text(0));
                    QString table = QString("StateTable");
                    if(learnMgr->isExist(table,bookpath))
                    {
                        learnMgr->deleteRecord(table,bookpath);
                    }

                    bcMgr->deleteBook(currItem->parent()->text(0),currItem->text(0));
                    bcMgr->removeChildItem(ui->treeWidget);

                    ui->treeWidget->clear();
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(0);
                    ui->tableWidget->setColumnCount(0);

                    bcMgr->showBookList(ui->treeWidget);
                }
                deleteDiag->close();
                delete deleteDiag;
                deleteDiag = NULL;
            }
            else
            {
                deleteDiag->close();
                delete deleteDiag;
                deleteDiag = NULL;
            }
        }
    }
    else
    {
        DeleteBookDialog *deleteDiag;
        deleteDiag = new DeleteBookDialog(this);

        if(deleteDiag->exec() == QDialog::Accepted)
        {
            if (QMessageBox::information(this, tr("提示信息"), tr("您确定要删除这个词库吗?"),
                                         QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
            {
                QString bookName = deleteDiag->getBookName();
                QString className = deleteDiag->getClassName();

                QString bookpath = bcMgr->getBookPaths(className,bookName);
                if(learnMgr->isExist("StateTable",bookpath))
                {
                    learnMgr->deleteRecord("StateTable",bookpath);
                }


                bcMgr->deleteBook(className,bookName);

                ui->treeWidget->clear();
                ui->tableWidget->clearContents();
                ui->tableWidget->setRowCount(0);
                ui->tableWidget->setColumnCount(0);

                bcMgr->showBookList(ui->treeWidget);
            }
            deleteDiag->close();
            delete deleteDiag;
            deleteDiag = NULL;
        }
        else
        {
            deleteDiag->close();
            delete deleteDiag;
            deleteDiag = NULL;
        }
    }
}

void MainWindow::on_action_Edit_triggered()
{
    QTreeWidgetItem* currItem = ui->treeWidget->currentItem();

    if(currItem != NULL && currItem->parent() != NULL)
    {
        QString currBook = currItem->text(0);
        QString currBookClass = currItem->parent()->text(0);
        QString currBookPath = bcMgr->getBookPaths(currBookClass,currBook);

        BookEditDialog *bookEditDiag;
        bookEditDiag = new BookEditDialog(this,currBookPath);
        if(bookEditDiag->exec() == QDialog::Rejected)
        {
            if(userBookDBMgr)
            {
                delete userBookDBMgr;
            }
            userBookDBMgr = new UserBookDBMgr(currBookPath,bcMgr->getBookName(currBookPath));
            int wordNum = userBookDBMgr->getWortCount();

            bcMgr->updateTotalNumb(currBookClass,currBook,wordNum);
            on_treeWidget_itemClicked(currItem,0);

            bookEditDiag->close();
            delete bookEditDiag;
            bookEditDiag = NULL;
        }
        else
        {
            bookEditDiag->close();
            delete bookEditDiag;
            bookEditDiag = NULL;
        }
    }
    else if(currItem != NULL && currItem->parent() == NULL)
    {
        QString roottext = "";
        roottext = currItem->text(0);
        QStringList bookList;
        bookList = bcMgr->getBookNames(roottext);

        QString bookName = "";

        QTableWidgetItem *currTabletItem = ui->tableWidget->currentItem();
        if(currTabletItem != NULL)
        {
            int row = currTabletItem->row();
            bookName = currItem->child(row)->text(0);

            QString currBookPath = bcMgr->getBookPaths(roottext,bookName);

            BookEditDialog *bookEditDiag;
            bookEditDiag = new BookEditDialog(this,currBookPath);
            if(bookEditDiag->exec() == QDialog::Rejected)
            {
                if(userBookDBMgr)
                {
                    delete userBookDBMgr;
                }
                userBookDBMgr = new UserBookDBMgr(currBookPath,bcMgr->getBookName(currBookPath));
                int wordNum = userBookDBMgr->getWortCount();

                bcMgr->updateTotalNumb(roottext,bookName,wordNum);
                on_treeWidget_itemClicked(currItem,0);

                bookEditDiag->close();
                delete bookEditDiag;
                bookEditDiag = NULL;
            }
            else
            {
                bookEditDiag->close();
                delete bookEditDiag;
                bookEditDiag = NULL;
            }
        }
        else
        {
            QMessageBox::warning(this, tr("注意"),tr("注意:\n请选择要编辑的词库!"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("注意"),tr("注意:\n请选择要编辑的词库!"));
    }
}

void MainWindow::on_action_addClass_triggered()
{
    AddRootDialog * addRoot;
    addRoot = new AddRootDialog(this);
    if(addRoot->exec() == QDialog::Accepted)
    {
        QString newRoot = addRoot->getNewRoot();
        bcMgr->addRootItem(ui->treeWidget,newRoot);

        addRoot->close();
        delete addRoot;
        addRoot = NULL;
    }
    else
    {
        addRoot->close();
        delete addRoot;
        addRoot = NULL;
    }
}

void MainWindow::on_action_deleteClass_triggered()
{
    QTreeWidgetItem* currItem = ui->treeWidget->currentItem();

    if(currItem != NULL && currItem->parent() == NULL)
    {
        if (QMessageBox::information(this, tr("提示信息"), tr("您确定要删除这个分类及其下的所有内容吗?"),
                                     QMessageBox::Yes | QMessageBox::No)
                == QMessageBox::Yes)
        {
            int childCount = currItem->childCount();
            for(int i=0; i<childCount; i++)
            {
                QString bookpath = bcMgr->getBookPaths(currItem->text(0),currItem->child(i)->text(0));
                if(learnMgr->isExist("StateTable",bookpath))
                {
                    learnMgr->deleteRecord("StateTable",bookpath);
                }

                bcMgr->deleteBook(currItem->text(0),currItem->child(i)->text(0));
            }

            bcMgr->removeRootItem(ui->treeWidget);
        }
    }
}

void MainWindow::on_action_addNewBook_triggered()
{
    AddBookDialog *addDiag;
    addDiag = new AddBookDialog(this);
    QTreeWidgetItem* currItem = ui->treeWidget->currentItem();
    if(currItem != NULL && currItem->parent() == NULL)
    {
        addDiag->setClassName(currItem->text(0));
    }
    else if(currItem != NULL && currItem->parent() != NULL)
    {
        addDiag->setClassName(currItem->parent()->text(0));
    }

    if(addDiag->exec() == QDialog::Accepted)
    {
//        if (QMessageBox::information(this, tr("提示信息"), tr("您确定要添加新词库吗?"),
//                                     QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        {
            QString bookName = addDiag->getBookName();
            QString className = addDiag->getClassName();
            bookPath = addDiag->getBookPath();

            if(userBookDBMgr)
            {
                delete userBookDBMgr;
            }
            userBookDBMgr = new UserBookDBMgr(bookPath,bcMgr->getBookName(bookPath));
            int wordNum = userBookDBMgr->getWortCount();

            if(bcMgr->addNewBook(className,bookName,bookPath,wordNum))
            {
                bcMgr->addChildItem(ui->treeWidget,className,bookName);
                addDiag->close();
                delete addDiag;
                addDiag = NULL;
            }
            else
            {
                QMessageBox::warning(this,tr("错误"),tr("\n该词库已经存在!"));

                addDiag->close();
                delete addDiag;
                addDiag = NULL;
            }
        }
    }
    else
    {
        addDiag->close();
        delete addDiag;
        addDiag = NULL;
    }
}

void MainWindow::on_action_deleteBook_triggered()
{
    if (QMessageBox::information(this, tr("提示信息"), tr("您确定要删除这个词库吗?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        QTreeWidgetItem* currItem = ui->treeWidget->currentItem();
        if(currItem != NULL)
        {
            if(currItem->parent() == NULL)
            {
                QString roottext = "";
                roottext = currItem->text(0);
                QStringList bookList;
                bookList = bcMgr->getBookNames(roottext);

                QString bookName = "";

                QTableWidgetItem *currTabletItem = ui->tableWidget->currentItem();

                if(currTabletItem != NULL)
                {
                    int row = currTabletItem->row();
                    bookName = currItem->child(row)->text(0);

                    QString bookpath = bcMgr->getBookPaths(roottext,bookName);
                    if(learnMgr->isExist("StateTable",bookpath))
                    {
                        learnMgr->deleteRecord("StateTable",bookpath);
                    }

                    bcMgr->deleteBook(roottext,bookName);
                    bcMgr->removeChildItemByRow(ui->treeWidget,row);

                    ui->treeWidget->clear();
                    ui->tableWidget->clearContents();
                    ui->tableWidget->setRowCount(0);
                    ui->tableWidget->setColumnCount(0);

                    bcMgr->showBookList(ui->treeWidget);

                    on_treeWidget_itemClicked(currItem, 0);
                }
            }
            else
            {
                QString bookpath = bcMgr->getBookPaths(currItem->parent()->text(0),
                                                       currItem->text(0));
                if(learnMgr->isExist("StateTable",bookpath))
                {
                    learnMgr->deleteRecord("StateTable",bookpath);
                }

                bcMgr->deleteBook(currItem->parent()->text(0),currItem->text(0));
                bcMgr->removeChildItem(ui->treeWidget);

                ui->tableWidget->clearContents();
                ui->tableWidget->setRowCount(0);
                ui->tableWidget->setColumnCount(0);

                bcMgr->showBookList(ui->treeWidget);
            }
        }
    }
}

void MainWindow::on_action_editItem_triggered()
{
    editItemDialog *editItem;
    editItem = new editItemDialog(this);

//    if (QMessageBox::information(this, tr("提示信息"), tr("您确定要修改名称吗?"),
//                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        QTreeWidgetItem* currItem = ui->treeWidget->currentItem();
        if(currItem != NULL && currItem->parent() == NULL)
        {
            editItem->setGroupText(tr("请在下面输入框内输入新的分类名:"));
            if(editItem->exec() == QDialog::Accepted)
            {
                QString newItemText = editItem->getNewItemText();
                bcMgr->updateBookClass(ui->treeWidget,currItem->text(0),newItemText);

                bcMgr->showBookList(ui->treeWidget);

                editItem->close();
                delete editItem;
                editItem = NULL;
            }
            else
            {
                editItem->close();
                delete editItem;
                editItem = NULL;
            }
        }
        else if(currItem != NULL && currItem->parent() != NULL)
        {
            editItem->setGroupText(tr("请在下面输入框内输入新的词库名:"));
            if(editItem->exec() == QDialog::Accepted)
            {
                QString newItemText = editItem->getNewItemText();
                if(!bcMgr->updateBookName(ui->treeWidget,currItem->parent()->text(0),
                                          currItem->text(0),newItemText))
                {
                    QMessageBox::warning(this,tr("错误"),tr("\n以此名命名的词库已经存在,词库不得重名!"));

                    editItem->close();
                    delete editItem;
                    editItem = NULL;
                }
            }
            else
            {
                editItem->close();
                delete editItem;
                editItem = NULL;
            }
        }
        else
        {
            QMessageBox::warning(this, tr("注意"),tr("注意:\n请选择要编辑的对象!"));
        }
    }
}

void MainWindow::on_action_BookeEditor_triggered()
{
//        QProcess::startDetached("./wortschatz/WortschatzEditor.exe",QStringList());
        QProcess::startDetached("./WortschatzEditor.exe",QStringList());
}

void MainWindow::on_action_Learn_triggered()
{
    QTreeWidgetItem* currItem = ui->treeWidget->currentItem();

    if(currItem != NULL && currItem->parent() != NULL)
    {
        QString currBook = currItem->text(0);
        QString currBookClass = currItem->parent()->text(0);
        QString currBookPath = bcMgr->getBookPaths(currBookClass,currBook);
        ////////////////////////////////////
        //此处添加学习代码

        LearnStartDialog *startLearn;
        startLearn = new LearnStartDialog(this,currBookPath);
        if(startLearn->exec() == QDialog::Accepted)
        {
            if(bcMgr->getLearnState(currBookPath) == 0)
            {
                bcMgr->updateLearnState(currBookPath,true);
            }
            bool learnByLektion = startLearn->getLearnByLektion();
            QString learnOrReview = startLearn->learnOrReview();
            int lektion = startLearn->getLektion();
            this->hide();

            startLearn->close();
            startLearn->deleteLater();
            startLearn = NULL;

            LearnWordDialog *learnWord;
            learnWord = new LearnWordDialog(NULL,currBookPath,learnOrReview,learnByLektion,lektion);
            if(learnWord->exec() == QDialog::Rejected)
            {
                //////////////////////////////////////////
                //保存已学词汇信息
                int recordCount = learnMgr->getRecordCount();
                QString date = QDate::currentDate().toString("yyyy-MM-dd");
                if(bcMgr->existsDayRecord(currBookPath,date))
                {
                    if(learnOrReview == "Learn")
                    {
                        int oldCount = bcMgr->getDayLearnRecord(currBookPath,date);
                        int newLearnCount = oldCount + recordCount;
                        bcMgr->updateLearnRecord(currBookPath,date,newLearnCount);
                    }
                    else if(learnOrReview == "Review")
                    {
                        int oldCount = bcMgr->getDayReviewRecord(currBookPath,date);
                        int newLearnCount = oldCount + recordCount;
                        bcMgr->updateReviewRecord(currBookPath,date,newLearnCount);
                    }
                    else
                    {}
                }
                else
                {
                    if(learnOrReview == "Learn")
                    {
                        bcMgr->addNewBookStudyRecord(currBookPath,date,recordCount,0);
                    }
                    else if(learnOrReview == "Review")
                    {
                        bcMgr->addNewBookStudyRecord(currBookPath,date,0,recordCount);
                    }
                    else
                    {}
                }
                ////////////////////////////////////////////////////////////////////////
                //
                learnMgr->transferRecord();
                int haveLearned = learnMgr->getHaveLearnedWordCount(currBookPath);
                bcMgr->updateHaveLearnedNum(currBookPath,haveLearned);
                on_treeWidget_itemClicked(currItem,0);
//                on_action_refresh_triggered();

                //////////////////////////////////////////
                //显示主窗口
                learnWord->close();
                learnWord->deleteLater();
                learnWord = NULL;
                this->show();
            }
            else
            {
                learnWord->close();
                learnWord->deleteLater();
                learnWord = NULL;
                this->show();
            }
        }
    }
    else if(currItem != NULL && currItem->parent() == NULL)
    {
        QString roottext = "";
        roottext = currItem->text(0);
        QStringList bookList;
        bookList = bcMgr->getBookNames(roottext);

        QString bookName = "";

        QTableWidgetItem *currTabletItem = ui->tableWidget->currentItem();
        if(currTabletItem != NULL)
        {
            int row = currTabletItem->row();
            bookName = currItem->child(row)->text(0);

            QString currBookPath = bcMgr->getBookPaths(roottext,bookName);
            ///////////////////////////////////
            //此处添加学习代码
            LearnStartDialog *startLearn;
            startLearn = new LearnStartDialog(this,currBookPath);
            if(startLearn->exec() == QDialog::Accepted)
            {
                if(bcMgr->getLearnState(currBookPath) == 0)
                {
                    bcMgr->updateLearnState(currBookPath,true);
                }
                bool learnByLektion = startLearn->getLearnByLektion();
                QString learnOrReview = startLearn->learnOrReview();
                int lektion = startLearn->getLektion();
                this->hide();

                startLearn->close();
                startLearn->deleteLater();
                startLearn = NULL;

                LearnWordDialog *learnWord;
                learnWord = new LearnWordDialog(NULL,currBookPath,learnOrReview,learnByLektion,lektion);
                if(learnWord->exec() == QDialog::Rejected)
                {
                    ////////////////////////////////////////
                    //保存已学词汇信息
                    int recordCount = learnMgr->getRecordCount();
                    QString date = QDate::currentDate().toString("yyyy-MM-dd");
                    if(bcMgr->existsDayRecord(currBookPath,date))
                    {
                        if(learnOrReview == "Learn")
                        {
                            int oldCount = bcMgr->getDayLearnRecord(currBookPath,date);
                            int newLearnCount = oldCount + recordCount;
                            bcMgr->updateLearnRecord(currBookPath,date,newLearnCount);
                        }
                        else if(learnOrReview == "Review")
                        {
                            int oldCount = bcMgr->getDayReviewRecord(currBookPath,date);
                            int newLearnCount = oldCount + recordCount;
                            bcMgr->updateReviewRecord(currBookPath,date,newLearnCount);
                        }
                        else
                        {}
                    }
                    else
                    {
                        if(learnOrReview == "Learn")
                        {
                            bcMgr->addNewBookStudyRecord(currBookPath,date,recordCount,0);
                        }
                        else if(learnOrReview == "Review")
                        {
                            bcMgr->addNewBookStudyRecord(currBookPath,date,0,recordCount);
                        }
                        else
                        {}
                    }


                    learnMgr->transferRecord();
                    int haveLearned = learnMgr->getHaveLearnedWordCount(currBookPath);
                    bcMgr->updateHaveLearnedNum(currBookPath,haveLearned);
                    currItem->setSelected(false);
                    currItem->child(row)->setSelected(true);
                    on_treeWidget_itemClicked(currItem->child(row),0);
//                    on_action_refresh_triggered();


                    ////////////////////////////////////////
                    //显示主窗口
                    learnWord->close();
                    learnWord->deleteLater();
                    learnWord = NULL;
                    this->show();
                }
                else
                {
                    learnWord->close();
                    learnWord->deleteLater();
                    learnWord = NULL;
                    this->show();
                }
            }
            else
            {
                startLearn->close();
                startLearn->deleteLater();
                startLearn = NULL;
            }
        }
        else
        {
            QMessageBox::warning(this, tr("注意"),tr("注意:\n请选择要学习的词库!"));
        }
    }
    else
    {
        QMessageBox::warning(this, tr("注意"),tr("注意:\n请选择要学习的词库!"));
    }
}

void MainWindow::on_action_Review_triggered()
{

}

void MainWindow::on_action_Analysis_triggered()
{
    AnalysisDialog *analysis;
    analysis = new AnalysisDialog(this);
    if(analysis->exec() == QDialog::Rejected)
    {

    }
    analysis->close();
    delete analysis;
    analysis = NULL;
}

void MainWindow::on_action_Options_triggered()
{
    OptionsDialog *option;
    option = new OptionsDialog(this);
    if(option->exec() == QDialog::Accepted)
    {
        on_action_refresh_triggered();      
    }
    else
    {
        on_action_refresh_triggered();
    }
    option->close();
    delete option;
    option = NULL;
}

void MainWindow::on_action_Help_triggered()
{
    QStringList openchm("./DeutschWortRezitieren_ReadMe.chm");
    QProcess::startDetached("hh.exe",openchm);
}

void MainWindow::on_action_AboutQT_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_action_Quit_triggered()
{
    if(QMessageBox::information(this, tr("提示信息"), tr("您确定要退出吗?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        QApplication::closeAllWindows();
    }
    else
    {

    }
}

void MainWindow::on_tableWidget_customContextMenuRequested(const QPoint &pos)
{
    QTableWidgetItem *currentItem = ui->tableWidget->itemAt(pos);
    if(currentItem == NULL)//这种情况是右键的位置不在tableItem的范围内，即在空白位置右击
    {

    }
    else
    {
        QMenu *popMenu =new QMenu(this);//定义一个右键弹出菜单
        popMenu->addAction(ui->action_Learn);
        popMenu->addAction(ui->action_Analysis);
        popMenu->addAction(ui->action_Edit);
        popMenu->addAction(ui->action_deleteBook);

        popMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
        delete popMenu;
    }
}

void MainWindow::on_action_refresh_triggered()
{
    bcMgr->showBookList(ui->treeWidget);

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
}

void MainWindow::trayiconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason)
    {
        case QSystemTrayIcon::Trigger:
            //单击托盘图标
            {
                if(this->isHidden())
                {
                    this->showNormal();
                    this->raise();
                    break;
                }
                else
                {
                    this->hide();
                    break;
                }
            }
        case QSystemTrayIcon::DoubleClick:
            //双击托盘图标
            {
                if(this->isHidden())
                {
                    this->showNormal();
                    this->raise();
                    break;
                }
                else
                {
                    this->hide();
                    break;
                }
            }
        default:
            break;
    }
}

void MainWindow::on_action_Dict_triggered()
{
    qDebug() << "启动电子词典";
    QProcess::startDetached("./AnsleDict.exe",QStringList());
}

void MainWindow::on_action_Support_triggered()
{
    HelpDialog *suport;
    suport = new HelpDialog(this);

    if(suport->exec() == QDialog::Accepted)
    {

    }
    suport->close();
    suport->deleteLater();
    suport = NULL;
}

void MainWindow::openUrl(const QString &url)
{
    QDesktopServices::openUrl(QUrl(url));
}
