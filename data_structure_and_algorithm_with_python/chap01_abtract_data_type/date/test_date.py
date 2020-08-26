from date import Date


def main():
    born_before = Date(9, 25, 1990)

    date = prompt_and_extract_date()
    while date is not None:
        if date <= born_before:
            print ("Is at least 30 years of age: ", date)
            date = prompt_and_extract_date()




def prompt_and_extract_date():
    print ("Enter a birth date.")
    month = int(input("month (0 to quit): "))
    if month == 0: return None
    else:
        day = int(input("day: "))
        year = int(input("year: "))
        return Date(month, day, year)

#call the main routine
main()