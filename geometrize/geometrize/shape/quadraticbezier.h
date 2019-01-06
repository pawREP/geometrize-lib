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
 * @brief The QuadraticBezier class represents a quadratic bezier curve.
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class QuadraticBezier : public Shape
{
public:
    QuadraticBezier() = default;
    QuadraticBezier(float cx, float cy, float x1, float y1, float x2, float y2);
    /**
     * @brief QuadraticBezier Creates a new quadratic bezier curve.
     * @param model The model that created this shape.
     */
    QuadraticBezier(const geometrize::Model& model);

    virtual std::shared_ptr<geometrize::Shape> clone() const override;
    virtual std::vector<geometrize::Scanline> rasterize() const override;
    virtual void mutate() override;
    virtual void translate(float x, float y) override;
    virtual void scale(float scaleFactor) override;
    virtual geometrize::ShapeTypes getType() const override;
    virtual std::vector<float> getRawShapeData() const override;
    virtual std::string getSvgShapeData() const override;

    float m_cx; ///< Control point x-coordinate.
    float m_cy; ///< Control point y-coordinate.
    float m_x1; ///< First x-coordinate.
    float m_y1; ///< First y-coordinate.
    float m_x2; ///< Second x-coordinate.
    float m_y2; ///< Second y-coordinate.
};

}
