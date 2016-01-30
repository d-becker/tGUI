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

#include <Game.h>

#include <memory>

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
     * Returns a (smart) pointer to the \c tetris::Game object that is
     * associated with this \c TetrisCanvas.
     *
     * \return A (smart) pointer to the \c tetris::Game object that is
     *         associated with this \c TetrisCanvas.
     */
    std::shared_ptr<tetris::Game> getGame() const;

    /**
     * Sets the \c tetris::Game object that is associated with this
     * \c TetrisCanvas to the one pointed to by \a game.
     *
     * \param game A (smart) pointer that points to the \c tetris::Game object
     *        that will be associated with this \c TetrisCanvas. If it is a
     *        null pointer, an instance of \c std::invalid_argument is thrown.
     */
    void setGame(std::shared_ptr<tetris::Game> game);

    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
  protected:
  private:
    std::shared_ptr<tetris::Game> m_game;
};

#endif // TETRISCANVAS_H
