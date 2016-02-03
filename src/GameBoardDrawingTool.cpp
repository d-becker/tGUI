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

#include "GameBoardDrawingTool.h"

#include <Shape.h>

#include "DrawingContextInfo.h"

namespace tetrisgui {

GameBoardDrawingTool::GameBoardDrawingTool()
  : tetris::DrawingTool<tetris::GameBoard>()
{
  //ctor
}

GameBoardDrawingTool::~GameBoardDrawingTool()
{
  //dtor
}

GameBoardDrawingTool::GameBoardDrawingTool(const GameBoardDrawingTool& other)
  : tetris::DrawingTool<tetris::GameBoard>(other)
{
  // Copy constructor.
}

GameBoardDrawingTool::GameBoardDrawingTool(GameBoardDrawingTool&& other)
  : tetris::DrawingTool<tetris::GameBoard>(other)
{
  // Move constructor.
}

void GameBoardDrawingTool::draw(const tetris::GameBoard& game_board,
                                tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;

  cr->save();
  game_board.getBoard()->draw(dci);

  cr->restore();
  cr->save();

  tetris::Coords c = game_board.getCurrentShapePosition();
  cr->translate(c.getHorizontal(), c.getVertical());

  const std::shared_ptr<const tetris::Shape>& current_shape
                                    = game_board.getCurrentShape();
  if (current_shape != nullptr) {
    current_shape->draw(dci);
  }

  cr->restore();
}

std::shared_ptr<tetris::DrawingTool<tetris::GameBoard>>
GameBoardDrawingTool::copy() const {
  return std::make_shared<GameBoardDrawingTool>(*this);
}

} // namespace tetrisgui.
