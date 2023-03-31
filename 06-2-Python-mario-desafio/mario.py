from cs50 import get_int

def man():
    #numero = int(input("Height: "))
    x = digita()
    printarvore(x)


def printarvore(nr):

    numero = (nr * 2 ) + 1
    for n in range(1, nr + 1):
        for x in range(1, numero+1):
            if( x < ( nr + 1 - n )):
                print(" ", end="")
            elif( x == nr + 1 ):
                print("  ", end="")
            else:
                if( x <= nr + 1 + n):
                    print("#", end="")
        print()


def digita():
   while True:
       numero = get_int("Height: ")
       if( numero > 0 and numero < 9):
           return numero

man()
