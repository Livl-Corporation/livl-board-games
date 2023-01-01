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

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();
    void showGameModesDialog();
    void setupUI();
    void acceptGameModeSelection();
private:
    Ui::Menu *ui;
    QComboBox* gameModesComboBox;
};
#endif // MENU_H