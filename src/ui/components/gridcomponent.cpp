//
// Created by Franck GUTMANN on 15/01/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GridComponent.h" resolved

#include <QHBoxLayout>
#include <QPushButton>
#include "gridcomponent.h"
#include "ui_GridComponent.h"


GridComponent::GridComponent(QWidget *parent) :
        QWidget(parent), ui(new Ui::GridComponent) {
    ui->setupUi(this);
}

GridComponent::~GridComponent() {
    delete ui;
}

void GridComponent::createGrid(const std::shared_ptr<Grid<PlayerId>> grid) {

    this->grid = grid;
    this->gridLayout = new QGridLayout(this);

    // Display the game board
    QString styleSheet = "QPushButton { background-color: white; border: none; color: black; font: bold 14px; } QPushButton:hover { background-color: #6699CC; } QPushButton:pressed { background-color: #003366; }";
    for (int row = 0; row < this->grid->getYSize(); row++)
    {
        for (int col = 0; col < this->grid->getXSize(); col++)
        {
            auto *button = new QPushButton;
            button->setStyleSheet(styleSheet);
            button->setFixedSize(50, 50);
            this->gridLayout->addWidget(button, row, col, 1, 1);
        }

    }

    this->setLayout(this->gridLayout);

}

void GridComponent::updateGrid(const std::shared_ptr<Grid<PlayerId>> grid) {
    this->grid = grid;

    for (int row = 0; row < this->grid->getYSize(); row++)
    {
        for (int col = 0; col < this->grid->getXSize(); col++)
        {
            auto *button = (QPushButton*) this->gridLayout->itemAtPosition(row, col)->widget();
            QString playerString(QChar(Player::getPlayerChar(this->grid->getElementAt({row, col}))));
            button->setText(playerString);
        }
    }
}