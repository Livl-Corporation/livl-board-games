//
// Created by Franck GUTMANN on 15/01/2023.
//

#ifndef LIVL_GRIDCOMPONENT_H
#define LIVL_GRIDCOMPONENT_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <memory>
#include "ui_GridComponent.h"
#include "models/interfaces/Player.h"
#include "models/Grid.h"
#include "models/Token.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GridComponent; }
QT_END_NAMESPACE

class GridComponent : public QWidget {
    Q_OBJECT

public:
    explicit GridComponent(QWidget *parent = nullptr, const std::function<void(Position)> &_onPositionSelected = nullptr);
    void setGrid(const Grid<Token> &value);

    QGridLayout* getGridLayout() { return this->gridLayout; };

    ~GridComponent() override;
    void disableGridButtons();
private:

    void createGrid(const Grid<Token> &grid);
    void updateGrid(const Grid<Token> &grid);

    Ui::GridComponent *ui;
    QGridLayout *gridLayout{};
    bool gridCreated = false;

    std::function<void(Position)> onPositionSelected;

};

#endif //LIVL_GRIDCOMPONENT_H
