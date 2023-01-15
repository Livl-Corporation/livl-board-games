//
// Created by Franck GUTMANN on 15/01/2023.
//

#ifndef LIVL_GRIDCOMPONENT_H
#define LIVL_GRIDCOMPONENT_H

#include <QWidget>
#include <QGridLayout>
#include "../../models/player.hpp"
#include "../../interfaces/grid.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class GridComponent; }
QT_END_NAMESPACE

class GridComponent : public QWidget {
Q_OBJECT

public:
    explicit GridComponent(QWidget *parent = nullptr);

    void createGrid(const std::shared_ptr<Grid<PlayerId>> grid);
    void updateGrid(const std::shared_ptr<Grid<PlayerId>> grid);

    ~GridComponent() override;

private:
    Ui::GridComponent *ui;
    QGridLayout *gridLayout;
    std::shared_ptr<Grid<PlayerId>> grid;
};


#endif //LIVL_GRIDCOMPONENT_H
