//
// Created by antwi on 15/07/2020.
//

#ifndef PROF_SAMUEL_FILA_H
#define PROF_SAMUEL_FILA_H

#include <iostream>

using namespace std;

template <class T>
class fila{
private:
    int tamanho;
    int final;
    T* elementos;

public:
    fila(int tamanho){
        this->tamanho = tamanho;
        this->final = -1;
        this->elementos = new T[tamanho];
    }
    void push(T elemento){
        if(final == tamanho-1){
            cout << "Fila cheia" << endl;
        } else{
            this->elementos[++final] = elemento;
        }
    }
    void pop(){
        if(final == -1){
            cout << "Fila vazia" << endl;
        } else{
            this->elementos[final--];
        }
    }
    bool isEmpty(){
        if(final == -1){
            return true;
        } else{
            return false;
        }
    }
    T back(){
        return this->elements[final];
    }
    T front(){
        return this->elements[0];
    }
    int sizeOf(){
        return this->tamanho;
    }
};

#endif //PROF_SAMUEL_FILA_H
