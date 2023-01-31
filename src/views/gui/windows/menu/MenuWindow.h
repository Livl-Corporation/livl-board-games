#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include "models/MenuData.h"
#include "./ui_MenuWindow.h"
#include "controllers/MenuController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow() override;

    void setController(const std::shared_ptr<MenuController> &_controller) {
        this->controller = _controller;
    };

protected:
    void setGameList(const std::vector<std::string> &gameList);
    void setPlayerList(const std::vector<std::string> &playerList);

private:
    Ui::MenuWindow *ui;
    std::shared_ptr<MenuController> controller;
    void onSaveSelected();


public slots:
    void onPlayClicked();

};
#endif // MENU_H
