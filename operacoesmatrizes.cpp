#include "operacoesmatrizes.h"
#include <iostream>
using namespace std;
namespace AL{
//FUNÇÃO MENU
void imprimir(Matriz& C){
    size_t m= C.size();
    size_t n= C[0].size();

    if(m>=1 & n>=1){
       for(size_t i=0; i<m;++i){
           cout << ""<< endl;
           for(size_t j=0; j<n;++j){
              cout << C[i][j];
            }
       }
}
    cout <<endl;
}
void menu()  //1a funcao
{
      Matriz A, B;
      criaMat(A,B);

}
int menu2(Matriz&A, Matriz& B)  //2a funcao
{
    //MENU
    cout << "Menu:" << endl;
    cout << "1.Criar Matriz(es)\n";
    cout << "2.Ler Matriz(es)\n";
    cout << "3.Imprimir Matriz(es)\n";
    cout << "4.Somar Matrizes\n";
    cout << "5.Subtrair Matrizes\n";
    cout << "6.Multiplicar Matrizes\n";
    cout << "7.Transpor Matriz(es)\n";
    cout << "8.Calcular o traco de uma (ou mais) matriz\n";
    cout << "9.Sair\n";
    int a;


    while(cin>>a){
        if(a==3){printMat(A,B);}
        if(a==4){somaMat(A,B);}
        if(a==5){subMat(A,B);}
        if(a==6){
           mulMat(A,B);
        }
        if(a==7){transpMat(A,B);}
        if(a==8){trMat(A,B);}
        if(a==9){break;}
    }
    return 1;
}

//FUNÇÕES PARA TRABALHAR COM MATRIZES

//TRATAR ERROS -----------------------------------------------------
void criaMat(Matriz& A, Matriz& B)  //faz bem
{
    int w;
    cout<<"Criar uma Matriz A?1 para sim, 0 para nao"; //dar a escolha
    cin>>w;
    if(w==1){
         size_t m;
         size_t n;
         cout<<"numero Linhas matriz A:"; cin >> m; cout << "" << endl;
         cout<<"numero Colunas matriz A:"; cin >> n; cout << "" << endl;
         if(m==0 ||n==0){throw errMat{"Matriz com dimensoes invalidas!"};}
         if(m>=1 & n>=1){
             A.resize(m);  //m elementos -- m linhas
             for(size_t i=0; i<m;++i) A[i].resize(n);  //n colunas
             }
    }
    cout << "Criar uma matriz B? 1 para sim, 0 para nao";  //dar a escolha
    int a;
    cin >> a;
    if(a==1){
         size_t o;
         size_t p;
         cout<<"Linhas matriz B:"; cin >> o; cout << "" << endl;
         cout<<"Colunas matriz B:"; cin >> p; cout << "" << endl;
         if(o==0 ||p==0){throw errMat{"Matriz com dimensoes invalidas"};}
         if(o>=1 & p>=1){
         B.resize(o);  //m elementos -- m linhas
         for(size_t i=0; i<p;++i) B[i].resize(p);
         }
    }
    leMat(A,B);
    menu2(A,B);
}


//TRATAR ERROS -----------------------------------------------------
void leMat(Matriz& A, Matriz& B)  //faz bem
{
        cout<<"Preencher a Matriz A? 1 para sim, 0 para nao ";
        int w;
        cin>>w;
        if(w==1){
            size_t m=A.size();
            size_t n=A[0].size();
            if(m==0 || n==0){throw errMat{"Matriz com dimensoes invalidas"};}  //n ta definida
            if(m>=1 & n>=1){
            cout<< "Introduza os elementos da matriz A:\n";
            for(size_t i=0; i<m; ++i)
            {
                 cout <<endl;
                 for(size_t j=0; j<n;++j)
                 {
                     cin>>A[i][j];
                 }
            }
         }

        }


     cout<<"Preencher a Matriz B? 1 para sim, 0 para nao ";
     int a;
     cin>>a;
     if(a==1){
        size_t o=B.size();
        size_t p=B[0].size();
        if(o>=1 & p>=1){
            cout <<"Introduza os elementos da Matriz B:\n";
            for(size_t i=0;i<o;++i){
               cout<<endl;
               for(size_t j=0;j<p;++j){
                cin >>B[i][j];
                }
             }
         }
      }

menu2(A,B);
}

//TRATAR ERROS -----------------------------------------------------
void printMat(Matriz& A, Matriz& B) //faz bem
{
    cout <<"Imprimir a matriz A?1 para sim, 0 para  nao   ";
    int a; cin>>a;
    if(a==1){
         size_t m= A.size();
         size_t n= A[0].size();
         if(m==0 || n==0){throw errMat{"Matriz com dimensoes invalidas"};} //n ta definida
         if(m>=1 & n>=1){
            for(size_t i=0; i<m;++i){
                cout << ""<< endl;
                for(size_t j=0; j<n;++j){
                   cout << A[i][j];
                 }
            }
         }
         cout <<endl;
    }

    cout<<"Imprimir a Matriz B? 1 para sim, 0 para nao  ";
    int w; cin >>w;
    if(w==1){
         size_t o=B.size();
         size_t p=B.size();
         if(o==0 || p==0){throw errMat{"Matriz com dimensoes invalidas"};}   //n ta definida
         if(o>=1 & p>=1){
             for(size_t i=0;i<o;++i){
                 cout << ""<< endl;
                 for(size_t j=0;j<p;++j){
                     cout <<B[i][j];
                 }
             }
        }
}
menu2(A,B);
}

Matriz somaMat( Matriz& A,  Matriz& B) //faz bem
{
    Matriz SOMA;
    size_t m= A.size();
    size_t n= A[0].size();
    SOMA.resize(m);
    for(size_t i=0; i<m; ++i){
        for(size_t j=0; j<n; ++j){
            SOMA[i].resize(n);
        }
    }
    if(A.size()!=B.size() || A[0].size()!=B[0].size())
    {
        throw errMat{"As dimensoes das duas matrizes nao sao iguais!"};
    }

        cout << "A+B:" << endl;
        for(size_t i=0; i<m;++i){
            cout<<""<<endl;
            for(size_t j=0; j<n;++j){
                SOMA[i][j]=A[i][j]+B[i][j];
            }
        }
    imprimir(SOMA);
    menu2(A,B);
    return SOMA;



}

//TRATAR ERROS -----------------------------------------------------

Matriz subMat(Matriz& A, Matriz& B)  //faz bem
{
    Matriz SUB;
    size_t m= A.size();
    size_t n= A[0].size();
    if(A.size()!=B.size() || A[0].size()!=B[0].size())
    {
        throw errMat{"As dimensoes das duas matrizes nao sao iguais!"};
    }
    else{
        cout <<"1a matriz - 2a matriz:\n";
        for(size_t i=0;i<m;++i)
        {
            cout<<""<<endl;
            for(size_t j=0; j<n;++j){
                SUB[i][j]=A[i][j]-B[i][j];
            }
        }
        cout <<"2a matriz - 1a matriz:\n";
        for(size_t i=0;i<m;++i)
        {
            cout<<""<<endl;
            for(size_t j=0; j<n;++j){
                SUB[i][j]=B[i][j]-A[i][j];
            }
        }
    }
    imprimir(SUB);
    menu2(A,B);
    return SUB;

}


//TRATAR ERROS -----------------------------------------------------
Matriz mulMat( Matriz& A, Matriz& B) //faz bem
{

    Matriz C;
    if(B.size()==0 || B[0].size()==0)
    {
        cout << "Matriz B nao existe.Sao necessarias duas matrizes para esta operacao"<<endl;
        size_t m=A.size();
        size_t n=A[0].size();
        cout << "Introduza um valor c para multiplicar pela Matriz existente";
        double c;
        cin >>c;
        C.resize(m);       //matriz com mesmas dimensoes que B
        for(size_t i=0;i<m;++i){
                C[i].resize(n);
        }
        cout << c <<"*B:"<< endl;
        for(size_t i=0;i<m;++i){
            cout << endl;
            for(size_t j=0;j<n;++j){
                C[i][j]=c*A[i][j];
        }
            imprimir(C);
            menu2(A,B);
    }

    }
    if(A.size()==0 || A[0].size()==0){
        cout << "Matriz A nao existe.Sao necessarias duas matrizes para esta operacao"<<endl;
        size_t m=B.size();
        size_t n=B[0].size();
        cout << "Introduza um valor c para multiplicar pela Matriz existente";
        double c;
        cin >>c;
        C.resize(m);       //matriz com mesmas dimensoes que B
        for(size_t i=0;i<m;++i){
                C[i].resize(n);
        }
        cout << c <<"*B:"<< endl;
        for(size_t i=0;i<m;++i){
            cout << endl;
            for(size_t j=0;j<n;++j){
                C[i][j]=c*A[i][j];
        }
     }
     imprimir(C);
     menu2(A,B);
     }


     if(B.size()!=0 & B[0].size()!=0)
     {
       if(A.size()!=0 & A[0].size()!=0){
           size_t m=A.size();
           size_t n=A[0].size();
           size_t o=B.size();
           size_t p=B[0].size();

            if(n==o){
           //A(m,n) * B(n,p) = C(m,p)
           C.resize(m);
           for(size_t i=0;i<m;++i){
               C[i].resize(p);
           }
           cout << "A*B:" << endl;
           for(size_t i=0; i<m; ++i) {
               for(size_t j=0; j<p;++j){
                  double soma=0.0;
                  for(size_t k=0; k<n;++k){
                            soma+=A[i][k]*B[k][j];
                  }
                   C[i][j]=soma;
               }
            imprimir(C);
            menu2(A,B);
           }
         }
            else{
                throw errMat{"O produto das duas matrizes nao esta definido"};
            }
      }
     }


   return C;

}
//TRATAR ERROS -----------------------------------------------------
Matriz transpMat(Matriz& A, Matriz& B)   //faz bem
{
    cout<<"Transporta da Matriz A?1 para sim, 0 para nao  ";
    int a;
    cin>>a;
    Matriz C;
    if(a==1){
        size_t m=A.size();
        size_t n=A[0].size();
        C.resize(n);
        for(size_t i=0; i<m;++i){
            C[i].resize(m);
        }
        for(size_t i=0;i<m;++i)
        {
            for(size_t j=0;j<n;++j){
            C[j][i]=A[i][j];
            }
        }
        imprimir(C);
    }
    cout<<"Transposta da Matriz B?1 para sim, 0 para nao  ";
    int b; cin>>b;
    if(b==1){
        size_t m=B.size();
        size_t n=B[0].size();
        C.resize(n);
        for(size_t i=0; i<m;++i){
            C[i].resize(m);
        }
        for(size_t i=0;i<m;++i)
        {
            for(size_t j=0;j<n;++j){
            C[j][i]=B[i][j];
            }
        }
        imprimir(B);
    }
    menu2(A,B);
    return A;


}
//TRATAR ERROS -----------------------------------------------------------
double trMat( Matriz& A, Matriz& B)  //faz bem
{
    double tr=0;
    cout <<"Traco da matriz A?1 para sim, 0 para nao  ";
    int a; cin>>a;
    if(a==1){
        size_t m=A.size();
        size_t n=A[0].size();
        if(m==0 || n==0){ throw errMat{"Matriz com dimensoes invalidas!"};}
        if(m!=n){throw errMat{"Nao e possivel calcular o traco de uma matriz nao quadrada!"};};
        for(size_t i=0;i<m;++i){
        for(size_t j=0;j<n;++j){
           if(i==j) tr+=A[i][j];
           else{
               break;
           }
        }
    }
    cout<<"Tr(A):"<<tr<<endl;
    }
    cout <<"Traco da matriz B?1 para sim, 0 para nao  ";
    int b; cin>>b;
    if(b==1){
        size_t m=B.size();
        size_t n=B[0].size();
        if(m==0 || n==0){ throw errMat{"Matriz com dimensoes invalidas"};}
        if(m!=n){throw errMat{"Nao e possivel calcular o traco de uma matriz nao quadrada!"};};
        for(size_t i=0;i<m;++i){
            for(size_t j=0;j<n;++j){
               if(i==j) tr+=B[i][j];
               else{
                   break;
               }
            }
        }
        cout<<"Tr(B):"<<tr<<endl;
    }

    menu2(A,B);
    return tr;

}
}


