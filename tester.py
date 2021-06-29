# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: copihendo <copihendo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 10:35:58 by telron            #+#    #+#              #
#    Updated: 2021/06/18 22:35:05 by copihendo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import itertools
import subprocess
from termcolor import colored
from sklearn.utils import shuffle
import numpy as np

path_generator = "./push_swap"
path_checkers = "./checker_linux"

def put_statistic(array, end = "\n"):
	std = round(np.std(array), 2)
	mean = round(np.mean(array), 2)
	min = np.min(array)
	max = np.max(array)
	print(f"\tMean: {colored(mean, 'yellow')} Std: {colored(std, 'yellow')} Min: {colored(min, 'yellow')} Max: {colored(max, 'yellow')}", end=end)

def get_count_moves(argums):
	command = f"{path_generator} {argums} | wc -l"
	output = subprocess.run(command, capture_output=True, shell=True)
	count_moves = int(output.stdout.decode().strip())
	return (count_moves)

def get_correctness(argums):
	command = f"{path_generator} {argums} | {path_checkers} {argums}"
	output = subprocess.run(command, capture_output=True, shell=True)
	return (output.stdout.decode().strip() == "OK")

def check_all_comb(shape, need_count):
	print(f"Check all {colored(shape, 'yellow')} number combination:")
	result = []
	counter_all, counter_false = 0, 0
	for comb in itertools.permutations(range(1, 1 + shape), shape):
		counter_all += 1
		argums = " ".join(map(str, comb))
		count_moves = get_count_moves(argums)
		correctness = get_correctness(argums)
		if (count_moves > need_count or not correctness):
			counter_false += 1
			print(f"{argums} comb", f"Correctness: {correctness}", f"Count_moves: {count_moves}", sep="\n\t", end="\n\n")
		result.append(count_moves)
	put_statistic(result)
	total = colored("All right!", "green") if not counter_false else colored("There is a problem", "red")
	print(f"\t{total} result -> {str(counter_all - counter_false)}/{str(counter_all)}", end="\n\n")

def	check_comb_statistic(shape, iter):
	print(f"Check combination {colored(shape, 'yellow')} statistic:")
	result = []
	for _ in range(iter):
		comb = shuffle(range(1, 1 + shape))
		argums = " ".join(map(str, comb))
		count_moves = get_count_moves(argums)
		correctness = get_correctness(argums)
		if not correctness:
			print(colored("Alarm! not correct combination", "red"), argums)
			return
		result.append(count_moves)
	put_statistic(result, end="\n\n")

check_all_comb(3, 3)
check_all_comb(5, 12)
# check_comb_statistic(100, 100)
# check_comb_statistic(500, 100)