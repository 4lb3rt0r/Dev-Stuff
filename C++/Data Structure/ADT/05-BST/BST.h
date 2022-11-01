#ifndef BST_h
#define BST_h

#include "Nodo.h"
#include "Queue.h"
#include "Stack.h"

template <class T>
class BST {
    private:
        Nodo<T>* root;
        void printTree(Nodo<T>* aux, int level);
        int countChildren (Nodo<T>* aux);
        void preOrder(Nodo<T>* aux);
        void inOrder(Nodo<T>* aux);
        void postOrder(Nodo<T>* aux);
        void lvlByLvl();
        int heightR(Nodo<T>* aux);
    public:
        BST();
        void add(T data);
        void print();
        bool isEmpty();
        bool find(T data);
        void visit (int order);
        void remove(T data);
        int height();
        void ancestors(T data);
        int whatLvl(T data);
};

template <class T>
BST<T> :: BST() {
    root = nullptr;
} 

template <class T>
void BST<T> :: visit (int order) {
    switch (order) {
    case 0:
        cout<<"PreOrder"<<endl;
        preOrder(root);
        cout<<endl;
        break;
    case 1:
        cout<<"InOrder"<<endl;
        inOrder(root);
        cout<<endl;
        break;
    case 2:
        cout<<"PostOrder"<<endl;
        postOrder(root);
        cout<<endl;
        break;
    case 3:
        cout<<"PreOrder"<<endl;
        preOrder(root);
        cout<<endl;
        break;
    case 4:
        cout<<"Level By Level"<<endl;
        lvlByLvl();
        cout<<endl;
        break;
    }
}

template <class T>
int BST <T> :: heightR(Nodo<T>* aux) {
    if (aux != nullptr) {
        int left = heightR(aux->left);
        int right = heightR(aux->right);
        return left >= right ? left + 1 : right + 1; 
    }
    else {
        return 0;
    }
}

template <class T>
int BST <T> :: height() {
    if (!isEmpty()) {
        return heightR(root);
    }
    else {
        return 0;
    }
}

template <class T>
void BST<T> :: preOrder (Nodo<T>* aux) {
    if (aux != nullptr) {
        cout<<aux->data<<" ";
    preOrder(aux->left);
    preOrder(aux->right);
    }
}

template <class T>
void BST<T> :: inOrder(Nodo<T>* aux) {
    if (aux != nullptr) {
    preOrder(aux->left);
    cout<<aux->data<<" ";
    preOrder(aux->right);
    }
}

template <class T>
void BST<T> :: postOrder(Nodo<T>* aux) {
    if (aux != nullptr) {
    preOrder(aux->left);
    preOrder(aux->right);
    cout<<aux->data<<" ";
    }
}

template<class T>
void BST<T>::add(T data) {
    //Validamos si el arbol está vacío
    if (isEmpty()) {
        // apuntamos root a un nodo nuevo
        root = new Nodo<T>(data);
    } else {
        // creamos un apuntador auxliar que apunte a root
        Nodo<T>* aux = root;
        // Recorrer el arbol hasta encontrar donde insertar el nodo nuevo
        while (aux != nullptr) {
            // comparamos el valor del dato nuevo con el valor del nodo auxiliar
            if (data < aux->data) {
                // Verificamos si el apuntador left es igual a nulo
                if (aux->left == nullptr) {
                    // agregamos el nodo nuevo en al apuntador left de aux
                    aux->left = new Nodo<T>(data);
                    // nos salimos del ciclo
                    aux = nullptr;
                } else {
                    // asignamos a aux a aux->left
                    aux = aux->left;
                }
            } else {
                // Verificamos si el apuntador right es igual a nulo
                if (aux->right == nullptr) {
                    // agregamos el nodo nuevo en al apuntador left de aux
                    aux->right = new Nodo<T>(data);
                    // nos salimos del ciclo
                    aux = nullptr;
                } else {
                    // asignamos a aux a aux->right
                    aux = aux->right;
                }
            }
        }
    }
}

