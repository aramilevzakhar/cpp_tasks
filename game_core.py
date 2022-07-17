from threading import Thread
from functools import partial
from random import choice, randint
import time
import keyboard

side_part = '#'

class SnakePart:
	def __init__(self, x: int, y: int, next_part):
		self.next_part = next_part
		self.x = x
		self.y = y
		self.next_x = self.next_part.x
		self.next_y = self.next_part.y

	def move_to_next(self):
		self.x = self.next_x
		self.y = self.next_y
		self.next_x = self.next_part.x
		self.next_y = self.next_part.y


class Snake:
	def __init__(self, x: int, y: int, length: int, direction: str):
		self.x = x
		self.y = y
		# последнее направление движения
		self.last_direction = direction
		# голова
		self.part = '▶'
		# тело змейки
		x_diff, y_diff = self.__get_xy_diff()
		self.body = [SnakePart(self.x+x_diff, self.y+y_diff, self)]
		self.move = True
		# содержимое экрана для вывода
		self.screen_data = ''

		for _ in range(1, length):
			self.add_part()

		# for key in 'wasd':
		# 	keyboard.add_hotkey(key, callback=partial(self.change_direction, key))
		# Thread(target=keyboard.wait).start()
		Thread(target=self.__move).start()

	# узнать с какой стороны добавлять часть тела змейки
	def __get_xy_diff(self):
		x_diff, y_diff = 0, 0
		if self.last_direction == 'w': y_diff = 1
		if self.last_direction == 'a': x_diff = 1
		if self.last_direction == 's': y_diff = -1
		if self.last_direction == 'd': x_diff = -1
		return x_diff, y_diff

	def add_part(self):
		last_part = self.body[-1]
		x_diff, y_diff = self.__get_xy_diff()
		self.body.append(SnakePart(last_part.x + x_diff, last_part.y + y_diff, last_part))

	def change_direction(self, key: str):
		# при попытке движения в резко противоположном направлении направление не меняется
		if (self.last_direction == 'w' and key == 's' 
			or self.last_direction == 's' and key == 'w'
			or self.last_direction == 'a' and key == 'd'
			or self.last_direction == 'd' and key == 'a'
			):
			return
		self.last_direction = key

	def __move(self):
		while self.move:
			if self.last_direction == 'w':
				self.y -= 1
				self.part = '▲'
			if self.last_direction == 'a':
				self.x -= 1
				self.part = '◀'
			if self.last_direction == 's':
				self.y += 1
				self.part = '▼'
			if self.last_direction == 'd':
				self.x += 1
				self.part = '▶'
			for part in self.body:
				part.move_to_next()
			time.sleep(0.15 if self.last_direction in ('a', 'd') else 0.20)
		

class Game:
	def __init__(self, width, height, snakes):
		self.snakes = snakes
		self.do_update = True
		self.width = width
		self.height = height
		self.apple_index = -1
		Thread(target=self.update_screen).start()

	def update_screen(self):
		global screen_data

		while self.do_update:
			self.screen = [' ' for x in range(self.width * self.height)]

			for x in range(self.width):
				for y in range(self.height):

					# отрисовка поля
					if x % self.width == 0:
						self.screen[x + y * self.width] = '\n'
					elif (y == 0 or y == self.height-1) or (x == 1 or x == self.width-1):
						self.screen[x + y * self.width] = side_part

					for snake in self.snakes:
						# смена координат змейки при столкновении со стеной
						if y == self.height-1 and snake.y == y:
							snake.y = 1
						if y == 0 and snake.y == y:
							snake.y = self.height-2

						if x == self.width-1 and snake.x == x:
							snake.x = 2
						if x == 1 and snake.x == x:
							snake.x = self.width-3

						# отрисовка змейки
						if x == snake.x and y == snake.y:
							self.screen[x + y * self.width] = snake.part
							for snake_part in snake.body:
								self.screen[snake_part.x + snake_part.y * self.width] = '+'

						# если змейка наткнулась на яблоко
						if snake.x + snake.y * self.width == self.apple_index:
							self.screen[self.apple_index] = ' '
							self.apple_index = -1
							snake.add_part()


			# если змейка врезалась в себя или другую змейку
			for snake in self.snakes:
				for another_snake in self.snakes:
					for another_snake_part in another_snake.body:
						if snake.x == another_snake_part.x and snake.y == another_snake_part.y:
							snake.move = self.do_update = False

			# генерация яблока
			if self.apple_index == -1:
				self.apple_index = choice([x for x in range(len(self.screen)) if self.screen[x] == ' '])
			self.screen[self.apple_index] = '◯'

			# print(f"\x1B[{self.height+1}A{''.join(self.screen)}")
			self.screen_data = f"\x1B[{self.height+1}A{''.join(self.screen)}"
			time.sleep(0.01)

#game = Game(50, 20)