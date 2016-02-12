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

#ifndef GTKGAMEFLOW_H
#define GTKGAMEFLOW_H

#include <BasicGameFlow.h>


#include "TetrisCanvas.h"

namespace tetrisgui {

class GtkGameFlow : public tetris::BasicGameFlow
{
  public:
    GtkGameFlow(std::shared_ptr<TetrisCanvas> tetris_canvas,
                std::shared_ptr<tetris::Game> game, unsigned int interval);
    GtkGameFlow(std::shared_ptr<TetrisCanvas> tetris_canvas,
                std::shared_ptr<tetris::Game> game);
    virtual ~GtkGameFlow();

    virtual void draw() override;
  protected:
  private:
    std::shared_ptr<TetrisCanvas> m_tetris_canvas;
};

} // namespace tetrisgui.

#endif // GTKGAMEFLOW_H
