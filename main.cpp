#include <iostream>
#include <fstream>

using namespace std;

//variaveis globais
    const int maxli=100, maxcol=2;
    int op, linha=0, cont=0;
    string contato[maxli][maxcol];
    string nome[50], telefone[50];
    string ma2[maxli][maxcol];

//declarando funcoes
void cadastrar(string x[maxli][maxcol]);
void listar();
void procurarnome(string y[][2]);
void pegarvalores();
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

        pegarvalores();
        //Switch case do menu

        switch(op){
            case 1:
                    cadastrar(contato);     
                
                break;
            case 2:
                //listar();//
                cout << endl;
                   for (linha = 0; linha < cont; linha++){
       
           
                        cout<<contato[linha][0] << contato[linha][1];
                        cout << endl;

                   }
                 
          
                break;
            case 3:
            procurarnome(contato);
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

void cadastrar(string x[maxli][maxcol]){



    fstream arquivo;
    arquivo.open("Agenda2023.txt", ios::out | ios::app);
    

        cout<< "Digite seu nome:"<<endl;
        
    
        for (linha = 0; linha < 1; linha++){
       
           
            cin>>x[cont][0];
            arquivo << x[cont][0]<<endl;
            
            
            cout << "Digite seu telefone:"<<endl;
            cin>> x[cont][1];
            arquivo << x[cont][1]<<endl;
        
        }
           cont++;
      
        
        
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
    arquivo2.close();
}

void pegarvalores (){
    int cont2 = 1, cont3=0;
    
    string line;
    fstream arquivo3;

    arquivo3.open("Agenda2023.txt",ios::in);
    while (!arquivo3.eof()){
        getline(arquivo3, line);
        cont2++;

        if (cont2%2 == 0){
            ma2[cont3][0]=line;

        }else if(cont2%2 != 0){
            ma2[cont3][1]=line;
            cont3++;
        }
    }
    
    for (int i = 0; i <2; i++)
    {
        cout << ma2[i][0]<< endl;
        cout << ma2[i][1] << endl;
    }
    
    arquivo3.close();
}


//funcao de procurar

void procurarnome (string y[][maxcol]){

     for (linha = 0; linha < 1; linha++){    
            
            cout << "Digite o nome do contato que deseja procurar:"<<endl;
            cin>> y[cont][0];
            }

            bool veri = false;
            pegarvalores();
            for (int i = 0; i <100; i++)
            {
                if (y[cont][maxcol] == ma2[i][maxcol]){
                    veri =  true;
                
                }else{
                    veri = false;
                }
            }
            
            if(veri == true){
                cout << "Contato existente";
            } else if (veri == false){
                cout << "Contato não encontrado";
            }
           cont++;

}




