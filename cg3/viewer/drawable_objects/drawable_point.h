/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#ifndef CG3_DRAWABLE_POINT_H
#define CG3_DRAWABLE_POINT_H

#include <cg3/geometry/point.h>
#include <cg3/utilities/color.h>

#include "../interfaces/drawable_object.h"

namespace cg3 {

class DrawablePoint : public Pointd, public DrawableObject
{
public:
    DrawablePoint(
            double x = 0,
            double y = 0,
            double z = 0,
            Color c = Color(),
            int size = 3);

    // DrawableObject interface
    void draw() const;
    Pointd sceneCenter() const;
    double sceneRadius() const;

protected:
    Color color;
    unsigned int size;
};

} //namespace cg3

#endif // CG3_DRAWABLE_POINT_H
