 #**********************************************************************
 #* Ejercicio: Dancing sentence                                        *
 #* Url: https://www.urionlinejudge.com.br/judge/es/problems/view/1234 *
 #* Lenguaje: Python 3.9                                               *
 #* Autor: Jhoser Pacheco                                              *
 #*********************************************************************/

# All spaces in the original sentence must be preserved, ie, " sentence " must be converted in " SeNtEnCe ".
# Python 3.9

while True:
    try:
    #read input 
        string = input()
        st = "" 
        b = True
        # If there is a space, ignore it
        for i in string:
        	if (i ==' '):
        		st+=' '
        		continue       
             #Interleaving upper and lower case in the elifs   
        	elif b:
                #Change from lowercase to uppercase if necessary
        		st += i.upper() 
        		b = False 
           
        	elif (not b):
        		st+= i.lower()
        		b = True
        	
        print(st)
        #print string
    except EOFError:
        break
        #end