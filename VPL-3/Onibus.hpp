#ifndef ONIBUS_H
#define ONIBUS_H

#include <iostream>
#include <string>
#include <vector>

struct Onibus
{
    std::string placa;
    int capacidade;
    int qtd_pessoas = 0;

    Onibus criar(std::string placa, int capacidade);
    void subir_passageiros(int pessoas);
    void descer_passageiros(int pessoas);
    void transfere_passageiros(Onibus* transfer, int pessoas);
    void imprimir_estado();
};

#endif