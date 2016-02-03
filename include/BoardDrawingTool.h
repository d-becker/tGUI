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

#ifndef BOARDDRAWINGTOOL_H
#define BOARDDRAWINGTOOL_H

#include <gdkmm/rgba.h>

#include <Board.h>
#include <Drawing.h>

namespace tetrisgui {

class BoardDrawingTool : public tetris::DrawingTool<tetris::Board>
{
  public:
    BoardDrawingTool(Gdk::RGBA background_colour);
    virtual ~BoardDrawingTool();
    BoardDrawingTool(const BoardDrawingTool& other);
    BoardDrawingTool(BoardDrawingTool&& other);

    virtual void draw(const tetris::Board& board,
                      tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool<tetris::Board>> copy()
                                                  const override;
  protected:
  private:
    Gdk::RGBA m_background_colour;
    //Gdk::RGBA m_line_colour;
    //double m_line_width;
};

} // namespace tetrisgui.

#endif // BOARDDRAWINGTOOL_H
