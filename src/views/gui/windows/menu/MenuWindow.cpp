#include <QMessageBox>
#include "MenuWindow.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
{
    QCoreApplication::applicationDirPath();
    ui->setupUi(this);

    connect(ui->playButton, &QPushButton::clicked, this, &MenuWindow::onPlayClicked);
    connect(ui->openSaveFileButton, &QPushButton::clicked, this, &MenuWindow::onSaveSelected);

    setPlayerList(MenuData::players);
    setGameList(MenuData::games);

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::setGameList(const std::vector<std::string> &gameList) {
    for (const auto &gameName : gameList) {
        ui->gameSelectionBox->addItem(QString::fromStdString(gameName));
    }
}

void MenuWindow::setPlayerList(const std::vector<std::string> &playerList) {
    for (const auto &playerName : playerList) {
        ui->playerSelectionBox->addItem(QString::fromStdString(playerName));
    }
}

void MenuWindow::onPlayClicked() {
    auto gameSelection = static_cast<GameMode>(ui->gameSelectionBox->currentIndex() + 1);
    auto playerSelection = static_cast<PlayMode>(ui->playerSelectionBox->currentIndex() + 1);

    this->close();

    std::shared_ptr<GameView> gameView = std::make_shared<GameWindow>(this);
    controller->onGameChoose(gameSelection, playerSelection, gameView);
}

void MenuWindow::onSaveSelected() {
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open Livl-board-game save file - <3"),
                                            "./",
                                            tr("livl-board-game save file (*.livl)")
    );

    std::string path = fileName.toStdString();
    std::shared_ptr<GameView> gameView = std::make_shared<GameWindow>();

    try {
        controller->onSaveFileChoose(path, gameView);
    }
    catch(std::exception &exception) {
        QMessageBox msgErrorBox;
        msgErrorBox.setText(exception.what());
        msgErrorBox.setIcon(QMessageBox::Warning);
        msgErrorBox.exec();
    }
}
