
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCO = 512;

int main(int argc, char *argv[])
{
    // verificar o argumento
    if (argc != 2)
    {
        printf("Uso: ./recuperar imagem");
        return 1;
    }

    // Abrir o arquivo de entrada
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Não foi possível abrir %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCO];
    char *recuperar  = malloc(8);
    int c = 0;
    FILE *img;

    // ler os BLOCOS de 512 bytes
    while (fread(&buffer, 1, BLOCO, file))
    {
        // verificar se é um jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(recuperar, "%03i.jpg", c);

            // criar um arquivo e escrever nele
            img = fopen(recuperar, "w");
            fwrite(buffer, 1, BLOCO, img);
            c++;
        }
        else
        {
            if (c > 0)
            {
                fwrite(buffer, 1, BLOCO, img);
            }
        }

    }

    // fechar os arquivos
    fclose(img);
    free(recuperar);
    fclose(file);

    return 0;

}