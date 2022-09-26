#ifndef FILEEXPLORER_H
#define FILEEXPLORER_H

#include <QWidget>
#include <QFileSystemModel>

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

private:
    Ui::FileExplorer *ui;
    QFileSystemModel *directory;
    QFileSystemModel *files;
    QString sPath;
};

#endif // FILEEXPLORER_H
