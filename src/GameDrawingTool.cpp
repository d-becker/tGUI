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

#include "GameDrawingTool.h"

#include "DrawingContextInfo.h"

namespace tetrisgui {

GameDrawingTool::GameDrawingTool()
  : tetris::DrawingTool<tetris::Game>()
{
  //ctor
}

GameDrawingTool::GameDrawingTool::~GameDrawingTool()
{
  //dtor
}

GameDrawingTool::GameDrawingTool(const GameDrawingTool& other)
  : tetris::DrawingTool<tetris::Game>(other)
{
  // Copy constructor.
}

GameDrawingTool::GameDrawingTool(GameDrawingTool&& other)
  : tetris::DrawingTool<tetris::Game>(other)
{
  // Move constructor.
}

void GameDrawingTool::draw(const tetris::Game& game,
                           tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;

  cr->save();

  game.getGameBoard()->draw(dci);

  cr->restore();
}

std::shared_ptr<tetris::DrawingTool<tetris::Game>>
GameDrawingTool::copy() const {
  return std::make_shared<GameDrawingTool>(*this);
}

} // namespace tetrisgui.
