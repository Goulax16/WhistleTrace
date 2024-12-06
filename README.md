# WhistleTrace

WhistleTrace is a simple and extensible logging library that allows efficient management of log levels and contexts. With WhistleTrace, you can customize the color of log messages and control the flow of your application through various severity levels.

## Features

- **Context Levels**: Supports Context to print a log with another information by using the predifined ones or create a custom another using CContext("Context").
  
  > **Predifined Levels**
  > - Rendering  (For operations related to graphics or web, like OpenGL or Treefrog Framework)
  > - Initialization (For things like init functions or Initialize a program)
  > - FileIO (For file input/output operations in the program)
  > - Network (For network-related operations)
  > - Database (For database management operations)
  > - User Input (For user input handling operations)
  
> [!NOTE]  
> Context are only a way to add more information to the log, they doesn't do anything themselves 

- **Built-in color management**: Native color management for text. Handles RGB and hexadecimal with 24 predefined colors.

- **Level System**: .

## Installation

To use WhistleTrace, simply include the header files in your project. No external dependencies are required.

`` #include "Logger.h" ``
