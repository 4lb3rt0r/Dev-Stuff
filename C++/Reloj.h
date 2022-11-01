#pragma once

struct Reloj {
    int horas;
    int minutos;
    int segundos;
    Reloj ();
    Reloj (int horas, int minutos, int segundos);
    void clock();
    void print();
};

Reloj :: Reloj () {
    this->horas = 0;
    this->minutos = 0;
    this->segundos = 0;
}

Reloj :: Reloj (int horas, int minutos, int segundos) {
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
}

void Reloj :: clock() {
    while (horas < 24) {
        segundos++;
        if (segundos == 60) {
            segundos = 0;
            minutos++;
        }
        if (minutos == 60) {
            minutos = 0;
            horas++;
        }
        if (horas == 24) {
            horas = 0;
            minutos = 0;
            segundos = 0;
        }
        print();
        Sleep(1000);
        system("cls");
    }
}

void Reloj :: print() {
    if (horas < 10 && minutos < 10 && segundos < 10) {
        cout << "Hora: " << "0" << horas << ":" << "0" << minutos << ":" << "0" << segundos << endl;
    }
    else if (horas < 10 && minutos < 10 && segundos >= 10) {
        cout << "Hora: " << "0" << horas << ":" << "0" << minutos << ":" << segundos << endl;
    }
    else if (horas < 10 && minutos >= 10 && segundos >= 10) {
        cout << "Hora: " << "0" << horas << ":" << minutos << ":" << segundos << endl;
    }
    else if (horas >= 10 && minutos < 10 && segundos < 10) {
        cout << "Hora: " << horas << ":" << "0" << minutos << ":" << "0" << segundos << endl;
    }
    else if (horas >=10 && minutos < 10 && segundos >= 10) {
        cout << "Hora: " << horas << ":" << "0" << minutos << ":" << segundos << endl;
    }
    else if (horas >= 10 && minutos >= 10 && segundos < 10) {
        cout << "Hora: " << horas << ":" << minutos << ":" << "0" << segundos << endl;
    }
    else if (horas < 10 && minutos >= 10 && segundos < 10) {
        cout << "Hora: "<< "0" << horas << ":" << minutos << ":" << "0" << segundos << endl;
    }
    else {
        cout << "Hora: " << horas << ":" << minutos << ":" << segundos << endl;
    }
}