#pragma once
#include "BarChartDataset.hpp"

template <typename NumericType>
class BarChart  
{
    public:
        BarChart() = default;

        void AddBarChartDataset(const BarChartDataset<NumericType>& dataset);
        
        void MakeGraphHorizontal();
        void MakeGraphVertical();

        void SetGrouped(const bool isGrouped);
        void SetLabels(const std::vector<std::string>& labels); 
        void SetSkipNull(const bool skipNull);
        //void SetStack()  THis is a dataset thing
        //void Order() Dataset order of drawing
        
        
        //Operator overloads  
        template <typename NumericType>
        friend std::ostream& operator<<(std::ostream& os, BarChart<NumericType>& chart);
    private:
        std::vector<BarChartDataset<NumericType>> m_barChartDatasets;
        std::vector<std::string> m_labels;
};


#pragma once
#include "BarChart.cpp"
