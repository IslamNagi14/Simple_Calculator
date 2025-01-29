<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Calculator Project</title>
</head>
<body>

<h1>Simple Calculator Project</h1>

<h3>Overview</h3>
<p>This project implements a simple calculator using <strong>AVR microcontroller</strong> and the <strong>C programming language</strong>. The calculator performs basic arithmetic operations: addition, subtraction, multiplication, and division. Input is received from a keypad, and the results are displayed on an LCD.</p>
<p>Additionally, the project includes a simulation in <strong>Proteus</strong> to visualize the circuit and test the functionality before physical implementation.</p>

<h3>Features</h3>
<ul>
    <li><strong>Addition</strong>: Calculate the sum of two numbers.</li>
    <li><strong>Subtraction</strong>: Subtract one number from another.</li>
    <li><strong>Multiplication</strong>: Multiply two numbers.</li>
    <li><strong>Division</strong>: Divide one number by another, with error handling for division by zero.</li>
    <li><strong>Clear Function</strong>: Clear the current input for fresh calculations.</li>
</ul>

<h3>Components</h3>
<ul>
    <li><strong>AVR Microcontroller</strong>: The heart of the project. This program is designed for <strong>ATmega32</strong>, but can be adapted for other AVR microcontrollers.</li>
    <li><strong>Keypad</strong>: A 4x4 matrix keypad for input.</li>
    <li><strong>16x2 LCD</strong>: Displays the input numbers, operator, and the result in <strong>8-bit mode</strong>.</li>
    <li><strong>Power Supply</strong>: 5V power supply to drive the microcontroller and the peripherals.</li>
</ul>

<h3>Schematic</h3>
<p>The project requires proper wiring of the following components:</p>
<ul>
    <li>The <strong>keypad</strong> is connected to specific PORT pins on the AVR for user input.</li>
    <li>The <strong>LCD</strong> is interfaced with the microcontroller using <strong>8-bit mode</strong> for display.</li>
</ul>

<hr>

<h2>Circuit Design</h2>
<ul>
    <li><strong>Keypad</strong>: Connect the 4x4 matrix keypad to specific GPIO pins of the AVR.</li>
    <li><strong>LCD</strong>: Connect the 16x2 LCD to AVR using <strong>8-bit mode</strong>. Use the appropriate PORT pins for RS, RW, E, and the 8 data lines (D0–D7).</li>
    <li><strong>Power Supply</strong>: Ensure a regulated 5V power supply to drive the AVR and peripherals.</li>
</ul>

<hr>

<h2>Code Structure</h2>
<ul>
    <li><strong>calculator.c</strong>: Contains the main logic of the calculator, handling inputs from the keypad and displaying results on the LCD.</li>
    <li><strong>keypad.c</strong>: Provides functions to handle input from the 4x4 matrix keypad.</li>
    <li><strong>lcd.c</strong>: Handles communication with the 16x2 LCD in <strong>8-bit mode</strong>, displaying input and results.</li>
    <li><strong>utils.c</strong>: Includes utility functions such as delay, clearing inputs, and error handling for division by zero.</li>
</ul>

<hr>

<h2>Simulation in Proteus</h2>
<p>This project is accompanied by a <strong>Proteus simulation</strong> to help you visualize the circuit and test the functionality of the calculator. The Proteus file (.pdsprj) contains:</p>
<ul>
    <li><strong>Microcontroller Setup</strong>: ATmega32 configured with the required connections.</li>
    <li><strong>Keypad & LCD</strong>: Simulated 4x4 keypad and 16x2 LCD to interact with the program.</li>
    <li><strong>Power Supply</strong>: A simulated 5V supply powering the circuit.</li>
</ul>
<p>You can use this simulation to ensure your connections are correct and to verify the logic of your code before transferring it to actual hardware.</p>

<hr>

<h2>Contact</h2>
<p>For questions, suggestions, or contributions, feel free to reach out:</p>
<ul>
    <li><strong>Author</strong>: I.M. Nagi</li>
    <li><strong>Email</strong>: eslamnagi144@gmail.com</li>
</ul>

</body>
</html>
