#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>

int main(){
    std::string fileName;
    std::cin >> fileName;

    std::ifstream file(fileName);

    std::vector<std::string> frase;

    std::string palavra;

    while(file >> palavra){
        std::string novaPalavra;

        bool sub = false;

        for(char letra : palavra){

            char lower = std::tolower(letra);

            if(std::isalpha(lower)){
                novaPalavra.push_back(lower);
            }
            if(std::isdigit(letra)){
                novaPalavra.push_back(letra);
            }
            if(letra == '-'){
                sub = true;
                novaPalavra.push_back(letra);
            }
        }

        if(sub){
            std::string subPalavra;
            int index = novaPalavra.find('-');
            for(int i = index + 1; i < novaPalavra.size(); i++){
                subPalavra.push_back(novaPalavra[i]);
            }

            frase.push_back(subPalavra);

            int dif = novaPalavra.size() - index;

            for(int i = 0; i < dif; i++){
                novaPalavra.pop_back();
            }

            frase.push_back(novaPalavra);
        } else {
            frase.push_back(novaPalavra);
        }
    }

    //std::cout << c << std::endl;

    //std::cout << frase.size() << std::endl;

    std::vector <std::string> fraseCompleta;

    for(std::string word : frase){
        int qtd = count(frase.begin(), frase.end(), word);

        std::string strQtd = std::to_string(qtd);

        fraseCompleta.push_back(word + ' ' + strQtd);
    }

    std::sort(fraseCompleta.begin(), fraseCompleta.end());
    fraseCompleta.erase(unique(fraseCompleta.begin(), fraseCompleta.end()), fraseCompleta.end());

    //std::cout << fraseCompleta.size() << std::endl;

    for(std::string word : fraseCompleta){
        if(word != ""){
            std::cout << word << std::endl;
        }
    }

    return 0;
}
