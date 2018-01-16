#include "buttonhoverwatcher.h"

ButtonHoverWatcher::ButtonHoverWatcher(QObject *parent) : QObject(parent)
{
    SetColor(QColor(Qt::white));
    SetHoverColor(QColor(238, 238, 238));
}

bool ButtonHoverWatcher::eventFilter(QObject * watched, QEvent * event)
{
    QPushButton * button = qobject_cast<QPushButton*>(watched);
    if (!button)
    {
        return false;
    }

    if (event->type() == QEvent::Enter)
    {
        // The push button is hovered by mouse
        QPalette pal = button->palette();
        pal.setColor(QPalette::Button, this->hover_color);
        button->setAutoFillBackground(true);
        button->setPalette(pal);
        button->update();
        return true;
    }

    if (event->type() == QEvent::Leave)
    {
        // The push button is not hovered by mouse
        QPalette pal = button->palette();
        pal.setColor(QPalette::Button, this->color);
        button->setAutoFillBackground(true);
        button->setPalette(pal);
        button->update();
        return true;
    }

    return false;
}

void ButtonHoverWatcher::SetHoverColor(QColor hover_color)
{
    this->hover_color = hover_color;
}

void ButtonHoverWatcher::SetColor(QColor color)
{
    this->color = color;
}
