#pragma once
#include <vector>
#include <string>
#include "DocumentElement.hpp"
#include <fstream>
#include <memory>

class Document
{
    public:
        Document() = default;
        inline void AddElement(std::shared_ptr<DocumentElement> element)
        {
            m_elements.push_back(element);
        }

        inline bool ToHTML(const std::string& fileName, const std::string& filePath = "", bool offline = false)
        {
            std::ofstream outFile;
            outFile.open(filePath + fileName);
            if (!outFile.is_open())
                return false;
            //Beginning of file
            outFile << "<!DOCTYPE html><html><div>";
            for (int i = 0; i < m_elements.size(); i++)
                outFile << "<canvas id=\"chart" << i << "\"></canvas>";
            
            ///@todo If/Else offline
            outFile << "</div><script src=\"https://cdn.jsdelivr.net/npm/chart.js@4.1.1/dist/chart.umd.min.js\"></script>";
            
            int i = 0;
            for(auto& element : m_elements)
            {
                outFile << "<script>const ctx" << i << "=document.getElementById('chart" << i <<"');new Chart(ctx" << i << ", {";
                element->ParseElement(outFile);
                outFile << "});</script>";
                i++;
            }
            //End File
            outFile << "</html>";
            outFile.close();
            return true;
        }

    private:
        std::vector<std::shared_ptr<DocumentElement>> m_elements;

};