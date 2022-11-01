#include <iostream>
#include <string>

using namespace std;

#pragma once

struct Bitacora {
    string month;
    int day;
    string time;
    int key;
    string ip;
    string message;
    Bitacora();
    Bitacora(string month, int day, string time, string ip, string message);
    long int createIPKey();
    vector<string> change(const string& str, const string& delim);
    bool operator < (Bitacora bitacora);
    bool operator > (Bitacora bitacora);
    bool operator == (Bitacora bitacora);
    bool operator <= (Bitacora bitacora);
    bool operator >= (Bitacora bitacora);
};

Bitacora :: Bitacora() {
    month = "";
    day = 0;
    time = "";
    ip = "";
    message = "";
    key = 0;
}

Bitacora :: Bitacora(string month, int day, string time, string ip, string message) {
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    this->key = createIPKey();
}

vector<string> Bitacora::change(const string& str, const string& delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}


long int Bitacora :: createIPKey() {
    vector<string> n = change(ip, ".");
    long int s = stoi(n[3].substr(0,3));
    long int p = stoi(n[2]) * 1000;
    long int key = p + s;

    return key;
}

bool Bitacora::operator < (Bitacora bitacora) {
    return key < bitacora.key;
}

bool Bitacora::operator > (Bitacora bitacora) {
    return key > bitacora.key;
}

bool Bitacora::operator <= (Bitacora bitacora) {
    return key <= bitacora.key;
}

bool Bitacora::operator >= (Bitacora bitacora) {
    return key >= bitacora.key;
}

bool Bitacora::operator == (Bitacora bitacora) {
    return key == bitacora.key;
}