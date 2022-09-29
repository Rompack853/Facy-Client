#include "fileexplorer.h"
#include "ui_fileexplorer.h"

FileExplorer::FileExplorer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileExplorer)
{
    ui->setupUi(this);

    // Code uebernommen aus Tutorial siehe Trello
    sPath = "C:/";
    directory = new QFileSystemModel(this);
    directory->setRootPath(sPath);
    directory->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    ui->directoryView->setModel(directory);
    QModelIndex index = directory->index(sPath, 0);
    ui->directoryView->setRootIndex(index);

    files = new QFileSystemModel(this);
    files->setRootPath(sPath);
    files->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    ui->fileView->setModel(files);
    index = files->index(sPath, 0);
    ui->fileView->setRootIndex(index);
}

FileExplorer::~FileExplorer()
{
    delete ui;
}

void FileExplorer::on_directoryView_clicked(QModelIndex index)
{
    QString path = directory->fileInfo(index).absoluteFilePath();
    ui->fileView->setRootIndex(files->setRootPath(path));
}


void FileExplorer::on_fileView_clicked(QModelIndex index)
{
    QString fileName = files->fileName(index);
    QString path = files->fileInfo(index).absoluteFilePath();
    QImage img(path);

    bool ok = true;
    for(QString name: selectedImageNames)
    {
        if(name == fileName)
        {
            ok = false;
        }
    }
    if(ok)
    {
        selectedImageNames.append(fileName);
        selectedImages.append(img);
    }


    qDebug() << "Selected Images:\n" << selectedImages;
}

