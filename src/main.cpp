#include <QApplication>

#include "mainwindow.h"
#include "translationmanager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName(QStringLiteral("markdown0011"));
    app.setApplicationName(QStringLiteral("markdown0011"));
    app.setApplicationDisplayName(QStringLiteral("markdown0011"));
    app.setApplicationVersion(QStringLiteral("0.1.0"));

    // Must happen before the main window is built, so that setupUi() already
    // picks up the translated strings.
    TranslationManager::instance().setLanguage(TranslationManager::preferredLanguage());

    MainWindow window;
    window.show();

    const QStringList args = app.arguments();
    if (args.size() > 1)
        window.openFile(args.at(1));

    return app.exec();
}
