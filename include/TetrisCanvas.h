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

#ifndef TETRISCANVAS_H
#define TETRISCANVAS_H

#include <gtkmm/builder.h>
#include <gtkmm/drawingarea.h>

#include <GameFlow.h>

#include <memory>

namespace tetrisgui {

/**
 * A Gtk::DrawingArea that is associated with a \c tetris::Game object.
 * The canvas' \c on_draw method draws the \c tetris::Game object.
 */
class TetrisCanvas : public Gtk::DrawingArea
{
  public:
    TetrisCanvas(BaseObjectType* cobject,
                 const Glib::RefPtr<Gtk::Builder>& builder);
    virtual ~TetrisCanvas();

    /**
     * Returns a (smart) pointer to the \c tetris::GameFlow object that is
     * associated with this \c TetrisCanvas.
     *
     * \return A (smart) pointer to the \c tetris::GameFlow object that is
     *         associated with this \c TetrisCanvas.
     */
    std::shared_ptr<tetris::GameFlow> getGameFlow() const;

    /**
     * Sets the \c tetris::GameFlow object that is associated with this
     * \c TetrisCanvas to the one pointed to by \a game.
     *
     * \param game A (smart) pointer that points to the \c tetris::GameFlow
     *        object that will be associated with this \c TetrisCanvas.
     *        If it is a null pointer, an instance of
     *        \c std::invalid_argument is thrown.
     */
    void setGameFlow(std::shared_ptr<tetris::GameFlow> game_flow);

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
  private:
    bool signal_handler(GdkEventKey* event);
  private:
    std::shared_ptr<tetris::GameFlow> m_game_flow;
};

} // namespace tetrisgui.

#endif // TETRISCANVAS_H
