#include "regular_lattice.h"

namespace cg3 {

template <class VT>
RegularLattice<VT>::RegularLattice() {
}

template<class VT>
RegularLattice<VT>::RegularLattice(const cg3::BoundingBox &bb, double unit, bool outsideBB) : bb(bb), unit(unit) {
    mresX = bb.getLengthX() / unit;
    if (outsideBB || std::fmod(bb.getLengthX(), unit) == 0)
        mresX++;
    mresY = bb.getLengthY() / unit;
    if (outsideBB || std::fmod(bb.getLengthY(), unit) == 0)
        mresY++;
    mresZ = bb.getLengthZ() / unit;
    if (outsideBB || std::fmod(bb.getLengthZ(), unit) == 0)
        mresZ++;
    bb.max() = Pointd(bb.minX() + unit * (mresX-1), bb.minY() + unit * (mresY-1), bb.minZ() + unit * (mresZ-1));
    vertexProperties.resize(mresX*mresY*mresZ);
}

template<class VT>
unsigned int RegularLattice<VT>::resX() const {
    return mresX;
}

template<class VT>
unsigned int RegularLattice<VT>::resY() const {
    return mresY;
}

template<class VT>
unsigned int RegularLattice<VT>::resZ() const {
    return mresZ;
}

template<class VT>
const BoundingBox &RegularLattice<VT>::boundingBox() const {
    return bb;
}

template<class VT>
Pointd RegularLattice<VT>::nearestVertex(const Pointd &p) const {
    return cg3::Pointd(bb.getMinX() + getIndexOfCoordinateX(p.x())*unit, bb.getMinY() + getIndexOfCoordinateY(p.y())*unit, bb.getMinZ() + getIndexOfCoordinateZ(p.z())*unit);
}

template<class VT>
const VT &RegularLattice<VT>::vertexProperty(const Pointd &p) const {
    assert(getIndexOfCoordinateX(p.x()) < mresX);
    assert(getIndexOfCoordinateY(p.y()) < mresY);
    assert(getIndexOfCoordinateZ(p.z()) < mresZ);
    return vertexProperties[getIndex(getIndexOfCoordinateX(p.x()), getIndexOfCoordinateY(p.y()), getIndexOfCoordinateZ(p.z()))];
}

template<class VT>
void RegularLattice<VT>::setVertexProperty(const Pointd &p, const VT &property) {
    assert(getIndexOfCoordinateX(p.x()) < mresX);
    assert(getIndexOfCoordinateY(p.y()) < mresY);
    assert(getIndexOfCoordinateZ(p.z()) < mresZ);
    vertexProperties[getIndex(getIndexOfCoordinateX(p.x()), getIndexOfCoordinateY(p.y()), getIndexOfCoordinateZ(p.z()))] = property;
}

template<class VT>
void RegularLattice<VT>::serialize(std::ofstream &binaryFile) const {
    bb.serialize(binaryFile);
    cg3::Serializer::serialize(unit, binaryFile);
    cg3::Serializer::serialize(mresX, binaryFile);
    cg3::Serializer::serialize(mresY, binaryFile);
    cg3::Serializer::serialize(mresZ, binaryFile);
    cg3::Serializer::serialize(vertexProperties, binaryFile);
}

template<class VT>
bool RegularLattice<VT>::deserialize(std::ifstream &binaryFile) {
    RegularLattice<VT> tmp;
    std::streampos begin = binaryFile.tellg();
    if (tmp.bb.deserialize(binaryFile) &&
            cg3::Serializer::deserialize(tmp.unit, binaryFile) &&
            cg3::Serializer::deserialize(tmp.mresX, binaryFile) &&
            cg3::Serializer::deserialize(tmp.mresY, binaryFile) &&
            cg3::Serializer::deserialize(tmp.mresZ, binaryFile) &&
            cg3::Serializer::deserialize(tmp.vertexProperties, binaryFile)){
        *this = std::move(tmp);
        return true;
    }
    else {
        Serializer::restore(binaryFile, begin);
        return false;
    }

}

template<class VT>
Pointd RegularLattice<VT>::getPoint(unsigned int i, unsigned int j, unsigned int k) const {
    return cg3::Pointd(bb.getMinX() + i*unit, bb.getMinY() + j*unit, bb.getMinZ() + k*unit);
}

template<class VT>
unsigned int RegularLattice<VT>::getIndex(unsigned int i, unsigned int j, unsigned int k) const {
    assert (i < mresX);
    assert (j < mresY);
    assert (k < mresZ);
    return k+mresZ*(j + mresY*i);
}

template<class VT>
int RegularLattice<VT>::getIndexOfCoordinateX(double x) const {
    double deltax = x - bb.getMinX();
    return (deltax * (mresX-1)) / bb.getLengthX();
}

template<class VT>
int RegularLattice<VT>::getIndexOfCoordinateY(double y) const {
    double deltay = y - bb.getMinY();
    return (deltay * (mresY-1)) / bb.getLengthY();
}

template<class VT>
int RegularLattice<VT>::getIndexOfCoordinateZ(double z) const {
    double deltaz = z - bb.getMinZ();
    return (deltaz * (mresZ-1)) / bb.getLengthZ();
}

}