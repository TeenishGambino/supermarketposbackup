#ifndef SUPERMARKET_DATABASE
#define SUPERMARKET_DATABASE

#include <iostream>
#include <mysql/mysql.h>
#include <string>
#include <vector>
#include <sstream>
#include <QObject>
#include <QtDebug>

#define SERVER "127.0.0.1"
#define UNAME "root"
#define PWORD "password"
#define DBNAME "SUPERMARKET_DB"
#define PORT 3306


using namespace std;
void closedatabase();

class productDatabase: public QObject{
    Q_OBJECT
private:
    string elements, tableName, stringJson;
    QString previoustext;
    MYSQL* mysql;
public:
    Q_INVOKABLE productDatabase();
    Q_INVOKABLE void initalize();
    Q_INVOKABLE QString retrieveData(QString);
    Q_INVOKABLE QString previoussearch();
    Q_INVOKABLE void inputtext(QString text);
    Q_INVOKABLE QString outputdata();
    Q_INVOKABLE QString mostSoldItems();

    ~productDatabase(){
        mysql_close(mysql);
    }
};

class request_suggest_complain_Database: public QObject{
    Q_OBJECT
private:
    string elements, tableName, stringJson, elementsu, elementtype, tableNamesu; // elementsu and tableNamesu is for the suggestion table
    MYSQL* mysql;
public:
    Q_INVOKABLE request_suggest_complain_Database();
    //Q_INVOKABLE request_suggest_complain_Database(QString);
    Q_INVOKABLE void initalize();
    Q_INVOKABLE void insertData(QString);
    Q_INVOKABLE void insertDatasu(QString, QString);
    Q_INVOKABLE QString outputdata();
    ~request_suggest_complain_Database(){
        mysql_close(mysql);
    }
};

class Shift_data: public QObject{
    Q_OBJECT
private:
    string elements, tableName;
    MYSQL* mysql;
public:
    Q_INVOKABLE Shift_data();
    Q_INVOKABLE void initalize();
    Q_INVOKABLE string retrieveData(string);
    ~Shift_data(){
        mysql_close(mysql);
    }
};

vector<string> toArray(string);
string jsonifier(vector<string>, vector<vector<string>>);
#endif
