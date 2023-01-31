#include <QApplication>
#include <QPushButton>
#include <memory>
#include <QSoundEffect>

#include "views/gui/windows/menu/MenuWindow.h"
#include "controllers/MenuController.h"
#include "views/cli/menu/MenuConsole.h"
#include "shared/SoundPlayer.h"

int setupConsole() {
    auto menuConsole = std::make_shared<MenuConsole>();
    auto menuController = std::make_shared<MenuController>();

    menuConsole->setController(menuController);
    menuConsole->show();

    return 0;
}

int setupGui() {
    int argc = 0;
    QApplication a(argc, nullptr);
    QApplication::setWindowIcon(QIcon(":/img/logo.png"));
    std::cout << "Starting GUI" << std::endl;

    auto menuWindow = std::make_shared<MenuWindow>();
    auto menuController = std::make_shared<MenuController>();

    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(":/assets/sounds/belle_musique.wav"));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.setVolume(1);
    effect.play();


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
