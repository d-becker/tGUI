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

#ifndef ADVANCEDGAMEBOARDDRAWINGTOOL_H
#define ADVANCEDGAMEBOARDDRAWINGTOOL_H

#include "GameBoardDrawingTool.h"

namespace tetrisgui {

/**
 * A class that makes it possible to display the place where the current shape
 * would land as a faded "shadow" of the shape.
 */
class AdvancedGameBoardDrawingTool : public GameBoardDrawingTool
{
  public:
    /**
     * Constructs a new \c AdvancedGameBoardDrawingTool. The default is to show
     * where the current shape would land with an alpha factor of 0.3.
     */
    AdvancedGameBoardDrawingTool();

    /**
     * Constructs a new \c AdvancedGameBoardDrawingTool with the given options.
     *
     * \param show_fall_place If \c true, the place where the current shape
     *        would land will be shown as a "shadow"; if this parameter is
     *        \c false, the no "shadow" will be shown.
     * \param alpha The alpha factor of the "shadow" (the value 1.0 means the
     *        "shadow" will be identical to the "real" shape, 0.0 means the
     *        "shadow" is invisible).
     */
    AdvancedGameBoardDrawingTool(bool show_fall_place, double alpha = 0.3);
    virtual ~AdvancedGameBoardDrawingTool();
    AdvancedGameBoardDrawingTool(const AdvancedGameBoardDrawingTool& other);
    AdvancedGameBoardDrawingTool(AdvancedGameBoardDrawingTool&& other);

    /**
     * Returns whether the place where the current shape would land is shown.
     *
     * \return \c true if the place where the current shape would land is shown;
     *         \c false otherwise.
     */
    virtual bool getShowFallingPlace() const;

    /**
     * Sets whether the place where the current shape would land is shown.
     *
     * \param show_fall_place If this is \c true, the place where the current
     *        shape would land is shown; otherwise it will not be shown.
     */
    virtual void setShowFallingPlace(bool show_fall_place);


    /**
     * Returns the alpha factor with which the "shadow" is shown.
     *
     * \return The alpha factor with which the "shadow" is shown.
     */
    virtual double getAlphaOfFallingPlace() const;

    /**
     * Sets the alpha factor with which the "shadow" will be shown.
     *
     * \param alpha The alpha factor with which the "shadow" will be shown.
     */
    virtual void setAlphaOfFallingPlace(double alpha);

    virtual void draw(const tetris::GameBoard& game_board,
                      tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool<tetris::GameBoard>> copy()
                                                 const override;
  protected:
  private:
    bool m_show_where_block_falls;
    double m_alpha_of_falling_place;
};

} // namespace tetrisgui.

#endif // ADVANCEDGAMEBOARDDRAWINGTOOL_H
