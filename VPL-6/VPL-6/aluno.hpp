#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

class Aluno
{
    private:
        std::string nome;
        int matricula;
        std::vector <int> notas;
    public:
        Aluno(int matricula, std::string nome);
        ~Aluno();
        std::string lerNome();
        int lerMatricula();
        std::vector <int> lerNotas();
        void adicionarNota(int nota);
        double calcularMedia();
        int lerMaiorNota();
        int lerMenorNota();
        void exibeInfo();
};
#endif

