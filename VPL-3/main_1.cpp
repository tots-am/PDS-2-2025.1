#include <iostream>
#include <string>
#include <vector>
#include "Empresa.hpp"
#include "Onibus.hpp"

int main () {
    Empresa empresa;

    char comando;
    while (comando != 'F')
    {
        std::cin >> comando;
        switch (comando) {
        case 'C':
        {
            std::string placa;
            int capacidade;

            std::cin >> placa >> capacidade;

            empresa.adicionar_onibus(placa, capacidade);
            break;
        }
        case 'S':
        {
            std::string placa;
            int pessoas;

            Onibus* existingBus = empresa.buscar_onibus(placa);

            if(existingBus == nullptr){
                std::cout << "ERRO : onibus inexistente" << std::endl;
            } else {
                if(existingBus->qtd_pessoas + pessoas > existingBus->capacidade){
                    std::cout << "ERRO : onibus lotado" << std::endl;
                } else {
                    existingBus->subir_passageiros(pessoas);
                    std::cout << "passageiros subiram com sucesso" << std::endl;
                }
            }

            break;
        }
        case 'D':
        {
            std::string placa;
            int pessoas;

            Onibus* existingBus = empresa.buscar_onibus(placa);

            if(existingBus == nullptr){
                std::cout << "ERRO : onibus inexistente" << std::endl;
            } else {
                if(existingBus->qtd_pessoas - pessoas < 0){
                    std::cout << "ERRO : faltam passageiros" << std::endl;
                } else {
                    existingBus->descer_passageiros(pessoas);
                    std::cout << "passageiros desceram com sucesso" << std::endl;
                }
            }
            break;
        }
        case 'T':
        {
            std::string placa1;
            std::string placa2;
            int pessoas;

            Onibus* bus1 = empresa.buscar_onibus(placa1);
            Onibus* bus2 = empresa.buscar_onibus(placa2);

            if(bus1 == nullptr || bus2 == nullptr){
                std::cout << "ERRO : onibus inexistente" << std::endl;
            } else {
                if(bus1->qtd_pessoas - pessoas < 0 || bus2->qtd_pessoas + pessoas > bus2->capacidade){
                    std::cout << "ERRO : transferencia cancelada" << std::endl;
                } else {
                    bus1->transfere_passageiros(bus2, pessoas);
                    std::cout << "transferencia de passageiros efetuada" << std::endl;
                }
            }
            break;
        }
        case 'I':
        {
            empresa.imprimir_estado();
            break;
        }
        case 'F':
            break;
        default:
            std::cout << "Esse comando não existe" << std::endl;
            break;
        }
    }

    return 0;
}
