#include <QApplication>
#include <QPushButton>
#include <memory>
#include "views/gui/windows/menu/MenuWindow.h"
#include "controllers/MenuController.h"
#include "views/cli/menu/MenuConsole.h"

int setupConsole() {
    std::shared_ptr<MenuConsole> menuConsole = std::make_shared<MenuConsole>();
    std::shared_ptr<MenuController> menuController = std::make_shared<MenuController>();

    menuConsole->setController(menuController);
    menuConsole->show();

    return 0;
}

int setupGui() {
    int argc = 0;
    QApplication a(argc, nullptr);
    QApplication::setWindowIcon(QIcon(":/img/logo.png"));
    std::cout << "Starting GUI" << std::endl;

    std::shared_ptr<MenuWindow> menuWindow = std::make_shared<MenuWindow>();
    std::shared_ptr<MenuController> menuController = std::make_shared<MenuController>();

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
