
#create an empty set
s = set()
print ('Empty set:', s)

#create a non empty set
s = set([0, 1, 5, 2, 4, 5])
print ('Non empty set:', s, '. Note that set has removed duplicated values, '
                            'and sort values in ascending order.')

#deep copy
cs = s.copy()
print ('deep copy:', cs)

#remove the smallest value
s.pop()
print ('after pop: ', s)


#remove a specific value. In case value not in set, return error.
s.remove(4)
print ('after remove: ', s)

#clear
s.clear()
print ('after clear: s = ', s, 'cs = ', cs)
s = cs.copy()


#intersection
t = set([6, 5, 7])
print ("intersection between s and t: ", s.intersection(t))

#union
print ("union between s and t: ", s.union(t))
