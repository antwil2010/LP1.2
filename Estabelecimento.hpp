//
// Created by antwi on 09/07/2020.
//
#ifndef PROVA1_ESTABELECIMENTO_HPP
#define PROVA1_ESTABELECIMENTO_HPP

#include <string>
#include <list>
#include "vector_supermercado.hpp"

using namespace std;

class estabelecimento{
public:
    int* codigo;
    vectorsupermercado<string> produtos;
    string* unidadeMedida;
    double* preco;
    int* quantidade;
    int quantia;
    string* produtosreserva;

    void consultar();
    void listar();
    void venda(int cod);
    void caixa();
    void reabastecer(string produto, int quantidade);
    estabelecimento();
    ~estabelecimento();
};
class fornecedor{
private:
    vectorsupermercado<string> produtosfornecedor;
public:
    fornecedor();
    ~fornecedor();
    void listarProdutos();
    void repassarProdutos();
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
