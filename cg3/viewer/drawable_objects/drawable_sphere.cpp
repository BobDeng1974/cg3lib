/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#include "drawable_sphere.h"
#include "../opengl_objects/opengl_objects.h"

namespace cg3 {

DrawableSphere::DrawableSphere() :
    Sphere(),
    color(128,128,128),
    precision(10)
{
}

DrawableSphere::DrawableSphere(
        const cg3::Pointd &center,
        double radius,
        QColor color,
        int precision) :
    Sphere(center, radius),
    color(color),
    precision(precision)
{
}

void DrawableSphere::draw() const
{
    opengl::drawSphere(_center, _radius, color, precision);
}

Pointd DrawableSphere::sceneCenter() const {
    return _center;
}

double DrawableSphere::sceneRadius() const {
    return _radius;
}

} //namespace cg3
