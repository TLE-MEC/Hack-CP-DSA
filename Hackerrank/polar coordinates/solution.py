#code to implement few methods of cmath module 
import cmath
num=complex(input())
#takes input of the form a +ib where a,b are any real numbers
print(abs(num)) #abs(num) returns absolute value or mod of complex number (a^2+b^2)^0.5
print(cmath.phase(num)) #returns phase in complex plane i.e arctan(b/a)
