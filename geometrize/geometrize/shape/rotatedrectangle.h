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
 * @brief The RotatedRectangle class represents a rotated rectangle.
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class RotatedRectangle : public Shape
{
public:
    RotatedRectangle() = default;
    RotatedRectangle(float x1, float y1, float x2, float y2, float angle);
    /**
     * @brief RotatedRectangle Creates a new rotated rectangle.
     * @param model The model that created this shape.
     */
    RotatedRectangle(const geometrize::Model& model);

    virtual std::shared_ptr<geometrize::Shape> clone() const override;
    virtual std::vector<geometrize::Scanline> rasterize() const override;
    virtual void mutate() override;
    virtual void translate(float x, float y) override;
    virtual void scale(float scaleFactor) override;
    virtual geometrize::ShapeTypes getType() const override;
    virtual std::vector<float> getRawShapeData() const override;
    virtual std::string getSvgShapeData() const override;

    std::vector<std::pair<float, float>> getCornerPoints() const;

    float m_x1; ///< Left coordinate.
    float m_y1; ///< Top coordinate.
    float m_x2; ///< Right coordinate.
    float m_y2; ///< Bottom coordinate.
    float m_angle; ///< Rotation angle.
};

}
