#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int EncriptyTXT( string txt, int nK);

int main( int argv, string argc[]) {

   int nRet = 0;

   if( argv== 2){

       int nTam = strlen(argc[1]);
//       int nr = "";
//       int nr2 = "";
       int k = 0;
       string sTXT = "";
       bool bTeste = false;


       if( isdigit( argc[1][0])   )  {
           if( nTam == 1 ){
               if(  (int)argc[1][0] >= 48 && (int)argc[1][0] <= 57 ){
                    k = (int)argc[1][0];
               }
           }else{
               if( ( (int)argc[1][0] >= 48 && (int)argc[1][0] <= 57 ) && ( (int)argc[1][1] >= 48 && (int)argc[1][1] <= 57 )  ){
                    k = (int)argc[1][1];
               }
           }

       }

       k = atoi(argc[1]);

       if( (k >= 0)  && (k < 26) ){

           nRet = 0;
           printf("\n");

         //  if ( k ==0 ){
         //      k = get_int(" nr cripto ");
         //      printf("\n");
         //  }

           sTXT = get_string( "plaintext: ");
          // printf("\n");
           printf( "ciphertext: ");

           EncriptyTXT( sTXT, k);

       }else{
           printf( "Usage: ./caesar key\n");
           //printf( "Key fora faxia de 0 a 26  -- Key informada %i \n", k);
           nRet = 1;
       }


   }else{
      nRet = 1;
      printf( "Usage: ./caesar key\n");
      //printf( "sem arqumento");
   }

   return nRet;

}



int EncriptyTXT( string txt, int nK){

   int  nTam = 0;
   int  nrLetra = 0;
   int  nPad = 65;
   int nAux = 0;

    nTam = strlen(txt);


   for( int i = 0;  i < nTam; i++){

        nAux = (int)txt[i];
        if( ( nAux >= 33 &&  nAux <= 47) || ( nAux >= 58 &&  nAux <= 64) || ( nAux >= 91 &&  nAux <= 96) ||
              ( nAux >= 123 &&  nAux <= 136) || ( nAux >= 145 &&  nAux <= 148) ||
               (nAux == 33 || nAux == 63 || nAux == 46 || nAux== 32) )  {

             printf( "%c", txt[i]);

               // não faz nada
        }else
        {

           if (isupper(txt[i])){
               nPad = 65;
           }else{
               nPad = 97;
           }

           nrLetra = ((int) txt[i]) - nPad;
           nrLetra = nrLetra + nK;
           if( nrLetra >= 26){
               nrLetra = nrLetra - 26;
           }

           nrLetra = nrLetra + nPad;
           //printf( " LETRS  %c    NUMERO  %i ", nrLetra, nrLetra);
           printf( "%c", nrLetra);
        }
   }

   printf("\n");

    return 1;
}






