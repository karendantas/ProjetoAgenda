#include <iostream>
#include <fstream>

using namespace std;

//variaveis globais
    const int maxli=100, maxcol=2;
    int op, linha=0, coluna=1;
    int nlinha=1, ncoluna=2;
    string contato[maxli][maxcol];
    string nome[50], telefone[50];

//declarando funcoes
void cadastrar(string x[maxli][maxcol],int tam_linha, int tam_coluna);
void listar();
void procurar(string y[][2]);
//


int main (){
    setlocale(LC_ALL, "portuguese");

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
          
                while(nlinha <100){
                        cadastrar(contato, nlinha, ncoluna);
                        break;
                        nlinha++;
                        cout << nlinha;
                }
                
                break;
            case 2:
                //listar();//
                cout << endl;

            for (linha = 0; linha < maxli; linha++)
            {
           
            for (coluna  = 0; coluna < maxcol; coluna++)
            {
                     cout<<contato[2][coluna];
            }
            }
                break;

            case 8:
                cout << "Saindo...";
                break;

            dafault:
                cout << "Opção inválida";
                break;
            }

    
        }while (op!=8);
    }else{
        cout << "Não foi possivel abrir o arquivo"<<endl;
    }

    arquivo.close();

    return 0;
}

void cadastrar(string x[maxli][maxcol], int tam_linha, int tam_coluna){

   

    fstream arquivo;
    arquivo.open("Agenda2023.txt", ios::out | ios::app);
    
    

        cout<< "Digite seu nome:"<<endl;
        
        for (linha = 0; linha < tam_linha; linha++)
        {
            cout << "Digite seu numero:"<<endl;
            for (coluna  = 0; coluna < tam_coluna; coluna++)
            {
            cin>>x[linha][coluna];

            arquivo << x[linha][coluna]<<" ";
            arquivo << endl;
            if(tam_linha > tam_linha+1){
                break;
            }
               
            }
            
            
            cout << endl;
        }      
        
        
    arquivo.close();

    
}


//função de listar 
void listar (){

    string line;
    fstream arquivo2;
    arquivo2.open("Agenda2023.txt", ios:: in);
    while (getline(arquivo2, line))
    {
        cout << line<< " ";
        cout << endl;
    }
    
}

//funcao de procurar





