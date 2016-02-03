/*
 * Copyright (C) 2016 Daniel Becker <beckerdaniel.dani@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GAMEBOARDDRAWINGTOOL_H
#define GAMEBOARDDRAWINGTOOL_H

#include <Board.h>
#include <Drawing.h>
#include <GameBoard.h>

namespace tetrisgui {

class GameBoardDrawingTool : public tetris::DrawingTool<tetris::GameBoard>
{
  public:
    GameBoardDrawingTool();
    virtual ~GameBoardDrawingTool();
    GameBoardDrawingTool(const GameBoardDrawingTool& other);
    GameBoardDrawingTool(GameBoardDrawingTool&& other);

    virtual void draw(const tetris::GameBoard& game_board,
                      tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool<tetris::GameBoard>> copy()
                                                 const override;
  protected:
  private:
};

} // namespace tetrisgui.

#endif // GAMEBOARDDRAWINGTOOL_H
