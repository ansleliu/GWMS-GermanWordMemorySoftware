#ifndef TABLISTMENU_H
#define TABLISTMENU_H


#include <QMenu>
#include <QTabWidget>


namespace QSint
{


/**
    \brief Class representing drop-down menu of QTabWidget's tabs.
    \since 0.2

    \image html TabListMenu.png An example of TabListMenu

    TabListMenu makes it easy to provide drop-down menu with a list of opened tabs,
    which highlights the current one and allows to switch between the tabs by
    choosing the corresponding menu items.

    Typycally you'd like to create a corner button at the right (or left) QTabWidget's
    edge and assign the menu to it using setTabs().

    An example how to use TabListMenu with QTabWidget and corner button.
    Only 3 lines of code needed.

    \code
    // assume that we're now in MainWindow constructor.
    // ui->tabWidget is QTabWidget.
    // tbTabsDropList is QToolButton.

    ui->setupUi(this);

    // create TabListMenu
    QSint::TabListMenu *tabMenu = new QSint::TabListMenu(this);

    // assing ui->tabWidget to the tabMenu
    tabMenu->setTabs(ui->tabWidget);

    // create corner button
    QToolButton *tbTabsDropList = new QToolButton(this);
    tbTabsDropList->setPopupMode(QToolButton::InstantPopup);
    ui->tabWidget->setCornerWidget(tbTabsDropList);

    // assing tabMenu to the tbTabsDropList
    tbTabsDropList->setMenu(tabMenu);
    \endcode

    You can also easily customize menu's items by subclassing TabListMenu's methods
    doCreateMenuItem() or/and doCreateMenu().

    An example how to customize 1st menu item by naming it "Main Page" and adding
    a separator after it.

    \code
    // a subclass of TabListMenu
    class MyTabListMenu : public QSint::TabListMenu
    {
    public:
        MyTabListMenu(QWidget *parent = 0) : QSint::TabListMenu(parent)
        {
        }

    protected:
        // reimplement this method to customize menu items
        virtual void doCreateMenuItem(int index, bool current, QAction *item, QTabWidget *tabs)
        {
            // call TabListMenu's doCreateMenuItem() first.
            // this will create and initialize menu's entry item.
            QSint::TabListMenu::doCreateMenuItem(index, current, item, tabs);

            // check tab index and change item's text if it's the very first tab.
            // also add a separator afterwards.
            if (index == 0) {
                item->setText(tr("Main Page"));
                addSeparator();
            }
        }
    };
    \endcode
*/
class TabListMenu : public QMenu
{
    Q_OBJECT

public:
    /** Constructor.
      */
    explicit TabListMenu(QWidget *parent = 0);

    /** The most important fuction which assigns QTabWidget \a tabs to the menu.
      */
    void setTabs(QTabWidget *tabs);
    /** Returns QTabWidget assigned to the menu or 0 if no QTabWidget assigned.
      */
    inline QTabWidget* tabs() const
    { return m_tabs; }

    /** Returns true if icons are allowed, false otherwise.
      */
    inline bool iconsAllowed() const
    { return m_icons; }

public slots:
    /** When \a allow is true, allows icons to be shown in the menu (enabled by default).
      */
    inline void setAllowIcons(bool allow = true)
    { m_icons = allow; }

    /** This slot is called internally when QMenu::aboutToShow() signal is emitted.
        You can reimplement it in order to customize TabListMenu behavior.
        By default it clears the menu and calls doCreateMenu().
      */
    virtual void createMenu();

    /** This slot is called when menu item \a from has been selected by the user.
        You can reimplement it in order to customize TabListMenu behavior.
        By default it calls doSwitchTab().
      */
    virtual void switchTab(QAction *from);

protected:
    /** This function is called internally before menu is shown.
        You can reimplement it in order to populate the menu manually.

        Default implementation calls doCreateMenuItem() for each tab of QTabWidget \a tabs
        separately.
      */
    virtual void doCreateMenu(QTabWidget *tabs);
    /** This function is called from doCreateMenu() for each tab separately.
        You can reimplement it in order to change \a item's representation.

        Default implementation creates QAction \a item of QTabWidget \a tabs's tab
        with index \a index. If this tab is current one, then \a current is set to true.

        In order to perform tab switching, it sets \a item's data value to the
        corresponding tab index. This value is being checked in doSwitchTab() when the user
        chooses an item from the menu.
      */
    virtual void doCreateMenuItem(int index, bool current, QAction *item, QTabWidget *tabs);
    /** This function is called internally when QAction \a from of QTabWidget \a tabs
        was triggered by the user.
        You can reimplement it in order to switch the tab manually.

        Default implementation switches current tab of \a tabs to \a from->data().
      */
    virtual void doSwitchTab(QAction *from, QTabWidget *tabs);

    QTabWidget *m_tabs;
    bool m_icons;
};


} // namespace QSint


#endif // TABLISTMENU_H
