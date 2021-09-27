# suing just lambdas and list comprehnsions, write code that puts names ("Last, First")(in list names) in format FIRST L.

# and adds them to a new list if the first name starts with A or B or C

names = ["Algorithm, Alice", "Binary, Bob","Compiler, Cody", "Deterministic, Danny", "Exponential, Ellie"]

shorten = lambda name: f"{name.split(', ')[1]} {name.split(', ')[0][0]}."

shortenList = [shorten(name) for name in names]

print(shortenList)

#takes a list of int L, creates a new list where min, max, odds are removed. Remianing evens are /= 2

numbers = [1,2,3,4,5,6,6,7,8]
isMin = lambda num, numbers: num == sorted(numbers)[0]
isMax = lambda num, numbers: num == sorted(numbers)[len(numbers)-1]
isOdd = lambda num: num % 2 != 0
isEven = lambda num: num % 2 == 0
divide = lambda num: num / 2

evenList = [
	divide(num) for num in numbers if 
	isEven 
	and not isMax(num, numbers) 
	and not isMin(num, numbers) 
	and not isOdd(num)
]

print(evenList)