# Singleton

A pattern that restricts the instantiation of class to one object

In more than one way it can be implemented.
Method of implementation may be directed by design or by 'initialization requirement of the members of the singleton class'.

    1. On first use
    2. Global static

## On first use

Object will be instantiated only on first use of the singleton.

    *) if single threaded, 'on first use' needs no protection over class instantiation
    *) if multi-threaded (if singleton class will be used in multiple threads), then protection over 'on first use' instantiation is needed
    *) Exclusive (mutual) access is required to both instantiation member and to non-const members.

## global static

A static object may be created (which will be created on global static object creation), can be shared with all the requests

    *) In this approach, exclusive (mutual) protection is required only to non-const members.
