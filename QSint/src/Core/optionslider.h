#ifndef OPTIONSLIDER_H
#define OPTIONSLIDER_H

#include <QStringList>

#include <QSlider>
#include <QLabel>
#include <QBoxLayout>


namespace QSint
{


/**
    \brief Slider widget with customizable options.
    \since 0.2.2

    \image html OptionSlider.png An example of OptionSlider

    OptionSlider is QSlider-bades widget allowing to set own list of the options and to choose
    one of them by dragging slider's handle.

*/
class OptionSlider : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QStringList optionsList READ optionsList WRITE setOptionsList)

public:
    /** Constructor.
      */
    explicit OptionSlider(QWidget *parent = 0);

    /** Sets displayed list of options to \a options.
      */
    void setOptionsList(const QStringList& options);

    /** Returns active list of options.
      */
    const QStringList& optionsList() const
            { return m_options; }

    /** Sets selected option index to \a index.
      */
    void setCurrentIndex(int index);

    /** Returns index of the currently selected option.
      */
    int currentIndex();
    
Q_SIGNALS:
    /** Signal emitted when the current index is changed either by the user or programmatically.
     */
    void valueChanged(int index);

    /** Signal emitted when the current index is changed by the user.
     */
    void sliderMoved(int index);
    
protected:
    QStringList m_options;

    QSlider *m_slider;
    QHBoxLayout *m_labelBox;
    QList<QLabel*> m_labels;
};


} // namespace

#endif // OPTIONSLIDER_H
