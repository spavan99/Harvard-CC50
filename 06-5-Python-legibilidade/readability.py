from cs50 import get_string


def man():
    sTexto = get_string("Digite o texto:  ")
    sAnalise = chKTexto(sTexto)
    if( sAnalise < 1):
        print("Before Grade 1");
    elif( sAnalise > 16 ):
        print("Grade 16+");
    else:
        print(f"Grade {sAnalise}");



def chKTexto( sTXT ):

    nLetras = 0;
    nPalavras = 1;   # inicia com 1 porque a logica sempres traz uma palavra a menos
    nSetenca = 0;
    nTam = len(sTXT)


    #// ***************************************************************************************************
    #//  tabela ascii   -   codigo que nao sao letras usado escrita padrao latim/protugue/ingles/frances/italia
    #//  codigos como ? ! | \ () '' "  etc  estao maior compreendidos nesta fixa de numero
    #//  faixa 1  ->  33  ao 47
    #//  faixa 2  ->  58  ao 64
    #//  faixa 3  ->  91  ao 96
    #//  faixa 4  ->  123  ao 136
    #//  faixa 5  ->  145  ao 148
    #//
    #//  simbolos especificos  ! -> 33   ? -> 63   . -> 46
    #//
    #//  espaço entre as palavras -> 32
    #//
    #//**************************************************************************************************


    for i in range( nTam ):
        nAux = ord( sTXT[i] )
        #// idetifica numero de espaços em branco palavra palavra
        if( nAux == 32 ):
            if( (i+1) < nTam):
                if( ord(sTXT[i+1]) != 32 ):
                    nPalavras += 1

        #// se é letra nao pode estar nas faixa de 1 a 5  e espaco  caracteres especicos
        if((nAux >= 33 and  nAux <= 47) or (nAux >= 58 and nAux <= 64) or (nAux >= 91 and nAux <= 96) or (nAux >= 123 and nAux <= 136)
            or (nAux >= 145 and nAux <= 148) or (nAux == 33 or nAux == 63 or nAux == 46 or nAux== 32)):
            #// ver se é frase
            if ( (nAux == 33 or nAux == 63 or nAux == 46 ) ):
                nSetenca += 1
        else:
            nLetras +=1

    #//**************************************************************************
    #// formula calculo   índice = 0,0588 * L - 0,296 * S - 15,8   todos base 100
    #//                   onde  L é o número médio de letras por 100 palavras
    #//                         S é o número médio de sentenças por 100 palavras
    #//*************************************************************************

    #//---> tranformando padrao 100 palavras  e 100 sentencas
    finalSetenca = float(nSetenca) / float(nPalavras) * 100   #//S
    finalLetras =  float(nLetras) / float(nPalavras) * 100   #//L

    indice =  round( 0.0588 *  finalLetras - 0.296  *  finalSetenca - 15.8 )
    return indice;


# CHAMA PROGRAMA PRINCIPAL  -----------------------------------------------
man()
# ------------------------------------------------------------------------





