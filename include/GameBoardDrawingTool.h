#ifndef GAMEBOARDDRAWINGTOOL_H
#define GAMEBOARDDRAWINGTOOL_H

#include <Board.h>
#include <Drawing.h>
#include <GameBoard.h>

namespace tetrisgui {

class GameBoardDrawingTool : public tetris::DrawingTool
{
  public:
    GameBoardDrawingTool(const tetris::GameBoard& game_board);
    virtual ~GameBoardDrawingTool();
    GameBoardDrawingTool(const GameBoardDrawingTool& other) = default;

    virtual void draw(tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool> copy(
                              const tetris::Drawable& parent) const override;
  protected:
  private:
    const tetris::GameBoard& m_game_board;
};

} // namespace tetrisgui.

#endif // GAMEBOARDDRAWINGTOOL_H
