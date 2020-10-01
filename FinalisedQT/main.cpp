#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dandt.h"
#include "supermarket_database.h"
#include"cppbinding.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QScopedPointer<dandt>dants(new dandt);
    QScopedPointer<productDatabase>productDatabases(new productDatabase);
    QScopedPointer<request_suggest_complain_Database>requestandsuggestion(new request_suggest_complain_Database);
//    createDatabaseTable();


    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("TDate", dants->TDate);
    engine.rootContext()->setContextProperty("TTime", dants->TTime);
    engine.rootContext()->setContextProperty("dants", dants.data());
    engine.rootContext()->setContextProperty("pd", productDatabases.data());
    engine.rootContext()->setContextProperty("rands", requestandsuggestion.data());





    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
