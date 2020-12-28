#include <iostream>
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QMainWindow w;
    w.resize(400,600);
    w.show();
    return a.exec();
}
