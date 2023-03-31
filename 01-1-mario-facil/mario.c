#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int main(void) {

    int nVez = -1;
    int nBr =  0;

    while( (nVez < 1) || ( nVez > 8) ){
         printf("\n");
         nVez = get_int("Infome o numero do tamano desejado (positivo de 1 a 8):  ");
         if( (nVez > 0 )  &&  ( nVez < 9) ){
             break;
         }else{
             printf("\n");
             printf( "Numero digitado fora do padrao de 1  a 8  - DIGITADO >>> %i \n", nVez);
         }
    }


     for(int i = 0; i < nVez; i++)
     {
          nBr = ( nVez - ( i + 1 ) );
          for( int n = 0; n < nVez; n++)
          {

               if( n < nBr )
               {
                    printf(" ");
               }else
               {
                   printf("#");
               }


          }
          printf("\n");

     }

}