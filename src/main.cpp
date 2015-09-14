#include "../include/LeapTestDialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog w(argc,argv);

    w.show();

    return a.exec();
}
