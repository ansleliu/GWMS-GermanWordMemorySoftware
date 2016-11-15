#ifndef RECENTFILES_H
#define RECENTFILES_H

#include <QtCore/QSettings>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QMenu>
#else
#include <QtGui/QMenu>
#endif


namespace QSint
{

/**
    \brief Class representing recently opened files as a QMenu.

    Class provides easy API to add, remove and signal of the picking of the
    recent file item. Each item can have associated QIcon.

    Class automatically maintains amount of the recent files and their order
    (i.e. most recently added and picked items always go to the top of the list).

    Also class can store and load the list of the recent files through a QSetting
    object.

    <b>Usage of RecentFiles in the application</b>

    There are two ways of representation of the recent files: as a submenu and as
    an embedded list.

    Usage as a \b submenu is very easy. Just create RecentFiles object and add its
    menu() to the appropriate action of the parent menu. Then connect activated()
    signal to the appropriate slot.

    \code
    // assume that myRecentFiles is RecentFiles object, and actionRecent is an action
    // in the parent menu

    // incorporate Recent Files menu as actionRecent's submenu
    actionRecent->setMenu(myRecentFiles.menu());

    // connect activated() signal to the your handling slot, i.e. handleActivated()
    connect(&myRecentFiles, SIGNAL(activated(QString)),
            this, SLOT(handleActivated(QString)));

    \endcode

    Usage as an \b embedded \b list requires handling of aboutToShow() signal of the
    menu where you'd like to show the recent files.

    First, as usual, create RecentFiles object. Then connect activated()
    signal to the appropriate slot.

    Second, in the slot associatiated with
    this signal, you have to create all the menu actions and in a mean time, call
    populateMenu() function to provide internal connections and insert recent files
    list into the menu.

    \code
    // assume that fileMenu is QMenu where you want to embed recent files in,
    // MyAppWindow is the class of your application,
    // myRecentFiles is RecentFiles object

    // connect activated() signal to the your handling slot, i.e. handleActivated()
    connect(&myRecentFiles, SIGNAL(activated(QString)),
            this, SLOT(handleActivated(QString)));


    // this is the slot connected to fileMenu's aboutToShow() signal
    void MyAppWindow::on_fileMenu_aboutToShow()
    {
        // first, clear our menu
        fileMenu->clear();

        // then, add some custom actions
        // ...

        // you probably want to add a separator before recent files
        fileMenu->addSeparator();

        // then, add recent files here
        myRecentFiles.populate(fileMenu);

        // you probably want to add a separator after recent files as well
        fileMenu->addSeparator();

        // then, add another custom actions
        // ...
    }
    \endcode
*/
class RecentFiles : public QObject
{
    Q_OBJECT

public:
    /** Constructor.
      */
    explicit RecentFiles(QWidget *parent = 0);
    /** Destructor.
      */
    virtual ~RecentFiles() {}

    /** Returns a pointer to the QMenu contating recent files.
      */
    inline QMenu* menu() const { return recentMenu; }
    /** Returns a const reference to the recent files names and icons.
      */
    inline const QList<QPair<QString,QIcon> >& recentFileList() const { return recentList; }

    /** Appends recent actions to \a menu. This is useful for embedding recent files
      list into existing QMenu.
      */
    void populateMenu(QMenu *menu);

    /** Returns maximal amount of the recent files in the menu (default is 10).
      */
    inline int maxFileCount() const { return maxCount; }
    /** Sets maximal amount of the recent files in the menu (default is 10).
      */
    void setMaxFileCount(int max);

    /** Fills recent files menu from the given \a set.
      */
    virtual void readConfig(QSettings &set);
    /** Stores recent files menu entries to the given \a set.
      */
    virtual void writeConfig(QSettings &set);

public slots:
    /** Creates an entry in the recent files menu with \a filename and \a icon.
        If \a filename already exists, moves it to the beginning of the list.
      */
    virtual void add(const QString &filename, const QIcon &icon = QIcon());
    /** Removes an entry with \a filename from the recent files menu.
      */
    virtual void remove(const QString &filename);
    /** Clears recent files list.
      */
    virtual void clear();

signals:
    /** Emitted when user picks an item with \a filename from the recent files menu.
      */
    void activated(const QString &filename);

protected slots:
    /** \internal
      */
    void chosen(QAction*);

protected:
    /** Builds up QMenu from the current recent files list.
      */
    virtual void updateMenu();

    int maxCount;
    QMenu *recentMenu;
    QList<QPair<QString,QIcon> > recentList;
};

} // namespace

#endif // RECENTFILES_H
