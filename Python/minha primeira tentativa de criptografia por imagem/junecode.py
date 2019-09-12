import cv2
import numpy

img = cv2.imread(input("Escolha um arquivo:"))
# print(img.shape)
# print(img)
# Reformat the H, W, C format into H*W, C format
data = img.reshape(-1, img.shape[2])
# print(data.shape)
# print(data)

# define your replacements
crypto = [
	[[  0,   0, 255], "a"],
	[[255,   0,   0], "b"],
	[[  0, 255,   0], "c"],
	[[128,   0, 128], "d"],
	[[128, 128,   0], "e"],
	[[  0, 128, 128], "f"],
	[[ 51, 102, 102], "g"],
	[[102,  51, 102], "h"],
	[[102, 102,  51], "i"],
	[[153,  51, 153], "j"],
	[[ 51, 153, 153], "k"],
	[[153, 153,  51], "l"],
	[[ 51, 204, 204], "m"],
	[[204,  51, 204], "n"],
	[[  0,   0,   0], "o"],
	[[204, 204,  51], "p"],
	[[  0,  64,   0], "q"],
	[[ 51, 255, 255], "r"],
	[[255,  51, 255], "s"],
	[[255, 255,  51], "t"],
	[[102, 255, 255], "u"],
	[[255, 102, 255], "v"],
	[[255, 255, 102], "w"],
	[[255, 204, 255], "x"],
	[[255, 255, 204], "y"],
	[[204, 255, 255], "z"],
	[[255, 255, 255], " "]
]

output = ""

for pixel in data:
	for mapping in crypto:
		# use the .all() to check that all values match
		# https://stackoverflow.com/questions/10580676/comparing-two-numpy-arrays-for-equality-element-wise
		if (pixel == mapping[0]).all():
			output += mapping[1]
			break

print(output)
