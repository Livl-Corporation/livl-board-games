#include <QApplication>
#include <QPushButton>
#include <memory>
#include "views/gui/windows/menu/MenuWindow.h"
#include "controllers/MenuController.h"

int setupConsole() {
    return 1;
}

int setupGui() {
    int argc = 0;
    QApplication a(argc, nullptr);
    QApplication::setWindowIcon(QIcon(":/img/logo.png"));

    auto menuWindow = std::make_shared<MenuWindow>();
    auto menuController = std::make_shared<MenuController>();

    menuWindow->setController(menuController);
    menuWindow->show();

    return QApplication::exec();

}

int main(int argc, char *argv[]) {

    // Run with param -console use the cli
    bool useConsole = argc > 1 && std::string(argv[1]) == "-console";
    if (useConsole) {
        return setupConsole();
    } else {
        return setupGui();
    }

}
