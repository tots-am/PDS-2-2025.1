#include <iostream>
#include <cmath>
#include <vector>
#include <cctype>
#include <iomanip>

class Ponto
{
    public:
        int x;
        int y;

        Ponto() : x(0), y(0) {}
        Ponto(int x, int y) : x(x), y(y) {}
};

class FiguraGeometrica
{
    protected:
        Ponto centro;

    public:
        FiguraGeometrica(Ponto centro) : centro(centro) {}

        virtual ~FiguraGeometrica() {}

        virtual void desenha()
        {
            std::cout << centro.x << " " << centro.y;
        }

        virtual float calculaArea() = 0;
};

class Retangulo : public FiguraGeometrica
{
    private:
        float lado_1;
        float lado_2;

    public:
        Retangulo(float pos_x, float pos_y, float lado1, float lado2)
        :FiguraGeometrica(Ponto(pos_x, pos_y)), lado_1(lado1), lado_2(lado2){}

        void desenha() override
        {
            std::cout << this->centro.x << " " << this->centro.y << " " << "RETANGULO" << std::endl;
        }

        float calculaArea() override
        {
            return lado_1 * lado_2;
        }
};

class Triangulo : public FiguraGeometrica
{
    private:
        float base;
        float altura;

    public:
        Triangulo(float pos_x, float pos_y, float base, float altura)
        :FiguraGeometrica(Ponto(pos_x, pos_y)), base(base), altura(altura){}

        void desenha() override
        {
            std::cout << this->centro.x << " " << this->centro.y << " " << "TRIANGULO" << std::endl;
        }

        float calculaArea() override
        {
            return base * altura / 2;
        }
};

class Circulo : public FiguraGeometrica
{
    private:
        float raio;

    public:
        Circulo(float pos_x, float pos_y, float raio)
        :FiguraGeometrica(Ponto(pos_x, pos_y)), raio(raio){}

        void desenha() override
        {
            std::cout << this->centro.x << " " << this->centro.y << " " << "CIRCULO" << std::endl;
        }

        float calculaArea() override
        {
            return raio * raio * M_PI;
        }
};

int main()
{
    std::vector<FiguraGeometrica*> figuras;

    char comando = ' ';
    while(comando != 'E')
    {
        std::cin >> comando;

        if(std::islower(comando))
        {
            comando = std::toupper(comando);
        }

        switch(comando)
        {
            case 'R' :
            {
                float x;
                float y;
                float lado1;
                float lado2;

                std::cin >> x >> y >> lado1 >> lado2;

                Retangulo* retangulo = new Retangulo(x, y, lado1, lado2);

                figuras.push_back(retangulo);

                break;
            }
            case 'C' :
            {
                float x;
                float y;
                float raio;

                std::cin >> x >> y >> raio;

                Circulo* circulo = new Circulo(x, y, raio);

                figuras.push_back(circulo);

                break;
            }
            case 'T' :
            {
                float x;
                float y;
                float base;
                float altura;

                std::cin >> x >> y >> base >> altura;

                Triangulo* triangulo = new Triangulo(x, y, base, altura);

                figuras.push_back(triangulo);

                break;
            }

            case 'D' :
            {
                for(auto f : figuras )
                {
                    f->desenha();
                }

                break;
            }

            case 'A' :
            {
                float soma = 0;
                float area;
                for(auto f : figuras)
                {
                    area = f->calculaArea();
                    soma = soma + area;
                }
                std::cout << std::fixed << std::setprecision(2) << soma << std::endl;

                break;
            }

            case 'E' :
            {
                break;
            }
        }
    }

    for (auto f : figuras)
    {
        delete f;
    }

    return 0;
}
