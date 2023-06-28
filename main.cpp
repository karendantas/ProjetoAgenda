#include <iostream>
#include <fstream>

using namespace std;

//declarando funcoes
void cadastrar(string x[][2]);
void listar();
//

    int op, linha=0, coluna=1;
    string contato[100][2];

int main (){
    setlocale(LC_ALL, "portuguese");

    bool opi= true;
    fstream arquivo;
    arquivo.open("Agenda2023.txt", ios::out | ios::app);
    if (arquivo.is_open()){
        do{
        cout << "|       -----MENU-----       |" << endl;
        cout << "|1 - Adicionar um contato    |" << endl;
        cout << "|2 - Listar todos os contatos|" <<endl;
        cout << "|3 - Procurar por contato    |"<<endl;
        cout << "|4 - Alterar contato         |"<<endl;
        cout << "|5 - Quantidade de contatos  |"<<endl;
        cout << "|6 - Excluir agenda          |"<<endl;
        cout << "|7 - Sair                    |"<<endl;
        cout << "|      Digite sua opcao      |" <<endl;
        cin >> op;

        
        //Switch case do menu

        switch(op){
            case 1:
                 cadastrar(contato);
                break;

            case 2:
                listar();
                break;
            }

    
        }while (op!=7);
    }else{
        cout << "Não foi possivel abrir o arquivo"<<endl;
    }

    arquivo.close();

    return 0;
}

void cadastrar(string x[][2]){

    int linhaprox=0;

    fstream arquivo;
    arquivo.open("Agenda2023.txt", ios::out | ios::app);
    
            
        cout << "Digite seu nome:"<< endl;
        for (linha = 0; linha < 1; linha++)
        {
            cout << "Digite seu numero:"<<endl;
            for (coluna  = 0; coluna < 2; coluna++)
            {
            cin>>x[linha][coluna];
            arquivo << x[linha][coluna];
            arquivo << " ";
            arquivo << endl;
               
            }
            
            
        }
        
        
    arquivo.close();

    
}


//função de listar 
void listar (){

    string linha;
    fstream arquivo2;
    arquivo2.open("Agenda2023.txt", ios:: in);
    while (getline(arquivo2, linha))
    {
        cout << linha<< " ";
        cout << endl;
    }
    
}