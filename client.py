from threading import Thread
from functools import partial
import socket
import keyboard

nickname = input('Введите никнейм\n> ')[:25]
# IP = input('Введите IPn> ')

def get_data():
	while True:
		data = sock.recv(1024)
		print(data.decode('utf-8'))

def send_move(key):
	sock.send(bytes(key, 'utf-8'))

def register_keys():
	for key in 'wasd':
		keyboard.add_hotkey(key, callback=partial(send_move, key))
	keyboard.wait()

sock = socket.socket()
sock.connect(('192.168.1.6', 9090))
sock.send(bytes(nickname, 'utf-8'))
Thread(target=get_data).start()
Thread(target=register_keys).start()