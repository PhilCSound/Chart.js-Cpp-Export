#pragma once
#include "Color.hpp"

Color::Color()
    : R(255), G(255), B(255), A(0)
{
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : R(red), G(green), B(blue), A(alpha)
{
}

///TODO: 
Color::Color(uint32_t color)
    :   R(static_cast<uint8_t>((color & 0xff000000) >> 24)), 
        G(static_cast<uint8_t>((color & 0x00ff0000) >> 16)), 
        B(static_cast<uint8_t>((color & 0x0000ff00) >> 8)), 
        A(static_cast<uint8_t>(color & 0x000000ff))
{
}

const uint32_t Color::ToInteger() const
{
    return static_cast<uint32_t>((R << 24) | (G << 16) | (B << 8) | A);
}
        
const std::string Color::ToHexColorCode() const
{
    std::stringstream ss;

    std::ios_base::fmtflags flags(std::cout.flags());
    ss << "'#" << std::hex << std::setw(8) << std::setfill('0') <<ToInteger() << "'";
    std::cout.flags(flags);
    return ss.str(); 
}

const Color Color::Black { 0, 0, 0 };
const Color Color::White { 255,255,255 };
const Color Color::Red { 255,0,0 };
const Color Color::Lime { 0,255,0 };
const Color Color::Blue { 0,0,255 };
const Color Color::Yellow { 255,255,0 };
const Color Color::Cyan { 0,255,255 };
const Color Color::Magenta { 255,0,255 };
const Color Color::Silver { 192,192,192 };
const Color Color::Grey { 128,128,128 };
const Color Color::Maroon { 128,0,0 };
const Color Color::Olive { 128,128,0 };
const Color Color::Green { 0,128,0 };
const Color Color::Purple { 128,0,128 };
const Color Color::Teal { 0,128,128 };
const Color Color::Navy { 0,0,128 };