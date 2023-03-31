#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("tem q da argumento bobao\n");
        return 1;
    }

    char *card= argv[1];
    FILE *file= fopen(card, "r");

    BYTE *buffer = malloc(512 * sizeof(BYTE));
    //loop pra achar o primeiro endereço com foto
    while(!((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && (buffer[3] >= 0xe0 && buffer[3] <= 0xef)))
    {
        fread(buffer, sizeof(BYTE), 512, file);
    }

    //loop q se basea no retorno do fread
    for(int check= 1, count_image= 0 ; check; count_image++)
    {
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            char *name= malloc(8);
            sprintf(name, "%.3i.jpg", count_image);
            FILE *image= fopen(name, "w");

            do
            {
                fwrite(buffer, sizeof(BYTE), 512, image);
                check= fread(buffer, sizeof(BYTE), 512, file);
                if (!check) break;
            }
            while(!((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) && (buffer[3] >= 0xe0 && buffer[3] <= 0xef)));

            free(name);
            fclose(image);
        }
        else
        {
            check= fread(buffer, sizeof(BYTE), 512, file);
        }
    }
    free(buffer);
}