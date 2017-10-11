#ifndef HASHENTRY_H
#define HASHENTRY_H

template<class T>
class NodoArbol {
private:
    NodoArbol *izq, *der;
    T dato;
public:
    T getDato() const;

    void setDato(T dato);

    void put(T d);

    void put(NodoArbol *nodo);

    T search(T d);

    NodoArbol* remover(T d);

//    void print(bool esDerecho, string identacion) {
//        if (der != NULL) {
//            der->print(true, identacion + (esDerecho ? "     " : "|    "));
//        }
//        cout << identacion;
//        if (esDerecho) {
//            cout << " /";
//        } else {
//            cout << " \\";
//        }
//        cout << "-- ";
//        cout << dato << endl;
//        if (izq != NULL) {
//            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
//        }
//    }
};

template<class T>
void NodoArbol::put(T d){
    if(d == dato)
        throw 1;
    if(d<dato){ //va a la izq
        if(izq == NULL)
            izq = new NodoArbol(d);
        else
            izq->put(d);
    }else{      //va a la der
        if(der == NULL)
            der = new NodoArbol(d);
        else
            der->put(d);
    }
}

template<class T>
void NodoArbol::put(NodoArbol *nodo){
    if(nodo->getDato == dato)
        throw 1;
    else if(nodo->getDato < dato){  //va a la izq
        if(izq == NULL)
            izq = nodo;
        else
            izq->put(nodo);
    }else{                          //va a la der
        if(der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }
}

template<class T>
T NodoArbol::search(T d) {
    if(d == dato){
        return dato;
    }else if(d < dato){
        if(izq == NULL)
            throw 3;
        else
            izq->search(d);
    }else{
        if(der == NULL)
            throw 3;
        else
            der->search(d);
    }
}

template<class T>
NodoArbol* NodoArbol::remover(T d){
    NodoArbol* aux;
    if(d == dato){
        if(der != NULL){
            der->put(izq);
            return der; //por criterio q yo tomo
        }
        return izq;     //si der es nulo, vemos el izq, si este es nulo no es problema
    }else if(d < dato){
        if(izq == NULL)
            throw 3;
        else{
            aux = izq;
            izq = izq->remover(d);
            if(izq != aux)
                delete aux;
        }
    }else{
        if(der == NULL)
            throw 3;
        else{
            aux = der;
            der = der->remover(d);
            if(der != aux)
                delete aux;
        }
    }
    return this;
}

template<class T>
T NodoArbol::getDato() const {
    return dato;
}

template<class T>
void NodoArbol::setDato(T dato) {
    NodoArbol::dato = dato;
}

#endif //HASHENTRY_H