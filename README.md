# WhistleTrace

WhistleTrace is a simple and extensible logging library that allows efficient management of log levels and contexts. With WhistleTrace, you can customize the color of log messages and control the flow of your application through various severity levels.

## Features

- **Context Levels**: Supports Context to print a log with another information by using the predifined ones or create a custom another using CContext("Context").
  
  > **Predifined Contexts**
  > - Rendering  (For operations related to graphics or web, like OpenGL or Treefrog Framework)
  > - Initialization (For things like init functions or Initialize a program)
  > - FileIO (For file input/output operations in the program)
  > - Network (For network-related operations)
  > - Database (For database management operations)
  > - User Input (For user input handling operations)
  
> [!NOTE]  
> Context are only a way to add more information to the log, they doesn't do anything themselves 

- **Built-in color management**: Native color management for text. Handles RGB and hexadecimal with 24 predefined colors.

- **Level System**: Types of level already built-in to indicate log importance. The level can be a custom one using CLevel("Level")

> **Predifined Levels**
> - WARNING
> - INFO
> - ERROR
> - FATAL (Fatal closes the program. This is subject to change)

## Installation

To use WhistleTrace, include the header in your project and set cpp level to c++17

```cpp
Logger log;

log.printLog(CContext("Test"), CLevel("Test"), Color("#fff"), "Test");
```
but it can't print more than one string. For that you need to do this:
```cpp
Logger log;

PRINT_LOG(log, Color("#FFF"), CLevel("Test"), CContext("Test"), "This", "is", "a", "test");
```

If you find bugs be free to publish in Github issue tab or a PR.
