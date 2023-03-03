#pragma once
#include <string>

class DocumentElement
{
    virtual void ParseElement(std::ostream &os) = 0;
};
