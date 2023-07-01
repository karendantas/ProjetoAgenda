#include <iostream>
#include <fstream>

using namespace std;

//variaveis globais
    const int maxli=100, maxcol=2;
    int op, linha=0, cont=0,quanticontatos=0;
    string contato[maxli][maxcol];
    string nome, num;
    string ma2[maxli][maxcol];

//declarando funcoes
void cadastrar(string x[maxli][maxcol]);
void listar();
void procurarnome();
void procurarnumero();
void pegarvalores();
void excluiragenda();
void quantidadecontatos();
//......................


int main (){
    setlocale(LC_ALL, "portuguese");

    fstream arquivo;
    arquivo.open("Agenda2023.txt", ios::out | ios::app);
    if (arquivo.is_open()){
        pegarvalores();

        do{
        cout << "|       -----MENU-----       |" << endl;
        cout << "|1 - Adicionar um contato    |" << endl;
        cout << "|2 - Listar todos os contatos|" <<endl;
        cout << "|3 - Procurar por nome       |"<<endl;
        cout << "|4 - Procurar por numero     |"<<endl;
        cout << "|5 - Alterar contato         |"<<endl;
        cout << "|6 - Quantidade de contatos  |"<<endl;
        cout << "|7 - Excluir agenda          |"<<endl;
        cout << "|8 - Sair                    |"<<endl;
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

            case 3:

            procurarnome();
            break;

            case 4:

            procurarnumero();
            break;

            case 5:

            procurarnome();
            break;

            case 6:

            quantidadecontatos();
            break;

            case 7:

            char resposta;
            cout << "Certeza que deseja excluir a agenda? [S/N]"<<endl;
            cin >> resposta;
                if(resposta == 'S' || resposta == 's'){
                excluiragenda();
                cout << "Agenda foi apaga com sucesso!"<<endl;
                }else{
                    cout << "Agenda não será excluída."<<endl;
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
    fstream arquivo3;

    arquivo3.open("Agenda2023.txt",ios::in);
  
    pegarvalores();
    
    for (int i = 0; i <100; i++)
    {
        cout << ma2[i][0]<<" ";
        cout << ma2[i][1];
        cout << endl;
    }   
    arquivo3.close();
}

  

//função que pega os valores do arquivo txt e joga em uma matriz
void pegarvalores (){
    int   cont2 = 1;
    
    string line;
    fstream arquivo4;

    arquivo4.open("Agenda2023.txt",ios::in);
    while (!arquivo4.eof()){
        getline(arquivo4, line);

        if (cont2%2 == 0){
            ma2[cont2][1]=line;

        }else{
            ma2[cont2][0]=line;
          
        }
        cont2++;     
    } 
    arquivo4.close();
}


//funcao de procurar por nome

void procurarnome (){
        cout << "Digite o nome do contato que deseja procurar:"<<endl;
        cin>> nome;
    pegarvalores();
     int procura=1, reprocura=0;
            for (int i = 0; i <100; i++)
            {
                if (nome == ma2[i][0]){
                    procura=0;
                    cout << "Contato existente"<<endl;
                    cout << ma2[i][0]<<endl;
                
                }else{
                    reprocura =1;
                }
            } 
        
             if (reprocura == 1 && procura ==1 ){
                cout << "Contato não encontrado" <<endl;
            }
}

//funcao procurar por numero

void procurarnumero(){
        cout << "Digite o número do contato que deseja procurar:"<<endl;
        cin>> num;
    pegarvalores();
     int procura=1, reprocura=0;
            for (int i = 0; i <100; i++)
            {
                if (num == ma2[i][1]){
                    procura=0;
                    cout << "Número existente"<<endl;
                    cout << ma2[i][1]<<endl;
                
                }else{
                    reprocura =1;
                }
            } 
        
             if (reprocura == 1 && procura ==1 ){
                cout << "Número não encontrado" <<endl;
            }
}
//função para escluir a agenda
void excluiragenda(){

    remove("Agenda2023.txt");

}

//quantidade de cadastros

void quantidadecontatos (){
 string line;
    fstream arquivo6;

    arquivo6.open("Agenda2023.txt",ios::in);
    while (!arquivo6.eof()){
        getline(arquivo6, line);

       quanticontatos++;
    

}

cout << "A quantidade atual de contatos na agenda é de: "<< quanticontatos/2<<endl;
    arquivo6.close();

}
