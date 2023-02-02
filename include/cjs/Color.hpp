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
        Color();
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
        Color(uint32_t color);
        ~Color() = default;

        const uint32_t ToInteger() const;
        const std::string ToHexColorCode() const;

        uint8_t R;
        uint8_t G;
        uint8_t B;
        uint8_t A;

        //Static constant Member Variables
        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Lime;
        static const Color Blue;
        static const Color Yellow;
        static const Color Cyan;
        static const Color Magenta;
        static const Color Silver;
        static const Color Grey;
        static const Color Maroon;
        static const Color Olive;
        static const Color Green;
        static const Color Purple;
        static const Color Teal;
        static const Color Navy;

    private:
};