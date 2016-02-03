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

#ifndef BLOCKDRAWINGTOOL_H
#define BLOCKDRAWINGTOOL_H

#include <gdkmm/rgba.h>

#include <Block.h>
#include <Drawing.h>

namespace tetrisgui {

class BlockDrawingTool : public tetris::DrawingTool<tetris::Block>
{
  public:
    BlockDrawingTool(Gdk::RGBA fill_colour, Gdk::RGBA line_colour,
                     double line_width);
    virtual ~BlockDrawingTool();
    BlockDrawingTool(const BlockDrawingTool& other);
    BlockDrawingTool(BlockDrawingTool&& other);

    virtual void draw(const tetris::Block& block,
                      tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool<tetris::Block>> copy()
                                                  const override;
  protected:
  private:
    Gdk::RGBA m_fill_colour;
    Gdk::RGBA m_line_colour;
    double m_line_width;
};

} // namespace tetrisgui.

#endif // BLOCKDRAWINGTOOL_H
