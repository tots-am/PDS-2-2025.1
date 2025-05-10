#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <vector>
#include <string>
#include "Onibus.hpp"

struct Empresa
{
    int total_onibus;
    std::vector <Onibus> Frota;

    void adicionar_onibus(std::string placa, int capacidade);
    Onibus* buscar_onibus(std::string placa);
    void imprimir_estado();
};

#endif
