#ifndef OPERACOESMATRIZES_H
#define OPERACOESMATRIZES_H

//declarar funções que realizem as 9 operações
#include <string>
#include <vector>

namespace AL {
class errMat{
private:
    std::string msgErro;
public:
    errMat(const std::string& erro){
        msgErro=erro;
    }
    const std::string& what() const{return msgErro;}
};

typedef std::vector<std::vector<double>> Matriz; //sinónimo de matriz
void imprimir(Matriz& C);
void menu();
int menu2(Matriz&A, Matriz& B);
void criaMat(Matriz& A, Matriz& B);
void leMat(Matriz& A, Matriz& B);
void printMat(Matriz& A,Matriz& B);  //const pq n queremos alterar as matrizes
Matriz somaMat(Matriz& A, Matriz& B);
Matriz subMat( Matriz& A,Matriz& B);
Matriz mulMat( Matriz& A, Matriz& B);
Matriz transpMat(Matriz& A, Matriz& B);
double trMat( Matriz& A, Matriz& B);
}
#endif // OPERACOESMATRIZES_H
