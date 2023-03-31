#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50
#include <math.h>


// fucntion
int ImputPop( string sTit );
int CalcPopulation( int start, int end );

int main(void) {

       int startSize = 0;
       int endSize   = 0 ;
       int years     = 0;
       bool inputLoop = true;

       while(inputLoop){
           printf("\n");

           if( startSize == 0){
               startSize = ImputPop( "Start Size: ");
               if( startSize < 9 ){
                   printf("\n");
                   printf(">>>>  Crescimento demografico igual a zero (Minimo 9) , tente novamente !!!!!  \n\n");
                   startSize = 0;
               }

           }

           if( startSize > 0){

                printf("\n");
                endSize = ImputPop( "End Size: ");

               if( endSize < startSize){
                printf("\n");
                printf(">>>>  Populacao final tem que ser maior que a inicial , tente novamente !!!!!  \n\n");

               }else{
                   inputLoop = false;
               }
//              printf("\n");
           }

       }

       // funcao devole os anos
       years = CalcPopulation( startSize, endSize);
       printf("Years: %i \n", years);

}


int ImputPop( string sTit ){
    int nRet = 0;
    do{
        nRet = get_int( "%s", sTit );
        if( nRet <= 0 ){
            printf("\n");
            printf(">>>>  Número nao pode ser negativo, tente novamente !!!!!  \n\n");
        }
    }while( nRet < 0 );
    return nRet;
}


int CalcPopulation( int start, int end ){

    int nRet = 0;
    int fatVivo = 3;
    int fatMorto = 4;
    int nAux = start;
    int nPopAno;

    while ( nAux < end){

        nPopAno = round( nAux / 3 ) -  round( nAux / 4 );
        if( nPopAno == 0){
           nRet = 0;
           break;
        }
        nAux += nPopAno;
        nRet++;
    }

    return nRet;

}

