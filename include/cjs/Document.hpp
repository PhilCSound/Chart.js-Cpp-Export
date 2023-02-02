#pragma once
#include <vector>
#include <string>
#include "HTMLElement"

namespace cjs
{

class Document
{
    public:
        Document();
        void AddElement(HTMLElement element);
        void ToHTML(std::string fileName, std::string filePath);

    private:
        std::vector<HTMLElement> m_elements;

};

}