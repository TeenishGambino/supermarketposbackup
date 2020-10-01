#include "supermarket_database.h"

vector<string> toArray(string fields){
    bool flag = true;
    int arraySize = 1;
    int pos;
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
        pos = fields.find(',');
        rightStrip = fields.substr(0, pos);
        fields = fields.substr(pos+1, fields.length()-pos-1);
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


customerDatabase:: customerDatabase() {
    tableName = "CUSTOMER_INFO";
    elements = "NAME, CONTACT_NUMBER, ADDRESS"; 
    elementsIncludingId = "ID,NAME, CONTACT_NUMBER, ADDRESS";
    initalize();
}

void customerDatabase:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

void customerDatabase:: insertData(string data) {
    stringstream query;
    query << "INSERT INTO " << tableName << "(" << elements << ") VALUES (" << data << ");";
    mysql_query(mysql, query.str().c_str());
}

/*NOTE: 'field' is the table header name (eg ID,NAME), element is the table (eg "mulu") */
void customerDatabase:: updateData(string field, string element, string field2, string data) {
    stringstream query;
    query << "UPDATE " << tableName << " SET " << field <<" = \"" << element << "\" WHERE " << field2 << " = \"" << data << "\";"; 
    mysql_query(mysql, query.str().c_str());
}

void customerDatabase:: deleteData(string name) {
    stringstream query;
    query << "DELETE FROM " << tableName << " WHERE NAME" << " = \"" << name << "\";"; 
    cout << query.str().c_str();
    mysql_query(mysql, query.str().c_str());
}

string customerDatabase:: getData(string attribute) {
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

    result = mysql_store_result(mysql);

    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    string stringJson;
    stringJson = jsonifier(toArray(elementsIncludingId), retrieveArray);
    return stringJson;
}

//base database

employeeDatabase:: employeeDatabase() {
    tableName = "EMPLOYEE_INFO";
    elements = "NAME,EMAIL,PASSWORD,GENDER,CONTACT_NUMBER,ADDRESS,DATE_OF_BIRTH,WORKING_SINCE";
    elementsIncludingId = "ID,NAME,EMAIL,PASSWORD,GENDER,CONTACT_NUMBER,ADDRESS,DATE_OF_BIRTH,WORKING_SINCE";
    initalize();
}

void employeeDatabase:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

void employeeDatabase:: insertData(string data) {
    stringstream query;
    query << "INSERT INTO " << tableName << "(" << elements << ") VALUES (" << data << ");";
    mysql_query(mysql, query.str().c_str());
}

/*NOTE: 'field' is the table header name (eg ID,NAME), element is the table (eg "mulu") */
void employeeDatabase:: updateData(string field, string element, string field2, string data) {
    stringstream query;
    query << "UPDATE " << tableName << " SET " << field <<" = \"" << element << "\" WHERE " << field2 << " = \"" << data << "\";"; 
    mysql_query(mysql, query.str().c_str());
}

void employeeDatabase:: deleteData(string name) {
    stringstream query;
    query << "DELETE FROM " << tableName << " WHERE NAME" << " = " << name << ";"; 
    mysql_query(mysql, query.str().c_str());
}

string employeeDatabase:: getData(string attribute) {
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

    result = mysql_store_result(mysql);

    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    string stringJson;
    stringJson = jsonifier(toArray(elementsIncludingId), retrieveArray);
    return stringJson;
}





ownerDatabase:: ownerDatabase() {
    tableName = "OWNER_INFO";
    elements = "NAME,EMAIL,PASSWORD,GENDER,CONTACT_NUMBER,DATE_OF_BIRTH,ADDRESS";
    elementsIncludingId = "ID,NAME,EMAIL,PASSWORD,GENDER,CONTACT_NUMBER,DATE_OF_BIRTH,ADDRESS";
    initalize();
}

void ownerDatabase:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

void ownerDatabase:: insertData(string data) {
    stringstream query;
    query << "INSERT INTO " << tableName << "(" << elements << ") VALUES (" << data << ");";
    mysql_query(mysql, query.str().c_str());
}

void ownerDatabase:: updateData(string field, string element, string field2, string data) {
    stringstream query;
    query << "UPDATE " << tableName << " SET " << field <<" = \"" << element << "\" WHERE " << field2 << " = \"" << data << "\";"; 
    mysql_query(mysql, query.str().c_str());
}

void ownerDatabase:: deleteData(string name) {
    stringstream query;
    query << "DELETE FROM " << tableName << " WHERE NAME" << " = " << name << ";"; 
    mysql_query(mysql, query.str().c_str());
}

string ownerDatabase:: getData(string attribute) {
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

    result = mysql_store_result(mysql);

    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    string stringJson;
    stringJson = jsonifier(toArray(elementsIncludingId), retrieveArray);
    return stringJson;
}




productDatabase:: productDatabase() {
    tableName = "PRODUCT_INFO";
    elements = "NAME,PRICE,MANUFACTURE_DATE,EXPIRY_DATE,ITEM_TYPE,LOCATION";
    elementsIncludingId = "ID,NAME,PRICE,MANUFACTURE_DATE,EXPIRY_DATE,ITEM_TYPE,LOCATION";
    initalize();
}

void productDatabase:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

void productDatabase:: insertData(string data) {
    stringstream query;
    query << "INSERT INTO " << tableName << "(" << elements << ") VALUES (" << data << ");";
    mysql_query(mysql, query.str().c_str());
}

void productDatabase:: updateData(string field, string element, string field2, string data) {
    stringstream query;
    query << "UPDATE " << tableName << " SET " << field <<" = \"" << element << "\" WHERE " << field2 << " = \"" << data << "\";"; 
    mysql_query(mysql, query.str().c_str());
}

void productDatabase:: deleteData(string name) {
    stringstream query;
    query << "DELETE FROM " << tableName << " WHERE NAME" << " = " << name << ";"; 
    mysql_query(mysql, query.str().c_str());
}

string productDatabase:: getData(string attribute) {
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

    result = mysql_store_result(mysql);

    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    string stringJson;
    stringJson = jsonifier(toArray(elementsIncludingId), retrieveArray);
    return stringJson;
}



request_suggest_complain_Database:: request_suggest_complain_Database() {}
request_suggest_complain_Database:: request_suggest_complain_Database(string type) {
    elements = tableName = type;
    initalize();
}
void request_suggest_complain_Database:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

void request_suggest_complain_Database:: insertData(string data) {
    stringstream query;
    query << "INSERT INTO " << tableName << "(" << elements << ") VALUES (" << data << ");";
    mysql_query(mysql, query.str().c_str());
}

void request_suggest_complain_Database:: updateData(string field, string element, string field2, string data) {
    stringstream query;
    query << "UPDATE " << tableName << " SET " << field <<" = \"" << element << "\" WHERE " << field2 << " = \"" << data << "\";"; 
    mysql_query(mysql, query.str().c_str());
}

void request_suggest_complain_Database:: deleteData(string name) {
    stringstream query;
    query << "DELETE FROM " << tableName << " WHERE NAME" << " = " << name << ";"; 
    mysql_query(mysql, query.str().c_str());
}

string request_suggest_complain_Database:: getData(string attribute) {
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

    result = mysql_store_result(mysql);

    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

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


Shift_data:: Shift_data() {
    tableName = "SHIFT_INFO";
    elements = "NAME,DATE,DAY,TIME";
    elementsIncludingId = "ID,NAME,DATE,DAY,TIME";
    initalize();
}

void Shift_data:: initalize() {
    mysql = mysql_init(0);
    mysql = mysql_real_connect(mysql, SERVER, UNAME, PWORD, DBNAME, PORT, NULL, 0);
}

void Shift_data:: insertData(string data) {
    stringstream query;
    query << "INSERT INTO " << tableName << "(" << elements << ") VALUES (" << data << ");";
    mysql_query(mysql, query.str().c_str());
}

void Shift_data:: updateData(string field, string element, string field2, string data) {
    stringstream query;
    query << "UPDATE " << tableName << " SET " << field <<" = \"" << element << "\" WHERE " << field2 << " = \"" << data << "\";"; 
    mysql_query(mysql, query.str().c_str());
}

void Shift_data:: deleteData(string name) {
    stringstream query;
    query << "DELETE FROM " << tableName << " WHERE NAME" << " = " << name << ";"; 
    mysql_query(mysql, query.str().c_str());
}

string Shift_data:: getData(string attribute) {
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

    result = mysql_store_result(mysql);

    num_fields = mysql_num_fields(result);
    num_records = mysql_num_rows(result);

    vector<vector<string>> retrieveArray(num_records, vector<string> (num_fields));

    while ((row = mysql_fetch_row(result)))
        {
            for(i = 0; i < num_fields; i++){
                retrieveArray[j][i] = row[i];
            }
            j++;
        }
    string stringJson;
    stringJson = jsonifier(toArray(elementsIncludingId), retrieveArray);
    return stringJson;
}



