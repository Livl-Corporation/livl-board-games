#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QCoreApplication>
#include <QAbstractButton>
#include "ui_GameWindow.h"
#include "../../components/GridComponent.h"
#include "models/Subject.h"
#include "models/interfaces/Player.h"
#include "models/Grid.h"
#include "models/interfaces/Token.h"
#include "controllers/GameController.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow, public Observer<Game>
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

    void setGameName(const std::string &gameName);

    void createPlayers(const std::vector<Player>& players);

    void setRound(unsigned int round);

    void setActivePlayer(const PlayerId &playerId);

    void setInfoText(const std::string &message);

    void setInfoTextColor(const std::string &color);

    void setController(const std::shared_ptr<GameController> &_controller) {
        this->controller = _controller;
    };

    void update(const Game &value) override;

    void createGrid(const std::shared_ptr<Grid<Token>> &grid);

private:
    Ui::GameWindow *ui;
    QVector<QLabel*> playerLabels;
    GridComponent *gridComponent;
    std::shared_ptr<GameController> controller;
};
