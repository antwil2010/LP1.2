//
// Created by antwi on 09/07/2020.
//

#include "cliente.h"
#include <iostream>

using namespace std;

ClientePJ::ClientePJ(){
    cout << "Digite a Razão Social da Pessoa Jurídica: ";
    string nomepj;
    cin >> nomepj;
    setRazaoSocial(nomepj);
    cout << "Digite o cnpj da Pessoa Jurídica: ";
    string cnpjpj;
    cin >> cnpjpj;
    setcnpj(cnpjpj);
}
ClientePJ::~ClientePJ(){

}

void ClientePJ::setRazaoSocial(string RazaoSocial){
    this->RazaoSocial = RazaoSocial;
}
string ClientePJ::getRazaoSocial(){
    return this->RazaoSocial;
}

void ClientePJ::setcnpj(string cnpj){
    this->cnpj = cnpj;
}
string ClientePJ::getcnpj(){
    return this->cnpj;
}

int Cliente::quantidadeClientes;

Cliente::Cliente(){
    this->quantidadeClientes += 1;
}

Cliente::~Cliente(){

}


