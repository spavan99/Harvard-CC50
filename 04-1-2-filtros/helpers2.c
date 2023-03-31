#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

   for( int n =0 ; n < height; n++){
       for( int x = 0 ; x < width; x++){
           //obtem cores atual
           float fRed    = image[n][x].rgbtRed;
           float fGreen  = image[n][x].rgbtGreen;
           float fBlue   = image[n][x].rgbtBlue;
           //media
           float fMedia =  round((( fRed + fGreen + fBlue) / 3));
           // RGB igual a media gerar tons de cinza
           image[n][x].rgbtRed  = fMedia;
           image[n][x].rgbtGreen = fMedia;
           image[n][x].rgbtBlue = fMedia;
       }
   }


}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{


   for( int n =0 ; n < height; n++){

       for( int x = 0 ; x < width /2 ; x++){
           RGBTRIPLE nIMGini = image[n][x];
           int xAux = (width - x - 1);
           image[n][x] = image[n][xAux];
           image[n][xAux] = nIMGini;
       }

   }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

       // DUPLICA IMAGREM
       RGBTRIPLE iNew[height][width];

       for( int n =0 ; n < height; n++){
           for( int x = 0 ; x < width; x++){
               iNew[n][x] = image[n][x];
           }
        }

        // alterar a imagem

        for( int n = 0;  n < height;  n++){

            for( int x = 0; x < width;  x++){

                float nRed =0, nGreen =0, nBlue =0;
                int nMedia = 0;

                for( int xLin = -1;  xLin < 2;  xLin++){

                    for( int xCol = -1;  xCol < 2; xCol++){

                        int lin = (n + xLin);
                        int col = (x + xCol);

                        // Verifica se o pixel está fora das linhas e colunas
                        if (! ( lin < 0 || lin >= height ||  col < 0 || col >= width)){
                             nRed+= iNew[n][x].rgbtRed;
                             nGreen+= iNew[n][x].rgbtGreen;
                             nBlue+= iNew[n][x].rgbtBlue;
                             nMedia++;
                        }
                    }
                }
                // caluclar a media e atribuir a foto
                if( nMedia > 0 ){
                    if(  nRed > 0  || nGreen > 0  || nBlue >  0 ){

                        nRed   =  round((nRed / nMedia));
                        nGreen =  round((nGreen / nMedia));
                        nBlue  =  round((nBlue / nMedia));
                        image[n][x].rgbtRed   =  nRed;
                        image[n][x].rgbtGreen =  nGreen;
                        image[n][x].rgbtBlue  =  nBlue;
                    }
                }

            }
        }

}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{


    RGBTRIPLE imagem[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imagem[i][j] = image[i][j];
        }
    }

    // Inicializa as matrizes
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // linhas
    for (int i = 0; i < height; i++)
    {
        // colunas
        for (int j = 0; j < width; j++)
        {
            float Gx_vermelho, Gx_azul, Gx_verde, Gy_vermelho, Gy_azul, Gy_verde;

            Gx_vermelho = 0;
            Gx_azul = 0;
            Gx_verde = 0;

            Gy_vermelho = 0;
            Gy_azul = 0;
            Gy_verde = 0;

            // Para cada pixel, loop vertical e horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    int d = i + k;
                    int e = j + l;

                    // Verifica se o pixel está fora das linhas e colunas
                    if (!(d < 0 || d >= height || e < 0 || e >= width))
                    {
                        Gx_vermelho = Gx_vermelho + imagem[d][e].rgbtRed * Gx[k + 1][l + 1];
                        Gx_azul = Gx_azul + imagem[d][e].rgbtBlue * Gx[k + 1][l + 1];
                        Gx_verde = Gx_verde + imagem[d][e].rgbtGreen * Gx[k + 1][l + 1];

                        Gy_vermelho = Gy_vermelho + imagem[d][e].rgbtRed * Gy[k + 1][l + 1];
                        Gy_azul = Gy_azul + imagem[d][e].rgbtBlue * Gy[k + 1][l + 1];
                        Gy_verde = Gy_verde + imagem[d][e].rgbtGreen * Gy[k + 1][l + 1];
                    }

                }
            }

            float vermelho = round(sqrt(pow(Gx_vermelho, 2) + pow(Gy_vermelho, 2)));
            float azul = round(sqrt(pow(Gx_azul, 2) + pow(Gy_azul, 2)));
            float verde = round(sqrt(pow(Gx_verde, 2) + pow(Gy_verde, 2)));

            if (vermelho > 255)
            {
                vermelho = 255;
            }
            if (azul > 255)
            {
                azul = 255;
            }
            if (verde > 255)
            {
                verde = 255;
            }

            // Atribui novos valores aos pixels
            image[i][j].rgbtRed = vermelho;
            image[i][j].rgbtBlue = azul;
            image[i][j].rgbtGreen = verde;
        }
    }
}
