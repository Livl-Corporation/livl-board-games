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

class GridComponent : public QWidget, public Subject<Position>, public Observer<Grid<Token>> {
    Q_OBJECT

public:
    explicit GridComponent(QWidget *parent = nullptr);

    void createGrid(const std::shared_ptr<Grid<Token>> &grid);
    void updateGrid(const Grid<Token> &grid);

    void update(const Grid<Token> &value) override;

    QGridLayout* getGridLayout() { return this->gridLayout; };

    ~GridComponent() override;

private:

    Ui::GridComponent *ui;
    QGridLayout *gridLayout{};
    bool gridCreated = false;

};

#endif //LIVL_GRIDCOMPONENT_H
