//
// Created by antwi on 06/07/2020.
//
#include "carro.h"
#include <iostream>

using namespace std;

int Carro::quantidadeCarros;

Carro::Carro(string& tipo): tipo(tipo){
    this->quantidadeCarros += 1;
}

Carro::Carro(){
    this->quantidadeCarros +=1;
}

Carro::~Carro(){
}

void Carro::liga(int ligado){
    this->ligado = 1;
}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::pegaMarcha(int marcha, int velocidade, int limite){
    if(marcha == 0) {
        this->marcha = 1;
    } else if(marcha == 1 && velocidade >= limite) {
        this->marcha = 2;
    } else if(marcha == 2 && velocidade >= limite) {
        this->marcha = 3;
    } else if(marcha == 3 && velocidade >= limite) {
        this->marcha = 4;
    } else if(marcha == 4 && velocidade >= limite) {
        this->marcha = 5;
    } else if(marcha == 5) {
        cout << "O carro já está na última marcha!" << endl;
    }
}

void Carro::abastecer(int tanque){
    if(tanque <= 10){
        this->tanque = 100;
    } else{
        cout << "Tanque do carro ainda possui gasolina suficiente pra andar sem perigo!" << endl;
    }
}

void Motor::trocaOleo(int oleo){
    if(oleo <= 1){
        this->oleo = 10;
    } else {
        cout << "Motor ainda possui oleo suficiente para andar sem perigo!" << endl;
    }
}



