#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QWidget>
#include <QFileSystemModel>
#include <QList>
#include <QDebug>

namespace Ui {
class FileExplorer;
}

class FileExplorer : public QWidget
{
    Q_OBJECT

public:
    explicit FileExplorer(QWidget *parent = nullptr);
    ~FileExplorer();

private slots:
    void on_directoryView_clicked(QModelIndex index);

    void on_fileView_clicked(QModelIndex index);

private:
    Ui::FileExplorer *ui;
    QFileSystemModel *directory;
    QFileSystemModel *files;
    QString sPath;
    QList<QImage> selectedImages;
    QList<QString> selectedImageNames;
};

#endif // FILEEXPLORER_H
