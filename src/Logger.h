#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <optional>
#include <chrono>
#include <ctime>
#include <cerrno>

struct Color {
    int red;
    int green;
    int blue;
    std::string hexcode;

    Color(int r, int g, int b) : red(r), green(g), blue(b) {
        hexcode = toHex();
    }

    Color(const std::string& hex) : hexcode(hex) {
        if (hexcode.length() == 7 && hexcode[0] == '#') {
            red = std::stoi(hexcode.substr(1, 2), nullptr, 16);
            green = std::stoi(hexcode.substr(3, 2), nullptr, 16);
            blue = std::stoi(hexcode.substr(5, 2), nullptr, 16);
        }
        else if (hexcode.length() == 4 && hexcode[0] == '#') {
            red = std::stoi(std::string(2, hexcode[1]), nullptr, 16);
            green = std::stoi(std::string(2, hexcode[2]), nullptr, 16);
            blue = std::stoi(std::string(2, hexcode[3]), nullptr, 16);
        }
        else {
            red = green = blue = 0;
        }
    }


    std::string toHex() const {
        std::stringstream ss;
        ss << "#"
            << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << red
            << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << green
            << std::setfill('0') << std::setw(2) << std::hex << std::uppercase << blue;
        return ss.str();
    }

    std::string toString() const {
        return hexcode; // Devuelve el código hexadecimal
    }

    std::string toAnsi() const {
        std::ostringstream oss;
        oss << "\u001b[38;2;" << red << ";" << green << ";" << blue << "m";
        return oss.str();
    }
};

enum Level {
    WARNING,
    INFO,
    ERROR,
    FATAL,
    CUSTOM
};

enum Context {
    RENDERING,          // Renderizado
    INITIALIZATION,     // Inicialización
    FILE_IO,           // Entrada/Salida de archivos
    NETWORK,           // Red
    DATABASE,          // Base de datos
    USER_INPUT,        // Entrada del usuario
};

struct CContext {
    std::string value;

    CContext(std::string value) : value(value) {
        this->value = value;
    }
};

std::string contextToString(Context context);

class Logger
{
public:

    void changeColor(Color* color);
    void changeColor(const std::string& hexcolor);
    void printLog(std::string value);
    void printLog(std::string value, Color hex);
    void printLog(std::string value, Level logLevel);
    void printLog(std::string value, Level logLevel, Color hex);
    void printLog(std::string value, Level logLevel, Color hex, Context context);
    void printLog(std::string value, Level logLevel, Color hex, CContext context);

    void setLevel(Level newLevel);


    std::string returnLevel() const;
    std::string getTime();
};

template<typename... Args>
std::string concatenate(Args... args) {
    std::ostringstream oss;
    (oss << ... << args); // Expansión de parámetros (C++17)
    return oss.str();
}

#ifndef LOG_INFO_DEFINED
#define LOG_INFO_DEFINED
#define LOG_INFO(logger, color, context, ...) logger.printLog(concatenate(__VA_ARGS__), INFO, color, context)
#endif

#ifndef LOG_WARNING_DEFINED
#define LOG_WARNING_DEFINED
#define LOG_WARNING(logger, color, context, ...) logger.printLog(concatenate(__VA_ARGS__), WARNING, color, context)
#endif

#ifndef LOG_ERROR_DEFINED
#define LOG_ERROR_DEFINED
#define LOG_ERROR(logger, color, context, ...) logger.printLog(concatenate(__VA_ARGS__), ERROR, color, context)
#endif

#ifndef LOG_FATAL_DEFINED
#define LOG_FATAL_DEFINED
#define LOG_FATAL(logger, color, context, ...) logger.printLog(concatenate(__VA_ARGS__), FATAL, color, context)
#endif

// Definiciones para ccontext
#ifndef LOG_INFO_CCONTEXT_DEFINED
#define LOG_INFO_CCONTEXT_DEFINED
#define LOG_INFO(logger, color, ccontext, ...) logger.printLog(concatenate(__VA_ARGS__), INFO, color, ccontext)
#endif

#ifndef LOG_WARNING_CCONTEXT_DEFINED
#define LOG_WARNING_CCONTEXT_DEFINED
#define LOG_WARNING(logger, color, ccontext, ...) logger.printLog(concatenate(__VA_ARGS__), WARNING, color, ccontext)
#endif

#ifndef LOG_ERROR_CCONTEXT_DEFINED
#define LOG_ERROR_CCONTEXT_DEFINED
#define LOG_ERROR(logger, color, ccontext, ...) logger.printLog(concatenate(__VA_ARGS__), ERROR, color, ccontext)
#endif

#ifndef LOG_FATAL_CCONTEXT_DEFINED
#define LOG_FATAL_CCONTEXT_DEFINED
#define LOG_FATAL(logger, color, ccontext, ...) logger.printLog(concatenate(__VA_ARGS__), FATAL, color, ccontext)
#endif

#define COLOR_RED Color(255, 0, 0)
#define COLOR_GREEN Color(0, 255, 0)
#define COLOR_BLUE Color(0, 0, 255)
#define COLOR_YELLOW Color(255, 255, 0)
#define COLOR_WHITE Color(255, 255, 255)
#define COLOR_BLACK Color(0, 0, 0)

#define COLOR_CYAN Color(0, 255, 255)        // Cyan
#define COLOR_MAGENTA Color(255, 0, 255)     // Magenta
#define COLOR_ORANGE Color(255, 165, 0)      // Orange
#define COLOR_PURPLE Color(128, 0, 128)      // Purple
#define COLOR_GRAY Color(128, 128, 128)      // Gray
#define COLOR_LIGHT_GRAY Color(211, 211, 211) // Light Gray
#define COLOR_DARK_GRAY Color(169, 169, 169)  // Dark Gray
#define COLOR_BROWN Color(165, 42, 42)        // Brown
#define COLOR_TURQUOISE Color(64, 224, 208)   // Turquoise
#define COLOR_VIOLET Color(238, 130, 238)     // Violet
#define COLOR_PINK Color(255, 192, 203)       // Pink
#define COLOR_LIME Color(0, 255, 0)           // Lime
#define COLOR_TEAL Color(0, 128, 128)          // Verde azulado
#define COLOR_PEACH Color(255, 218, 185)       // Durazno
#define COLOR_SALMON Color(250, 128, 114)      // Salmón
#define COLOR_MINT Color(189, 252, 201)        // Menta
#define COLOR_LAVENDER Color(230, 230, 250)    // Lavanda

#define COLOR_FATAL Color(255, 46, 67)