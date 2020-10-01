#include "dandt.h"
#include <ctime>
#include <windows.h>
#include <sstream>
#include <iostream>


dandt::dandt(QObject *parent) : QObject(parent)
{
    std::stringstream str, strr;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    str<<1900+ltm->tm_year<<"-"<<1+ltm->tm_mon<<"-"<<ltm->tm_mday;
    TDate = QString::fromUtf8(str.str().c_str());

    strr<<1+ltm->tm_hour<<":"<<1+ltm->tm_min<<":"<<1+ltm->tm_sec;
    TTime = QString::fromUtf8(strr.str().c_str());
}

