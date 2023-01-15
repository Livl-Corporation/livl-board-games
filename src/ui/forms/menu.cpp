#include "menu.h"
#include "./ui_menu.h"
#include "gamewindow.h"
#include "../../games/gameFactory.hpp"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    QCoreApplication::applicationDirPath();
    ui->setupUi(this);
    this->setupUI();
    this->showGameModesDialog();
}

void Menu::setupUI()
{

}

void Menu::showGameModesDialog()
{
    auto* title = new QLabel("Welcome to Livl Boardgame", this);
    title->setAlignment(Qt::AlignCenter);

    QFont fontTitle("Verdana", 30);
    title->setFont(fontTitle);

    auto* imageLabel = new QLabel(this);
    QPixmap image(":/img/logo.png"); // from .qrc file located in img/img.qrc
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);

    auto* titleLabel = new QLabel("Choose a game mode", this);
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont font("Verdana", 20);
    titleLabel->setFont(font);

    gameModesComboBox = new QComboBox(this);
    gameModesComboBox->addItem("Tic Tac Toe");
    gameModesComboBox->addItem("Power 4");
    gameModesComboBox->addItem("Othello");
    gameModesComboBox->addItem("Checkers");
    gameModesComboBox->setFont(font);

    auto* okButton = new QPushButton("OK", this);
    okButton->setFont(font);

    auto* hLayout = new QHBoxLayout();
    hLayout->addWidget(gameModesComboBox);
    hLayout->addWidget(okButton);
    hLayout->setAlignment(Qt::AlignCenter);

    // Connecter le signal "clicked" du bouton OK au slot "accept" de la fenêtre de dialogue
    connect(okButton, &QPushButton::clicked, this, &Menu::acceptGameModeSelection);

    auto* vLayout = new QVBoxLayout();
    vLayout->addWidget(title);
    vLayout->addWidget(imageLabel);
    vLayout->addWidget(titleLabel);
    vLayout->addLayout(hLayout);

    auto* centralWidget = new QWidget(this);
    centralWidget->setLayout(vLayout);

    this->setCentralWidget(centralWidget);
}

// Function to create players based on the given player selection
std::vector<Player> Menu::createPlayers(unsigned int playerSelection)
{
    std::vector<Player> players;
    Player p1(1, false);
    Player p2(2, playerSelection == 1);
    players.push_back(p1);
    players.push_back(p2);
    return players;
}

void Menu::acceptGameModeSelection()
{
    // Retrieve the selected game mode from the combo box
    int index = gameModesComboBox->currentIndex();
    QString gameMode = gameModesComboBox->itemText(index);

    // Create the GameWindow object on the heap
    auto* gameWindow = new GameWindow(this);
    close(); // Close the menu window to display the other one just after

    gameWindow->setWindowTitle(gameMode);

    unsigned int playerSelection = 1;
    std::vector<Player> players = createPlayers(playerSelection);
    std::unique_ptr<Game> game = GameFactory::createGame(index+1, players);

    gameWindow->setGame(std::move(game), gameMode);

    gameWindow->show();
}

Menu::~Menu()
{
    delete ui;
}



