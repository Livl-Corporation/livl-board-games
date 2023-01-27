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
#include "models/Subject.h"
#include "models/interfaces/Player.h"
#include "models/Grid.h"
#include "models/interfaces/Token.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GridComponent; }
QT_END_NAMESPACE

class GridComponent : public QWidget, public Subject<Position> {
    Q_OBJECT

public:
    explicit GridComponent(QWidget *parent = nullptr);
    void setGrid(const Grid<Token> &value);

    QGridLayout* getGridLayout() { return this->gridLayout; };

    ~GridComponent() override;

private:

    void createGrid(const Grid<Token> &grid);
    void updateGrid(const Grid<Token> &grid);

    Ui::GridComponent *ui;
    QGridLayout *gridLayout{};
    bool gridCreated = false;

};

#endif //LIVL_GRIDCOMPONENT_H
