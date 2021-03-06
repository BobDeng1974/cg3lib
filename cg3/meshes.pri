#
# This file is part of cg3lib: https://github.com/cg3hci/cg3lib
# This Source Code Form is subject to the terms of the GNU GPL 3.0
#
# @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
# @author Stefano Nuvoli (stefano.nuvoli@gmail.com)
#

!contains(DEFINES, CG3_CORE_DEFINED){
    error(Meshes module requires the Core module!)
}

DEFINES += CG3_DCEL_DEFINED
MODULES += CG3_MESHES

HEADERS += \
    $$PWD/meshes/dcel/dcel.h \
    $$PWD/meshes/dcel/dcel_face.h \
    $$PWD/meshes/dcel/dcel_face_iterators.h \
    $$PWD/meshes/dcel/dcel_half_edge.h \
    $$PWD/meshes/dcel/dcel_iterators.h \
    $$PWD/meshes/dcel/dcel_struct.h \
    $$PWD/meshes/dcel/dcel_vertex.h \
    $$PWD/meshes/dcel/dcel_vertex_iterators.h \
    $$PWD/meshes/dcel/algorithms/dcel_algorithms.h  \
    $$PWD/meshes/dcel/algorithms/dcel_bounding_boxes.h \
    $$PWD/meshes/dcel/algorithms/dcel_to_vectors.h \
    $$PWD/meshes/dcel/algorithms/dcel_changes.h \
    $$PWD/meshes/dcel/algorithms/dcel_flooding.h \
    $$PWD/meshes/dcel/algorithms/dcel_coloring.h \
    $$PWD/meshes/dcel/algorithms/dcel_connected_components.h \
    $$PWD/meshes/dcel/dcel_builder.h \
    $$PWD/meshes/mesh.h


SOURCES += \
    $$PWD/meshes/dcel/dcel_face.cpp \
    $$PWD/meshes/dcel/dcel_half_edge.cpp \
    $$PWD/meshes/dcel/dcel_vertex.cpp \
    $$PWD/meshes/dcel/dcel_struct.cpp \
    $$PWD/meshes/dcel/dcel_inline.tpp \
    $$PWD/meshes/dcel/dcel_half_edge_inline.tpp \
    $$PWD/meshes/dcel/dcel_face_iterators_inline.tpp \
    $$PWD/meshes/dcel/dcel_iterators_inline.tpp \
    $$PWD/meshes/dcel/dcel_vertex_inline.tpp \
    $$PWD/meshes/dcel/dcel_vertex_iterators_inline.tpp \
    $$PWD/meshes/dcel/dcel_face_inline.tpp \
    $$PWD/meshes/dcel/algorithms/dcel_to_vectors.cpp \
    $$PWD/meshes/dcel/algorithms/dcel_changes.cpp \
    $$PWD/meshes/dcel/algorithms/dcel_flooding.tpp \
    $$PWD/meshes/dcel/algorithms/dcel_coloring.cpp \
    $$PWD/meshes/dcel/algorithms/dcel_connected_components.tpp \
    $$PWD/meshes/dcel/algorithms/dcel_bounding_boxes.tpp \
    $$PWD/meshes/dcel/dcel_builder.cpp


contains(DEFINES, CG3_WITH_EIGEN) {

DEFINES += CG3_EIGENMESH_DEFINED

unix:!macx {
    LIBS += -lboost_system -DBOOST_LOG_DYN_LINK -lboost_log -lboost_thread -lpthread
}

HEADERS += \
    $$PWD/meshes/eigenmesh/simpleeigenmesh.h \
    $$PWD/meshes/eigenmesh/eigenmesh.h \
    $$PWD/meshes/eigenmesh/algorithms/eigenmesh_algorithms.h


SOURCES += \
    $$PWD/meshes/eigenmesh/simpleeigenmesh.cpp \
    $$PWD/meshes/eigenmesh/eigenmesh.cpp \
    $$PWD/meshes/eigenmesh/algorithms/eigenmesh_algorithms.cpp

}
