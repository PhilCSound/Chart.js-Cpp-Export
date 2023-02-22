#pragma once
#include "BarChartDataset.hpp"

template <typename NumericType>
class BarChart
{
public:
    /// @brief Default Constructor
    BarChart() = default;

    ///@brief Inserts a COPY of a BarchartDataset into the bar chart.
    inline void AddBarChartDataset(const BarChartDataset<NumericType>& dataset)
    {
        m_barChartDatasets.push_back(dataset);
    }

    /// @brief Disables Animations on the bar chart, animations are on by default.
    inline void DisableAnimations()
    {
        m_allowAnimations = false;
    }

    /// @brief Enables Animations on the bar chart, animations are on by default.
    inline void EnableAnimations()
    {
        m_allowAnimations = true;
    }

    /// @brief Makes the bar chart horizontal, the graph is vertical by default. 
    inline void MakeGraphHorizontal()
    {
        m_isHorizontal = true;
    }

    /// @brief Makes the bar chart vertical, the graph is vertical by default.
    inline void MakeGraphVertical()
    {
        m_isHorizontal = false;
    }

    /// @brief By default the value axis starts at zero, if you wish to change this pass false to begin at lowest value. 
    /// @param isBeginAtZero True: the value axis begins at zero. False: the chart axis begins at the lowest value.
    inline void SetBeginAtZero(const bool isBeginAtZero)
    {
        m_beginAxisAtZero = isBeginAtZero;
    };

    //TODO?
    inline void SetGrouped(const bool isGrouped)
    {
        m_isGrouped = false;
    }

    /// @brief COPYS a vector of labels. If not done, the bar chart will draw empty.
    /// @param labels A vector of labels to draw under each bar in the bar chart. This will be COPIED.
    inline void SetLabels(const std::vector<std::string>& labels)
    {
        m_labels = labels;
    }

    /// @brief If a null value is somehow inserted in the chart, then that value will be skipped.
    /// @brief Off by default, but there should not be a way to pass null object to begin with.
    /// @param skipNull Boolean, if set to true then Chart.js will skip null values.
    inline void SetSkipNull(const bool skipNull)
    {
        m_skipNull = skipNull;
    }

    /// @brief Was added for testing purposes. Set both to regardless of if the graph is vertical/horizontal.
    /// @brief Set both the X and Y axis bars to stack on top each other instead of side to side.
    /// @param bothAxis If true, will stack bars regardless of a horizontal/veritical graph. False by default.
    inline void SetStackBothAxes(const bool bothAxis)
    {
        m_stackXAxis = bothAxis;
        m_stackYAxis = bothAxis;
    }
    
    /// @brief If graph is horizontal, stacks bars on top of each other instead of side to side.
    /// @param stackXAxis If true, will stack bars if a horizontal graph. False by default.
    inline void SetStackXAxis(const bool stackXAxis)
    {
        m_stackXAxis = stackXAxis;
    }

    /// @brief If graph is vertical, stacks bars on top of each other instead of side to side.
    /// @param stackXAxis If true, will stack bars if a vertical graph. False by default.
    inline void SetStackYAxis(const bool stackYAxis)
    {
        m_stackYAxis = stackYAxis;
    }

    //=================================================================~~~~~~~~~~~~~~~~~~~~~~~~
    //              Operator overloads  !!!!!!!!
    //=========================================================================================

    /// @brief Parses the barchart using the outstream.
    /// @tparam NumericType 
    template <typename NumericType>
    inline friend std::ostream &operator<<(std::ostream &os, BarChart<NumericType> &chart)
    {
        if (chart.m_barChartDatasets.empty() || chart.m_labels.empty())
            return os;

        /// TODO: This part can be moved to a HTMLDocument class.
        os << "<!DOCTYPE html><html><div><canvas id=\"chart\"></canvas></div>"
           << "<script src=\"https://cdn.jsdelivr.net/npm/chart.js@4.1.1/dist/chart.umd.min.js\"></script>"
           << "<script>const ctx = document.getElementById('chart');new Chart(ctx, {"
           << "type: 'bar', data: { labels: [";

        // Labels
        for (size_t i = 0; i < chart.m_labels.size(); i++)
            os << "'" << chart.m_labels[i] << "',";

        // Datasets
        os << "],datasets:[";

        for (auto &dataSet : chart.m_barChartDatasets)
            os << "{" << dataSet << "},";
        os << "]},";

        // Options
        os << " options: {";
        if (!chart.m_allowAnimations)
            os << "animation: false,";
        if (chart.m_isHorizontal)
            os << "indexAxis: 'y',";
        os << "scales: { x: {"; // XAxis
        if (chart.m_stackXAxis)
            os << "stacked: true,";
        if (!chart.m_beginAxisAtZero && chart.m_isHorizontal)
            os << "beginAtZero: false";
        os << "}, y: {"; // YAxis
        if (chart.m_stackYAxis)
            os << "stacked: true,";
        if (!chart.m_beginAxisAtZero && !chart.m_isHorizontal)
            os << "beginAtZero: false";
        os << "}}},";

        // TODO: Set Grouped?
        os << "});</script></html>";

        return os;
    }

private:
    /// @brief Collection of BarChartDatasets.
    std::vector<BarChartDataset<NumericType>> m_barChartDatasets;
    
    /// @brief True by default, allows animations. Set to false to disable.
    bool m_allowAnimations = true;

    /// @brief True by default, begins the value axis at zero. If false, begins at lowest value.
    bool m_beginAxisAtZero = true;

    /// @brief Vector of strings used for the labels under each bar group. Must be set or blank render.
    std::vector<std::string> m_labels;

    /// @brief False by default, if true the bar chart is rendered horizontally instead of vertically.
    bool m_isHorizontal = false;

    /// @todo Figure this out...
    bool m_isGrouped = false;

    /// @brief Mainly here to try and keep functionality, but if true will skip nullable values.
    bool m_skipNull = false;

    /// @brief If true, will stack bars if a horizontal graph. False by default.
    bool m_stackXAxis = false;

    /// @brief If true, will stack bars if a vertical graph. False by default.
    bool m_stackYAxis = false;
};
