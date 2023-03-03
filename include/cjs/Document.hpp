#pragma once
#include <vector>
#include <string>
#include "DocumentElement.hpp"

namespace cjs
{

class Document
{
    public:
        Document();
        void AddElement(DocumentElement element);
        void ToHTML(std::string fileName, std::string filePath);

    private:
        std::vector<DocumentElement> m_elements;

};

}