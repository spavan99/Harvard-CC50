#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50
#include <math.h>


// fucntion
int lenCard(long long cartao);
bool digitoCartao(long long nCartao, int cont);
string operadoraCard(int nInCard);


int main(void) {


       long long lNumberCard;

       int nTamMaximo = 16;
       int nTamMinimo = 6;
       int nTamAtual = 0;
       int nAux = 0;
       string mensagem = "Card Invalido";
       string msgoper = "INVALID";

       printf("\n");
       do{

           printf("\n");
           lNumberCard = get_long( "Informe o numero do Cartão de Credito: ");
           printf("\n");

           nTamAtual = lenCard( lNumberCard);
           if( nTamAtual > nTamMaximo ){
               printf("Cartao tem mais de %i digito, digite NOVO \n", nTamMaximo);
           }else if(nTamAtual < nTamMinimo){
               printf("Cartao tem menos de %i  digitos, digite NOVO \n", nTamMinimo);
           }else if( nTamAtual == 0 ){
               printf("Cartao tem branco, digite NOVO \n");
           }

       }while( (lNumberCard <= 0)  || ( nTamAtual > nTamMaximo) || ( nTamAtual < nTamMinimo) );


       //checar cartao
       if( digitoCartao(lNumberCard, nTamAtual )){
           mensagem = "Cartao Valido";
           nAux =  ( lNumberCard / pow (10, (nTamAtual -2)));
           msgoper = operadoraCard(nAux);
       }

      printf("\n");
      printf(">>>>  %s  Operadora ->>>  %s \n", mensagem, msgoper);

      printf("\n");
      printf("%s \n", msgoper);


}


bool digitoCartao(long long nCartao, int cont){

    bool nRet = false;
    int somaA = 0;
    int ultimo = 0;
    int multiplo = 1;
    int nAux = 0;
    int nAux2 = 0;
    int nDig = 0;

    for( int i = 1;  i <= cont; i++)
    {
        if( ( i % 2 ) == 0){
            multiplo = 2;
        }else{
            multiplo = 1;
        }
        // utlimo digito
        ultimo = ( nCartao % 10);
        nAux = ( ultimo * multiplo);

        // verifica mais de um digito reduz para somar
        nDig = lenCard( nAux);
        if ( nDig > 1 ){
            nAux2 = nAux;
            nAux = 0;
            for( int n = 0;  n < nDig; n++){
                ultimo = ( nAux2 % 10);
                nAux = nAux +ultimo;
                nAux2 = ( nAux2 / 10);
            }
        }
        // soma digitos
        somaA = somaA + nAux;
        //atuliza numero carta eliminndo ultimo digito
        nCartao = ( nCartao / 10);
    }

    if( ( somaA % 10) == 0 ){
       return true;
    }else{
        return false;
    }

}

string operadoraCard(int nInCard){

    string retOp = "INVALID";

    if( (nInCard / 10) ==  4){
        retOp  = "VISA";
    }else if( (nInCard == 51) || (nInCard == 52) || (nInCard == 53) || (nInCard == 54) || (nInCard == 55) ){
        retOp  = "MASTERCARD";
    }else if( (nInCard == 34) || (nInCard == 37)  ){
        retOp  = "AMEX";
    }


 

    return retOp;

}


int lenCard(long long cartao)
{
    int ret = 0;

    while (cartao != 0)
    {
        cartao = cartao / 10;
        ret++;
    }
    return ret;
}


