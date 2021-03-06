/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#ifndef DRAWABLE_PLANE_H
#define DRAWABLE_PLANE_H

#include <cg3/geometry/plane.h>
#include <cg3/viewer/interfaces/drawable_object.h>

namespace cg3 {

/**
 * @ingroup cg3viewer
 * @brief The DrawablePlane class
 */
class DrawablePlane : public cg3::Plane, public DrawableObject
{
public:
    DrawablePlane(const Vec3& _normal, double _d);
    DrawablePlane(double a, double b, double c, double _d);
    DrawablePlane(const Pointd &p1, const Pointd &p2, const Pointd &p3);
    DrawablePlane(Plane p);

    // DrawableObject interface
    void draw() const;
    Pointd sceneCenter() const;
    double sceneRadius() const;

    // SerializableObject interface
    void deserialize(std::ifstream& binaryFile);

protected:
    void calculatePoints();
    cg3::Pointd p1, p2, p3, p4;
};

} // namespace cg3

#endif // DRAWABLE_PLANE_H
