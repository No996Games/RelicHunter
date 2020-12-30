#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFont font("Courier");
    QIcon icon("./resources/apple.png");

    std::cout << icon.isNull() << std::endl;

    QPushButton button("Hello World!");

    button.setIcon(icon);
    button.setFont(font);
    button.setText("Hey bro");
    button.setToolTip("Just click this");

    button.show();

    return app.exec();
}
