#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50
#include <math.h>
#include <string.h>
#include <ctype.h>



// fucntion
int ClassificaTXT( string texto);


int main(void) {


    string sTexto;
    int finalIndice = 0;
    int sTam = 0;


    sTexto = get_string( "Texto: ");
//    printf("\n");

    sTam = strlen(sTexto);

    if( sTam > 0){
       finalIndice = ClassificaTXT(sTexto);

    }else{

        printf( "Texto em Branco não possivel qualificar");
    }

    if( finalIndice < 1){
      printf("Before Grade 1\n");
    }else if( finalIndice > 16 ){
      printf("Grade 16+\n");
    }else{
      printf("Grade %i\n", finalIndice);
    }


}

int ClassificaTXT(string txt){

    int sTam = 0;
    int nLetras = 0;
    int nPalavras = 1;   // incia com 1 porque a logica sempres traz uma palavra a menos
    int nSetenca = 0;
    int nAux = 0;
    float finalLetras = 0;
    float finalSetenca = 0;
    float indice = 0;

    sTam = strlen(txt);

    // ***************************************************************************************************
    //  tabela ascii   -   codigo que nao sao letras usado escrita padrao latim/protugue/ingles/frances/italia
    //  codigos como ? ! | \ () '' "  etc  estao maior compreendidos nesta fixa de numero
    //  faixa 1  ->  33  ao 47
    //  faixa 2  ->  58  ao 64
    //  faixa 3  ->  91  ao 96
    //  faixa 4  ->  123  ao 136
    //  faixa 5  ->  145  ao 148
    //
    //  simbolos especificos  ! -> 33   ? -> 63   . -> 46
    //
    //  espaço entre as palavras -> 32
    //
    //**************************************************************************************************


    for( int i = 0;  i < sTam; i++){

        nAux = (int)txt[i];
        // idetifica numero de espaços em branco palavra palavra
        if( nAux == 32){
           if( (i > 0 ) && (i < sTam -1 )){
              // proximo for branco desconsidera
              if( i+1 < sTam ){
                 if( (int)txt[i+1] !=32  ){
                   nPalavras++;
                 }
              }
           }
        }

        // se é letra nao pode estar nas faixa de 1 a 5  e espaco  caracteres especicos
        if( ( nAux >= 33 &&  nAux <= 47) || ( nAux >= 58 &&  nAux <= 64) || ( nAux >= 91 &&  nAux <= 96) ||
              ( nAux >= 123 &&  nAux <= 136) || ( nAux >= 145 &&  nAux <= 148) ||
               (nAux == 33 || nAux == 63 || nAux == 46 || nAux== 32) )  {

               // ver se é frase
                if ( (nAux == 33 || nAux == 63 || nAux == 46 ) )  {
                   nSetenca++;
                }
        }else{
           nLetras++;
        }
   }

    //printf( "Palavras   %i   Letras %i  Setenca %i  \n", nPalavras, nLetras,  nSetenca);

    //**************************************************************************
    // formula calculo   índice = 0,0588 * L - 0,296 * S - 15,8   todos base 100
    //                   onde  L é o número médio de letras por 100 palavras
    //                         S é o número médio de sentenças por 100 palavras
    //*************************************************************************

    //---> tranformando padrao 100 palavras  e 100 sentencas
    finalSetenca =  ( (float) nSetenca / (float) nPalavras) * 100;  //S
    finalLetras = ( (float) nLetras / (float) nPalavras ) * 100;  //L

    indice =  0.0588 *  finalLetras - 0.296  *  finalSetenca - 15.8;

    indice = (int) round(indice);

    //printf( " fSentenca ->>  %f    fLetras ->>  %f    indice  >>>>>  %f", finalSetenca,  finalLetras, indice);

    return indice;

}
