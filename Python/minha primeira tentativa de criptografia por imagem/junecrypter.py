import cv2
import numpy

contagem = 0
mensagem = list(input("Digite sua mensagem: "))
nome = input("Escolha o nome da saída: ")
mainarray = numpy.asarray(mensagem)

#counts number of characters in the message
for letraseespaco in mensagem:
	if letraseespaco in 'abcdefghijklmnopqrstuvwxyz ':
		contagem += 1

#your stuff, changed the variable name to fix better
crypto = [
	["a", [  0,   0, 255]],
	["b", [255,   0,   0]],
	["c", [  0, 255,   0]],
	["d", [128,   0, 128]],
	["e", [128, 128,   0]],
	["f", [  0, 128, 128]],
	["g", [ 51, 102, 102]],
	["h", [102,  51, 102]],
	["i", [102, 102,  51]],
	["j", [153,  51, 153]],
	["k", [ 51, 153, 153]],
	["l", [153, 153,  51]],
	["m", [ 51, 204, 204]],
	["n", [204,  51, 204]],
	["o", [  0,   0,   0]],
	["p", [204, 204,  51]],
	["q", [  0,  64,   0]],
	["r", [ 51, 255, 255]],
	["s", [255,  51, 255]],
	["t", [255, 255,  51]],
	["u", [102, 255, 255]],
	["v", [255, 102, 255]],
	["w", [255, 255, 102]],
	["x", [255, 204, 255]],
	["y", [255, 255, 204]],
	["z", [204, 255, 255]],
	[" ", [255, 255, 255]]
]

#creates a black image, resolution is 1 per number of characters
#                    H, W, C
imagem = numpy.zeros((1, contagem, 3), numpy.uint8)

#test stuff ignore this
'''imagem[:, 0:10//2] = (255,0,0)      # (B, G, R)
imagem[:, 10//2:10] = (0,255,0)'''

i = 0
for letra in mainarray:
	for mapping in crypto:
		if letra == mapping[0]:
			imagem[0][i] = mapping[1]
			i += 1
			break

#prints the output and some tests, noted cause i don't wanna create a zillion images
cv2.imwrite(nome, imagem)
print(imagem)
print("Imagem criada com sucesso.")