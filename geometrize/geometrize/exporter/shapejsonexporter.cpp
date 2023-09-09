#include "shapejsonexporter.h"

#include <cassert>
#include <cstdint>
#include <sstream>
#include <string>
#include <vector>

#include "../shape/shape.h"
#include "../shape/shapetypes.h"
#include "../shaperesult.h"
#include "shapeserializer.h"

namespace geometrize {

    namespace exporter {

        std::string exportShapeJson(const std::vector<geometrize::ShapeResult>& data) {
            std::ostringstream stream;
            stream << "[";

            for(std::size_t i = 0; i < data.size(); i++) {
                const geometrize::ShapeResult& s(data[i]);
                const geometrize::ShapeTypes type{ s.shape->getType() };
                const std::vector<float> shapeData{ getRawShapeData(*s.shape.get()) };
                const geometrize::rgba color(s.color);
                const double score{ s.score };

                uint32_t typeId{};
                switch(type) {
                case RECTANGLE:
                    typeId = 0;
                    break;
                case ROTATED_RECTANGLE:
                    typeId = 1;
                    break;
                case TRIANGLE:
                    typeId = 2;
                    break;
                case ELLIPSE:
                    typeId = 3;
                    break;
                case ROTATED_ELLIPSE:
                    typeId = 4;
                    break;
                case CIRCLE:
                    typeId = 5;
                    break;
                default:
                    assert(false);
                }

                stream << "{"
                       << "\"type\":" << typeId << ", \"data\":[";
                for(std::size_t d = 0; d < shapeData.size(); d++) {
                    stream << shapeData[d];
                    if(d <= shapeData.size() - 2) {
                        stream << ",";
                    }
                }
                stream << "],\"color\":[" << static_cast<std::uint32_t>(color.r) << ","
                       << static_cast<std::uint32_t>(color.g) << "," << static_cast<std::uint32_t>(color.b) << ","
                       << static_cast<std::uint32_t>(color.a) << "],";
                stream << "\"score\":" << score << "}";

                if(i <= data.size() - 2) {
                    stream << ",\n";
                }
            }

            stream << "\n]";
            return stream.str();
        }

    } // namespace exporter

} // namespace geometrize
