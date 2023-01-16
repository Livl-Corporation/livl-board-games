#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QScopedPointer>
#include <QSharedPointer>
#include <QLabel>
#include <QComboBox>
#include <QFont>
#include <QVBoxLayout>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QFileInfo>
#include "../../../models/player.hpp"
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu() override;

    void setGameList(const std::vector<std::string> &gameList);
    void setPlayerList(const std::vector<std::string> &playerList);

private:
    Ui::Menu *ui;
};
#endif // MENU_H
