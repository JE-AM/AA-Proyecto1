# Magic Squares Generator

## Description
GTK application that generates magic squares of odd order (3-21) using different filling algorithms. A magic square is a grid filled with distinct positive integers such that the sum of each row, column, and diagonal is the same.

## Features
- **4 generation methods:**
  - Up-Right (traditional method)
  - Down-Left (variant method)
  - L-Shaped Movement (like chess knight)
  - Diagonal Movement
- **Functionalities:**
  - Step-by-step number placement visualization
  - Automatic completion of the square
  - Real-time display of partial sums
  - Input validation (odd numbers 3-21)
  - Visual grid interface with GTK+
  - Memory-safe design with proper cleanup

## Requirements
- Linux system with GTK+ 3.0
- GCC compiler
- GTK development libraries

## Installation
```bash
# Install dependencies on Ubuntu/Debian:
sudo apt update
sudo apt install libgtk-3-dev build-essential

# For other distributions, install equivalent packages
```

## Compilation and Execution
```bash
# Compile the project
make

# Run the application
./magic_square

# Clean build files
make clean
```

## How to Use
1. Select the order of the square (3, 5, 7, ..., 21)
2. Choose the generation method from the dropdown
3. Press "Iniciar" (Start) to begin
4. Use "Paso" (Step) to place numbers one by one
5. Or "Completar" (Complete) to finish automatically
6. "Reiniciar" (Reset) to start over with new parameters

## Algorithms Explanation

### Up-Right Method (Traditional)
- Starts at the top row, middle column
- Moves up-right for each next number
- When blocked, moves down from previous position

### Down-Left Method
- Starts at the bottom row, middle column
- Moves down-left for each next number
- When blocked, moves up from previous position

### L-Shaped Method
- Uses knight's move pattern (2 up, 1 left)
- Starts at first row, second column
- When blocked, moves down from previous position

### Diagonal Method
- Moves diagonally up-left
- Starts at middle row, first column
- When blocked, moves down from previous position

## Project Structure
- `proyecto1.h` - Header file with definitions and prototypes
- `proyecto1.c` - Main implementation with algorithms and GUI
- `magic_square.glade` - GTK interface design file
- `Makefile` - Build configuration
- `README.md` - This documentation

## Notes
- The application includes comprehensive Spanish comments in the code
- Memory management has been carefully implemented to prevent leaks
- The GUI is designed to be intuitive and educational
- All algorithms generate mathematically correct magic squares