#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QCoreApplication>
#include <QAbstractButton>
#include "ui_GameWindow.h"
#include "../../components/GridComponent.h"
#include "models/interfaces/Player.h"
#include "models/interfaces/Token.h"
#include "controllers/GameController.h"
#include "views/interfaces/GameView.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow, public GameView
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);

    void closeEvent(QCloseEvent* event) override
    {
        QMainWindow::closeEvent(event);
    };

    ~GameWindow() override;

    void setGameName(const std::string &gameName);

    void createPlayers(const std::vector<std::shared_ptr<Player>>& players);

    void setRound(unsigned int round);

    void setActivePlayer(const PlayerId &playerId);

    void setInfoText(const std::string &message);

    void setInfoTextColor(const std::string &color);

    void createGrid(const Grid<Token> &grid);

    GameWindow* getGameWindow() { return this;}

    void show() override;

    // As on observer, the view is notified when the game is updated
    void update(const Game &value) override;

    void onGridClicked(const Position &value);

private:
    Ui::GameWindow *ui;
    QVector<QLabel*> playerLabels;
    std::shared_ptr<GridComponent> gridComponent;
};
