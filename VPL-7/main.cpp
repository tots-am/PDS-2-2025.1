#include <iostream>
#include <list>
#include <cctype>
#include <iterator>

class Classe
{
    private:
        static int n_objects_atual;
        static int n_objects_total;
        int id;

    public:
        Classe()
        {
            Classe::n_objects_atual++;
            Classe::n_objects_total++;
            this->id = n_objects_total;
        }
        Classe(int id)
        {
            this->id = id;
            Classe::n_objects_atual++;
        }

        ~Classe()
        {
            Classe::n_objects_atual--;
        }

        void exibeId()
        {
            std::cout << "id: " << this->id;
        }

        void exibeNObj()
        {
            std::cout << this->n_objects_atual << std::endl;
        }
        void exibeEndereco()
        {
            std::cout << "Endereco: " << this << std::endl;
        }
        void exibeInfo()
        {
            std::cout << this->id << " " << this << std::endl;
        }

};

int Classe::n_objects_atual = 0;
int Classe::n_objects_total = 0;

int main ()
{
    std::list <Classe*> Lista;

    char comando;
    while(comando != 'E')
    {
        std::cin >> comando;

        if(std::islower(comando))
        {
            comando = std::toupper(comando);
        }
        switch(comando)
        {
            case 'A' :
            {
                Classe* c = new Classe;

                Lista.push_back(c);

                Lista.back()->exibeInfo();

                break;
            }
            case 'C' :
            {
                int id;
                std::cin >> id;

                if(id > -1)
                {
                    std::cout << "ERRO" << std::endl;
                }
                else
                {
                    Classe* c = new Classe(id);
                    Lista.push_front(c);

                    Lista.front()->exibeInfo();
                }

                break;
            }
            case 'R' :
            {
                if(Lista.empty())
                {
                    std::cout << "ERRO" << std::endl;
                }
                else
                {
                    Classe *c = Lista.front();

                    Lista.pop_front();

                    c->exibeInfo();

                    delete c;
                }

                break;
            }
            case 'N' :
            {
                Lista.front()->exibeNObj();
                break;
            }
            case 'P' :
            {
                int index;
                std::cin >> index;
                index--;

                if (index >= 0 && index < Lista.size())
                {
                    std::list<Classe*>::iterator it = Lista.begin();
                    std::advance(it, index);
                    Classe *c = *it;
                    c->exibeInfo();
                }
                else
                {
                    std::cout << "ERRO" << std::endl;
                }
                break;
            }
            case 'L' :
            {
                for(std::list<Classe*>::iterator it = Lista.begin(); it != Lista.end(); it++)
                {
                    Classe *c = *it;
                    c->exibeInfo();
                }

                break;
            }
            case 'E' :
            {
                break;
            }
        }
    }

    return 0;
}
