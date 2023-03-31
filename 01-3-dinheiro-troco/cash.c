#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50
#include <math.h>


int retTrocoMoedas(int nMoeda, int nValor);


int main(void) {

    float nTroco = 0.00;
    int   nCents = 0;

    // moeds disposniveis
    int moedasCaixa[4] = { 25, 10, 5, 1 };
    int nTam = 0;
    // vetor para troco
    int moedasTroco[4] = { 0, 0, 0,  0};
    int nQtde = 0;

    int nVez = -1;
    int nVez2 = 0;
    int nBr =  0;
    float nAux = 0;

    do
    {

         printf("\n");
         nTroco = get_float("Informe o Troco a ser Devolvido:  ");
         if( (nTroco < 0.00 ) || ( nTroco == 0)  ){
             printf("\n");
             printf( "Troco Invalido - DIGITADO >>> %f \n", nTroco);
         }

         nTroco = (nTroco * 100);
         nCents = round(nTroco);     // nao usr round 4.2 vira 4.19  erro // para erro usando round fica certo


    } while (nCents <= 0);
    //for vetor moeda e alimentar

    // obter tamanho array c
    nTam = sizeof(moedasCaixa) / sizeof(moedasCaixa[0]);

        for( int i = 0;  i < nTam ; i++){
            if( nCents > 0 ){
                nQtde = 0;
                nQtde =  retTrocoMoedas( moedasCaixa[i], nCents );
                nCents = nCents - ( nQtde * moedasCaixa[i]);
                moedasTroco[i] = nQtde;
             }
        }

    //imprime o troco
    printf("\n");
    printf( "Troco em Moedas------------------- ");
    printf("\n");
    nCents = 0;
    nQtde = 0;
    for( int i = 0;  i < nTam ; i++){

             nQtde = nQtde + moedasTroco[i];
             nCents = nCents + ( moedasTroco[i] * moedasCaixa[i] );
             printf( ">> Qtdes de Moedas: >>> %i ", moedasTroco[i]);
             printf( "   >> Valor da Moeda: >>> %i ", moedasCaixa[i]);
             printf( "   <<< Total Centis>>>  %i ", (moedasTroco[i]*moedasCaixa[i]));

             nAux =  ((float) (moedasTroco[i]*moedasCaixa[i]))/100;
             printf( "   <<< Total Dolar>>>  %f ", nAux);

             printf("\n");

     }
     printf( "-------------------------------------------------------- ");
     printf("\n");
     printf( ">> Total de Moedas >>> %i ", nQtde);
     printf( "   >> Valor Total Troco: >>> %i ", nCents);
     nAux =  ((float) (nCents))/100;
     printf( "   <<< Total Dolar>>>  %f ", nAux);
     printf("\n");
     printf( "%i \n", nQtde);



}


int retTrocoMoedas(int nMoeda, int nValor)
{
    int retQtde = 0;
    while(( nValor >= nMoeda)){
       if( ( nValor >= nMoeda)){
           retQtde++;
           nValor = nValor - nMoeda;
       }

    }
    return retQtde;
}
