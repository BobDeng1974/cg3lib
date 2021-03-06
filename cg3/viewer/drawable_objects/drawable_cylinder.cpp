/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#include "drawable_cylinder.h"
#include "../opengl_objects/opengl_objects.h"

#ifdef _WIN32
#undef min
#undef max
#endif

namespace cg3 {

DrawableCylinder::DrawableCylinder() :
    Cylinder(),
    color(128,128,128),
    slices(50),
    stacks(10)
{
}

DrawableCylinder::DrawableCylinder(
        const Pointd &a,
        const Pointd &b,
        double radius,
        QColor color,
        unsigned int slices,
        unsigned int stacks) :
    Cylinder(a, b, radius),
    color(color),
    slices(slices),
    stacks(stacks)
{
}

void DrawableCylinder::draw() const
{
    opengl::drawCylinder(a, b, _radius, _radius, color, slices, stacks);
}

Pointd DrawableCylinder::sceneCenter() const
{
    return (a+b)/2;
}

double DrawableCylinder::sceneRadius() const
{
    return std::max(_radius, a.dist(b)/2);
}

} //namespace cg3
