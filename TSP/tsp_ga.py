#!/usr/bin/env python

#Jinu Jacob
# CS 385 HW4
# Genetic Algorithm for TSP using DEAP

import random, operator
import time
import itertools
import numpy
import math
from deap import algorithms, base, creator, tools

random.seed(time.time())

def readDistances(fileName):
	distances = []
	f = open(fileName, 'r')
	next(f)
	next(f)

	words = []
	for line in f:
		lineSplit = line.split()
		for l in range(len(lineSplit)):
			words.append(int(lineSplit[l]))

	k = 0
	for i in range(30):
		distances.append([])
		for j in range(30):
			distances[i].append(words[k])
			k += 1
	return distances	
			 

def exact_TSP(cities):
    "Generate all possible tours of the cities and choose the shortest one."
    return shortest(alltours(cities))

def shortest(tours):
    "Return the tour with the minimum total distance."
    return min(tours, key=total_distance)

alltours = itertools.permutations # The permutation function is already defined in the itertools module
numbersList = range(30)
cities = set(numbersList)
distances = readDistances("30cities.txt")

def total_distance(tour):
	"The total distance between each pair of consecutive cities in the tour."
	return sum(distance(tour[i], tour[i-1]) 
             for i in range(len(tour)))

def distance(a, b):
	return distances[a][b]

def all_non_redundant_tours(cities):
    "Return a list of tours, each a permutation of cities, but each one starting with the same city."
    start = first(cities)
    return [[start] + list(tour)
            for tour in itertools.permutations(cities - {start})]

def first(collection):
    "Start iterating over collection, and return the first element."
    for x in collection: return x

def exact_non_redundant_TSP(cities):
    "Generate all possible tours of the cities and choose the shortest one."
    return shortest(all_non_redundant_tours(cities))


toolbox = base.Toolbox()

creator.create("FitnessMin", base.Fitness, weights=(-1.0,))
creator.create("Individual", list, fitness=creator.FitnessMin)

toolbox.register("indices", numpy.random.permutation, len(cities))
toolbox.register("individual", tools.initIterate, creator.Individual, toolbox.indices)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

toolbox.register("mate", tools.cxOrdered)
toolbox.register("mutate", tools.mutShuffleIndexes, indpb=0.05)

def create_tour(individual):
	return [list(cities)[e] for e in individual]

def evaluation(individual):
    '''Evaluates an individual by converting it into 
    a list of cities and passing that list to total_distance'''
    return (total_distance(create_tour(individual)),)

toolbox.register("evaluate", evaluation)

toolbox.register("select", tools.selTournament, tournsize=3)

pop = toolbox.population(n=100)

result,log =  algorithms.eaSimple(pop, toolbox, cxpb=0.8, mutpb=0.2, ngen=400, verbose=False)

best_individual = tools.selBest(result, k=1)[0]
print('Fitness of the best individual: ', evaluation(best_individual)[0])
print best_individual



