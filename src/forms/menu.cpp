#include "menu.h"
#include "./ui_menu.h"

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
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

        // Appliquer une police d'écriture en grande taille
        QFont fontTitle("Verdana", 30);
        title->setFont(fontTitle);

        // Création du QLabel pour l'image
        QFileInfo fileInfo("../../img/LIVL_CPP.png");
        QString absolutePath = fileInfo.absoluteFilePath();

        QLabel* imageLabel = new QLabel(this);
        imageLabel->setMinimumSize(500, 500); // Définit une taille minimale de 500x500 pixels
        QPixmap image("../../img/LIVL_CPP.png");
        imageLabel->setPixmap(image);
        imageLabel->setAlignment(Qt::AlignCenter);

    // Création du QLabel pour le titre
       QLabel* titleLabel = new QLabel("Choose a game mode", this);
       titleLabel->setAlignment(Qt::AlignCenter);

       // Appliquer une police d'écriture en grande taille
       QFont font("Verdana", 20);
       titleLabel->setFont(font);

       // Création du QComboBox
       gameModesComboBox = new QComboBox(this);
       gameModesComboBox->addItem("Othello");
       gameModesComboBox->addItem("Tic Tac Toe");
       gameModesComboBox->addItem("Power 4");
       gameModesComboBox->addItem("Checkers");
       gameModesComboBox->setFont(font);

       // Création du bouton OK
       QPushButton* okButton = new QPushButton("OK", this);
       okButton->setFont(font);

       // Création du layout horizontal
      QHBoxLayout* hLayout = new QHBoxLayout();
      hLayout->addWidget(gameModesComboBox);
      hLayout->addWidget(okButton);

      // Centrer les données
      hLayout->setAlignment(Qt::AlignCenter);

       // Connecter le signal "clicked" du bouton OK au slot "accept" de la fenêtre de dialogue
       connect(okButton, &QPushButton::clicked, this, &Menu::acceptGameModeSelection);

       // Ajouter le titre et le layout horizontal à la fenêtre principale
       QVBoxLayout* vLayout = new QVBoxLayout();
       vLayout->addWidget(title);
       vLayout->addWidget(imageLabel);
       vLayout->addWidget(titleLabel);
       vLayout->addLayout(hLayout);

       // Création d'un widget pour contenir le layout vertical
       QWidget* centralWidget = new QWidget(this);
       centralWidget->setLayout(vLayout);

       // Remplacer le widget central par le widget contenant le layout vertical
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

