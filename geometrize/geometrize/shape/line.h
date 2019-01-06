#pragma once

#include <cstdint>
#include <memory>

#include "shape.h"

namespace geometrize
{
class Model;
}

namespace geometrize
{

/**
 * @brief The Line class represents a simple line.
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class Line : public Shape
{
public:
    Line() = default;
    Line(float x1, float y1, float x2, float y2);
    /**
     * @brief Line Creates a new line.
     * @param model The model that created this shape.
     */
    Line(const geometrize::Model& model);

    virtual std::shared_ptr<geometrize::Shape> clone() const override;
    virtual std::vector<geometrize::Scanline> rasterize() const override;
    virtual void mutate() override;
    virtual void translate(float x, float y) override;
    virtual void scale(float scaleFactor) override;
    virtual geometrize::ShapeTypes getType() const override;
    virtual std::vector<float> getRawShapeData() const override;
    virtual std::string getSvgShapeData() const override;

    float m_x1; ///< First x-coordinate.
    float m_y1; ///< First y-coordinate.
    float m_x2; ///< Second x-coordinate.
    float m_y2; ///< Second y-coordinate.
};

}
