#ifndef CG3_LIBIGL_IS_VERTEX_MANIFOLD_H
#define CG3_LIBIGL_IS_VERTEX_MANIFOLD_H

#include <cg3/meshes/eigenmesh/eigenmesh.h>

namespace cg3 {

namespace libigl {
    bool isVertexManifold(const SimpleEigenMesh& input, Eigen::Matrix<bool, Eigen::Dynamic, 1>& B);
    bool isVertexManifold(const SimpleEigenMesh& input);

}

}

#include "is_vertex_manifold.ipp"

#endif // CG3_LIBIGL_IS_VERTEX_MANIFOLD_H