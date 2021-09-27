def mean(conciseL):
	"""calculate the mean value of the input concise list

	Args:
		conciseL (Dict): input consise list, displaying the frequency of
		each value

	Returns:
		float: the mean value of all values in input list
	"""
	total = 0
	count = 0
	for key in conciseL:
		value = conciseL[key]
		count += conciseL[key]
		total += value * key
	return float(total / count)

assert mean({1: 1, 2: 1, 3: 1}) == 2, "Test 1 Failed"
assert mean({3: 1, 5: 1, 7: 1}) == 5, "Test 2 Failed"
assert mean({2: 3, 4: 3, 6: 3}) == 4, "Test 3 Failed"
assert mean({-3: 2, -1: 2, 1: 2}) == -1, "Test 4 Failed"
assert mean({10: 5, 15: 5, 20: 5}) == 15, "Test 5 Failed"
print("All Tests Passed")

def median(conciseL:dict):
	"""calculate the median value of the input concise list

	Args:
			conciseL (Dict): input concise list, storing frequency of each value

	Returns:
			float: the median of all values in input list
	"""
	count = 0
	for key in conciseL.keys():
		count += conciseL[key]
	half_count = count / 2
	i = 0
	while count > half_count:
		key = list(conciseL.keys())[i]
		count -= conciseL[key]
		i += 1
	if count == half_count:
		return float((list(conciseL.keys())[i] + list(conciseL.keys())[i-1]) / 2)
	return float(list(conciseL.keys())[i-1])

assert median({1: 1, 2: 1, 3: 1}) == 2, "Test 1 Failed"
assert median({3: 1, 5: 1, 7: 1}) == 5, "Test 2 Failed"
assert median({2: 3, 4: 3, 6: 3}) == 4, "Test 3 Failed"
assert median({-3: 1, -1: 2, 1: 3}) == 0, "Test 4 Failed"
assert median({10: 2, 15: 4, 20: 6}) == 17.5, "Test 5 Failed"
print("All Tests Passed")

def moveToList(nameFreq:dict, nameList:list):
	"""move every name in input nameFreq dictionary once to nameList list.

	Args:
			nameFreq (dict): input dictionary storing frequency of names
			nameList (list): input list storing all name in input dictionary
	"""
	removeName = []
	for name in nameFreq.keys():
		nameList.append(name)
		nameFreq[name] -= 1
		if nameFreq[name] == 0:
			removeName.append(name)
	for name in removeName:
		nameFreq.pop(name)

D = {"minh":1, "wilson":2, "le":3}
L = []
moveToList(D,L)
assert D == {"wilson":1, "le":2} and L == ['minh', 'wilson', 'le'], "Test 1 failed"

D = {"a":2, "b":3, "c":4}
L = []
moveToList(D,L)
assert D == {"a":1, "b":2, "c": 3} and L == ['a', 'b', 'c'], "Test 2 failed"

D = {"d":1}
L = []
moveToList(D,L)
assert D == {} and L == ['d'], "Test 3 failed"

D = {}
L = []
moveToList(D,L)
assert D == {} and L == [], "Test 4 failed"

D = {"d": 5, "e": 7, "f": 10}
L = []
moveToList(D,L)
assert D == {"d": 4, "e": 6, "f": 9} and L == ["d", "e", "f"], "Test 4 failed"
print("All Tests Passed")

# (['Alice', 17, 'Bob', 15], 'name', 'age' )
LoL = list[list]
Attribute = list[str]
DoL = dict[str, list]
def LolToDoL(lol: LoL, attributes: Attribute):
	"""transform an input list of list and its list of keys into a dictionary of list, storing lists of the keys' values

	Args:
			lol (LoL): input list of list
			attributes (Attribute): input list that stores keys of the input list of list

	Returns:
			dol (DoL): output dictionary of list
	"""
	dol:DoL = {}
	for attribute in attributes:
		dol[attribute] = []
	for i in range(0, len(lol), 2):
		for j in range(len(attributes)):
			attribute = attributes[j]
			dol[attribute].append(lol[i+j])
	return dol

output = LolToDoL(['Alice', 17, 'Bob', 15], ['name', 'age'] )
assert output == {'name': ['Alice', 'Bob'], 'age': [17, 15]}, "Test 0 failed"

