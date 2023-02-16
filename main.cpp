#pragma once
#include "Color.hpp"
#include "BarChart.hpp"
#include "BarChartDataset.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
int main()
{
    BarChartDataset<int> barData;
    BarChartDataset<int> barData1;
    std::vector<int> dataset;
    for (int i = 0; i < 12; i++)
        dataset.push_back(35-i);

    barData.SetData(dataset);
    std::reverse(dataset.begin(), dataset.end());
    barData1.SetData(dataset);

    barData.SetLabel("Test Data");
    barData1.SetLabel("Test Data 2");
    
    std::vector<std::string> xaxis
    {
        "Jan", "Feb", "Mar", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    
    BarChart<int> bc;
    bc.AddBarChartDataset(barData);
    bc.AddBarChartDataset(barData1);
    bc.SetLabels(xaxis);
    bc.MakeGraphHorizontal();
    bc.SetBeginAtZero(false);
    bc.SetStackBothAxes(true);

    std::ofstream outFile;
    outFile.open("test.html");
    if (outFile.is_open())
        outFile << bc;
    else
        return -5;
    outFile.close();
    return 0;
}