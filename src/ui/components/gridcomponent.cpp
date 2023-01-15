//
// Created by Franck GUTMANN on 15/01/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GridComponent.h" resolved

#include <QHBoxLayout>
#include "gridcomponent.h"
#include "ui_GridComponent.h"


GridComponent::GridComponent(QWidget *parent) :
        QWidget(parent), ui(new Ui::GridComponent) {
    ui->setupUi(this);
}

GridComponent::~GridComponent() {
    delete ui;
}

void GridComponent::createGrid(const Grid<PlayerId> &grid) {

    this->grid = std::make_shared<Grid<PlayerId>>(grid);

    // Display the game board
    buttons.resize(this->grid->getYSize());
    QString styleSheet = "QPushButton { background-color: white; border: none; color: black; font: bold 14px; } QPushButton:hover { background-color: #6699CC; } QPushButton:pressed { background-color: #003366; }";
    for (int row = 0; row < this->grid->getYSize(); row++)
    {
        buttons[row].resize(this->grid->getXSize());
        auto *buttonRowLayout = new QHBoxLayout;
        buttonRowLayout->setSpacing(5);

        for (int col = 0; col < this->grid->getXSize(); col++)
        {
            auto *button = new QPushButton;
            buttons[row][col] = button;

            QObject::connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

            buttons[row][col]->setStyleSheet(styleSheet);
            buttons[row][col]->setFixedSize(50, 50);
            buttonRowLayout->setContentsMargins(5, 5, 5, 5);
            buttonRowLayout->addWidget(button);
        }
        ui->mainWidget->setLayout(buttonRowLayout);
    }
}

void GridComponent::updateGrid(const Grid<PlayerId> &grid) {
    this->grid = std::make_shared<Grid<PlayerId>>(grid);

    for (int row = 0; row < this->grid->getYSize(); row++)
    {
        for (int col = 0; col < this->grid->getXSize(); col++)
        {
            QString playerString(QChar(Player::getPlayerChar(this->grid->getElementAt({row, col}))));
            buttons[row][col]->setText(playerString);
        }
    }
}
