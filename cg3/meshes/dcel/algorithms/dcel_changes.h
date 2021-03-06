/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#ifndef CG3_DCEL_CHANGES_H
#define CG3_DCEL_CHANGES_H

#include <cg3/meshes/dcel/dcel.h>

namespace cg3 {
namespace dcelAlgorithms {

bool edgeFlip(Dcel& d, const cg3::Dcel::HalfEdge* he);

} //namespace cg3::dcelAlgorithms
} //namespace cg3

#endif // CG3_DCEL_CHANGES_H
