//
// Created by Franck GUTMANN on 15/01/2023.
//

#ifndef LIVL_GRIDCOMPONENT_H
#define LIVL_GRIDCOMPONENT_H

#include <QWidget>
#include <QPushButton>
#include "../../models/player.hpp"
#include "../../interfaces/grid.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class GridComponent; }
QT_END_NAMESPACE

class GridComponent : public QWidget {
Q_OBJECT

public:
    explicit GridComponent(QWidget *parent = nullptr);

    void createGrid(const Grid<PlayerId> &grid);
    void updateGrid(const Grid<PlayerId> &grid);

    ~GridComponent() override;

private:
    Ui::GridComponent *ui;

    std::shared_ptr<Grid<PlayerId>> grid;
    std::vector<std::vector<QPushButton*>> buttons = std::vector<std::vector<QPushButton*>>();
};


#endif //LIVL_GRIDCOMPONENT_H
