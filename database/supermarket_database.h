#ifndef SUPERMARKET_DATABASE
#define SUPERMARKET_DATABASE

#include <iostream>
#include <mysql/mysql.h>
#include <string>
#include <vector>
#include <sstream>

#define SERVER "127.0.0.1"
#define UNAME "root"
#define PWORD "password"
#define DBNAME "SUPERMARKET_DB"
#define PORT 3306

using namespace std;
vector<string> toArray(string);
string jsonifier(vector<string>, vector<vector<string>>);

class customerDatabase{
    private:
    string elements, tableName, data, elementsIncludingId;
    MYSQL* mysql;
    public:
    string askForData();
    customerDatabase();
    void initalize();
    void insertData(string);
    void updateData(string, string, string, string);
    void deleteData(string);
    string getData(string);
};

class employeeDatabase{
    private:
    string elements, tableName, elementsIncludingId;
    MYSQL* mysql;
    public:
    employeeDatabase();
    void initalize();
    void insertData(string);
    void updateData(string, string, string, string);
    void deleteData(string);
    string getData(string);
};

class ownerDatabase{
    private:
    string elements, tableName, elementsIncludingId;
    MYSQL* mysql;
    public:
    ownerDatabase();
    void initalize();
    void insertData(string);
    void updateData(string, string, string, string);
    void deleteData(string);
    string getData(string);
};

class productDatabase{
    private:
    string elements, tableName, elementsIncludingId;
    MYSQL* mysql;
    public:
    productDatabase();
    void initalize();
    void insertData(string);
    void updateData(string, string, string, string);
    void deleteData(string);
    string getData(string);
};

class request_suggest_complain_Database{
    private:
    string elements, tableName, elementsIncludingId;
    MYSQL* mysql;
    public:
    request_suggest_complain_Database();
    request_suggest_complain_Database(string);
    void initalize();
    void insertData(string);
    void updateData(string, string, string, string);
    void deleteData(string);
    string getData(string);
};

class Shift_data{
    private:
    string elements, tableName, elementsIncludingId;
    MYSQL* mysql;
    public:
    Shift_data();
    void initalize();
    void insertData(string);
    void updateData(string, string, string, string);
    void deleteData(string);
    string getData(string);
};

#endif