output = LolToDoL(['apple', 0.5, 'orange', 0.4], ['fruit', 'weight'] )
assert output == {'fruit': ['apple', 'orange'], 'weight': [0.5, 0.4]}, "Test 1 failed"

output = LolToDoL(['Wilson', 180, 'Le', 175], ['name', 'height'] )
assert output == {'name': ['Wilson', 'Le'], 'height': [180, 175]}, "Test 2 failed"

output = LolToDoL(['a', 3, 'b', 4], ['value', 'freq'] )
assert output == {'value': ['a', 'b'], 'freq': [3, 4]}, "Test 3 failed"

output = LolToDoL(['water', 2, 'coke', 1], ['item', 'price'] )
assert output == {'item': ['water', 'coke'], 'price': [2, 1]}, "Test 4 failed"

output = LolToDoL(['waffle', 4, 'donut', 2], ['food', 'price'] )
assert output == {'food': ['waffle', 'donut'], 'price': [4, 2]}, "Test 5 failed"

print("All Tests Passed")

def secretMessage(exampleEncoded:str, exampleDecoded:str, mysteryEncoded:str):
	"""decode the input mystery string given a pair of encode/decode example

	Args:
			exampleEncoded (str): example input encoded string
			exampleDecoded (str): example input decoded
			mysteryEncoded (str): mystery encoded string that needs decoding

	Returns:
			str: decoded mystery string
	"""
	mysteryDecoded = ""
	for char in mysteryEncoded:
		for i in range(len(exampleEncoded)):
			if exampleEncoded[i] == char:
				mysteryDecoded += exampleDecoded[i]
				break
	return mysteryDecoded

output = secretMessage("rovvyley!vnj", "hello world!", "eyej")
assert output == "wow!", "Test 0 Failed"

output = secretMessage("jnv!yelyvvor", "!dlrow olleh", "jeye")
assert output == "!wow", "Test 1 Failed"

output = secretMessage("aqbrh!", "wilson", "b!a")
assert output == "lnw", "Test 2 Failed"

output = secretMessage("qtzv4", "minh!", "qtz4")
assert output == "min!", "Test 3 Failed"

output = secretMessage("", "", "")
assert output == "", "Test 4 Failed"

output = secretMessage("hello world!", "hello world!", "hello")
assert output == "hello", "Test 5 Failed"

print("All Tests Passed")

DoL = dict[str, list]
LoD = list[dict]
def removeFromDoL(dol:DoL, element):
	"""remove a row that contains input element from an input dictionary of list

	Args:
			dol (DoL): input dictionary of list
			element: element to be removed from dict
	"""
	firstKey = list(dol.keys())[0]
	removeIndex = []
	for i in range(len(dol[firstKey])):
		for key in dol.keys():
			value = dol[key][i]
			if element == value:
				removeIndex.append(i)
	for i in removeIndex:
		for key in dol.keys():
			dol[key].pop(i)

D = {"name": ["wilson", "le", "minh"], "age": [18, 19, 20]}
removeFromDoL(D, "wilson")
assert D == {'name': ['le', 'minh'], 'age': [19, 20]}, "Test 1 Failed"

D = {"fruit": ["apple", "orrage", "mango"], "price": [1, 2, 3]}
removeFromDoL(D, 1)
assert D == {'fruit': ['orrage', 'mango'], 'price': [2, 3]}, "Test 2 Failed"

D = {"food": ["pie", "chocolate", "candy"], "calorie": [400, 100, 25]}
removeFromDoL(D, "chocolate")
assert D == {'food': ['pie', 'candy'], 'calorie': [400, 25]}, "Test 3 Failed"

D = {"vehicle": ["plane", "car", "train"], "mass": [10000, 2000, 15000]}
removeFromDoL(D, "plane")
assert D == {'vehicle': ['car', 'train'], 'mass': [2000, 15000]}, "Test 4 Failed"

D = {"city": ["Chicago", "New York", "San Francisco"], "population": [2700000, 19000000, 800000]}
removeFromDoL(D, "Chicago")
assert D == {'city': ['New York', 'San Francisco'], 'population': [19000000, 800000]}, "Test 5 Failed"
print("All Tests Passed")