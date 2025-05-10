#include <iostream>
#include <string>

#include "Onibus.hpp"

Onibus Onibus::criar(std::string placa, int capacidade) {
    Onibus newBus;
    newBus.placa = placa;
    newBus.capacidade = capacidade;
    newBus.qtd_pessoas = 0;

    return newBus;
}

void Onibus::subir_passageiros(int pessoas) {
    qtd_pessoas = qtd_pessoas + pessoas;
}

void Onibus::descer_passageiros(int pessoas) {
    qtd_pessoas = qtd_pessoas - pessoas;
}

void Onibus::transfere_passageiros(Onibus* transfer, int pessoas) {
    qtd_pessoas = qtd_pessoas - pessoas;
    transfer->qtd_pessoas = transfer->qtd_pessoas + pessoas;
}

void Onibus::imprimir_estado() {
    std::cout << placa << " (" << qtd_pessoas << "/" << capacidade << ")" << std::endl;
}

