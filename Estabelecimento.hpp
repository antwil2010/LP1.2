//
// Created by antwi on 09/07/2020.
//
#ifndef PROVA1_ESTABELECIMENTO_HPP
#define PROVA1_ESTABELECIMENTO_HPP

#include <string>
#include "vector_supermercado.hpp"

using namespace std;

class estabelecimento{
public:
    vectorsupermercado<string> produtos;
    double* preco;
    int quantia;



    void caixa();
    estabelecimento();
    ~estabelecimento();
};

class Supermercado : public estabelecimento{
public:
    int* codigo;
    string* unidadeMedida;
    int* quantidade;
    string* produtosreserva;

    void venda(int cod); //Não pude colocar em estabelecimento pois usa objetos únicos dessa classe
    void listar(); //Não pude colocar em estabelecimento pois usa objetos únicos dessa classe
    void consultar();
    void reabastecer(string produto, int quantidade);
};

class Restaurante : public estabelecimento{
public:
    Restaurante();
    ~Restaurante();
    void venda(string produto); //Não pude colocar em estabelecimento para não conflitar com o Supermercado
    void listar(); //Não pude colocar em estabelecimento para não conflitar com o Supermercado
};

class fornecedor{
private:
    vectorsupermercado<string> produtosfornecedor;
public:
    fornecedor();
    ~fornecedor();
    void listarProdutos();
    int repassarProdutos(string produto);
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
