#pragma once
#include <QMainWindow>
#include "../../../models/player.hpp"
#include "../../../interfaces/grid.hpp"

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

    void setGameName(const std::string &gameName);

    void createPlayers(const std::vector<Player>& players);

    void setRound(unsigned int round);

    void setActivePlayer(const PlayerId &playerId);

    void setInfoText(const std::string &message);

    void setInfoTextColor(const std::string &color);

    void setGrid(const std::shared_ptr<Grid<PlayerId>> &grid);

private:
    Ui::GameWindow *ui;
};
