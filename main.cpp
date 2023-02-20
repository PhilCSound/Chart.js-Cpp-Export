#pragma once
#include "Color.hpp"
#include "BarChart.hpp"
#include "BarChartDataset.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <windows.h>

int main()
{
    //Random number generation for the purpose of testing charts
    std::mt19937 eng { std::default_random_engine{}()};
    std::uniform_int_distribution<int> dist { 30, 100 };
    BarChart<int> bc;

    BarChartDataset<int> barData;
    BarChartDataset<int> barData1;
    std::vector<int> dataset;

    for (int i = 0; i < 12; i++)
        dataset.push_back(dist(eng));

    barData.SetData(dataset);
    std::reverse(dataset.begin(), dataset.end());
    barData1.SetData(dataset);

    barData.SetLabel("Test Data");
    barData1.SetLabel("Test Data 2");
    std::vector<Color> test1 {Color(2579610111), Color(2390605567), Color(3465373439), Color(3646508287), Color(2330066175)};
    std::vector<Color> test {Color(2579610111)};
    barData.SetHoverBackgroundColor(test1[0]);
    barData1.SetHoverBackgroundColor(test1[0]);
    barData.SetBackgroundColors(test1);
    barData1.SetBackgroundColors(test1);
    std::vector<std::string> xaxis
    {
        "Jan", "Feb", "Mar", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    
    bc.AddBarChartDataset(barData);
    bc.AddBarChartDataset(barData1);

    bc.SetLabels(xaxis);
    //bc.MakeGraphHorizontal();
    bc.SetBeginAtZero(true);
    bc.SetStackBothAxes(false);

    std::ofstream outFile;
    outFile.open("test.html");
    if (outFile.is_open())
        outFile << bc;
    else
        return -5;
    outFile.close();
    char url[100] = "test.html";

    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
    return 0;
}