/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Nov 24 04:05:56 2015
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_ChgUser;
    QAction *action_Quit;
    QAction *action_Learn;
    QAction *action_Delete;
    QAction *action_Edit;
    QAction *action_Add;
    QAction *action_Analysis;
    QAction *action_BookeEditor;
    QAction *action_Options;
    QAction *action_Help;
    QAction *action_Support;
    QAction *action_About;
    QAction *action_AboutQT;
    QAction *action_addClass;
    QAction *action_deleteClass;
    QAction *action_addNewBook;
    QAction *action_deleteBook;
    QAction *action_editItem;
    QAction *action_refresh;
    QAction *action_Review;
    QAction *action_Dict;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(732, 415);
        action_ChgUser = new QAction(MainWindow);
        action_ChgUser->setObjectName(QString::fromUtf8("action_ChgUser"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/switchuser.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ChgUser->setIcon(icon);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/system_shutdown.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Quit->setIcon(icon1);
        action_Learn = new QAction(MainWindow);
        action_Learn->setObjectName(QString::fromUtf8("action_Learn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Learn->setIcon(icon2);
        action_Delete = new QAction(MainWindow);
        action_Delete->setObjectName(QString::fromUtf8("action_Delete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/vcs_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Delete->setIcon(icon3);
        action_Edit = new QAction(MainWindow);
        action_Edit->setObjectName(QString::fromUtf8("action_Edit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Edit->setIcon(icon4);
        action_Add = new QAction(MainWindow);
        action_Add->setObjectName(QString::fromUtf8("action_Add"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/vcs_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Add->setIcon(icon5);
        action_Analysis = new QAction(MainWindow);
        action_Analysis->setObjectName(QString::fromUtf8("action_Analysis"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/view_statistics.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Analysis->setIcon(icon6);
        action_BookeEditor = new QAction(MainWindow);
        action_BookeEditor->setObjectName(QString::fromUtf8("action_BookeEditor"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix2/rc/edit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_BookeEditor->setIcon(icon7);
        action_Options = new QAction(MainWindow);
        action_Options->setObjectName(QString::fromUtf8("action_Options"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/tool.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Options->setIcon(icon8);
        action_Help = new QAction(MainWindow);
        action_Help->setObjectName(QString::fromUtf8("action_Help"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/help_contents.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Help->setIcon(icon9);
        action_Support = new QAction(MainWindow);
        action_Support->setObjectName(QString::fromUtf8("action_Support"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix2/rc/love.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Support->setIcon(icon10);
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QString::fromUtf8("action_About"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix2/rc/ansle.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_About->setIcon(icon11);
        action_AboutQT = new QAction(MainWindow);
        action_AboutQT->setObjectName(QString::fromUtf8("action_AboutQT"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/qt-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_AboutQT->setIcon(icon12);
        action_addClass = new QAction(MainWindow);
        action_addClass->setObjectName(QString::fromUtf8("action_addClass"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/archive_insert.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_addClass->setIcon(icon13);
        action_deleteClass = new QAction(MainWindow);
        action_deleteClass->setObjectName(QString::fromUtf8("action_deleteClass"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/archive_remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_deleteClass->setIcon(icon14);
        action_addNewBook = new QAction(MainWindow);
        action_addNewBook->setObjectName(QString::fromUtf8("action_addNewBook"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_addNewBook->setIcon(icon15);
        action_deleteBook = new QAction(MainWindow);
        action_deleteBook->setObjectName(QString::fromUtf8("action_deleteBook"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_deleteBook->setIcon(icon16);
        action_editItem = new QAction(MainWindow);
        action_editItem->setObjectName(QString::fromUtf8("action_editItem"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/edit_rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_editItem->setIcon(icon17);
        action_refresh = new QAction(MainWindow);
        action_refresh->setObjectName(QString::fromUtf8("action_refresh"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/view_refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_refresh->setIcon(icon18);
        action_Review = new QAction(MainWindow);
        action_Review->setObjectName(QString::fromUtf8("action_Review"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/prefix1/rc/actions/player_time.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Review->setIcon(icon19);
        action_Dict = new QAction(MainWindow);
        action_Dict->setObjectName(QString::fromUtf8("action_Dict"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/new/prefix2/rc/book2.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Dict->setIcon(icon20);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMaximumSize(QSize(16777215, 16777215));
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new QTreeWidget(splitter);
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/new/prefix2/rc/kontact.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setIcon(0, icon21);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setMinimumSize(QSize(50, 0));
        treeWidget->setMaximumSize(QSize(218, 16777215));
        treeWidget->setFocusPolicy(Qt::TabFocus);
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        treeWidget->setLayoutDirection(Qt::LeftToRight);
        treeWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        treeWidget->setSortingEnabled(false);
        treeWidget->setAllColumnsShowFocus(false);
        splitter->addWidget(treeWidget);
        tableWidget = new QTableWidget(splitter);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setFocusPolicy(Qt::TabFocus);
        tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->setSortingEnabled(false);
        splitter->addWidget(tableWidget);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 732, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(action_ChgUser);
        menu->addSeparator();
        menu->addAction(action_Quit);
        menu_2->addAction(action_Learn);
        menu_2->addAction(action_Edit);
        menu_2->addSeparator();
        menu_2->addAction(action_Add);
        menu_2->addAction(action_Delete);
        menu_3->addAction(action_BookeEditor);
        menu_3->addAction(action_Analysis);
        menu_3->addAction(action_Dict);
        menu_3->addSeparator();
        menu_3->addAction(action_Options);
        menu_4->addAction(action_Help);
        menu_4->addAction(action_Support);
        menu_4->addSeparator();
        menu_4->addAction(action_AboutQT);
        menu_4->addAction(action_About);
        mainToolBar->addAction(action_ChgUser);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Add);
        mainToolBar->addAction(action_Delete);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_addClass);
        mainToolBar->addAction(action_Edit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Learn);
        mainToolBar->addAction(action_Analysis);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_BookeEditor);
        mainToolBar->addAction(action_Dict);
        mainToolBar->addSeparator();
        mainToolBar->addAction(action_Options);
        mainToolBar->addAction(action_Support);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_ChgUser->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_ChgUser->setToolTip(QApplication::translate("MainWindow", "\345\210\207\346\215\242\345\210\260\345\217\246\344\270\200\347\224\250\346\210\267\346\210\226\346\226\260\345\273\272\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_ChgUser->setStatusTip(QApplication::translate("MainWindow", "\345\210\207\346\215\242\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_ChgUser->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+C", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Quit->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\345\276\267\350\257\255\350\203\214\345\215\225\350\257\215\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Quit->setStatusTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Learn->setText(QApplication::translate("MainWindow", "\345\255\246\344\271\240", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Learn->setToolTip(QApplication::translate("MainWindow", "\345\255\246\344\271\240\346\226\260\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Learn->setStatusTip(QApplication::translate("MainWindow", "\345\255\246\344\271\240", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Learn->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        action_Delete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Delete->setToolTip(QApplication::translate("MainWindow", "\347\247\273\351\231\244\344\270\200\344\270\252\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Delete->setStatusTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Delete->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+D", 0, QApplication::UnicodeUTF8));
        action_Edit->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Edit->setToolTip(QApplication::translate("MainWindow", "\347\274\226\350\276\221\344\270\200\344\270\252\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Edit->setStatusTip(QApplication::translate("MainWindow", "\347\274\226\350\276\221\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Edit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+E", 0, QApplication::UnicodeUTF8));
        action_Add->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Add->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\260\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Add->setStatusTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Add->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+A", 0, QApplication::UnicodeUTF8));
        action_Analysis->setText(QApplication::translate("MainWindow", "\347\273\237\350\256\241\345\210\206\346\236\220\345\231\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Analysis->setToolTip(QApplication::translate("MainWindow", "\345\220\257\345\212\250\347\273\237\350\256\241\345\210\206\346\236\220\345\231\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Analysis->setStatusTip(QApplication::translate("MainWindow", "\347\273\237\350\256\241\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Analysis->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        action_BookeEditor->setText(QApplication::translate("MainWindow", "\350\257\215\345\272\223\347\274\226\350\276\221\346\237\245\347\234\213\345\231\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_BookeEditor->setToolTip(QApplication::translate("MainWindow", "\345\220\257\345\212\250\350\257\215\345\272\223\347\274\226\350\276\221\346\237\245\347\234\213\345\231\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_BookeEditor->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\257\215\345\272\223\347\274\226\350\276\221\346\237\245\347\234\213\345\231\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_BookeEditor->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        action_Options->setText(QApplication::translate("MainWindow", "\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Options->setToolTip(QApplication::translate("MainWindow", "\350\275\257\344\273\266\347\232\204\351\205\215\347\275\256\351\200\211\351\241\271", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Options->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\200\211\351\241\271\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Options->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+P", 0, QApplication::UnicodeUTF8));
        action_Help->setText(QApplication::translate("MainWindow", "\345\270\256\345\212\251\346\226\207\346\241\243", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Help->setToolTip(QApplication::translate("MainWindow", "\346\237\245\347\234\213\350\275\257\344\273\266\344\275\277\347\224\250\347\232\204\345\270\256\345\212\251\346\226\207\346\241\243", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Help->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\270\256\345\212\251\346\226\207\346\241\243", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Help->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+H", 0, QApplication::UnicodeUTF8));
        action_Support->setText(QApplication::translate("MainWindow", "\346\224\257\346\214\201\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Support->setToolTip(QApplication::translate("MainWindow", "\346\224\257\346\214\201\350\275\257\344\273\266\347\232\204\345\274\200\345\217\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Support->setStatusTip(QApplication::translate("MainWindow", "\346\224\257\346\214\201\350\275\257\344\273\266\347\232\204\345\274\200\345\217\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        action_Support->setWhatsThis(QApplication::translate("MainWindow", "\346\224\257\346\214\201\350\275\257\344\273\266\347\232\204\345\274\200\345\217\221", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        action_Support->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+S", 0, QApplication::UnicodeUTF8));
        action_About->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_About->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216\350\275\257\344\273\266\345\222\214\344\275\234\350\200\205", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_About->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\205\263\344\272\216\350\275\257\344\273\266", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_AboutQT->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_AboutQT->setToolTip(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_AboutQT->setStatusTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\205\263\344\272\216Qt\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_addClass->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\257\215\345\272\223\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_addClass->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\257\215\345\272\223\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_addClass->setStatusTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\350\257\215\345\272\223\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_addClass->setShortcut(QApplication::translate("MainWindow", "Alt+A", 0, QApplication::UnicodeUTF8));
        action_deleteClass->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\245\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_deleteClass->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\245\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_deleteClass->setStatusTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\245\345\210\206\347\261\273", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_deleteClass->setShortcut(QApplication::translate("MainWindow", "Alt+D", 0, QApplication::UnicodeUTF8));
        action_addNewBook->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\260\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_addNewBook->setToolTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\260\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_addNewBook->setStatusTip(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\260\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_addNewBook->setShortcut(QApplication::translate("MainWindow", "Shift+A", 0, QApplication::UnicodeUTF8));
        action_deleteBook->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\245\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_deleteBook->setToolTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\245\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_deleteBook->setStatusTip(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\257\245\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_deleteBook->setShortcut(QApplication::translate("MainWindow", "Shift+D", 0, QApplication::UnicodeUTF8));
        action_editItem->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\350\257\245\346\235\241\347\233\256", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_editItem->setToolTip(QApplication::translate("MainWindow", "\347\274\226\350\276\221\350\257\245\346\235\241\347\233\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_editItem->setStatusTip(QApplication::translate("MainWindow", "\347\274\226\350\276\221\350\257\245\346\235\241\347\233\256", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_editItem->setShortcut(QApplication::translate("MainWindow", "Shift+E", 0, QApplication::UnicodeUTF8));
        action_refresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\350\257\215\345\272\223\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_refresh->setToolTip(QApplication::translate("MainWindow", "\345\210\267\346\226\260\350\257\215\345\272\223\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_refresh->setStatusTip(QApplication::translate("MainWindow", "\345\210\267\346\226\260\350\257\215\345\272\223\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_refresh->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+F", 0, QApplication::UnicodeUTF8));
        action_Review->setText(QApplication::translate("MainWindow", "\345\244\215\344\271\240", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Review->setToolTip(QApplication::translate("MainWindow", "\345\244\215\344\271\240\345\255\246\350\277\207\347\232\204\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Review->setStatusTip(QApplication::translate("MainWindow", "\345\244\215\344\271\240\345\255\246\350\277\207\347\232\204\345\215\225\350\257\215", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Dict->setText(QApplication::translate("MainWindow", "\345\276\267\350\257\255\350\257\215\345\205\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Dict->setToolTip(QApplication::translate("MainWindow", "\345\220\257\345\212\250\345\276\267\350\257\255\347\224\265\345\255\220\350\257\215\345\205\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action_Dict->setStatusTip(QApplication::translate("MainWindow", "\345\260\206\350\257\215\345\272\223\344\275\234\344\270\272\347\224\265\345\255\220\350\257\215\345\205\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Dict->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\257\215\345\272\223", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", 0, QApplication::UnicodeUTF8));
        menu_4->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
