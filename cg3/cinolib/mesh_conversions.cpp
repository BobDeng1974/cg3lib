#include "mesh_conversions.h"

#ifdef EIGENMESH_DEFINED
void MeshConversions::eigenMeshToTrimesh(cinolib::Trimesh& m, const SimpleEigenMesh& simpleEigenMesh) {
    unsigned int nVertices=simpleEigenMesh.getNumberVertices();
    unsigned int nFaces=simpleEigenMesh.getNumberFaces();

    std::vector<double> coords;
    std::vector<unsigned int> tris;

    coords.resize(nVertices*3);
    tris.resize(nFaces*3);

    for(unsigned int i=0;i<nVertices;++i) {
        unsigned int j=i*3;
        coords[j]=simpleEigenMesh.getVertex(i).x();
        coords[j+1]=simpleEigenMesh.getVertex(i).y();
        coords[j+2]=simpleEigenMesh.getVertex(i).z();

    }
    for(unsigned int i=0;i<nFaces;++i) {
        unsigned int j=i*3;
        tris[j]=simpleEigenMesh.getFace(i).x();
        tris[j+1]=simpleEigenMesh.getFace(i).y();
        tris[j+2]=simpleEigenMesh.getFace(i).z();
    }
    m = cinolib::Trimesh(coords, tris);
}
#endif

#ifdef DCEL_DEFINED
void MeshConversions::dcelToTrimesh(cinolib::Trimesh& m, const Dcel& d) {
    unsigned int nVertices=d.getNumberVertices();
    unsigned int nFaces=d.getNumberFaces();

    std::vector<double> coords;
    std::vector<unsigned int> tris;

    std::map<const Dcel::Vertex*, int> map;

    coords.resize(nVertices*3);
    tris.resize(nFaces*3);

    unsigned int i = 0;
    for(const Dcel::Vertex* v : d.vertexIterator()) {
        Pointd coord = v->getCoordinate();
        unsigned int j=i*3;
        coords[j]=coord.x();
        coords[j+1]=coord.y();
        coords[j+2]=coord.z();
        map[v] = i;
        i++;
    }

    i = 0;
    for(const Dcel::Face* f : d.faceIterator()) {
        unsigned int j=i*3;
        for (const Dcel::Vertex* v : f->incidentVertexIterator()){
            if (j < (i+1)*3){
                tris[j] = map[v];
                j++;
            }
        }
        i++;
    }
    m = cinolib::Trimesh(coords, tris);
}
#endif
