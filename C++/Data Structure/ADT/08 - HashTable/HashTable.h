#ifndef HashTable_h
#define HashTable_h

//HashTable para matrículas
class HashTable {
    private:
        vector<string> table; 
        vector<char> status; //v: vacía, o: ocupada, b: borrada
        int size;
        int hashing(string data);
        int occupied;
    public:
        HashTable();
        HashTable(vector<string> list);
        int find(string data);
        void add(string data);
        bool remove(string data);
        void print();
};

HashTable :: HashTable() {
    size = 110;
    table = vector<string>(110, "");
    status = vector<char>(110, 'v');
    occupied = 0;
}

HashTable :: HashTable(vector<string> list) {
    table = vector<string>(110, "");
    status = vector<char>(110, 'v');
    occupied = 0;
    size = 100;
    for (auto data : list) {
        add(data);
    }
}

//Función hashinf con método cuadrático
int HashTable :: hashing(string data) {
    long long int numMat = stoi(data.substr(1,8));
    long long int quadMat = numMat * numMat;
    int d10, d11, d10d11;
    //12345678, d2 = 2, si elevas al cuadrado se vuelbven 16 digitos
    d10 = quadMat / 100000000 % 10;
    d11 = quadMat / 10000000 % 10;
    d10d11 = d10 * 10 + d11;
    return d10d11;
}

//Busca un elemento en la HashTable
int HashTable :: find(string data) {
    //Obtenemos un índice que regresa la función hashing
    int index = hashing(data);
    //Buscar el elemento en la tabla hasta encontrarlo o encontrar una casilla vacía
    bool found = false;
    int auxIndex = index;
    int colisiones = 1;
    while (status[auxIndex] != 'v' && !found && colisiones <= size) {
        //Validamos si en la posición auxIndex se encuentra el dato buscado
        if (table[auxIndex] == data && status[auxIndex] == 'o') {
            found = true;
        }
        else {
            //Actualizamos el índice proporcionado por la función hashing() al siguiente índice
            auxIndex = (index + colisiones * colisiones) % size;
            colisiones++;
        }
    }
    //Validamos si el elemento buscado es igual al elemento que 
    //se encuentre dentro de la posición arrojada por la función find()
    if (found) {
        return auxIndex;
    } else {
        return -1;
    }
}

void HashTable :: add(string data) {
    //Obtener el índice de la funcion hashing
    //cout << occupied << endl;
    if (occupied != size) {
        int index = hashing(data);
        int auxIndex = index;
        int colisiones = 1;
        //Buscamos hasta encontrar una casilla vacía o borrada
        while (status[auxIndex] == 'o' && colisiones <= size) {
            //Actualizamos el índice a la siguiente posicion
            auxIndex = (index + colisiones * colisiones) % size;
            colisiones++;
        }
        if (colisiones <= size) {
            table[auxIndex] = data;
            status[auxIndex] = 'o';
            occupied++;
        }
        else {
            throw out_of_range("No se puede insertar el dato");
        }
    }
    else {
            throw out_of_range("No se puede insertar el dato");
        }
}

void HashTable :: print() {
    for (auto data : table) {
        cout<<data<<endl;
    }
}


#endif