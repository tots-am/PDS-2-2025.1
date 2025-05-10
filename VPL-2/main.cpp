#include <iostream>

using namespace std;

// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por referência 
//    - A segunda deve ser passada "por referência" usando apontadores (passgem "por referência" disponível em C)
//    - A terceira deve ser passada por valor
//   A função deverá incrementar em 1 o valor das 3 variáveis e retornar.

void somaUm(int &n1, int *n2, int n3){
    n1++;
    *n2 = *n2 + 1;
    n3++;
}


int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int n;
    //cout << "input: ";
    cin >> n;
    
    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *p = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamanho;
    cin >> tamanho;
    int* vetor = new int[tamanho];
    for(int i = 0; i < tamanho; i++){
        cin >> vetor[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &n << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &p << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << &vetor << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &vetor[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << vetor[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    p = &n;

    // 12) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *p = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    cout << n << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    p = vetor;

    // 17) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    p = &vetor[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    if(p == vetor){
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }

    // 21) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for(int i = 0; i < tamanho; i++){
        p[i] = p[i] * 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i];
        if(i < tamanho - 1){
            cout << " ";
        }
    }
    cout << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    for(int *i = &vetor[0]; i != &vetor[tamanho]; i++){
        cout << *i;
        if(i != &vetor[tamanho - 1]){
            cout << " ";
        }
    }
    cout << endl;
    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    for(int i = 0; i < tamanho; i++){
        cout << p[i];
        if(i < tamanho - 1){
            cout << " ";
        }
    }
    cout << endl;
    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    p = &vetor[tamanho - 1];

    // 28) Imprima o VALOR da variável declarada em (2)
    cout << p << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *p << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **pp = &p;

    // 31) Imprima o VALOR da variável declarada em (30)
    cout << pp << endl;

    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &pp << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *pp << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << **pp << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    int n1, n2, n3;
    cin >> n1; cin >> n2; cin >> n3;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    somaUm(n1, &n2, n3);
    
    // 37) Imprima o valor das 3 variáveis criadas em 35, uma por linha
    cout << n1 << endl << n2 << endl << n3 << endl;

    return 0;
}