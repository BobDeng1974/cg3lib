/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */
#ifndef CG3_DCEL_TO_VECTORS_H
#define CG3_DCEL_TO_VECTORS_H

#include <cg3/meshes/dcel/dcel.h>

namespace cg3 {
namespace dcelAlgorithms {
namespace internal {

static std::vector<const Dcel::Vertex*> dummymv;
static std::vector<const Dcel::Face*> dummymf;

} //namespace cg3::dcelAlgorithms::internal

void getVectorFaces(std::vector<const Dcel::Face*> &vector, const Dcel& d);
void getVectorFaces(std::vector<Dcel::Face*> &vector, Dcel& d);


void getVectorMesh(
        std::vector< Pointd > &coords,
        std::vector< std::vector<int>> &faces,
        const Dcel &d,
        std::vector<const Dcel::Vertex*> &mappingVertices = internal::dummymv,
        std::vector<const Dcel::Face*> &mappingFaces = internal::dummymf);

} //namespace cg3::dcelAlgorithms
} //namespace cg3

#endif // CG3_DCEL_TO_VECTORS_H