#pragma once

struct IP {
    string ip;
    int counter;
    long int key;
    IP(string ip);
    void createIPKey();
    bool operator < (IP bitacora);
    bool operator > (IP bitacora);
    bool operator == (IP bitacora);
    bool operator <= (IP bitacora);
    bool operator >= (IP bitacora);
    vector<string> change(const string& str, const string& delim);
};

IP :: IP (string ip) {
    this->ip = ip;
    this->counter = 0;
    createIPKey();
}

void IP :: createIPKey() {
    vector<string> num = change(ip, ".");
    int p = stoi(num[2]) * 1000;
    int s = stoi(num[3].substr(0,3));
    long int key = p + s;
    this->key = key;
}

vector<string>IP :: change (const string& str, const string& delim) {
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

// ostream& operator<< (ostream& salida, const IP& ipe) {
//     salida << ipe.ip << " " << ipe.counter << " " << ipe.key;
//     return salida;
// }

bool IP::operator < (IP bitacora) {
    return counter < bitacora.counter;
}

bool IP::operator > (IP bitacora) {
    return counter > bitacora.counter;
}

bool IP::operator <= (IP bitacora) {
    return counter <= bitacora.counter;
}

bool IP::operator >= (IP bitacora) {
    return counter >= bitacora.counter;
}

bool IP::operator == (IP bitacora) {
    return counter == bitacora.counter;
}

