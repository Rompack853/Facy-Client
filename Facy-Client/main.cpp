#include "frmlogin.h"
#include <QApplication>

#include "frmmain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FrmLogin w;
    w.show();
    return a.exec();
}
