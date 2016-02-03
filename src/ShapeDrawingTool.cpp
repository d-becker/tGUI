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

#include "ShapeDrawingTool.h"

#include <cairomm/context.h>

#include <Block.h>

#include "DrawingContextInfo.h"

namespace tetrisgui {

ShapeDrawingTool::ShapeDrawingTool()
  : tetris::DrawingTool<tetris::Shape>()
{
  //ctor
}

ShapeDrawingTool::~ShapeDrawingTool()
{
  //dtor
}

ShapeDrawingTool::ShapeDrawingTool(const ShapeDrawingTool& other
                                   __attribute__((unused)))
  : tetris::DrawingTool<tetris::Shape>()
{
  // Copy constructor.
}

ShapeDrawingTool::ShapeDrawingTool(ShapeDrawingTool&& other
                                   __attribute__((unused)))
  : tetris::DrawingTool<tetris::Shape>()
{
  // Move constructor.
}

void ShapeDrawingTool::draw(const tetris::Shape& shape,
                            tetris::DrawingContextInfo& dci) {
  const Cairo::RefPtr<Cairo::Context>& cr = dci.cr;
  std::vector<tetris::Coords> block_positions = shape.getBlockPositions();

  for (const tetris::Coords& c : block_positions) {
    std::shared_ptr<tetris::Block> block = shape.get(c);
    if (block != nullptr) {
      cr->save();

      cr->translate(c.getHorizontal(), c.getVertical());
      block->draw(dci);

      cr->restore();
    }
  }
}

std::shared_ptr<tetris::DrawingTool<tetris::Shape>>
ShapeDrawingTool::copy() const {
  return std::make_shared<ShapeDrawingTool>(*this);
}

} // namespace tetrisgui.
