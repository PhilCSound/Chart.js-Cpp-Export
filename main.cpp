#pragma once
#include "Color.hpp"
#include "BarChart.hpp"
#include "BarChartDataset.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>
#include <windows.h>
#include "Document.hpp"

//Random number generation for the purpose of testing charts 
//Bad but good enough for this example.
std::vector<int> GetRandomData(int low, int high, int numRandom)
{
    std::mt19937 eng { std::default_random_engine{}()};
    std::uniform_int_distribution<int> dist { low, high };
    std::vector<int> dataset;
    for (int i = 0; i < numRandom; i++)
        dataset.push_back(dist(eng));
    return dataset;
}



int main()
{
    //Created two sets of barchart data.
    BarChartDataset<int> barData { "Test Data", GetRandomData(2, 300, 12) };
    BarChartDataset<int> barData1 { "More Test Data", GetRandomData(30, 230, 12) };
    
    //Created a document.
    Document doc;
    
    //Created Color vectors to test coloring bars/hovering changes
    std::vector<Color> test1 {Color(2579610111), Color(2390605567), Color(3465373439), Color(3646508287), Color(2330066175)};
    std::vector<Color> test {Color(2579610111)};
    //On Hover Color change
    barData.SetHoverBackgroundColor(test1[0]);
    barData1.SetHoverBackgroundColor(test1[0]);
    //Base bar color change
    barData.SetBackgroundColors(test1);
    barData1.SetBackgroundColors(test1);
    //Labels for the X axis of the bar chart.
    std::vector<std::string> xaxis
    {
        "Jan", "Feb", "Mar", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    
    //Create the barchart
    auto bc = BarChart<int>::Create();
    //Add both the barchart datasets we created earlier.
    bc->AddBarChartDataset(barData);
    bc->AddBarChartDataset(barData1);
    //Disabled animations for performance
    bc->DisableAnimations();
    //Set labels and made graph horizontal
    bc->SetLabels(xaxis);
    bc->MakeGraphHorizontal();

    //Add the bar chart to the document.
    doc.AddElement(bc);
    //Adding multiple charts to a document.
    doc.AddElement(bc);
    if (!doc.ToHTML("test.html", ""))
        return -3;
    /*
    if (!bc.ToFile("test.html"))
        return -5;
    */
    char url[100] = "test.html";
    ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
    return 0;
}