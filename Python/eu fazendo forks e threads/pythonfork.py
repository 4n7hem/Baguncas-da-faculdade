import os
import signal

def paiefilho():
    #faz fork na função "paiefilho"
    n = os.fork()
    #checa se a função atual é um pai ou um filho
    if n != 0:
        print("Este é o processo pai, com ID: ", os.getpid())
    else:
        print("Este é o processo filho, com ID: ", os.getpid())
        #mata o processo filho com ID = n
        os.kill(n, signal.SIGKILL)
    


paiefilho()

