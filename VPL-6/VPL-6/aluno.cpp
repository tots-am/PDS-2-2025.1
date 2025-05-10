#include "aluno.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

Aluno::Aluno(int mat, std::string name)
{
    this->matricula = mat;
    this->nome = name;
}

Aluno::~Aluno(){}

std::string Aluno::lerNome()
{
    return nome;
}

int Aluno::lerMatricula()
{
    return matricula;
}

std::vector <int> Aluno::lerNotas()
{
    return notas;
}

void Aluno::adicionarNota(int n)
{
    notas.push_back(n);
    //std::cout << "Nota adicionada" << std::endl;
}

double Aluno::calcularMedia()
{
    double media = 0;
    for(int nota : notas)
    {
        media = media + nota;
    }
    media = media / notas.size();
    return media;
}

int Aluno::lerMaiorNota()
{
    int maior = 0;
    for(int nota : notas)
    {
        if(maior < nota)
        {
            maior = nota;
        }
    }
    return maior;
}

int Aluno::lerMenorNota()
{
    int menor = 100;
    for(int nota : notas)
    {
        if(menor > nota)
        {
            menor = nota;
        }
    }
    return menor;
}

void Aluno::exibeInfo()
    {
    std::cout << matricula << " " << nome;
    for(int nota : notas)
    {
        std::cout << " " << nota;
    }
    std::cout << std::endl;
    double media = calcularMedia();
    int maiorNota = lerMaiorNota();
    int menorNota = lerMenorNota();
    std::cout << std::fixed << std::setprecision(2) << media << " " << maiorNota << " " << menorNota << std::endl;
}

