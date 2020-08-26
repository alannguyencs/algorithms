



class Date():
    def __init__(self, month, day, year):
        #assumption: month, day and year are valid
        tmp = -1 if month < 3 else 0
        self._julian_day = day - 32075 + \
                           (1461 * (year + 4800 + tmp) // 4) + \
                           (367 * (month - 2 - tmp * 12) // 12) - \
                           (3 * ((year + 4900 + tmp) // 100) // 4)

    #Extracts the appropriate Gregorian date component
    def month(self):
        return self._to_gregorian()[0]

    def day(self):
        return self._to_gregorian()[1]

    def year(self):
        return self._to_gregorian()[2]

    #Returns day of the weeks as an int between 0 (Mon) and 6 (Fri)
    def day_of_week(self):
        month, day, year = self._to_gregorian()
        if month < 3:
            month = month + 12
            year = year - 1
        return ((13 * month + 3) // 5 + day +\
                year + year // 4 - year // 100 + year // 400) % 7

    #Returns the date as a string in Gregorian format
    def __str__(self):
        month, day, year = self._to_gregorian()
        return "{:02d}/{:02d}/{:04d}".format(month, day, year)

    #Logically compares the two dates
    #In python 3, after implementing __lt__ and __le__,
    # python will automatically implement gt and ge
    def __eq__(self, other_date):
        return self._julian_day == other_date._julian_day

    def __lt__(self, other_date):
        return self._julian_day < other_date._julian_day

    def __le__(self, other_date):
        return self._julian_day <= other_date._julian_day

    #Return the Gregorian date as a tuple: (month, day, year)
    def _to_gregorian(self):
        A = self._julian_day + 68569
        B = 4 * A // 146097
        A = A - (146097 * B + 3) // 4
        year = 4000 * (A + 1) // 1461001
        A = A - (1461 * year // 4) + 31
        month = 80 * A // 2447
        day = A - (2447 * month // 80)
        A = month // 11
        month = month + 2 - (12 * A)
        year = 100 * (B - 49) + year + A
        return month, day, year




