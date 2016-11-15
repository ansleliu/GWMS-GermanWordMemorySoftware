#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myglobal.h"
#include "bcmgr.h"
#include "QMessageBox"
#include "userbookdbmgr.h"
#include "learnmgr.h"
#include "addbookdialog.h"
#include "aboutdialog.h"
#include "deletebookdialog.h"
#include "addrootdialog.h"
#include "edititemdialog.h"
#include "logindialog.h"
#include "bookeditdialog.h"
#include "learnstartdialog.h"
#include "learnworddialog.h"
#include "optionsdialog.h"
#include "analysisdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void display(bool bDisableAutoLogin = false);

    void redisplay();

    void on_action_ChgUser_triggered();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_action_Add_triggered();

    void on_action_About_triggered();

    void on_treeWidget_customContextMenuRequested(const QPoint &pos);

    void on_action_Delete_triggered();

    void on_action_Edit_triggered();

    void on_action_addClass_triggered();

    void on_action_deleteClass_triggered();

    void on_action_addNewBook_triggered();

    void on_action_deleteBook_triggered();

    void on_action_editItem_triggered();

    void on_action_BookeEditor_triggered();

    void on_action_Learn_triggered();

    void on_action_Review_triggered();

    void on_action_Analysis_triggered();

    void on_action_Options_triggered();

    void on_action_Help_triggered();

    void on_action_AboutQT_triggered();

    void on_action_Quit_triggered();

    void on_tableWidget_customContextMenuRequested(const QPoint &pos);

    void on_action_refresh_triggered();

    void trayiconActivated(QSystemTrayIcon::ActivationReason reason);

    void on_action_Dict_triggered();

    void on_action_Support_triggered();

    void openUrl(const QString &url);

private:
    Ui::MainWindow *ui;

    QSystemTrayIcon *trayIcon;
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QMenu   *trayIconMenu;

    QString bookPath;
    QString currLearnBookPath;
};

#endif // MAINWINDOW_H
