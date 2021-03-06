#!/usr/bin/env python

#Jinu Jacob
# CS 385 HW4
# Genetic Algorithm for TSP using DEAP

import random, operator
import itertools
import numpy
import math
from deap import algorithms, base, creator, tools


def readCosts(fileName):
	costs = []
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
		costs.append([])
		for j in range(30):
			costs[i].append(words[k])
			k += 1
	return costs	
			 

numbersList = range(30)
cities = set(numbersList)
costs = readCosts("30cities.txt")

# Returns the cost between all cities in a tour
def total_cost(tour):
	return sum(cost(tour[i], tour[i-1]) 
             for i in range(len(tour)))
# Returns the cost between two cities
def cost(a, b):
	return costs[a][b]

# Returns a list of cities from individual
def create_tour(individual):
	return [list(cities)[e] for e in individual]

# Returns total cost of tour to consecutive cities in individual
def evaluation(individual):
    return (total_cost(create_tour(individual)),)



toolbox = base.Toolbox()

# Objective minimizing fitness
creator.create("FitnessMin", base.Fitness, weights=(-1.0,))

# Individual of type list with FitnessMin attribute
creator.create("Individual", list, fitness=creator.FitnessMin)

toolbox.register("indices", numpy.random.permutation, len(cities))
toolbox.register("individual", tools.initIterate, creator.Individual, toolbox.indices)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

toolbox.register("mate", tools.cxOrdered)
toolbox.register("mutate", tools.mutShuffleIndexes, indpb=0.05)

toolbox.register("evaluate", evaluation)

toolbox.register("select", tools.selTournament, tournsize=3)

pop = toolbox.population(n=100)

result,log =  algorithms.eaSimple(pop, toolbox, cxpb=0.8, mutpb=0.2, ngen=400, verbose=False)

best_individual = tools.selBest(result, k=1)[0]
print ('\nOrdered Crossover, Shuffled Indices Mutation, Tournament Selection')
print ('Fitness of the best individual: ', evaluation(best_individual)[0])
print (best_individual)
print 


toolbox.register("mutate", tools.mutShuffleIndexes, indpb=0.15)
toolbox.register("select", tools.selBest)

print ('Ordered Crossover, Shuffled Indices Mutation, Best Selection')
result,log =  algorithms.eaSimple(pop, toolbox, cxpb=0.8, mutpb=0.2, ngen=400, verbose=False)
best_individual = tools.selBest(result, k=1)[0]
print ('Fitness of the best individual: ', evaluation(best_individual)[0])
print best_individual
