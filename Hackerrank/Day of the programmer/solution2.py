def dayOfProgrammer(year):
    '''
    We have 3 main cases: before 1918, during 1918, after 1918.
    Before 1918 : Only 2 sub cases - Leap Year(YEAR is divisble by 4) or Non-leap Year
    At 1918: Will always be 26.09.1918
    After 1918 : 2 sub cases - Leap Year(YEAR divisible by 400 or YEAR divisible by 4 and not by 100) or Non-Leap Year
    '''
    if year < 1918:
        if year % 4 == 0:
            return "12.09." + str(year)
        else:
            return "13.09." + str(year)
    if year == 1918:
        return "26.09." + str(year)
    else:
        if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
            return "12.09." + str(year)
        else:
            return "13.09." + str(year)

print("Year 2016 :", dayOfProgrammer(2016))
print("Year 2017 :", dayOfProgrammer(2017))
print("Year 1800 :", dayOfProgrammer(1800))
print("Year 1918 :", dayOfProgrammer(1918))
