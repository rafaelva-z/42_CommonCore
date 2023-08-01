# Minitalk

A *client* program that sends a text message to the specified PID (Process ID), and a *server* program that will print its PID and wait for messages

# Communication

The communication is done between both programs using signals, the function *signal()* will define how the signal is handled and the function *kill()* will send a signal to the specified PID\

The _Linux Programmer's Manual_ says to avoid the use of the signal() function, and use *sigaction()* instead.\
Using *sigaction()* the function can also store the PID of the process that sent a signal and other information. In this project this is used to send the acknowledgement that the server recieved the message.