#include "menu.h"
#include "./ui_menu.h"

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
    QLabel* title = new QLabel("Welcome to Livl Boardgame", this);
    title->setAlignment(Qt::AlignCenter);

    QFont fontTitle("Verdana", 30);
    title->setFont(fontTitle);

    QLabel* imageLabel = new QLabel(this);
    QPixmap image(":/img/logo.png"); // from .qrc file located in img/img.qrc
    imageLabel->setPixmap(image);
    imageLabel->setAlignment(Qt::AlignCenter);

    QLabel* titleLabel = new QLabel("Choose a game mode", this);
    titleLabel->setAlignment(Qt::AlignCenter);

    QFont font("Verdana", 20);
    titleLabel->setFont(font);

    gameModesComboBox = new QComboBox(this);
    gameModesComboBox->addItem("Othello");
    gameModesComboBox->addItem("Tic Tac Toe");
    gameModesComboBox->addItem("Power 4");
    gameModesComboBox->addItem("Checkers");
    gameModesComboBox->setFont(font);

    QPushButton* okButton = new QPushButton("OK", this);
    okButton->setFont(font);

    QHBoxLayout* hLayout = new QHBoxLayout();
    hLayout->addWidget(gameModesComboBox);
    hLayout->addWidget(okButton);
    hLayout->setAlignment(Qt::AlignCenter);

    // Connecter le signal "clicked" du bouton OK au slot "accept" de la fenêtre de dialogue
    connect(okButton, &QPushButton::clicked, this, &Menu::acceptGameModeSelection);

    QVBoxLayout* vLayout = new QVBoxLayout();
    vLayout->addWidget(title);
    vLayout->addWidget(imageLabel);
    vLayout->addWidget(titleLabel);
    vLayout->addLayout(hLayout);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(vLayout);

    this->setCentralWidget(centralWidget);
}

void Menu::acceptGameModeSelection()
{
    // Récupérer l'élément sélectionné dans le QComboBox
    int index = gameModesComboBox->currentIndex();
    QString gameMode = gameModesComboBox->itemText(index);
}

Menu::~Menu()
{
    delete ui;
}

