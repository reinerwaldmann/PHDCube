#ifndef CONSOLEMSG_H
#define CONSOLEMSG_H



#include <QtGui>

static void myMessageOutput(bool debug, QtMsgType type, const QString & msg) {

    if (!debug) return;

    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateString = dateTime.toString("yyyy.MM.dd hh:mm:ss:zzz");
/*
    switch (type) {

        case QtDebugMsg:
            fprintf(stderr, "%s\n", msg.toAscii().data());
            break;
        case QtWarningMsg:
            fprintf(stderr, "Warning: %s\n", msg.toAscii().data());
            break;
        case QtCriticalMsg:
            fprintf(stderr, "Critical: %s\n", msg.toAscii().data());
            break;
        case QtFatalMsg:
            fprintf(stderr, "Fatal: %s\n", msg.toAscii().data());
            abort();
    }
*/

}

#endif // CONSOLEMSG_H
