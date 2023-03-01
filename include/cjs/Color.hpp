#pragma once
#include <string>
#include <cstdint>
#include <iostream>
#include <ios>
#include <sstream>
#include <iomanip>

class Color
{
    public:
        /// @brief Default Constructor.
        Color();

        /// @brief Constructs a 32 bit color.
        /// @param red 8 bit red value, 0-255.
        /// @param green 8 bit green value, 0-255.
        /// @param blue 8 bit blue value, 0-255.
        /// @param alpha 8 bit alpha value, 0-255. By default is 255 (solid) if you wish to omit.
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);

        /// @brief Constructs a 32 bit color out of a unsigned 32 bit integer.
        /// @param color 32 bit unsigned integer you wish to convert to color.
        Color(uint32_t color);

        /// @brief Default destructor.
        ~Color() = default;

        /// @return Returns the color in the form of a 32 bit unsigned integer.
        const uint32_t ToInteger() const;

        /// @return Returns the color as a Hexcode string. EXAMPLE: ff0000ff for red.
        const std::string ToHexColorCode() const;

        /// @brief The colors red value as a 8 bit unsigned integer.
        uint8_t R;

        /// @brief The colors green value as a 8 bit unsigned integer.
        uint8_t G;

        /// @brief The colors blue value as a 8 bit unsigned integer.
        uint8_t B;

        /// @brief The colors alpha value as a 8 bit unsigned integer. 255 being solid, and 0 being transparent.
        uint8_t A;

        /// @brief Predefined color for Black.
        static const Color Black;

        /// @brief Predefined color for White.
        static const Color White;

        /// @brief Predefined color for Red.
        static const Color Red;

        /// @brief Predefined color for Lime.
        static const Color Lime;

        /// @brief Predefined color for Blue.        
        static const Color Blue;

        /// @brief Predefined color for Yellow.
        static const Color Yellow;

        /// @brief Predefined color for Cyan.
        static const Color Cyan;

        /// @brief Predefined color for Magenta.
        static const Color Magenta;

        /// @brief Predefined color for Silver.
        static const Color Silver;

        /// @brief Predefined color for Grey.
        static const Color Grey;

        /// @brief Predefined color for Maroon.
        static const Color Maroon;

        /// @brief Predefined color for Olive.
        static const Color Olive;

        /// @brief Predefined color for Green.
        static const Color Green;

        /// @brief Predefined color for Purple.
        static const Color Purple;

        /// @brief Predefined color for Teal.
        static const Color Teal;

        /// @brief Predefined color for Navy.
        static const Color Navy;
};