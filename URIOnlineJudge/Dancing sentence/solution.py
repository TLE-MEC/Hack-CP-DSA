
# Autor: Jhoser Pacheco
# All spaces in the original sentence must be preserved, ie, " sentence " must be converted in " SeNtEnCe ".
# Python 3.9

while True:
    try:
        string = input()
        st = "" 
        b = True
        for i in string:
        	if (i ==' '):
        		st+=' '
        		continue
        	elif b:
        		st += i.upper() 
        		b = False 
        	elif (not b):
        		st+= i.lower()
        		b = True
        	
        print(st)
    except EOFError:
        break