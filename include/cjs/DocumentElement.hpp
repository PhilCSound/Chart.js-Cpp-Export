#pragma once
#include <string>

class DocumentElement
{
    friend class Document;
    virtual void ParseElement(std::ostream &os) = 0;
};
