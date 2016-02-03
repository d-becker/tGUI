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

#ifndef GAMEDRAWINGTOOL_H
#define GAMEDRAWINGTOOL_H

#include <Drawing.h>
#include <Game.h>

namespace tetrisgui {

class GameDrawingTool : public tetris::DrawingTool<tetris::Game>
{
  public:
    GameDrawingTool();
    virtual ~GameDrawingTool();
    GameDrawingTool(const GameDrawingTool& other);
    GameDrawingTool(GameDrawingTool&& other);

    virtual void draw(const tetris::Game& game,
                      tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool<tetris::Game>> copy()
                                                 const override;
  protected:
  private:
};

} // namespace tetrisgui.

#endif // GAMEDRAWINGTOOL_H
