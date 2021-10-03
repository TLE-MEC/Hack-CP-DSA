def print_full_name(first, last):
	last = last+'!'
	print('Hello', first, last,'You just delved into python.')
first = input('Enter your first name - ')
last = input('Enter your last name - ')
print_full_name(first, last)

# Need to print - 'Hello _firstname_ _lastname_! You just delved into python.'
# --> must change string value of variable 'last' to (string of 'last') + '!', 
# since, print('Hello', first, last, '! You just delved into python.') --> 'Hello first last ! You just delved into python.'
# --> and print required string
# Note: this code is written in Python 3, in Pypy2, the brackets in the 'print' function would be removed

# For eg. first = Arush, last = Mangal
# --> last = last+'!' --> last = Mangal + '!' --> last = Mangal!
# --> Now, print(Hello, first, last, 'You just delved into python.) --> 'Hello Arush Mangal! You just delved into python.'