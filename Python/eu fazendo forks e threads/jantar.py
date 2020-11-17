import time
import threading
import random

semaforo = threading.Semaphore()

def filosofo(num, id): #o nosso filosofo
  barrigaCheia = num # um limitador de iterações
  idFilosofo = id
  garfoDireito = False #checadas para ver se o filósofo possui ambos os garfos para comer
  garfoEsquerdo = False

  while barrigaCheia > 0:
    global garfos

    time.sleep(random.random()) # eles pensam

    semaforo.acquire()
    if (garfos[idFilosofo % (numFilosofos-1)].checarSeSegurado()): #vê se ele pode pegar o garfo à esquerda
      print("Filósofo número ", idFilosofo, "segurou o garfo esquerdo.")
      garfos[idFilosofo % (numFilosofos-1)].segurado(idFilosofo) #pega garfo a esquerda
      garfoEsquerdo = True
    semaforo.release()

    time.sleep(random.random()) #vira a sua cabeça para a direita

    semaforo.acquire()
    if (garfos[(idFilosofo + 1) % (numFilosofos-1)].checarSeSegurado()): #vê se ele pode pegar o garfo à direita
      print("Filósofo número ", idFilosofo, "segurou o garfo direito.")
      garfos[(idFilosofo + 1) % (numFilosofos-1)].segurado(idFilosofo) #pega garfo a direita
      garfoDireito = True
    else: # se não pode pegar o garfo a direita, solte o da esquerda
      garfos[idFilosofo % (numFilosofos-1)].solto()
      print("Filósofo número ", idFilosofo, "soltou o esquerdo.")
    semaforo.release()

    time.sleep(random.random())
    
    if (garfoDireito and garfoEsquerdo): #se ele possui ambos os garfos, coma
      print("Filósofo número ", idFilosofo, "comeu spaghetti.")    
      barrigaCheia -= 1
      semaforo.acquire()
      garfos[idFilosofo % (numFilosofos-1)].solto()
      garfos[(idFilosofo + 1) % (numFilosofos-1)].solto()
      semaforo.release()
      print("Filósofo número ", idFilosofo, "soltou ambos os garfos.")
      garfoDireito = False
      garfoEsquerdo = False
    time.sleep(random.random()*1.2) #digere, depois olha para a esquerda

class garfo():
  def __init__(self):
    self.filosofoID = -1    
  def segurado(self,id):    
    self.filosofoID = id
  def solto(self):
    self.filosofoID = -1
  def checarSeSegurado(self):
    if self.filosofoID == -1:
      return True
    else:
      return False

numFilosofos = 5
garfos = [] #garfos de 0-4 em indice
limiteContador = 10 #cada filosofo só pode comer este tanto de vezes, para não deixar o programa infinito.
for id in range(numFilosofos): #isto cria todos os objetos de filosofo
  garfos.append(garfo())
for id in range(numFilosofos):  
  temp = threading.Thread(target= filosofo, args=(limiteContador, id))
  temp.start()
