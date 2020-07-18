//
// Created by antwi on 17/07/2020.
//

#ifndef PROVA1_VECTOR_SUPERMERCADO_HPP
#define PROVA1_VECTOR_SUPERMERCADO_HPP

#include <string>
#include <iostream>

using namespace std;

template <class T>
class vectorsupermercado{
private:
    T* produtos;
    int* quantidade;
    int contaprodutos;
    int capacidade;
public:
    vectorsupermercado(){
        capacidade = 10;
        produtos = new T[capacidade];
        quantidade = new int[capacidade];
        contaprodutos = 0;
    }
    ~vectorsupermercado(){
        delete[] produtos;
        delete[] quantidade;
    }
    void pushQuant(int quantia){
        quantidade[contaprodutos-1] = quantia;
    }
    void push(T produto){
        if(capacidade <= contaprodutos){
            int* reserva2 = new int[2 * capacidade];
            T* reserva = new T[2 * capacidade];
            for(int i = 0; i < capacidade; i++){
                reserva[i] = produtos[i];
                reserva2[i] = quantidade[i];
            }
            delete[] quantidade;
            delete[] produtos;
            capacidade *= 2;
            quantidade = reserva2;
            produtos = reserva;
        }
        produtos[contaprodutos] = produto;
        contaprodutos++;
    }
    void pop(){
        contaprodutos--;
    }
    T back(){
        return produtos[contaprodutos];
    }
    T get(int i){
        if(i < contaprodutos){
            return produtos[i];
        } else{
            return "false";
        }
    }
    T front(){
        return produtos[0];
    }
    T find(T produto){
        for(int i = 0; i < contaprodutos; i++){
            if(produto == produtos[i]){
                return produtos[i];
            }
        }
        return "false";
    }
    int getCapacidade(){
        return capacidade;
    }
    int getQuantidade(string produto){
        string checa = find(produto);
        for(int i = 0;i < contaprodutos; i++){
            if(checa == produtos[i]){
                int aux = quantidade[i];
                return aux;
            }
        }
        return -1;
    }
    int sizeOf(){
        return contaprodutos;
    }
    void print(){
        for(int i = 0; i < contaprodutos;i++){
            cout << produtos[i] << endl;
        }
    }
    void listar(){
        cout << "Lista de produtos do fornecedor:" << endl;
        for(int i = 0; i < contaprodutos;i++){
            cout << produtos[i] << " Quantidade: " << quantidade[i] << endl;
        }
    }
    void clear(){
        delete[] produtos;
        capacidade = 0;
        contaprodutos = 0;
    }
};

#endif //PROVA1_VECTOR_SUPERMERCADO_HPP
