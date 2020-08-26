from linear_bag import Bag

my_bag = Bag()
my_bag.add(1)
my_bag.add(3)
my_bag.add(2)
my_bag.add(1)
my_bag.add(6)

# while(True):
#     value = int(input("Guess a value contained in the bag: "))
#     if value in my_bag:
#         print ("Yes")
#     else:
#         print("No")

print ("before: ")
for id, value in enumerate(my_bag):
    print (id, value)

my_bag.pop(1)

print ("after: ")
for id, value in enumerate(my_bag):
    print (id, value)