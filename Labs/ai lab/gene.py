import random

def fitness(board):
    conflicts = 0
    n = len(board)
    
    for i in range(n):
        for j in range(i + 1, n):
            if board[i] == board[j]:
                conflicts += 1
            elif abs(board[i] - board[j]) == j - i:
                conflicts += 1
    return conflicts

def create_population(pop_size, n):
    return [random.sample(range(n), n) for _ in range(pop_size)]

def tournament_selection(population):
    tournament_size = 3
    selected = random.sample(population, tournament_size)
    selected.sort(key=lambda x: fitness(x))
    return selected[0]

def crossover(parent1, parent2):
    point = random.randint(1, len(parent1) - 1)
    child1 = parent1[:point] + parent2[point:]
    child2 = parent2[:point] + parent1[point:]
    return child1, child2

def mutate(board):
    idx1, idx2 = random.sample(range(len(board)), 2)
    board[idx1], board[idx2] = board[idx2], board[idx1]
    return board

def genetic_algorithm(pop_size, n, generations, mutation_rate):
    population = create_population(pop_size, n)
    
    for generation in range(generations):
        population.sort(key=lambda x: fitness(x))
        best_solution = population[0]
        
        if fitness(best_solution) == 0:
            print(f"Solution found in generation {generation}: {best_solution}")
            return best_solution
        
        new_population = population[:2]
        
        while len(new_population) < pop_size:
            parent1 = tournament_selection(population)
            parent2 = tournament_selection(population)
            
            child1, child2 = crossover(parent1, parent2)
            
            if random.random() < mutation_rate:
                child1 = mutate(child1)
            if random.random() < mutation_rate:
                child2 = mutate(child2)
            
            new_population.extend([child1, child2])
        
        population = new_population[:pop_size]
        
    return None

pop_size = 100
n = 4
generations = 1000
mutation_rate = 0.05

solution = genetic_algorithm(pop_size, n, generations, mutation_rate)

if solution:
    print("Final Solution:", solution)
else:
    print("No solution found.")
