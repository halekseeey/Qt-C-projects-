# About

This project involves developing a multithreaded Qt application that interacts with a microcontroller via a serial port. The application features the following threads:

- GUI Thread: Handles the interaction with the widgets.
- Serial Port Thread: Manages communication with the serial port.
- Random Number Generation Thread: Generates random numbers every 2 seconds.

The serial port thread receives data from the port and stores it in a container. The graphical interface includes a text field to display the contents of the container, an input field, and a button for adding numbers to the container.

When the random number generation thread generates a random number, it checks if the number exists in the container. If it does, the number and its frequency of occurrence are sent through the serial port and displayed in a popup window in the graphical interface.

For testing purposes, write a program on a microcontroller or use virtual microcontroller that sends numbers through the serial port every 2 seconds and connect it to the computer running your application.

This project demonstrates the implementation of multithreading and serial communication in a Qt application to facilitate interaction with a microcontroller.
