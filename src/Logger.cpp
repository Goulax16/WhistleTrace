#ifndef LOGGER_H
#define LOGGER_H

#include "Logger.h"

std::string current_color;
Level level = INFO;
Color color = Color("#FFF");

void Logger::changeColor(const std::string& hexcode) {
    std::string colorResult = hexcode;

    current_color = colorResult;
}

void Logger::changeColor(Color* color) {
    std::string colorResult = color->toAnsi();

    current_color = colorResult;
}

std::string Logger::getTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);

    std::tm* now_tm = std::localtime(&now_c);

    std::ostringstream oss;
    oss << std::put_time(now_tm, "%H:%M:%S");
    return oss.str();
}

std::string Logger::returnLevel() const {
    switch (level) {
    case WARNING:
        return "WARNING";
    case INFO:
        return "INFO";
    case ERROR:
        return "ERROR";
    case FATAL:
        return "FATAL";
    case CUSTOM:
        return "CUSTOM"; // You can customize this further if needed
    default:
        return "UNKNOWN"; // In case of an invalid level
    }
}

void Logger::setLevel(Level newLevel) {
    level = newLevel; // Update the log level
}


void Logger::printLog(std::string value) {
    std::cout << current_color << "[" + getTime() + +"] " << "[" + returnLevel() + "] " << value << "\033[0m" << '\n';

    if (level == FATAL) {
        std::exit(EXIT_FAILURE);
    }
}

void Logger::printLog(std::string value, Color ccolor) {
    Color prevColor = color;

    changeColor(ccolor.toAnsi());
    std::cout << ccolor.toAnsi() << "[" + getTime() + +"] " << "[" + returnLevel() + "] " << value << "\033[0m" << '\n';

    if (level == FATAL) {
        std::exit(EXIT_FAILURE);
    }

    changeColor(prevColor.toAnsi());
}

void Logger::printLog(std::string value, Level logLevel, Color ccolor) {
    Color prevColor = color;
    Level previousLevel = level;

    changeColor(ccolor.toAnsi());
    setLevel(logLevel);
    std::cout << ccolor.toAnsi() << "[" + getTime() + +"] " << "[" + returnLevel() + "] " << value << "\033[0m" << '\n';

    if (level == FATAL) {
        std::exit(EXIT_FAILURE);
    }

    changeColor(prevColor.toAnsi());
    setLevel(previousLevel);
}

void Logger::printLog(std::string value, Level logLevel) {
    Level previousLevel = level; // Guarda el nivel actual
    setLevel(logLevel); // Establece el nuevo nivel

    // Imprime el log con el nuevo nivel
    std::cout << current_color << "[" + getTime() + "] " << "[" + returnLevel() + "] " << value << "\033[0m" << '\n';

    // Si el nivel es FATAL, salir del programa
    if (logLevel == FATAL) {
        std::exit(EXIT_FAILURE);
    }

    // Restaura el nivel anterior
    setLevel(previousLevel);
}

std::string contextToString(Context context) {
    switch (context) {
    case RENDERING: return "RENDERING";
    case INITIALIZATION: return "INITIALIZATION";
    case FILE_IO: return "FILE_IO";
    case NETWORK: return "NETWORK";
    case DATABASE: return "DATABASE";
    case USER_INPUT: return "USER_INPUT";
    default: return "UNKNOWN_CONTEXT";
    }
}

void Logger::printLog(std::string value, Level logLevel, Color ccolor, Context context) {
    Color prevColor = color;
    Level previousLevel = level;

    changeColor(ccolor.toAnsi());
    setLevel(logLevel);

    // Construir el mensaje
    std::ostringstream oss;
    oss << ccolor.toAnsi() << "[" << getTime() << "] ";

    // Agregar contexto como string
    oss << "[" << contextToString(context) << "/" << returnLevel() << "] ";

    oss << value << "\033[0m" << '\n'; // Agregar el valor y restable // cer el color
    std::cout << oss.str();

    // Restaurar el color y nivel anteriores
    changeColor(prevColor.toAnsi());
    setLevel(previousLevel);
}

void Logger::printLog(std::string value, Level logLevel, Color ccolor, CContext context) {
    Color prevColor = color;
    Level previousLevel = level;

    changeColor(ccolor.toAnsi());
    setLevel(logLevel);

    // Construir el mensaje
    std::ostringstream oss;
    oss << ccolor.toAnsi() << "[" << getTime() << "] ";

    // Agregar contexto como string
    oss << "[" << context.value << "/" << returnLevel() << "] ";

    oss << value << "\033[0m" << '\n'; // Agregar el valor y restable // cer el color
    std::cout << oss.str();

    // Restaurar el color y nivel anteriores
    changeColor(prevColor.toAnsi());
    setLevel(previousLevel);
}

#endif