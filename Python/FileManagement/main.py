from Game import Game

game = Game()

def leituraDelimitador(f, game):
    print(game)
    

filePath = "/media/a2419890/home/Data-Structures/Python/FileManagement/games.txt"
f = open(filePath, "r").readlines()
for line in f:
    reading = line.split("|")
    print(reading)
    nome, genero, plataforma, ano, classificacao, preco, midia, tamanho, produtora = reading
       
