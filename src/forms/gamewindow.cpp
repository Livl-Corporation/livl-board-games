#include "gamewindow.h"
#include "qlabel.h"
#include "ui_gamewindow.h"

#include <QVBoxLayout>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setGame(std::unique_ptr<Game> game, const QString &_gameName)
{
    // Set the game
    localGame = std::move(game);
    this->gameName = _gameName;

    // Set the main layout of the window
    auto *layout = new QVBoxLayout;

    // Display the main title of the game
    auto *titleLabel = new QLabel;
    titleLabel->setText(gameName);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont("Arial", 20, QFont::Bold);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("QLabel {color : blue;}");
    titleLabel->setFixedHeight(50);
    layout->addWidget(titleLabel);

    // Display the game information and the error label
    auto *gridLayout = new QGridLayout;
    auto* informationLabel = new QLabel(this);
    informationLabel->setText("Information: Player 1 it is your turn");
    informationLabel->setAlignment(Qt::AlignCenter);
    QFont informationFont("Arial", 12, QFont::Bold);
    informationLabel->setFont(informationFont);
    informationLabel->setStyleSheet("QLabel {color : blue;}");
    informationLabel->setFixedHeight(50);
    gridLayout->addWidget(informationLabel, 0, 0, 1, 1);
    errorLabel = new QLabel(this);
    errorLabel->setText("Hello");
    errorLabel->hide();
    errorLabel->setAlignment(Qt::AlignCenter);
    errorLabel->setStyleSheet("QLabel { color : red; }");
    errorLabel->setFixedHeight(errorLabel->fontMetrics().height());
    gridLayout->addWidget(errorLabel, 1, 0, 1, 1);
    layout->addLayout(gridLayout);

    // Display the game board
    buttons = std::vector<std::vector<QPushButton*>>();
    buttons.resize(localGame->getGrid()->getYSize());
    QString styleSheet = "QPushButton { background-color: white; border: none; color: black; font: bold 14px; } QPushButton:hover { background-color: #6699CC; } QPushButton:pressed { background-color: #003366; }";
    for (int row = 0; row < localGame->getGrid()->getYSize(); row++)
    {
        buttons[row].resize(localGame->getGrid()->getXSize());
        auto *buttonRowLayout = new QHBoxLayout;
        buttonRowLayout->setSpacing(5);

        for (int col = 0; col < localGame->getGrid()->getXSize(); col++)
        {
            auto *button = new QPushButton;
            buttons[row][col] = button;

            QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

            buttons[row][col]->setStyleSheet(styleSheet);
            buttons[row][col]->setFixedSize(50, 50);
            buttonRowLayout->setContentsMargins(5, 5, 5, 5);
            buttonRowLayout->addWidget(button);
        }
        layout->addLayout(buttonRowLayout);
    }

    // Add the layout to the window
    this->centralWidget()->setLayout(layout);
}

void GameWindow::buttonClicked()
{
    // Get the sender QPushButton
    auto *button = qobject_cast<QPushButton*>(sender());

    // Find the row and column of the clicked button
    int row, col;
    for (row = 0; row < localGame->getGrid()->getYSize(); row++)
    {
        for (col = 0; col < localGame->getGrid()->getXSize(); col++)
        {
            if (buttons[row][col] == button)
            {
                // Update the button's text to show the token
                QString token = "X";
                this->displayError("error");
                button->setText(token);
                button->setEnabled(false);

                return;
            }
        }
    }
}

void GameWindow::displayError(const std::string &message)
{
    ConsoleHandler::printLineLabel(errorLabel, "This is an error message");
    errorLabel->setVisible(true);
}



