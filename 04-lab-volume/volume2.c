#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

int main(int argc, char *argv[]) {

float PCM_sinal_alterado;
int HEADER_SIZE=44;
float volume = 2;
float *PCM_sinal;
long tam_audio;
short data;
FILE *fp2;
FILE *fp;
int n;


if(argc < 2) {

    printf("Usage: %s <file.wav>", argv[0]);
        exit(0);
}

fp = fopen(argv[1], "rb");

fp2 = fopen("alterado.wav", "wb");

uint8_t bytes[HEADER_SIZE];

//copiando o cabeçalho original para o novo arquivo
fread(bytes,sizeof(uint8_t),HEADER_SIZE,fp);
fwrite(bytes,sizeof(uint8_t),HEADER_SIZE,fp2);

/*
//nao vou usar nada disso agora...
printf("%c",bytes[0]);
printf("%c",bytes[1]);
printf("%c",bytes[2]);
printf("%c",bytes[3]);
*/


//voltando o ponteiro para o byte 40 (quero saber a quantidade de amostras existente no áudio)
fseek(fp,40,0);

fread(&tam_audio, 4, 1, fp);
//tamanho real tam_audio / 2

PCM_sinal = calloc(tam_audio/2, sizeof(float));

for (n = 0; n < tam_audio/2; n++)
{

        //convertendo para float point e aplicando mudança de volume
        fread(&data, 2, 1, fp);



        PCM_sinal[n] = ((float)data / 32768.0) * volume;

        //convertendo para short int novamente e escrevendo no novo arquivo
        //clippando o áudio para não extrapolar os limites
        PCM_sinal_alterado = (PCM_sinal[n] + 1.0) / 2.0 * 32768.0 * 2.0;

        if (PCM_sinal_alterado  > (2.0 * 32768.0)-1 )
        {
            PCM_sinal_alterado = (2.0 * 32768.0)-1 ;
        }
        else if (PCM_sinal_alterado  < 0.0)
        {
            PCM_sinal_alterado  = 0.0;
        }

        data = (short)(PCM_sinal_alterado  + 0.5) - 32768;



        fwrite(&data, 2, 1, fp2);
}

fclose(fp);
fclose(fp2);
free(PCM_sinal);

//puts("Feito...");
//exit(0);
}