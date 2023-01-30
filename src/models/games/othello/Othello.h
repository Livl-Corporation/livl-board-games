//
// Created by Franck GUTMANN on 30/01/2023.
//

#ifndef LIVL_OTHELLO_H
#define LIVL_OTHELLO_H


#include "models/Game.h"
#include "models/enums/PlayMode.h"

class Othello : public Game {

public:
    explicit Othello(PlayMode playMode);

protected:
    void onPositionSelected(Position position) override;

private:

    static Grid<Token> initGrid();

    static constexpr GridSize colCount = 8;
    static constexpr GridSize rowCount = 8;

};


#endif //LIVL_OTHELLO_H
