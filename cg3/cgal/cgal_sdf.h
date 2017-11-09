#ifndef CG3_CGAL_SDF_H
#define CG3_CGAL_SDF_H

#include "cgal_polyhedron.h"

#ifdef  CG3_DCEL_DEFINED
#include "cg3/meshes/dcel/dcel.h"
#endif

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/IO/Polyhedron_iostream.h>
#include <CGAL/mesh_segmentation.h>

#include <CGAL/property_map.h>

#include <iostream>
#include <fstream>

namespace cg3 {

namespace cgal {
    namespace sdf {

        std::vector<double> getSDFMap(const cgal::polyhedron::Polyhedron_3& mesh);

        #ifdef  CG3_DCEL_DEFINED
        std::map<const Dcel::Face*, double> getSDFMap(const Dcel& dcel);
        #endif

        #ifdef  CG3_EIGENMESH_DEFINED
        std::vector<double> getSDFMap(const SimpleEigenMesh& m);
        #endif


    }
}

}

#endif // CG3_CGAL_SDF_H