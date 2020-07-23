//
// Created by antwi on 09/07/2020.
//
#include "Cliente.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vectorsupermercado<string> cliente::sacola;

cliente::cliente(){
    contacliente += 1;
}

cliente::~cliente(){

}

int cliente::compra(string produto, double aux){
    if(saldo >= aux){
        saldo -= aux;
        sacola.push(produto);
        cout << "Compra realizada com sucesso" << endl;
        cout << "Saldo restante: " << saldo << endl;
        return 0;
    } else{
        cout << "Saldo insuficiente para comprar " << produto << endl;
        cout << "Saldo: " << saldo << endl;
        return 1;
    }
}

void cliente::verSacola(){
    if(sacola.sizeOf() == 0){
        cout << "Sacola está vazia, compre primeiro para adicionar e ver produtos" << endl;
    } else{
        cout << "Produtos da sacola: " << endl;
        for(int i = 0; i < sacola.sizeOf(); i++){
            cout << sacola.get(i) << endl;
        }
    }
}

void cliente::registro(){
    ofstream clientx;
    string filename = "cliente_" + to_string(contacliente) + ".csv";
    clientx.open(filename);
    clientx << "Sacola dos produtos comprados: " << endl;
    for(int i = 0; i < sacola.sizeOf(); i++){
        clientx << sacola.get(i) << endl;
    }
    clientx.close();
}

