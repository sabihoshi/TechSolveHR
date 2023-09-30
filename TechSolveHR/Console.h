#pragma once
#pragma execution_character_set("utf-8")

#include "Console.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <Windows.h>

enum ConsoleColor
{
    Black,
    Blue,
    Green,
    Aqua,
    Red,
    Purple,
    Yellow,
    White,
    Gray,
    LightBlue,
    LightGreen,
    LightAqua,
    LightRed,
    LightPurple,
    LightYellow,
    BrightWhite
};

enum class ClearType
{
    Screen,
    Line,
    Up,
    Down,
    Right,
    Left,
    EndOfLine,
    EndOfScreen,
    Color
};

enum class CursorDirection
{
    Up,
    Down,
    Right,
    Left
};

enum class ScrollDirection
{
    Screen,
    Down,
    Up
};

enum class TableCharacter
{
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight,
    TopEdge,
    BottomEdge,
    LeftEdge,
    RightEdge
};

enum class GroundType
{
    Fore,
    Back
};

struct Color
{
    int R;
    int G;
    int B;
};

const std::string COLOR_RESET = "\033[0m";

/**
 * \brief Changes the color of the foreground text in the console.
 * \param color The ConsoleColor to change the color to.
 */
inline void ChangeColor(const ConsoleColor color)
{
    const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
}

/**
 * \brief Returns the encoded string that allows you to change the console color.
 * \param color The Color to change the output to.
 * \param type Specify whether to change the foreground or the background color.
 * \return The encoded string with color.
 */
inline std::string ChangeColor(const Color color, const GroundType type)
{
    if (color.R == -1 && color.G == -1 && color.B == -1)
        return COLOR_RESET;

    const auto r = std::to_string(color.R);
    const auto g = std::to_string(color.G);
    const auto b = std::to_string(color.B);

    switch (type)
    {
        case GroundType::Fore:
            return "\033[38;2;" + r + ";" + g + ";" + b + "m";
        case GroundType::Back:
            return "\033[48;2;" + r + ";" + g + ";" + b + "m";
    }
}

/**
 * \brief Returns an encoded string in which the specific given text has a specific color.
 * \param string The text to change the color.
 * \param color The Color to change the text to.
 * \param type Specify whether to change the foreground or the background color.
 * \return The text you provided with the coloring you provided.
 */
inline std::string ChangeColor(const std::string& string, const Color color, const GroundType type)
{
    return ChangeColor(color, type) + string + COLOR_RESET;
}

/**
 * \brief Swaps the colors of the foreground and background around.
 */
inline void SwapColors()
{
    std::cout << "\033[7m";
}

/**
 * \brief Change the colors of the console so that the next outputs will be the specific color.
 * \param color The Color to use.
 * \param type Specify whether to change the foreground or the background color.
 */
inline void SetColor(const Color color, const GroundType type)
{
    std::cout << ChangeColor(color, type);
}

/**
 * \brief Resets the color back to the console defaults.
 */
inline void ResetColor()
{
    std::cout << COLOR_RESET;
}

inline std::string Repeat(const std::string& string, const size_t repeats)
{
    std::ostringstream repeated;
    const auto iterator = std::ostream_iterator<std::string>(repeated);
    fill_n(iterator, repeats, string);
    return repeated.str();
}

inline std::string Repeat(const char character, const int repeats)
{
    return Repeat(std::to_string(character), repeats);
}

inline std::string Center(const std::string& string, const size_t length)
{
    const size_t left = length / 2 - string.length() / 2;
    return Repeat(" ", left) + string;
}

inline std::string Right(const std::string& string, const size_t length)
{
    const size_t repeat = length - string.length();
    return string + Repeat(" ", repeat);
}

inline std::string Left(const std::string& string, const size_t length)
{
    const size_t repeat = length - string.length();
    return Repeat(" ", repeat) + string;
}

inline void SetConsoleMode(const int mode)
{
    const auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= mode;
    SetConsoleMode(hOut, dwMode);
}

/**
 * \brief Sets the cursor position based on the coordinates.
 * \param c The coordinate you want to set the cursor to.
 * \return The new coordinates.
 */
inline COORD XY(const COORD c)
{
    const auto output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, c);
    return c;
}

/**
 * \brief Returns the current position of the cursor.
 * \return A coordinate of the current position.
 */
inline COORD XY()
{
    const auto output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(output, &info);
    return info.dwCursorPosition;
}

inline COORD XY(const short x, const short y)
{
    return XY({x, y});
}

inline COORD MoveCursor(const CursorDirection direction, const short amount = 1)
{
    const auto c = XY();
    switch (direction)
    {
        case CursorDirection::Up:
            XY(c.X, c.Y - amount);
            break;
        case CursorDirection::Down:
            XY(c.X, c.Y + amount);
            break;
        case CursorDirection::Right:
            XY(c.X + amount, c.Y);
            break;
        case CursorDirection::Left:
            XY(c.X - amount, c.Y);
            break;
    }
    return XY();
}

inline COORD WriteLine(const std::string& string)
{
    const auto p = XY();
    std::cout << string;
    XY(p);
    return MoveCursor(CursorDirection::Down);
}

inline void Clear(const ClearType type)
{
    switch (type)
    {
        case ClearType::Screen:
            system("cls");
            break;
        case ClearType::Line:
            printf("\033[2K");
            break;
        case ClearType::Up:
            printf("\033[1J");
            break;
        case ClearType::Down:
            printf("\033[J");
            break;
        case ClearType::Right:
            printf("\033[K");
            break;
        case ClearType::Left:
            printf("\033[1K");
            break;
        case ClearType::EndOfLine:
            printf("\033K");
            break;
        case ClearType::EndOfScreen:
            printf("\033J");
            break;
        case ClearType::Color:
            break;
    }
}

inline void Pause()
{
    XY(45, 25);
    system("pause");
}

inline void CinReset()
{
    std::cin.clear();
#pragma push_macro("max")
#undef max
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#pragma pop_macro("max")
}
