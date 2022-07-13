# Matrix calculator.

**This calculator is capable of performing various unary and binary operations with the entered matrices. 
The loaded matrices are saved in the calculator's matrix list and then the possibility of operations 
with them is provided.**

**The matrix can be loaded with a name presented as one capital letter of the English alphabet.**

**The calculator stops its work after entering the EXIT command or with 7 possible exceptions:**
- with different dimensions of the operated matrices;
- when using a non-square matrix to calculate the determinant or inversion;
- when detecting an irreversible matrix when searching for the inverse matrix;
- when entering invalid element indexes into the console or reading from a file to add an element 
or trimming the matrix;
- when the file with loaded matrix is incorrectly formatted;
- if it is impossible to open the file to load the matrix or for writing exception;
- when the input is finished (EOF).

**The file for loading the matrix from it must be formatted correctly, in the examples/ folder 
there are several examples of the correct formatting of a dense and sparse matrix.**
