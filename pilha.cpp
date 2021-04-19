#include<iostream>
#include<cstdlib>
using namespace std;

struct No
{
    int info;
    No *lig;

};
typedef No *Pilha;


bool buscapilha(Pilha& Topo, int x)
{
    No* Aux = new No;
    Aux = Topo;
    while(Aux!=NULL)
    {
        if(Aux->info == x)
        {
            cout<<"O elemento "<< x << " esta na pilha";
            return 1;
        }

        Aux = Aux->lig;
    }

    cout<<"O elemento "<< x << " nao esta na pilha";
    return 0;
}
bool pilhavazia(Pilha& Topo)
{
    if(Topo == NULL)
        return true;
    else
        return false;
}

bool empilha(Pilha& Topo, int x)
{
    if(buscapilha(Topo,x))
    {

        return false;
    }
    else
    {
        No* Aux = new No;
        Aux->info = x;
        Aux->lig = Topo;
        Topo = Aux;
    }
}

bool desempilha(Pilha& Topo)
{
    if(pilhavazia(Topo))
        return false;
    else
    {
        No* Aux = new No;
        Aux = Topo;
        Topo = Topo->lig;
        delete Aux;
        return true;
    }

}

void topoPilha(Pilha& Topo)
{
    if(pilhavazia(Topo))
        cout<<"Pilha Vazia! ";
    else
    {
        cout<<"O elemento do topo da pilha eh: "<<Topo->info;
    }
}

void quantelementos(Pilha& Topo)
{
    int quant = 0;
    No *Aux = new No;
    Aux = Topo;

    while(Aux!=NULL)
    {
        Aux = Aux->lig;
        quant++;
    }

    cout<<"\nA quantidade de elementos na pilha eh: " <<quant;
}

void primeiroelemento(Pilha& Topo)

{
    if(pilhavazia(Topo))
    {
        cout<<"Pilha vazia!";
    }
    else
    {
        No *Aux = new No;
        Aux = Topo;

        while(Aux!=NULL)
        {
            Aux = Aux->lig;
        }

        cout<<"O primeiro elmento inserido na pilha foi: "<<Aux->info;
    }
}
void imprimepilha(Pilha& Topo)
{
    if(pilhavazia(Topo))
    {
        cout<<"Pilha vazia!";
    }
    else
    {
        cout<<endl;
        No* Aux = new No;
        Aux = Topo;
        cout<<"Os elementos da pilha sao: ";
        while(Aux!=NULL)
        {
            cout<<Aux->info<<" ";
            Aux = Aux->lig;
        }

    }

}





int main()
{
    Pilha Topo=NULL;//Inicializando uma pilha vazia

    int y;
    int op;

    do
    {
        cout << " Opcoes: " << endl;
        cout << " (0) - Fechar o programa "<<endl;
        cout << " (1) - Empilhar um elemento " << endl;
        cout << " (2) - Desempilhar um elemento" << endl;
        cout << " (3) - Imprimir topo da pilha" << endl;
        cout << " (4) - Imprimir os elementos da pilha" << endl;
        cout << " (5) - Buscar um elemento na pilha" <<endl;
        cout << " (6) - Quantidade de elementos da pilha "<<endl;
        cout << " (7) - Primeiro elemento inserido"<<endl;

        cin >> op;
        cout <<endl;

        if(op==1)
        {
            cout<<"Insira um elemento: ";
            cin>>y;

            empilha(Topo,y);

        }
        else if(op==2)
        {
            cout<<"Removendo o topo da pilha"<<endl;
            if(desempilha(Topo))
                cout<<"O top foi removido com sucesso";
            else
                cout<<"A pilha esta vazia";
        }
        else if(op==3)
        {
            cout<<endl;
            topoPilha(Topo);

        }
        else if(op==4)
        {
            imprimepilha(Topo);
        }
        else if(op==5)
        {
            cout<<"Insira o elemento que voce deseja buscar: ";
            cin>>y;
            buscapilha(Topo,y);
        }
        else if(op==6)
        {
            quantelementos(Topo);
        }
        else if (op==7)
        {

            primeiroelemento(Topo);
        }

        system("pause");
        system("cls");

    }
    while(op!=0);

    return 0;
}
