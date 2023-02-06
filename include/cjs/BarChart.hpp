#pragma once
#include "BarChartDataset.hpp"

template <typename NumericType>
class BarChart  
{
    public:
        BarChart() = default;

        inline void AddBarChartDataset(const BarChartDataset<NumericType>& dataset)
            { m_barChartDatasets.push_back(dataset); }
        
        inline void MakeGraphHorizontal() { m_isHorizontal = true; }
        inline void MakeGraphVertical() { m_isHorizontal = false; }

        inline void SetGrouped(const bool isGrouped) { m_isGrouped = false; }
        inline void SetLabels(const std::vector<std::string>& labels) { m_labels = labels; } 
        inline void SetSkipNull(const bool skipNull) { m_skipNull = skipNull; }
        //void SetStack()  This is a dataset thing
        //void Order() Dataset order of drawing
        

        //Operator overloads  
        template <typename NumericType>
        inline friend std::ostream& operator<<(std::ostream& os, BarChart<NumericType>& chart)
        {
            if (chart.m_barChartDatasets.empty() || chart.m_labels.empty())
                return os;
    
            ///TODO: This part can be moved to a HTMLDocument class.
            os << "<!DOCTYPE html><html><div><canvas id=\"chart\"></canvas></div>"
                << "<script src=\"https://cdn.jsdelivr.net/npm/chart.js@4.1.1/dist/chart.umd.min.js\"></script>" 
                << "<script>const ctx = document.getElementById('chart');new Chart(ctx, {"
                << "type: 'bar', data: { labels: [";
            
            //Labels
            for(size_t i = 0; i < chart.m_labels.size(); i++)
                os << "'" << chart.m_labels[i] << "',";
            os << "],datasets:[";
            
            for(auto& dataSet : chart.m_barChartDatasets)
                os << "{"<< dataSet.ToString() << "},";
            os << "]}});</script></html>";
            
            return os;
        }

    private:
        std::vector<BarChartDataset<NumericType>> m_barChartDatasets;
        std::vector<std::string> m_labels;
        bool m_isHorizontal = false;
        bool m_isGrouped = false;
        bool m_skipNull = false;
};
