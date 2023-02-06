#pragma once
#include "BarChartDataset.hpp"

template <typename NumericType>
BarChartDataset<NumericType>::BarChartDataset(const std::string& title)
    : m_label(title)
{
}

template <typename NumericType>
const std::vector<Color> BarChartDataset<NumericType>::GetBackGroundColors() const
{
    return m_backGroundColors;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetBarPercentage() const
{
    return m_barPercentage;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetBarThickness() const
{
    return m_barThickness;
}

template <typename NumericType>
const std::vector<Color> BarChartDataset<NumericType>::GetBorderColors() const
{
    return m_borderColors;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetBorderWidth() const
{
    return m_borderWidth;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetBorderRadius() const
{
    return m_borderRadius;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetCategoryPercentage() const
{
    return m_categoryPercent;
}

template <typename NumericType>
const Color BarChartDataset<NumericType>::GetHoverBackgroundColor() const
{
    return m_hoverBkgColor;
}

template <typename NumericType>
const Color BarChartDataset<NumericType>::GetHoverBorderColor() const
{
    return m_hoverBorderColor;
}

template <typename NumericType>
const std::vector<NumericType> BarChartDataset<NumericType>::GetData() const
{
    return m_data;
}

template <typename NumericType>
const NumericType BarChartDataset<NumericType>::GetDataAt(uint32_t index) const
{
    return m_data[index];
}

template <typename NumericType>
const bool BarChartDataset<NumericType>::IsGrouped() const
{
    return m_isGrouped;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetHoverBorderWidth() const
{
    return m_hoverBorderWidth;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetHoverBorderRadius() const
{
    return m_hoverBorderRadius;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetInflateAmount() const
{
    return m_inflateAmount;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetMaxBarThickness() const
{
    return m_maxBarThickness;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetMinBarLength() const
{
    return m_minBarLength;
}

template <typename NumericType>
const std::string BarChartDataset<NumericType>::GetLabel() const
{
    return m_label;
}

template <typename NumericType>
const float BarChartDataset<NumericType>::GetOrder() const
{
    return m_order;
}

template <typename NumericType>
const bool BarChartDataset<NumericType>::IsSkipNull() const
{
    return m_isSkipNull;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetBackgroundColors(std::vector<Color>& colors)
{
    m_backGroundColors = colors;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetBarPercentage(float barPercentage)
{
    m_barPercentage = barPercentage;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetBarThickness(float barThickness)
{
    m_barThickness = barThickness;
    m_userBarThickness = true;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetBorderColors(std::vector<Color>& colors)
{
    m_borderColors = colors;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetBorderWidth(float borderWidth)
{
    m_borderWidth = borderWidth;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetBorderRadius(float radius)
{
    m_borderRadius = radius;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetCategoryPercentage(float categoryPer)
{
    m_categoryPercent = categoryPer;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetHoverBackgroundColor(Color& hoverBkgColor)
{
    m_hoverBkgColor = hoverBkgColor;
    m_userHoverBkgColor = true;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetHoverBorderColor(Color& hoverBorderColor)
{
    m_hoverBorderColor = hoverBorderColor;
    m_userHoverBorderColor = true;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetData(std::vector<NumericType>& data)
{
    m_data = data;
    return *this;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetDataAt(uint32_t index, NumericType data)
{
    m_data[index] = data;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetGrouped(bool grouped)
{
    m_isGrouped = grouped;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetHoverBorderWidth(float hoverBorderWidth)
{
    m_hoverBorderWidth = hoverBorderWidth;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetHoverBorderRadius(float hoverBorderRadius)
{
    m_hoverBorderRadius = hoverBorderRadius;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetInflateAmount(float inflateAmt)
{
    m_inflateAmount = inflateAmt;
    m_userInflateAmount = true;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetMaxBarThickness(float maxBarThickness)
{
    m_maxBarThickness = maxBarThickness;
    m_userMaxBarThickness = true;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetMinBarLength(float minBarLength)
{
    m_minBarLength = minBarLength;
    m_userMinBarLength = true;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetLabel(const std::string& label)
{
    m_label = label;
    return *this;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetOrder(float order)
{
    m_order = order;
}

template <typename NumericType>
BarChartDataset<NumericType>& BarChartDataset<NumericType>::SetSkipNull(bool skipNull)
{
    m_isSkipNull = skipNull;
}

template <typename NumericType>
const std::string BarChartDataset<NumericType>::ToString()
{ 
    if (m_data.empty())
        return std::string();

    std::stringstream ss;

    ///Labels & Data..
    ss << "label: '" << m_label << "'," << "data: [";
    for (int i = 0; i < m_data.size(); i++)
    {
        ss << m_data[i];
        if ((i + 1) != m_data.size())
            ss << ",";
    }
    ss << "]";

    // Background Colors
    if (!m_backGroundColors.empty())
    {
        ss << ",backgroundColor: [";
        for (int i = 0; i < m_backGroundColors.size(); i++)
        {
            ss << m_backGroundColors[i].ToHexColorCode();
            if ((i + 1) != m_backGroundColors.size())
                ss << ",";
        }
        ss << "]";
    }

    /// Bar Thickness & Bar Percentage/Category Percentage
    if (m_userBarThickness)
        ss << ",barThickness: " << m_barThickness;
    else
    {
        if (m_barPercentage != .9f)
            ss << ",barPercentage: " << m_barPercentage;
        if (m_categoryPercent != .8f)
            ss << ",categoryPercentage" << m_categoryPercent;
    }

    /// Border Colors
    if (!m_borderColors.empty())
    {
        ss << ",borderColor: [";
        for (int i = 0; i < m_borderColors.size(); i++)
        {
            ss << m_borderColors[i].ToHexColorCode();
            if ((i + 1) != m_borderColors.size())
                ss << ",";
        }
        ss << "]";
    }

    /// Border Width and Border Radius
    if (m_borderWidth != 0)
        ss << ",borderWidth: " << m_borderWidth;
    if (m_borderRadius != 0)
        ss << ",borderRadius: " << m_borderRadius;

    /// Grouped
    if (!m_isGrouped)
        ss << ",grouped: false";

    /// Hover Background Color and HoverBorderColor
    if (m_userHoverBkgColor)
        ss << ",hoverBackgroundColor: " << m_hoverBkgColor.ToHexColorCode();
    if (m_userHoverBorderColor)
        ss << ",hoverBorderColor: " << m_hoverBorderColor.ToHexColorCode();

    /// HoverBorderWidth and HoverBorderRadius
    if (m_hoverBorderWidth != 1.0f)
        ss << ",hoverBorderWidth: " << m_hoverBorderWidth;
    if (m_hoverBorderRadius != 0)
        ss << ",hoverBorderRadius: " << m_hoverBorderRadius;

    /// Inflate Amount
    if (m_userInflateAmount)
        ss << ",inflateAmount: " << m_inflateAmount;

    // MaxBarThickness and MinBarLength
    if (m_userMaxBarThickness)
        ss << ",maxBarThickness: " << m_maxBarThickness;
    if (m_userMinBarLength)
        ss << ",minBarLength: " << m_minBarLength;

    /// Order and SkipNull
    if (m_order)
        ss << ",order: " << m_order; 
    if (m_isSkipNull) 
        ss << ",skipNull: true";
    return ss.str();
}


///Fileout
/*
 std::ofstream outFile;
    outFile.open(path+filename);
    if (outFile.is_open())
    {
        outFile << "<!DOCTYPE html><html><div><canvas id="chart"></canvas></div>"
        << "<script src=\"https://cdn.jsdelivr.net/npm/chart.js\"></script>" 
        << "<script>const ctx = document.getElementById('myChart');new Chart(ctx, {"
        << "type: 'bar', data: {"


        << "});</script></html>";
    }

*/