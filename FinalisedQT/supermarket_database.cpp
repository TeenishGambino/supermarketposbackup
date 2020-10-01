#include "supermarket_database.h"

#include <iostream>
#include <mysql/mysql.h>
#include <string>
#include <vector>
#include <sstream>
#include <QObject>
#include <QtDebug>
#include<string.h>
#include <stdio.h>
#include <QDebug>

using namespace std;

vector<string> toArray(string fields){
    bool flag = true;
    int arraySize = 1;
    vector<string> convertedArray(arraySize);
    int commaPosition;
    string rightStrip;

    if (fields.find(',') == string::npos){
        convertedArray[arraySize-1] = fields;
        return convertedArray;
    }

    while(flag){
        if(fields.find(',') == string::npos){
            flag = false;
        }
        commaPosition = fields.find(',');
        rightStrip = fields.substr(0, commaPosition);
        fields = fields.substr(commaPosition+1, fields.length()-commaPosition-1);
        convertedArray[arraySize-1] = rightStrip;
        if(flag != false){
            arraySize++;
            convertedArray.resize(arraySize);
        }
    }

    return convertedArray;
}

string jsonifier(vector<string> attribute, vector<vector<string>> data)
{
    stringstream json;
    json << "[";
    for(unsigned int i = 0; i< data.size(); i++){
        json << "{";
        for(unsigned int j =0; j< attribute.size(); j++) {
            json << "\"" << attribute[j] << "\"" << ":" << "\"" << data[i][j] << "\"";
            if(j==attribute.size()-1) {
                break;
            }
            json << ",";
        }
        json << "}";
        if(i==data.size()-1) {
            break;
        }
        json << ",";
    }
    json << "]";
    return json.str();
}


QString productDatabase::previoussearch()
{
    return previoustext;
}

void productDatabase::inputtext(QString text)
{
    previoustext = text;
}

QString productDatabase::outputdata()
{
    return "";
}

QString productDatabase::mostSoldItems()
{
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields, num_records;
    int i = 0, j = 0;
    string attri;
    stringstream query;
    query<<"SELECT S_NO,NAME,PRICE,NO_OF_ITEM_SOLD FROM product_info ORDER BY NO_OF_ITEM_SOLD DESC LIMIT 6";

    mysql_query(mysql, query.str().c_str());

    // result contains all the elements name for eg: ID, NAME
    result = mysql_store_result(mysql);

    // num_fields contains number of elements in a row of a table
    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    /* row contanis all the data from the table eg: "ishan", "98412315"
        it will fetch only one row at a time untill it finish the while loop goes on */
    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    string stringJson;
    stringJson = jsonifier(toArray("S_NO,NAME,PRICE,NO_OF_ITEM_SOLD"), retrieveArray);
    return QString::fromUtf8(stringJson.c_str());

}


productDatabase:: productDatabase() {
    tableName = "PRODUCT_INFO";
    elements = "S_NO,NAME,PRICE,DESCRIPTION,ITEM_TYPE,LOCATION";
    initalize();
}

void productDatabase:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

//Try make the = to LIKE//
QString productDatabase:: retrieveData(QString a) {

    previoustext = a;
    string attribute = a.toStdString();
    //string tester;
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields, num_records;
    int i = 0, j = 0;
    string attri;
    stringstream query;
    if (attribute == "") {
        query << "SELECT * FROM " << tableName << ";";
    } else {
        query << "SELECT * FROM " << tableName << " WHERE NAME LIKE \"%"<< attribute <<"%"<<"\""<<";";
        //tester = query.str();
       // qDebug()<<QString::fromStdString(tester);
    }

    mysql_query(mysql, query.str().c_str());

    // result contains all the elements name for eg: ID, NAME
    result = mysql_store_result(mysql);

    // num_fields contains number of elements in a row of a table
    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    /* row contanis all the data from the table eg: "ishan", "98412315"
        it will fetch only one row at a time untill it finish the while loop goes on */
    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    inputtext(a);
    stringJson = jsonifier(toArray(elements), retrieveArray);
    //return stringJson;
    return QString::fromStdString(stringJson);
}



request_suggest_complain_Database:: request_suggest_complain_Database() {
    tableNamesu = "suggestion";
    elementsu = "SUGGESTION";
    elementtype = "SUGGESTION_TYPE";
    tableName = "request_item";
    elements = "REQUEST_ITEM";
    initalize();
}
/*request_suggest_complain_Database:: request_suggest_complain_Database(QString type) {
    elements = tableName ;
    initalize();
}*/
void request_suggest_complain_Database:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

void request_suggest_complain_Database:: insertData(QString a) {
    stringstream query;
    string data = a.toStdString();
    query << "INSERT INTO " << tableName << "(" << elements << ") VALUES (\"" << data << "\");";
    mysql_query(mysql, query.str().c_str());
}

void request_suggest_complain_Database::insertDatasu(QString a, QString b)
{
    stringstream query;
    string data = a.toStdString();
    string type = b.toStdString();
    query << "INSERT INTO " << tableNamesu << "(" << elementsu <<"," <<elementtype<<") VALUES (\"" << data<<"\""   <<", "<<"\"" <<type<<"\");";
    string test = query.str();
    //qDebug()<<QString::fromStdString(test);
    mysql_query(mysql, query.str().c_str());
}

QString request_suggest_complain_Database::outputdata()
{
   QString qstr = QString::fromStdString(stringJson);
   return qstr;
}


Shift_data:: Shift_data() {
    tableName = "SHIFT_INFO";
    elements = "NAME,DATE,DAY,TIME";
    initalize();
}

void Shift_data:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}


string Shift_data:: retrieveData(string attribute) {
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields, num_records;
    int i = 0, j = 0;
    string attri;
    stringstream query;
    if (attribute == "") {
        query << "SELECT * FROM " << tableName << ";";
    } else {
        query << "SELECT * FROM " << tableName << " WHERE NAME = \"" << attribute <<"\";";
    }

    mysql_query(mysql, query.str().c_str());

    // result contains all the elements name for eg: ID, NAME
    result = mysql_store_result(mysql);

    // num_fields contains number of elements in a row of a table
    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    /* row contanis all the data from the table eg: "ishan", "98412315"
        it will fetch only one row at a time untill it finish the while loop goes on */
    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    string stringJson;
    stringJson = jsonifier(toArray(elements), retrieveArray);
    return stringJson;
}


void closedatabase()
{
    MYSQL* mysql;
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
    mysql_close(mysql);
}
