# Abstract Data Types
**Data type** is a collection of values together with a collection of operations. It can be classified as:
 - primitive data type: provided by programming language.
    + simple data type: basic form.
    + complex data type: constructed of multiple simple ones, such as objects, strings, lists.
 - user-defined data type: constructed by users. 
 
 An **abstract data type (ADT)** is a programmer-defined
 data type that specifies a set of data values and a collection of well-defined operations (**interface**) that
 can be performed on those values. The set of operations can be grouped into 4 categories:
  - constructors: create and initialize new instances of the ADT.
  - accessors: return data contained in an instance without modifying it.
  - mutators: modify the contents of an ADT instance.
  - iterators: process individual data components sequentially.
  
 Along this chapter, an ADT example namely *Date* is presented. A *date* represents a single day in Gregorian calendar
 in which the first day starts on Nov 24, 4713 BC. Some remarkable methods from this data type 
 are *comparable* and *toString*.
 
 While *Date* provides an example of a **Simple ADT**, *Bag* will be a **Complex ADT**.  A *bag* is a simple container
 used to store collection of items. The bag container restricts access to individual items by only defining operations
 for *adding, removing, checking and traversing* over the collections of items.