template<class T>
bool BST<T>::find(T data) {
    // Creamos un nodo auxiliara que apunte a root
    Nodo<T>* aux = root;
    // Recorremos el arbol hasta encontrar el dato
    while (aux != nullptr) {
        // Validamos si el dato a buscar es igual al dato de auxiliar
        if (data == aux->data) {
            // regresamos true para decir que si lo encontramos
            return true;
        } else {
            // if (data < aux->data) {
            //     // Recorremos el auxiliar a la izquierda
            //     aux = aux->left;
            // } else {
            //     // Recorremos el auxiliar a la derecho
            //     aux = aux->right;
            // }
            // Vamos a hacerlos de otra forma más sencilla
            data < aux->data ? aux->left = aux->right : aux = aux->right;
        }
    }
    // No encontré el dato en el BST
    return false;
}

template <class T> 
int BST<T> :: countChildren (Nodo<T>* aux) {
    if (aux-> left == nullptr && aux->right == nullptr) {
        return 0; // 0 hijos
    }
    else {
        if (aux->left != nullptr && aux->right != nullptr) {
            return 2; // 2 hijos
        }
        else {
            return 1; //1 hijo
        }
    }
}

template<class T>
void BST<T>::ancestors(T data) {
    // Creamos un nodo auxiliara que apunte a root
    Nodo<T>* aux = root;
    //Creamos un stack de tipo 
    Stack<T> stack;
    //Creamos una variable booleana que indique si encontramos el datos dentro del árbol
    bool found = false;
    // Recorremos el arbol hasta encontrar el dato
    while (aux != nullptr && !found) {
        // Validamos si el dato a buscar es igual al dato de auxiliar
        if (data == aux->data) {
            // regresamos true para decir que si lo encontramos
            found = true;
        } else {
            //Agregamos el dato a nuestro stack
            stack.push(aux->data);
            //Recorremos aux al lado correspondiente
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    if (found) {
        while (!stack.isEmpty()) {
            cout<<stack.pop()<<" ";
        }
        cout<<endl;
    }
}

template <class T>
int BST <T> :: whatLvl(T data) {
    // Creamos un nodo auxiliara que apunte a root
    Nodo<T>* aux = root;
    //Creamos un contador entero de levels
    int levels = 0;
    //Creamos una variable booleana que indique si encontramos el dato dentro del árbol
    bool found = false;
    // Recorremos el arbol hasta encontrar el dato
    while (aux != nullptr && !found) {
        // Validamos si el dato a buscar es igual al dato de auxiliar
        if (data == aux->data) {
            // regresamos true para decir que si lo encontramos
            found = true;
        } else {
            //Incrementamos el nivel
            levels++;
            //Recorremos aux al lado correspondiente
            data < aux->data ? aux = aux->left : aux = aux->right;
        }
    }
    if (found) {
        return levels + 1;
    }
    else {
        return -1;
    }
}

template <class T>
void BST<T> :: remove (T data) {
    //Creamos nodo auxiliar que apunta a root
    Nodo<T>* auxPointer = root;
    //validamos si el dato a eliminar es root
    if (data == auxPointer->data) {
        //Verificamos si root posee hijos de cualquier lado
        switch(countChildren(auxPointer)) {
        case 0: 
            //root apunta a nulo
            root = nullptr;
            //borramos el apuntador auxiliar
            delete auxPointer;
            break;
        case 1:
            //apuntamos root al hijo correspondiente
            auxPointer->left != nullptr ? root = auxPointer->left : auxPointer->right;
            //borramos el apuntador auxiliar
            delete auxPointer;
            break;
                
        case 2:
            //Creamos un apuntador auxiliar auxPointer2 que apunte a el hijo del lado izquierdo de auxPointer
            Nodo<T>* auxPointer2 = auxPointer->left;
            //Validamos si el lado derecho del hijo del lado izquierdo es == nullptr
            if (auxPointer2->right == nullptr) {
                //auxPointer2 es el hijo más grande del lado izquierdo
                //Cambiamos el valor de auxPointer a auxPointer2
                auxPointer->data = auxPointer2->data;
                //Apuntamos auxPointer->left a auxPointer2->left sin importar que no tenga hijos
                auxPointer->left = auxPointer2->left;
                delete auxPointer2;
            }
            else {
                //Buscamos el hijo mayor del lado izquierdo
                //creamos un apuntador auxiliar a auxPointer2
                Nodo<T>* father = auxPointer2;
                //recorremos auxPointer2
                auxPointer2 = auxPointer2->right;
                while (auxPointer2->right != nullptr) {
                    //Recorremos los apuntadores 
                    father = auxPointer2;
                    auxPointer2 = auxPointer2->right;
                }
                //Cambiamos el valor de auxPointer por el de auxPointer2
                auxPointer->data = auxPointer2->data;
                //Hacemos que el apuntador del lado derecho del nodo padre apunte al lado izquierdo de auxPointer2
                father->right = auxPointer2->left;
                //borramos auxPointer2
                delete auxPointer2;
            }
            break;
        }
            
    }
    else {
        //Buscar el nodo a remover
        //Crear un apuntador auxiliar que apunte al padre de aux
        Nodo<T>* father = auxPointer;
        //Recorremos auxPointer
        data < auxPointer->data ? auxPointer = auxPointer->left : auxPointer = auxPointer->right;
        //Recorremos el árbol hata encontrar el nodo que coincide con data
        while (auxPointer != nullptr) {
            //Validamos si el dato a borrar es aux->data
            if (data == auxPointer->data) {
                //Borramos aux
                switch(countChildren(auxPointer)) {
                case 0: 
                    data < father->data ? father->left = nullptr : father->right = nullptr;
                    //borramos auxPointer
                    delete auxPointer;
                    break;
                        
                case 1: 
                    //apuntamos al lado correspondiente de auxPointer al hijo
                    if (auxPointer->left != nullptr) {
                        data < father->data ? father->left = auxPointer->left : father->right = auxPointer->left;
                    }
                    else {
                        data < father->data ? father->left = auxPointer->right : father->right = auxPointer->right;
                    }
                    //borramos auxPointer
                    delete auxPointer;
                    break;

                case 2:
                    //Creamos un apuntador auxiliar auxPointer2 que apunte a el hijo del lado izquierdo de auxPointer
                    Nodo<T>* auxPointer2 = auxPointer->left;
                    //Validamos si el lado derecho del hijo del lado izquierdo es == nullptr
                    if (auxPointer2->right == nullptr) {
                        //auxPointer2 es el hijo más grande del lado izquierdo
                        //Cambiamos el valor de auxPointer a auxPointer2
                        auxPointer->data = auxPointer2->data;
                        //Apuntamos auxPointer->left a auxPointer2->left sin importar que no tenga hijos
                        auxPointer->left = auxPointer2->left;
                        delete auxPointer2;
                    }
                    else {
                        //Buscamos el hijo mayor del lado izquierdo
                        //creamos un apuntador auxiliar a auxPointer2
                        Nodo<T>* father = auxPointer2;
                        //recorremos auxPointer2
                        auxPointer2 = auxPointer2->right;
                        while (auxPointer2->right != nullptr) {
                            //Recorremos los apuntadores 
                            father = auxPointer2;
                            auxPointer2 = auxPointer2->right;
                        }
                        //Cambiamos el valor de auxPointer por el de auxPointer2
                        auxPointer->data = auxPointer2->data;
                        //Hacemos que el apuntador del lado derecho del nodo padre apunte al lado izquierdo de auxPointer2
                        father->right = auxPointer2->left;
                        //borramos auxPointer2
                        delete auxPointer2;
                    }
                    break;
                }
                auxPointer = nullptr; 
            }

            else {
                //recorremos los apuntadores
                father = auxPointer;
                data < auxPointer->data ? auxPointer = auxPointer->left : auxPointer = auxPointer->right;
            }
        }
    }
}

template <class T>
void BST<T> :: lvlByLvl() {
    if (!isEmpty()) {
        Queue<Nodo<T>*> queue;
        //Colocamos el root a la fila 
        queue.push(root);
        //recorremos la fila hasta que se vacíe, pasando por todos los hijos posibles
        while (!queue.isEmpty()) {
            //Sacamos el primer elemento de la fila y lo Imprimimos
            Nodo<T>* aux = queue.pop();
            cout<<aux->data<<" ";
            if (aux->left != nullptr) {
                queue.push(aux->left);
            }
            if (aux->right != nullptr) {
                queue.push(aux->right);
            }
        }
    }
}

template<class T>
void BST<T>::printTree(Nodo<T>* aux, int level) {
    if (aux != NULL) {
        printTree(aux->right,level+1);
        for (int i=0;i<level;i++) {
            cout<< "  ";
        }
        cout<<aux->data<<endl;
        printTree(aux->left,level+1);
    }
}

template <class T>
void BST<T> :: print() {
    if (!isEmpty()) {
        int level = 0;
        cout<<endl;
        printTree(root,level);
        cout<<endl;
    }
    else {
        cout<<endl<<"El árbol se encuentra vacío :o"<<endl<<endl;
    }
}

template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

#endif