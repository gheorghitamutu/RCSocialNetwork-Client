// https://stackoverflow.com/questions/40318759/change-qpushbutton-icon-on-hover-and-pressed
// https://stackoverflow.com/questions/21685414/qt5-setting-background-color-to-qpushbutton-and-qcheckbox

#ifndef BUTTONHOVERWATCHER_H
#define BUTTONHOVERWATCHER_H

#include <QObject>
#include <QPushButton>
#include <QEvent>

class ButtonHoverWatcher : public QObject
{
    Q_OBJECT
    public:
        explicit ButtonHoverWatcher(QObject * parent = Q_NULLPTR);
        virtual bool eventFilter(QObject * watched, QEvent * event) Q_DECL_OVERRIDE;

        void SetHoverColor(QColor hover_color);
        void SetColor(QColor color);
    private:
        QColor hover_color;
        QColor color;
};



#endif // BUTTONHOVERWATCHER_H
