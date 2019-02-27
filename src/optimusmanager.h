#ifndef OPTIMUSMANAGER_H
#define OPTIMUSMANAGER_H

#include <QObject>

class QMenu;
#ifdef KDE
class KStatusNotifierItem;
#else
class QSystemTrayIcon;
#endif

class OptimusManager : public QObject
{
    Q_OBJECT

public:
    enum Mode {
        Intel,
        Nvidia,
    };
    Q_ENUM(Mode)

    OptimusManager(QObject *parent = nullptr);
    ~OptimusManager() override;


private slots:
    void switchToIntel();
    void switchToNvidia();
    void openSettings();
    void showAppRunningMessage();

private:
    void switchMode(Mode mode);
    void retranslateUi();

    static Mode currentMode();

    QMenu *m_contextMenu;
#ifdef KDE
    KStatusNotifierItem *m_trayIcon;
#else
    QSystemTrayIcon *m_trayIcon;
#endif
};

#endif // OPTIMUSMANAGER_H
