//
// Created by Franck GUTMANN on 15/01/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GridComponent.h" resolved

#include "GridComponent.h"
#include "../../../models/Grid.cpp"

GridComponent::GridComponent(QWidget *parent, const std::function<void(Position)> &_onPositionSelected) :
        QWidget(parent), ui(new Ui::GridComponent) {
    ui->setupUi(this);
    this->onPositionSelected = _onPositionSelected;
}

GridComponent::~GridComponent() {
    delete ui;
    delete gridLayout;
}

void GridComponent::createGrid(const Grid<Token> &grid) {

    gridLayout = new QGridLayout(this);

     // Display the game board
     QString styleSheet = "QPushButton { background-color: white; border: none; color: black; font: bold 14px; } QPushButton:hover { background-color: #6699CC; } QPushButton:pressed { background-color: #003366; }";
     for (int row = 0; row < grid.getRowCount(); row++)
     {
         for (int col = 0; col < grid.getColCount(); col++)
         {
             auto *button = new QPushButton;
             connect(button, &QPushButton::clicked, this, [row, col, this]{
                    if (this->onPositionSelected != nullptr) {
                        qDebug() << "GridComponent::click on row : " << row << " ,col : " << col;
                        this->onPositionSelected({row, col});
                    } else {
                        qDebug() << "No callback for position selected";
                    }
             });
             button->setStyleSheet(styleSheet);
             button->setFixedSize(50, 50);
             gridLayout->addWidget(button, row, col, 1, 1);
         }

     }

     this->updateGrid(grid);

     setLayout(gridLayout);
}

void GridComponent::updateGrid(const Grid<Token> &grid) {
    for (int row = 0; row < grid.getRowCount(); row++)
    {
        for (int col = 0; col < grid.getColCount(); col++)
        {
            auto *button = (QPushButton*) this->gridLayout->itemAtPosition(row, col)->widget();
            QString playerString(QChar(grid.getElementAt({row, col}).getDisplayChar()));
            button->setText(playerString);
        }
    }
}

void GridComponent::setGrid(const Grid<Token> &value) {
    if (!gridCreated) {
        createGrid(value);
        gridCreated = true;
    } else {
        updateGrid(value);
    }
}