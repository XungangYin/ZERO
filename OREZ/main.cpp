#include "orez.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OREZ w;
    w.show();

    return a.exec();
}
