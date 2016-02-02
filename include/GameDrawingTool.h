#ifndef GAMEDRAWINGTOOL_H
#define GAMEDRAWINGTOOL_H

#include <Drawing.h>
#include <Game.h>

namespace tetrisgui {

class GameDrawingTool : public tetris::DrawingTool
{
  public:
    GameDrawingTool(const tetris::Game& game);
    virtual ~GameDrawingTool();
    GameDrawingTool(const GameDrawingTool& other) = default;

    virtual void draw(tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool> copy(
                              const tetris::Drawable& parent) const override;
  protected:
  private:
    const tetris::Game& m_game;
};

} // namespace tetrisgui.

#endif // GAMEDRAWINGTOOL_H
