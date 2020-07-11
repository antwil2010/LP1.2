//
// Created by antwi on 09/07/2020.
//
#ifndef PROVA1_ESTABELECIMENTO_HPP
#define PROVA1_ESTABELECIMENTO_HPP

#include <string>
#include <list>

using namespace std;

class estabelecimento{
public:
    int* codigo;
    list<string> produtos;
    string* unidadeMedida;
    double* preco;
    int* quantidade;
    int quantia;
    string* produtosreserva;

    void consultar();
    void listar();
    void venda(int cod);
    void caixa();
    estabelecimento();
    ~estabelecimento();
};
class vendido{
public:
    static double total;
    static string* produtosvendido;
    static int* codigovendido;
    static double* precovendido;
    static int* quantidadevendida;
    static int vendas;
};

#endif //PROVA1_ESTABELECIMENTO_H
