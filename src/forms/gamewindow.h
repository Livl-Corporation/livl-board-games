#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <qpushbutton.h>

#include <src/interfaces/game.hpp>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent* event)
    {
        // Delete the object when it is closed
        delete this;
    };

    ~GameWindow();
    void setGame(std::unique_ptr<Game> game, const QString &gameName);
private:
    Ui::GameWindow *ui;
    std::unique_ptr<Game> localGame;
    QString gameName;
    std::vector<std::vector<QPushButton*>> buttons;

private slots:
    void buttonClicked();
};

#endif // GAMEWINDOW_H
