#include <QApplication>
#include <QResource>
#include <QTimer>
#include <QPixmap>
#include <QDebug>

void run_main(QApplication& app) {
    bool f = QResource::registerResource("resources.rcc");
    qDebug() << "registerResource = " << f;
    f = QResource::registerResource("resources-small.rcc");
    qDebug() << "registerResoruce = " << f;

    QPixmap pix(":/image.jpg");
    qDebug() << "loading pixmap = " << (false == pix.isNull());
    qDebug() << "pixmap width/height: " << pix.width() << "x" << pix.height();

    QPixmap pixsmall(":/image-small.jpg");
    qDebug() << "loading pixmap = " << (false == pixsmall.isNull());
    qDebug() << "pixmap width/height: " << pixsmall.width() << "x" << pixsmall.height();

    app.exit();
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QTimer::singleShot(0, [&app]() { run_main(app); });
    app.exec();
    return 0;
}
