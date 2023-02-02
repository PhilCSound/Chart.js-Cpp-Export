#pragma once
#include "BarChart.hpp"

template <typename NumericType>
std::ostream& operator<<(std::ostream& os, BarChart<NumericType>& chart)
{
    if (chart.m_barChartDatasets.empty())
        return os;
    
    ///TODO: This part can be moved to a HTMLDocument class.
    os << "<!DOCTYPE html><html><div><canvas id=\"chart\"></canvas></div>"
        << "<script src=\"https://cdn.jsdelivr.net/npm/chart.js@4.1.1/dist/chart.umd.min.js\"></script>" 
        << "<script>const ctx = document.getElementById('chart');new Chart(ctx, {"
        << "type: 'bar', data: { labels: [";
            
    //Labels
    for(size_t i = 0; i < chart.m_labels.size(); i++)
        os << "'" << chart.m_labels[i] << "',";


    os << "],datasets:[{";
    for(auto& dataSet : chart.m_barChartDatasets)
        os << dataSet.ToString();
    os << "}});</script></html>";
    return os;
}

template <typename NumericType>
void BarChart<NumericType>::AddBarChartDataset(const BarChartDataset<NumericType>& dataset)
{
    m_barChartDatasets.push_back(dataset);
}

template <typename NumericType>
void BarChart<NumericType>::SetLabels(const std::vector<std::string>& labels)
{
    m_labels = labels;
}