#ifndef HASHENTRY_H
#define HASHENTRY_H
using namespace std;


template<class T>
class NodoArbol {
private:
    NodoArbol *izq, *der;
    T dato;

public:
    NodoArbol(T dato);

    void put(T);

    void put(NodoArbol *);

    T search(T);

    T getDato() const;

    void setDato(T dato);

    NodoArbol *remover(T);

    void preorder();

    void inorder();

    void postorder();

    int contarPorNivel(unsigned int);

    void espejo();

    bool compara(NodoArbol *);

    void print(bool esDerecho, std::string identacion) {
        if (der != NULL) {
            der->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        std::cout << identacion;
        if (esDerecho) {
            std::cout << " /";
        } else {
            std::cout << " \\";
        }
        std::cout << "-- ";
        std::cout << dato << std::endl;
        if (izq != NULL) {
            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }
};

template<class T>
NodoArbol<T>::NodoArbol(T dato) : dato(dato), izq(NULL), der(NULL) {};

template<class T>
void NodoArbol<T>::put(T d) {
    if (d == dato)     // arbol no permite duplicados   ***Aca hay que hacer algo, para el 2do parcial***
        throw 1;
    if (d < dato) { // va pa la izq
        if (izq == NULL)
            izq = new NodoArbol(d);
        else
            izq->put(d);
    } else {   //va a la derecha
        if (der == NULL)
            der = new NodoArbol(d);
        else
            der->put(d);
    }
}

template<class T>
void NodoArbol<T>::put(NodoArbol *nodo) {
    if (nodo == NULL)
        return;
    if (nodo->getDato() == dato)
        throw 1;
    if (nodo->getDato() < dato) { // va pa la izq
        if (izq == NULL)
            izq = nodo;
        else
            izq->put(nodo);
    } else {   //va a la derecha
        if (der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }
}

template<class T>
T NodoArbol<T>::search(T d) {
    if (d == dato)
        return dato;

    if (d < dato) {
        if (izq == NULL)
            throw 3;
        else
            return izq->search(d);
    } else {
        if (der == NULL)
            throw 3;
        else
            return der->search(d);
    }
}

template<class T>
NodoArbol<T> *NodoArbol<T>::remover(T d) {
    NodoArbol<T> *aux;
    if (d == dato) {
        if (der != NULL) {
            der->put(izq);
            return der;     //por criterio tomado anteriormente
        }
        return izq;
    }
    if (d < dato) {
        if (izq == NULL) {
            throw 3;
        } else {
            aux = izq;
            izq = izq->remover(d);
            if (izq != aux)
                delete aux;
        }
    } else {
        if (der == NULL)
            throw 3;
        else {
            aux = der;
            der = der->remover(d);
            if (der != aux)
                delete aux;
        }
    }
    return this; // todos se devuelven a si mismos, gralmente
}

template<class T>
T NodoArbol<T>::getDato() const {
    return dato;
}

template<class T>
void NodoArbol<T>::setDato(T dato) {
    NodoArbol<T>::dato = dato;
}

using std::cout;

template<class T>
void NodoArbol<T>::preorder() {
    cout << dato << ", ";
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

template<class T>
void NodoArbol<T>::inorder() {
    if (izq != NULL) izq->inorder();
    cout << dato << ", ";
    if (der != NULL) der->inorder();
}

template<class T>
void NodoArbol<T>::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    cout << dato << ", ";
}

template<class T>
int NodoArbol<T>::contarPorNivel(unsigned int L) {      // y si l es mayor?
    if (L == 0)
        return 1;
    int c = 0;
    if (izq != NULL) {
        c += izq->contarPorNivel(L - 1);
    }
    if (der != NULL) {
        c += der->contarPorNivel(L - 1);
    }
    return c;
}

template<class T>
void NodoArbol<T>::espejo() {
    NodoArbol *aux = izq;
    izq = der;
    der = aux;
    if (izq != NULL)
        izq->espejo();
    if (der != NULL)
        der->espejo();
}

template<class T>
bool NodoArbol<T>::compara(NodoArbol *a) {
    if (this->dato != a->getDato())
        return false;
    if (izq == NULL ^ a->izq == NULL) // xor operator
        return false;
    if (der == NULL ^ a->der == NULL)
        return false;

    bool estIzq = true, estDer = true;

    if (izq != NULL)
        estIzq = izq->compara(a->izq);
    if (der != NULL)
        estDer = der->compara(a->der);

    return estIzq == estDer;
}

//visualalgo & xckd


#endif //HASHENTRY_H