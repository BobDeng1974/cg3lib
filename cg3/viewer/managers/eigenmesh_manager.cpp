/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#include "eigenmesh_manager.h"
#include "ui_eigenmesh_manager.h"

#include <QFileDialog>

namespace cg3 {
namespace viewer {

EigenMeshManager::EigenMeshManager(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::EigenMeshManager),
    mainWindow((cg3::viewer::MainWindow&)*parent),
    loaded (false)
{
    ui->setupUi(this);
    objls.addSupportedExtension("obj", "ply");
}

void EigenMeshManager::setEigenMesh(const EigenMesh& m)
{
    if (loaded){
        mainWindow.deleteDrawableObject(&mesh);
    }
    mesh = m;
    mainWindow.pushDrawableObject(&mesh, "EigenMesh");
    setButtonsMeshLoaded(true);
    loaded = true;
    mainWindow.canvas.update();
    mainWindow.canvas.fitScene();
}

EigenMeshManager::~EigenMeshManager()
{
    if (loaded){
        mainWindow.deleteDrawableObject(&mesh);
    }
    delete ui;
}

void EigenMeshManager::on_loadMeshButton_clicked()
{
    std::string filename = objls.loadDialog("Open Eigen Mesh");
    if (filename != "") {
        if (loaded){
            mainWindow.deleteDrawableObject(&mesh);
        }
        loaded = mesh.loadFromFile(filename);

        if (loaded) {
            mesh.setEnableTriangleColor();
            mainWindow.pushDrawableObject(&mesh, filename.substr(filename.find_last_of("/") + 1));
            setButtonsMeshLoaded(true);
            mainWindow.canvas.update();
            mainWindow.canvas.fitScene();
        }
        else {
            std::cerr << "Error while loading file " << filename << ".\n";
        }
    }
}

void EigenMeshManager::on_clearMeshButton_clicked()
{
    if (loaded) {
        setButtonsMeshLoaded(false);
        mainWindow.deleteDrawableObject(&mesh);
        mainWindow.canvas.update();
        mainWindow.canvas.fitScene();
    }
}

void EigenMeshManager::on_saveMeshButton_clicked()
{
    if (loaded){
        QString selectedFilter;
        QString filename = QFileDialog::getSaveFileName(nullptr,
                           "Save Eigen Mesh",
                           ".",
                           "PLY(*.ply);;OBJ(*.obj)", &selectedFilter);
        if (!filename.isEmpty()) {
            std::cout << "save: " << filename.toStdString() << std::endl;

            if (selectedFilter == "PLY(*.ply)") {
                mesh.saveOnPly(filename.toStdString());
            }
            else  if (selectedFilter == "OBJ(*.obj)") {
                mesh.saveOnObj(filename.toStdString());
            }
        }
    }
}

void EigenMeshManager::on_pointsMeshRadioButton_toggled(bool checked)
{
    if (loaded) {
        if (checked){
            mesh.setPointsShading();
            mainWindow.canvas.update();
        }
    }
}

void EigenMeshManager::on_flatMeshRadioButton_toggled(bool checked)
{
    if (loaded) {
        if (checked){
            mesh.setFlatShading();
            mainWindow.canvas.update();
        }
    }
}

void EigenMeshManager::on_smoothMeshRadioButton_toggled(bool checked)
{
    if (loaded) {
        if (checked){
            mesh.setSmoothShading();
            mainWindow.canvas.update();
        }
    }
}

void EigenMeshManager::on_wireframeMeshCheckBox_stateChanged(int arg1)
{
    if (loaded) {
        mesh.setWireframe(arg1 == Qt::Checked);
        mainWindow.canvas.update();
    }
}

void EigenMeshManager::on_verticesColorRadioButton_toggled(bool checked)
{
    if (loaded) {
        if (checked){
            mesh.setEnableVertexColor();
            mainWindow.canvas.update();
        }
    }
}

void EigenMeshManager::on_faceColorRadioButton_toggled(bool checked)
{
    if (loaded) {
        if (checked){
            mesh.setEnableTriangleColor();
            mainWindow.canvas.update();
        }
    }
}

void EigenMeshManager::on_boundingBoxCheckBox_stateChanged(int arg1)
{
    if (loaded) {
        mesh.setVisibleBoundingBox(arg1 == Qt::Checked);
        mainWindow.canvas.update();
    }
}

void EigenMeshManager::setButtonsMeshLoaded(bool b)
{
    ui->loadMeshButton->setEnabled(!b);
    ui->clearMeshButton->setEnabled(b);
    ui->saveMeshButton->setEnabled(b);
    ui->pointsMeshRadioButton->setEnabled(b);
    ui->flatMeshRadioButton->setEnabled(b);
    ui->smoothMeshRadioButton->setEnabled(b);
    ui->wireframeMeshCheckBox->setEnabled(b);
    ui->boundingBoxCheckBox->setEnabled(b);
    ui->verticesColorRadioButton->setEnabled(b);
    ui->faceColorRadioButton->setEnabled(b);
    ui->wireframeMeshCheckBox->setChecked(false);
    ui->boundingBoxCheckBox->setChecked(false);
    ui->smoothMeshRadioButton->setChecked(true);
    ui->faceColorRadioButton->setChecked(true);
    ui->verticesColorRadioButton->setChecked(false);
}

} //namespace cg3::viewer
} //namespace cg3
