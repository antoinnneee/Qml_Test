#include "imap.h"
#include "define.h"
#include <QApplication>
#include "pov_container.h"
#include <QtQml>

# ifdef PLATFORM_AND
#  define ANDROID 1
# else
#    define ANDROID 0
# endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(text);

    Pov_Container p;
    if (ANDROID)
        p.showFullScreen();
    else
        p.show();

    return a.exec();
}
