#include "aluno.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool comparaNome(Aluno& a, Aluno& b) {
    return a.lerNome() < b.lerNome();
}

int main()
{
    std::vector <Aluno> alunos;

    for(int i = 0; i < 100; i++)
    {
        //std::cout << "entrou\n";
        std::string nome;
        std::cin >> nome;

        if(nome == "END"){ break; }

        int matricula;
        std::cin >> matricula;

        Aluno a(matricula, nome);

        //std::cout << "Insira as notas:" << std::endl;

        int nota;
        while(std::cin >> nota)
        {
            //std::cout << "entrou2\n";
            if(nota == -1){break;}

            a.adicionarNota(nota);
        }

        alunos.push_back(a);
        //alunos[0].exibeInfo();
        //std::cout << "saiu\n";
    }

    std::sort(alunos.begin(), alunos.end(), comparaNome);

    for(Aluno aluno : alunos)
    {
        aluno.exibeInfo();
    }

    return 0;
}
