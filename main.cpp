#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Vector que armazena as letras, cada item do vector grande "texto"
//representa o número do botão do celular, ou seja, são vetores que possuem as letras.
vector < vector<char> > texto{ {'a', 'b', 'c'}, //Letras do numero 2 - item 0 no vector
                            {'d', 'e', 'f'}, //Letras do numero 3 - item 1 no vector
                            {'g', 'h', 'i'}, //Letras do numero 4 - item 2 no vector
                            {'j', 'k', 'l'}, //Letras do numero 5 - item 3 no vector
                            {'m', 'n', 'o'}, //Letras do numero 6 - item 4 no vector
                            {'p', 'q', 'r', 's'}, //Letras do numero 7 - item 5 no vector
                            {'t', 'u', 'v'}, //Letras do numero 8 - item 6 no vector
                            {'w', 'x', 'y', 'z'} //Letras do numero 9 - item 7 no vector
                        }; 



bool verificador(string code){
    if (code[0] == '#' and code[2] == '='){
        if ((code[1] >= 50) and (code[1] <= 57)){
            for (int i = 3; i < code.length(); i++){
                if ((code[i] < 49) or (code[i] > 57)){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        } 
    }else{
        return false;
    }
}

string formadorDepalavra(int tamanho){
    int n1, n2;
    string aux, codigo = "", palavra = ""; 
    for(int i = 0; i < tamanho; i++){     
        cin >> codigo;
        if(verificador(codigo) == true){
            aux = codigo[1];
            n1 = stoi(aux) - 2;

            //Essa parte permite que o usuário aperte o "botão" mais vezes
            //Como exemplo caso o usuário escolha o numero 2 e no código peça para apertar 4
            //Vezes, ao invés de ocasionar um bug por ser um numero maior que o tamanho do vector,
            //Irá simplesmente fazer que ele volte para o inicio, ou seja, se ele colocar 4 irá para
            //letra "a" de novo, 5 ira para a "b" e assim por diante, deixando a experiência mais
            //parecida com um celular da época.
            //Inicio
            aux = "";
            for (int n = 3; n < codigo.length(); n++){
                aux += codigo[n];
            }
            n2 = stoi(aux) - 1;
            if (n1 != 5 and n1 != 7){
                n2 %= 3;
            }else{
                n2 %= 4;
            }
            //Fim

            palavra += texto[n1][n2];    
        }else{
            cout << "código invalido, tente de novo\n";
            i--;
        }
    }
    return palavra;
}

int main() {
    int tamanhoPalavra;
    string palavra = "";
    cin >> tamanhoPalavra;
    if (tamanhoPalavra != 0){
        cout << formadorDepalavra(tamanhoPalavra);
    }else{
        cout << "Tamanho da palavra inválido";
    }
}