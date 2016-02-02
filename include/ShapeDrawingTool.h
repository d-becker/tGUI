#ifndef SHAPEDRAWINGTOOL_H
#define SHAPEDRAWINGTOOL_H

#include <Drawing.h>
#include <Shape.h>

namespace tetrisgui {

class ShapeDrawingTool : public tetris::DrawingTool
{
  public:
    ShapeDrawingTool(const tetris::Shape& shape);
    virtual ~ShapeDrawingTool();
    ShapeDrawingTool(const ShapeDrawingTool& other) = delete;

    virtual void draw(tetris::DrawingContextInfo& dci) override;
    virtual std::shared_ptr<tetris::DrawingTool> copy(
                              const tetris::Drawable& parent) const override;
  protected:
  private:
    /**
     * Non-owning reference to the shape with which it is associated.
     */
    const tetris::Shape& m_shape;
};

} // namespace tetrisgui.

#endif // SHAPEDRAWINGTOOL_H
