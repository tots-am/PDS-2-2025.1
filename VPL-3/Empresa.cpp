#include <iostream>
#include <string>
#include <vector>

#include "Empresa.hpp"

void Empresa::adicionar_onibus(std::string placa, int capacidade) {
    bool ok = true;

    if(!Frota.empty()) {
        for (int i = 0; i < Frota.size(); i++)
        {
            if(Frota[i].placa == placa) {
                std::cout << "ERRO : onibus Repetido" << std::endl;
                ok = false;
            }
        }
    }

    if(ok){
        Onibus newBus = newBus.criar(placa, capacidade);
        Frota.push_back(newBus);
        std::cout <<"novo onibus cadastrado"<<std::endl;
    }
}

Onibus* Empresa::buscar_onibus(std::string placa) {
    Onibus* existingBus = nullptr;

    for(int i = 0; i < Frota.size(); i++){
        if(Frota[i].placa == placa) {
            *existingBus = Frota[i];
        }
    }

    return existingBus;
}

void Empresa::imprimir_estado() {
    for(int i = 0; i < Frota.size(); i++){
        std::cout << Frota[i].placa << " (" << Frota[i].qtd_pessoas << "/" << Frota[i].capacidade << ")" << std::endl;
    }
}

