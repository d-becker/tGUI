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

#ifndef SHAPEDRAWINGTOOL_H
#define SHAPEDRAWINGTOOL_H

#include <Drawing.h>
#include <Shape.h>

namespace tetrisgui {

class ShapeDrawingTool : public tetris::DrawingTool<tetris::Shape>
{
  public:
    ShapeDrawingTool();
    virtual ~ShapeDrawingTool();
    ShapeDrawingTool(const ShapeDrawingTool& other);
    ShapeDrawingTool(ShapeDrawingTool&& other);

    virtual void draw(const tetris::Shape& shape,
                      tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool<tetris::Shape>> copy()
                                                 const override;
  protected:
  private:
};

} // namespace tetrisgui.

#endif // SHAPEDRAWINGTOOL_H
