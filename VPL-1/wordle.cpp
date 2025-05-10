#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

string isCorrect(string chave, string guess, string hint)
{
    //cout << "isCorrect\n";
    for(int i = 0; i < 5; i++)
    {
        if(chave[i] == guess[i])
        {
            hint[i] = guess[i];
        }
    }

    return hint;
}

string isPresent(string chave, string guess, string hint, string *notPresent)
{
    //cout << "isPresent\n";
    for(int i = 0; i < 5; i++)
    {
        bool isPresent = false;
        for(int j = 0; j < 5; j++)
        {
            if(guess[i] == chave[j])
            {
                if(i != j)
                {
                    hint[i] = tolower(guess[i]);
                }
                isPresent = true;
            }
        }
        if(!isPresent)
        {
            *notPresent = *notPresent + guess[i];
        }
    }

    return hint;
}

bool isEqual(string chave, string guess)
{
    //cout << "isequal\n";
    if(chave == guess)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string eliminarRep(string str, string ord)
{
    //cout << "eliminarRep\n";
    int t_str = str.length(); 
    string preCorrected = "";
    
    for(int i = 0; i < t_str; i++)
    {
        int reps = 0;
        for(int j = i; j < t_str; j++)
        {
            if(str[i] == str[j])
            {
                reps++;
            }
        }
        if(reps == 1)
        {
            preCorrected = preCorrected + str[i];
        }
    }
    if(ord != "")
    {
        string corrected = "";
        int t_ord = ord.length();
        int t_total = preCorrected.length() + t_ord;
        
        for(int i = t_ord; i < t_total; i++)
        {
            int reps = 0;
            for(int j = 0; j < t_ord; j++)
            {
                if(preCorrected[i - t_ord] == ord[j])
                {
                    reps++;
                }
            }
            if(reps == 0)
            {
                corrected = corrected + preCorrected[i - t_ord];
            }
        }
        string joined = ord + corrected;
        return joined;
    }
    return preCorrected;
}

string getChave(int n)
{
    ifstream file("../palavras.txt");
    string num;
    getline(file, num);
    int nPalavras = stoi(num);

    if(n > nPalavras)
    {
        return "err";
    }

    int currentLine = 0;
    string line;
    while(!file.eof())
    {
        currentLine++;
        getline(file, line);
        if(currentLine == n)
        {
            break;
        }
    }

    file.close();
    return line;
}

int main () 
{
    int n;
    cin >> n;
    if(n <= 0)
    {
        cout << "Erro: O valor deve ser maior que 0" << endl;
        return 1;
    }

    string chave = getChave(n);
    if(chave == "err")
    {
        return 1;
    }

    string notPresent = "";

    for(int w = 0; w < 5; w++)
    {
        string guess;

        cin >> guess;

        if(guess.length() != 5)
        {
            cout << "Erro: O palpite deve ter 5 caracteres" << endl;
            return 1;
        }
        for(int i = 0; i < 5; i++){
            if(islower(guess[i]))
            {
                cout << "Erro: O palpite deve ser em caixa alta" << endl;
                return 1;
            }
        }

        string hint = "*****";

        string notPresentGuess = "";

        if(isEqual(chave, guess))
        {
            cout << chave << " (" << notPresent << ")" << endl;
            cout << "GANHOU!" << endl;
            return 0;
        }

        hint = isCorrect(chave, guess, hint);
        hint = isPresent(chave, guess, hint, &notPresentGuess);

        notPresent = eliminarRep(notPresentGuess, notPresent);

        cout << hint << " (" << notPresent << ")" << endl;
    }

    cout << "PERDEU! " << chave << endl;

    return 0;
}