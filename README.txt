A couple of notes for using this program:

1) Run this program with COMPLETELY valid logical input. This means for example,
to create an order, a customer must be made. For self-serving, the customer
must first make at least one serving then proceed to make an order.
Or, if a customer is made to be assigned to a server, either the server
or customer must make a serving then make an order. This kind of logic applies
to all actions.

2) This program does not yet handle incorrect choices. For example,
if the user clicks OK but something has not been chosen,
undefined behavior will occur.

3) Invalid inputs (e.g. wrong data type) or multiple people with same name
has not been handled. Weird behavior will occur if this is done.

4) There are of course many other invalid inputs that the program will not handle.
Avoid making this incorrect inputs.

Built in by default:
-One server
-One customer not assigned to a server
-One type of scoop, one type of container, and one type of topping
-It's best to make your own customer/server then run the program.