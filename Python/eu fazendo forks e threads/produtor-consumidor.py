import threading
import time
import random

#que conveniente, um objeto de semáforo em biblioteca padrão!

semaphoroFechado = threading.Semaphore()

#o que as threads vão copiar
def funcaoProdutor():  
  global limitadorDeIteracoes #isto limita o programa a não rodar infinitamente 
  while limitadorDeIteracoes < 200:        
    criarProduto()

def funcaoConsumidor():  
  global limitadorDeIteracoes  #isto limita o programa a não rodar infinitamente 
  while limitadorDeIteracoes < 200:       
    consumir()
#----------------------------------------------------------------------------------    
def criarProduto(): #a função base do Produtor     
  global limitadorDeIteracoes  
  while True and limitadorDeIteracoes < 200:
    semaphoroFechado.acquire() # semaforo vermelho
    global contador
    if contador == itensMaximos: # se a prateleira está cheia
      semaphoroFechado.release() #semaforo verde
      time.sleep(random.random())       
      return
    else:                 
      limitadorDeIteracoes += 1 #técnicamente aqui também é uma seção crítica
      contador += 1 #incremente a seção crítica 
      print("Item produzido. Itens atuais: ", contador, " - ", limitadorDeIteracoes)
      semaphoroFechado.release() #semaforo verde     
      time.sleep(random.random())

def consumir(): # a função base do Consumidor 
  global limitadorDeIteracoes  
  while True and limitadorDeIteracoes < 200:
    semaphoroFechado.acquire() # semaforo vermelho
    global contador  
    if contador > 0:
      limitadorDeIteracoes += 1       
      contador -= 1 #decremente a seção crítica   
      print("Item consumido. Itens atuais: ", contador, " - ", limitadorDeIteracoes)
      semaphoroFechado.release() #semaforo verde     
      time.sleep(random.random())      
    else:
      semaphoroFechado.release() #semaforo verde     
      time.sleep(random.random())    
      return
      
# finge que o "main" começa aqui
contador = 0
itensMaximos = 10
limitadorDeIteracoes = 0

#cria as threads
a = threading.Thread(target = funcaoProdutor, args = ())
b = threading.Thread(target = funcaoConsumidor, args = ())
c = threading.Thread(target = funcaoProdutor, args = ())
d = threading.Thread(target = funcaoConsumidor, args = ())
e = threading.Thread(target = funcaoProdutor, args = ())
f = threading.Thread(target = funcaoConsumidor, args = ())
#começa as threads, incrívelmente similar a C
a.start()
b.start()
c.start()
d.start()
e.start()
f.start()

