#Implements the Bag ADT container using a Python list

class Bag:
    #construct an empty bag
    def __init__(self):
        self._items = list()

    #return the number of items in the bag
    def __len__(self):
        return len(self._items)

    #determines if an item is contained in the bag
    def __contains__(self, item):
        return item in self._items

    #add a new item to the bag
    def add(self, item):
        self._items.append(item)

    #removes and return an instance of the item from the bag
    def pop(self, item):
        assert item in self._items
        idx = self._items.index(item)
        return self._items.pop(idx)

    #returns an iterator for traversing the list of items
    def __iter__(self):
        return _BagIterator(self._items)

#In computer programming, an iterator is an object that enables
# a programmer to traverse a container, particularly lists.
#An iterator for the Bag ADT implemented as a Python list
class _BagIterator:
    def __init__(self, items):
        self._bag_items = items
        self._current_item = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self._current_item < len(self._bag_items):
            item = self._bag_items[self._current_item]
            self._current_item += 1
            return item
        else:
            raise StopIteration
