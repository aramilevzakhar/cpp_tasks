from threading import Thread
from datetime import datetime
from game_core import Game, Snake
from random import randint, choice
import socket
import time
import os
nl = '\n'

class Player:
	def __init__(self, client, id, nick, snake):
		self.nick = nick
		self.client = client
		self.id = id
		self.snake = snake

client_count = int(input('Количество игроков\n> '))
width = 50
height = 20
os.system('cls')
players = []
game = None

print('\rОжидание игроков...'+' '*20, end='')


def send_data(player):
	while not game:
		time.sleep(1)
	while True:
		player.client.send(bytes(game.screen_data, 'utf-8'))
		time.sleep(0.01)

def get_move(player):
	while True:
		key_data = player.client.recv(1024)
		key = key_data.decode('utf-8')
		player.snake.change_direction(key)

def wait_clients():
	global players, game

	snakes = []

	for _ in range(client_count):
		conn, addr = sock.accept()
		nickname = conn.recv(1024)
		snake = Snake(randint(5, width-5), randint(5, height-5), 1, choice('wasd'))
		players.append(Player(conn, addr[1], nickname.decode('utf-8'), snake))
		snakes.append(snake)
		print(f'\rПодключено {len(players)}/{client_count}'+' '*20, end='')
	os.system('cls')


	for player in players:
		Thread(target=send_data, args=[player]).start()
		Thread(target=get_move, args=[player]).start()

	game = Game(width, height, snakes)


sock = socket.socket()
sock.bind(('192.168.1.6', 9090))
sock.listen(client_count)
Thread(target=wait_clients).start()