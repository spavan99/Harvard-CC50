from cs50 import get_int

def man():
    #numero = int(input("Height: "))
    numero = digita()
    printarvore(numero)


def printarvore(numero):
    if( numero > 0  and numero < 9):
        for n in range(1, numero + 1):
            for x in range(1, numero+1):
                if( x < ( numero +1 - n )):
                    print(" ", end="")
                else:
                    print("#", end="")
            print()


def digita():
   while True:
       numero = get_int("Height: ")
       if( numero > 0 and numero < 9):
           return numero

man()
