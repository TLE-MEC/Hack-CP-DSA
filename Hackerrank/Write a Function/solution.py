def is_leap(year):
    leap=False
    if year%400==0:
        leap=True
    elif year%100==0:
        leap=False
    elif year%4==0:
        leap=True
    return leap

year=int(input('Enter the year - '))
is_leap(year)

# According to the conditions to check if a year is a leap year:
# --> If divisible by 4, it is a leap year
# --> But, if divisible by 100, it is not a leap year
# --> But, if divisible by 400, it is a leap year
# Must check if the year is divisible by 400 since values divisible by 400 are also divisible by 100 and 4 but the converse is not nessecarily true.

# Eg:2004. 
# --> Fails first if. 2004%400=4
# --> Fails elif. 2004%100==4
# --> Passes second elif. 2004%4==0 and returns 'True'
# --> 2004 is a leap year

# Eg:2500. 
# --> Fails first if. 2500%400=100
# --> Passes elif. 2500%100==0
# --> Doesn't run second elif.
# --> Returns 'False', 2500 is a leap year

# Eg:2400. 
# --> Passes first if. 2400%400=0
# --> Passes elif. 2400%100==0
# --> Passes second elif. 2400%4==0 and returns 'True'
# --> 2400 is a leap year

