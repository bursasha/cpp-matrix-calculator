# CMatrixCalculator 🧮

## Project Structure: 📁
- `src/`: Contains the source code files for the matrix calculator.
- `examples/`: Includes example files for loading matrices.
- `assets/`: Holds images and documentation files.
- `Makefile`: Used for building the project.
- `Doxyfile`: Configuration file for generating documentation with Doxygen.
- `DOCUMENTATION.md`: Additional documentation for the project.
- `README.md`: The main README file for the project.

## Technology Stack: 🔍
- **Language:** C++
- **Paradigm:** Object-Oriented Programming (OOP)
- **Techniques:** Polymorphism, Inheritance, Encapsulation
- **Libraries:** STL (Standard Template Library)
- **Tools:** Makefile, Doxygen
- **Concepts:** Dense and Sparse Matrices, Effective Memory Usage
- **Other:** Parsers, Various Algorithms

## What is it capable of? 🚀

### **Support for working with many matrices (as many as there are letters in the English alphabet).**

**Basic operations:**
* ➕ Addition.
* ➖ Subtraction.
* ✖️ Multiplication/multiplication by a constant.
* ✂️ Trimming/joining matrices.
* 📏 Vertical/Horizontal join of matrices.
* 📄 Loading the matrix from the formatted file.
* ✏️ Changing the entered matrix by the console or file input.
* 🖥️ Output of the matrix to the console or to the file.

**Advanced linear operations:**
* 🔄 Transposition.
* 🔁 Finding the inverse matrix.
* 🧮 Search for a determinant.
* 📉 Gaussian elimination.

## Program interface: 🖥️
* Console application.
* User and file input processing.
* Support for the above operations, also read the documentation.
* Error output depending on the problem encountered.
* To load a matrix from a file, it must be formatted as files in the `examples/` folder.

## Application of polymorphic functions: 🧬
* 2 types of matrices – dense and sparse, for efficient storage of internal elements, depending on the number of non-zero elements.
* The `getElement` function to get the desired element from the matrix, depending on its type.
* The `print` function to output the matrix to the console, depending on its type.
* The `save` function to save the matrix to a file depending on its type.

## Project Description: 📜
I created a console calculator for performing basic operations on different matrices. It will be possible to interact with the program by entering commands such as `ADD`, `SUBTRACT`, `MULTIPLY`, `TRANSPOSE`, `DETERMINANT`, and others. When starting the calculator, the user will be greeted with a welcome message and a short guide to using the program. While working with the calculator, in case of incorrect input or other issues, the program will notify the user of the exceptions that have occurred. It will also be possible to terminate the program using a specific command.

## General basic view of the program: 🏗️
![Calculator structure](/assets/class_hierarchy.png)

## Calculator documentation: 📖
![Calculator documentation](/assets/documentation.png)
