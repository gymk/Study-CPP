# Design patterns

TO DO
## Singleton

A pattern that resticts the instantiation of class to one object

More than one it can be implemented.
Method of implementation may be directed by design or by 'initialization requirement of the members of the singleton class'.

### On first use
Object will be instantiated only on first use of the singleton.

    *) if single threaded, 'on first use' needs no protection over class instatiation
    *) if multi-threaded (if singleton class will be used in multiple threads), then protection over 'on first use' instantiation is needed
    *) Exclusive (mutual) access is required to both instantiation member and to non-const members.

### gloabl static
A static object may be created (which will be created on global static object creation), can be shared with all the requests
    
    *) In this approach, exclusive (mutual) protection is required only to non-const members.
