#include "imap.h"
#include "define.h"
#include <QApplication>

# ifdef PLATFORM_AND
#  define ANDROID 1
# else
#    define ANDROID 0
# endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMap w;
    if (ANDROID)
        w.showFullScreen();
    else
        w.show();

    return a.exec();
}
