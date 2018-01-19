Some notes about this sprint:

1) The regex usage is located in the controller_gui.cpp file.
2) The server can only see orders of their OWN customers and only if the customer made an order
that was requested. If the customer used self-serve, it has no association with that server.
A customer can always view their own order to confirm.
