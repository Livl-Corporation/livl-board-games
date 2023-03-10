#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QCoreApplication>
#include <QAbstractButton>
#include "ui_GameWindow.h"
#include "../../components/GridComponent.h"
#include "models/interfaces/Player.h"
#include "models/Token.h"

#include "views/interfaces/GameView.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui {
    class GameWindow;
}
QT_END_NAMESPACE

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

    void createPlayers(const std::vector<std::shared_ptr<Player>>& players);

    void setActivePlayer(const PlayerId &playerId);

    void setInfoText(const std::string &message);

    void setErrorText(const std::string &message);

    void createGrid(const Grid<Token> &grid);

    void show() override;

    // As on observer, the view is notified when the game is updated
    void updateError(const std::string &message) override;
    void updateMessage(const std::string &message) override;
    void updateAskForPosition(const std::string &message, unsigned int numberOfValues) override;
    void updateGameEnd(const std::string &message) override;

    void updateGameName(const std::string &gameName) override;
    void updateRound(Round round, const std::shared_ptr<Player> &player) override;
    void updateGrid(const Grid<Token> &grid) override;
    void updatePlayers(const std::vector<std::shared_ptr<Player>> &players) override;

    void onGridClicked(const Position &value);

private:
    Ui::GameWindow *ui;
    QVector<QLabel*> playerLabels;
    QWidget* parent;
    std::shared_ptr<GridComponent> gridComponent;
    void onReturnBackButtonClicked();
};
