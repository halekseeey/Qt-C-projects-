# About

This project involves creating a decorator class. The basic version of this class reads data from a file and returns it as a string. The user interface includes the following elements:

- Main Method Button: A button to invoke the main method of the decorator class. When pressed, the data is displayed in a text field.
- ComboBox: Contains a list of available wrappers.
  Add Wrapper Button: When pressed, the selected wrapper is added to the decorator class.
- Reset Button: Removes all wrappers.

## Necessary Wrappers:

- Calculates all formulas of the form <number1>+<number2> and <number1>-<number2>, replacing the formulas in the text with the result.
- Appends "(Formula <formula number>)" after each formula.
- Replaces all hexadecimal numbers (e.g., 0x1B) with decimal numbers.
- Replaces all decimal numbers with hexadecimal numbers.
- Removes all digits from the text except for 0.
- Reverses the text.

This project demonstrates the use of the decorator pattern to extend the functionality of a class dynamically.
