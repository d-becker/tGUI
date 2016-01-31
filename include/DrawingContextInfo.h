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

#ifndef TETRIS_DRAWINGCONTEXTINFO_H
#define TETRIS_DRAWINGCONTEXTINFO_H

#include <cairomm/context.h>

namespace tetris {

/**
 * This class is the definition and implementation of the class forward
 * declared in the tetris library. It contains a Cairo context object that
 * should be used when drawing the objects of the tetris library.
 */
class DrawingContextInfo
{
  public:
    DrawingContextInfo(Cairo::RefPtr<Cairo::Context> cr);
    virtual ~DrawingContextInfo();

    /**
     * A Cairo context object that should be used when drawing the objects of
     * the tetris library.
     */
    const Cairo::RefPtr<Cairo::Context> cr;
};

} // namespace tetris

#endif // TETRIS_DRAWINGCONTEXTINFO_H
