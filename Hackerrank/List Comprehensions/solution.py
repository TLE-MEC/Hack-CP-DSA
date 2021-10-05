#Main function definition
if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())

#Creation of the permutations (For all possible combinations of x, y, z)
    string = "["
for x in range(x+1):
    for y in range(y+1):
        for z in range(z+1):
            if x+y+z != n:
                string += "["+str(x)+", "+str(y)+", "+str(z)+"]" + ", " #One such set of points

if len(string) > 1:                
    lent = len(string)-2                
    string = string[:lent] + "]"
else: 
    string +=  "]"

#Finally displaying the permutations list
print(string)
