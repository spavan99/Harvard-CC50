from cs50 import get_float

def man():
    troco = digita()
    moedas = voltatroco(troco)
    print(moedas)


def voltatroco(valor):

    moedas = [25, 10, 5, 1]
    troco = []
    cont = 0
    valor = valor * 100

    while (valor > 0 ):
        nrMoedas = valor // moedas[cont]
        if( nrMoedas > 0 ):
            valor = valor- ( nrMoedas * moedas[cont])
            troco.append(nrMoedas)
        else:
            troco.append(0)
        cont +=1

    return sum(troco)



def digita():
   while True:
       numero = get_float("Change owed: ")
       if( numero > 0 ):
           return numero

man()
