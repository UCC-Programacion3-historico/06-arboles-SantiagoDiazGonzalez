#ifndef HASHMAP_H
#define HASHMAP_H

#include "NodoArbol.h"

template<class T>
class ArbolBinario {
private:
    NodoArbol<T> *raiz;
public:
    ArbolBinario();

    void put(T dato);

    T search(T dato);

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolBinario();

    bool esVacio();

    void print();

    int contarPorNivel(unsigned int);

    void espejo();

    bool operator==(ArbolBinario);
};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template<class T>
ArbolBinario<T>::ArbolBinario() {
    raiz = NULL;
}


/**
 * Destructor del Arbol
 */
template<class T>
ArbolBinario<T>::~ArbolBinario() {

}


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template<class T>
T ArbolBinario<T>::search(T dato) {
    if (raiz == NULL)
        throw 1;
    return raiz->search(dato);
}


/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template<class T>
void ArbolBinario<T>::put(T dato) {
    if (raiz == NULL)
        raiz = new NodoArbol<T>(dato);
    else
        raiz->put(dato);
}


/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template<class T>
void ArbolBinario<T>::remove(T dato) {
    NodoArbol<T> *aux;
    if (raiz == NULL)
        throw 6;
    aux = raiz;
    raiz = raiz->remover(dato);
    if (raiz != aux)        //si se quiere eliminar la raiz no hay padre para borrar el aux
        delete aux;
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template<class T>
bool ArbolBinario<T>::esVacio() {
    return raiz == NULL;
}


/**
 * Recorre un árbol en preorden
 */
template<class T>
void ArbolBinario<T>::preorder() {
    if (raiz != NULL) {
        raiz->preorder();
    }
}


/**
 * Recorre un árbol en orden
 */
template<class T>
void ArbolBinario<T>::inorder() {
    if (raiz != NULL)
        raiz->inorder();
}


/**
 * Recorre un árbol en postorden
 */
template<class T>
void ArbolBinario<T>::postorder() {
    if (raiz != NULL)
        raiz->postorder();
}


/**
 * Muestra un árbol por consola
 */
template<class T>
void ArbolBinario<T>::print() {
    if (raiz != NULL)
        raiz->print(false, "");
}

template<class T>
int ArbolBinario<T>::contarPorNivel(unsigned int L) {
    if (raiz == NULL)
        throw -1;
    raiz->contarPorNivel(L);
}

template<class T>
void ArbolBinario<T>::espejo() {
    if (raiz == NULL)
        throw -1;
    raiz->espejo();
}

template<class T>
bool ArbolBinario<T>::operator==(ArbolBinario A) {
    if (this->raiz == NULL && A.raiz == NULL)
        return true;

    if (this->raiz != NULL && A.raiz != NULL) {
        return this->raiz->compara(A.raiz);
    }

    return false;
}

#endif //HASHMAP_H