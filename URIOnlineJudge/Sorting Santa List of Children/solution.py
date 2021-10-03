# **********************************************************************
# * Ejercicio: Ordenando la Lista de Niños de Santa                                              *
# * Url: https://www.urionlinejudge.com.br/judge/es/problems/view/2479 *
# * Lenguaje: Python                                                   *
# * Autor: Jhoser Pacheco                                              *
# *********************************************************************/

# initialize variables
n = int(input())
posi = set()
nega = set()
total = []
# loop to n kids 
for i in range(n):
	# split input c, caracter behave + or - 
	# name, string kid name 
	c, name = input().split(" ")
	# append kid name into list
	total.append(name)
	# children who behave well
	if c == "+":
		posi.add(name)
	# children who misbehave
	else:
		nega.add(name)
# Sort the list by name
total.sort()
for i in total:
	print(i)
# print the total of children misbehave and children misbehave
print(f"Se comportaram: {len(posi)} | Nao se comportaram: {len(nega)}")

#end

	