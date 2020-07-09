//
// Created by antwi on 06/07/2020.
//
#ifndef PROF_SAMUEL_CARRO_H
#define PROF_SAMUEL_CARRO_H
#include <string>

using namespace std;

class Carro{
    public:
    string tipo;
    string placa;
    int numPortas;
    int velocidade;
    int limite;
    int ligado;
    int marcha;
    int tanque;
    static int quantidadeCarros;

    Carro(string& tipo);
    Carro();
    ~Carro();

    void liga(int ligado);
    void acelera(int velocidade);
    void freia(int velocidade);
    void pegaMarcha(int marcha, int velocidade, int limite);
    void abastecer(int tanque);
};
class Motor{
public:
    int oleo;
    void trocaOleo(int oleo);
};

#endif //PROF_SAMUEL_CARRO_H
