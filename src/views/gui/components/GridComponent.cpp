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
    gridLayout->setAlignment(Qt::AlignCenter);
    gridLayout->setSpacing(0);
     // Display the game board
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
            Token token = grid.getElementAt({row, col});
            QString playerString(QChar(token.getDisplayChar()));
            button->setText(playerString);

            // set the color of the button
            std::string color = token.getDisplayColor();
            button->setStyleSheet("QPushButton { background-color: " + QString::fromStdString(color) + "; border: 1px solid #777; color: " + (color == "black" ? "white" : "black") + "; font: bold 14px; } QPushButton:hover { background-color: #6699CC; } QPushButton:pressed { background-color: #003366; }");
        }
    }
}

void GridComponent::disableGridButtons()
{
    for (int i = 0; i < this->gridLayout->count(); ++i) {
        auto item = this->gridLayout->itemAt(i);
        item->widget()->setEnabled(false);
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