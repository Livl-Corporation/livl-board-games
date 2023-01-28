//
// Created by Franck GUTMANN on 19/01/2023.
//

#include "TicTacToeHumanPlayer.h"
#include <QDebug>

void TicTacToeHumanPlayer::play(const std::shared_ptr<Grid<Token>> &grid) {

}


void TicTacToeHumanPlayer::onPositionSelected(Position position) {
    qDebug() << "TicTacToeHumanPlayer::onPositionSelected() with position " << position.x << " " << position.y << "\n";
}
