//
// Created by antwi on 09/07/2020.
//
#include "Cliente.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

vector<string> cliente::sacola;

cliente::cliente(){
    contacliente += 1;
}

cliente::~cliente(){

}

int cliente::compra(string produto, double aux){
    if(saldo >= aux){
        saldo -= aux;
        sacola.push_back(produto);
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
    if(sacola.empty()){
        cout << "Sacola está vazia, compre primeiro para adicionar e ver produtos" << endl;
    } else{
        cout << "Produtos da sacola: " << endl;
        for(int i = 0; i < sacola.size(); i++){
            cout << sacola[i] << endl;
        }
    }
}

void cliente::registro(){
    ofstream clientx;
    string filename = "cliente_" + to_string(contacliente) + ".csv";
    clientx.open(filename);
    clientx << "Sacola dos produtos comprados: " << endl;
    for(int i = 0; i < sacola.size(); i++){
        clientx << sacola[i] << endl;
    }
    clientx.close();
}

