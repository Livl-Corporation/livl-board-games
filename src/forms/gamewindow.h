#pragma once
#include <QMainWindow>
#include <qpushbutton.h>

#include "../interfaces/game.hpp"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);

    void closeEvent(QCloseEvent* event) override
    {
        // Delete the object when it is closed
        delete this;
    };

    ~GameWindow() override;
    void setGame(std::unique_ptr<Game> game, const QString &gameName);
private:
    Ui::GameWindow *ui;
    std::unique_ptr<Game> localGame;
    QString gameName;
    std::vector<std::vector<QPushButton*>> buttons;
private slots:
    void buttonClicked();
};
