from cs50 import get_int


def man():
    # numero do cartao de credito
    cartao = digita()
    nValido = validacartao(cartao)
    if( nValido == 0 ):
       nOperadora = chkOperadora(cartao)
       print( nOperadora)
    else:
        print( "INVALID")



#    moedas = voltatroco(troco)
#    print(moedas)


def validacartao(cartao):

    if( len(cartao)%2 == 0):
        i = 0
    else:
        i = 1

    nSoma = 0
    nAux= 0
    for nrCar in cartao:
        if((i % 2 ) == 0 ):
            nAux = ( int(nrCar) * 2 )
            for j in str(nAux):
                nSoma = nSoma + int(j)
        else:
            nSoma = nSoma + int(nrCar)
        i += 1
    return ( nSoma % 10)


def chkOperadora( nrCard ):
    nInCard = int(nrCard[0:2])
    retOp = "INVALID";
    if( (nInCard / 10) ==  4):
        retOp  = "VISA"
    elif( (nInCard == 51) or (nInCard == 52) or (nInCard == 53) or (nInCard == 54) or (nInCard == 55) ):
        retOp  = "MASTERCARD"
    elif( (nInCard == 34) or (nInCard == 37)  ):
        retOp  = "AMEX"

    return retOp


def digita():
   while True:
       numero = get_int("Number:: ")
       # verfica numero total
       if(len(str(numero)) > 6):        # == 16
           return str(numero)

# CHAMA PROGRAMA PRINCIPAL  -----------------------------------------------
man()
