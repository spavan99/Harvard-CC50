import csv

from cs50 import get_string
from sys import argv


def man():

    dnaPesquisa = {}
    dnaBanco = {}
    dnaChave = -1
    nomeDNA = "-1"

    if len(argv) < 3:
        print(f"Numero de paramento invalido , {len(argv)-1}")
        return 1

    montaBancoDNA( dnaPesquisa, dnaBanco, argv[1])

    dnaChave = retDNA( argv[2], dnaPesquisa )

    if dnaChave in dnaBanco:
        print(dnaBanco.get(dnaChave))
    else:
        print("No match.")


    print( dnaChave)
    #print("lista dna-----------------------------")
    #for i in dnaPesquisa.keys():
    #    print( i)


    #print("banco-----------------------------")
    #for i in dnaBanco.keys():
    #    print( i)


    return 0


def retDNA( arq, vetDNA):
    # pegar dados TXY
    with open( arq, "r") as dados:
        texto = dados.read()

        nLoop = len(texto)
        for dna in vetDNA.keys():
            #print(f"dna     1 looop    {dna}")

            nFinal = len(dna)
            ativo = False
            nrCont = 0

            for i in range(0, nLoop):
                nSeq = texto[ i : i+nFinal]
                #print(f"2 looop  i = {i}   nFinal  {nFinal}   DNA>>>>>  {nSeq}    pesquis  {dna} ")

                if( nSeq == dna):
                    ativo = True
                    nrCont = nrCont + 1
                    #vetDNA[dna]+=1
                    #print(f" chave {dna}     vezes  {vetDNA[dna]} ")
                    #print(f"{i}  {contador} {vetDNA[dna]} pulou -----------------------------------------------------------------------------------------------------------------")
                    i =  i+nFinal
                else:
                    #nrCont = 0
                    ativo = False


                # alimenta maior valor
                if( ativo):
                    print("sequenccccc@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
                    print( nrCont)
                    if( nrCont > vetDNA[dna]):
                        vetDNA[dna] = nrCont
                        #nrCont = 0



    # percorer a lista e retonar o numero em um string
    numero = ""
    for dna in vetDNA.values():
        numero = numero + str( dna)

    return numero



def montaBancoDNA( dnaPesq, dnaBD, arqDNA ):

    # abre o aqrquivo e verifica se não tem erro
    with open( arqDNA, "r") as dados:

       csv_reader = csv.reader(dados, delimiter=',')
       nLinha = 0

       for row in csv_reader:
            tam = len(row)
            nr = ""
            if nLinha == 0:    # reader dna a pesquisar
                for i in range(0,tam):
                    if( i > 0):
                        dnaPesq[row[i]] = 0
            else:
                for i in range(0,tam):
                    if( i > 0):
                        nr = nr + row[i]
                #adiconar dicinario
                #dnaBD[int(nr)] = row[0]   # interior chave dict
                dnaBD[nr] = row[0]         # string chave dict

            nLinha = 2

    dados.close()



# CHAMA PROGRAMA PRINCIPAL  -----------------------------------------------
man()
# ------------------------------------------------------------------------





