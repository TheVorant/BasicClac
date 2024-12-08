# Rudimentary GUI Calculator

## Overview

This project implements a graphical user interface (GUI) calculator for performing basic arithmetic operations. The calculator features a simple layout with a clickable button interface for entering numbers and operations. It utilizes custom graphics routines from a library to create a visually appealing and functional calculator interface.

## Features

- **Basic Operations**: Supports addition, subtraction, multiplication, and division.
- **Interactive GUI**:
  - Clickable buttons for numbers (0-9) and operators (+, -, ×, ÷).
  - Clear (C) button to reset the calculator.
  - Equals (=) button to display the result.
- **Continuous Calculations**: Allows chaining operations without restarting.
- **Real-time Updates**: Displays inputs and results dynamically on the calculator screen.

## File Structure

### Key Files

- **`RudCalc.cpp`**: Main program file containing the logic for the calculator.
- **`library.h`**: Custom graphics library providing utilities for drawing and user interaction.
- **`sample.pdf`**: Contains expected outputs of the calculator's operations.

## Implementation Details

### Button Layout

The calculator interface is organized into a 4x4 grid:

| Button | Button | Button | Button |
|--------|--------|--------|--------|
| 7      | 8      | 9      | +      |
| 4      | 5      | 6      | -      |
| 1      | 2      | 3      | ×     |
| C      | 0      | =      | ÷     |

### Functions in `RudCalc.cpp`

#### `draw_calc()`
- Draws the calculator interface, including buttons and labels.
- Utilizes loops to position buttons dynamically.

#### `num_grabber()`
- Detects button clicks for numeric input.
- Returns the number formed by consecutive button presses.

#### `calc(double results)`
- Handles arithmetic operations based on user input.
- Tracks intermediate results for continuous calculations.
- Supports clearing the screen and restarting the calculation.

#### `main()`
- Initializes the graphical window.
- Calls `draw_calc()` to render the calculator interface.
- Starts the calculator logic with `calc(0)`.

## Setup and Execution

1. **Compile the Program**:
   ```bash
   g++ -o RudCalc RudCalc.cpp
   ```

2. **Run the Program**:
   ```bash
   ./RudCalc
   ```

The program opens a 300x400 graphical window displaying the calculator interface.

## Example Usage

1. **Perform Addition**:
   - Click `7`, `+`, `3`, `=`.
   - The result `10` is displayed on the screen.

2. **Clear and Restart**:
   - Click `C` to reset the calculator.

3. **Chained Calculations**:
   - Click `5`, `+`, `2`, `×`, `3`, `=`.
   - The result `21` is displayed.

## Contributions

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature-branch
   ```
3. Commit changes:
   ```bash
   git commit -m "Add new feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature-branch
   ```
5. Create a pull request.


---

Explore the calculator, suggest improvements, or create new features. Happy coding!

