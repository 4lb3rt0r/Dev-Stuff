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
    long int createKey();
    bool operator < (Bitacora bitacora);
    bool operator > (Bitacora bitacora);
    bool operator == (Bitacora bitacora);
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
    this->key = createKey();
}


long int Bitacora :: createKey() {
    //Inicializamos variable de lso meses convertidos a segundos
    long int mSeg;
     //Conversión de unidad meses a segundos
    if (this-> month == "Jun") {
        mSeg = 6 * 2592000;;
    }
    else if (this-> month == "Jul") {
        mSeg = 7 * 2592000;;
    }
    else if (this-> month == "Aug") {
        mSeg = 8 * 2592000;;
    }
    else if (this-> month == "Sep") {
        mSeg = 9 * 2592000;;
    }
    else {
        mSeg = 10 * 2592000;;
    }

    //Formato Horas:Minutos:Segundos
    string HH = this->time.substr(0,2);
    string MM = this->time.substr(3,2);
    string SS = this->time.substr(6,2);

    //Conversión Horas a Segundos
    int HHI = stoi(HH) * 3600;

    //Conversión Minutos a Segundos
    int MMI = stoi(MM) * 60;
    //Solo segundos
    int SSI = stoi(SS);

    //Conversión Dias a Segundos
    long int dSeg = this->day * 86400;
    //Sumatoria de Todos los Tiempos Convertidos a Segundos
    long int key = mSeg + dSeg + HHI + MMI + SSI;

    return key;
}

bool Bitacora::operator <(Bitacora bitacora) {
    return key < bitacora.key;
}

bool Bitacora::operator >(Bitacora bitacora) {
    return key > bitacora.key;
}

bool Bitacora::operator ==(Bitacora bitacora) {
    return key == bitacora.key;
}