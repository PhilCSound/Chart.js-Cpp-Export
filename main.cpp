#pragma once
#include "Color.hpp"
#include "BarChart.hpp"
#include "BarChartDataset.hpp"
#include <iostream>
#include <fstream>

int main()
{
    Color color { 0,0, 0};
    Color color2 {255, 255, 0};
    Color color3 {0, 255, 255};

    std::cout << "Color 1: " << color.ToHexColorCode() << '\n';
    std::cout << "Color 2: " << color2.ToHexColorCode() << '\n'; 
    std::cout << "Color 3: " << color3.ToHexColorCode() << '\n'; 
    std::cout << "Test 4: " << 244 << '\n';

    BarChartDataset<int> barData;
    std::vector<int> dataset;
    for (int i = 0; i < 10; i++)
        dataset.push_back(11-i);
    barData.SetData(dataset);
    barData.SetLabel("Test Data");
    std::vector<std::string> xaxis
    {
        "Jan", "Feb", "Mar", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    BarChart<int> bc;
    bc.AddBarChartDataset(barData);
    bc.SetLabels(xaxis);

    std::ofstream outFile;
    outFile.open("test.html");
    if (outFile.is_open())
        outFile << bc;
    else
        return -5;
    outFile.close();
    return 0;
}