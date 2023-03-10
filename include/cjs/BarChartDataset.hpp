#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include "Color.hpp"
/**
 * TODO:
 * RADAR CHART IS UNIQUE in that deervivi
 * Bar/Bubble/Line/Pie/Polar/Radar are all unique charts
 * Scatter is a variation of Line and Doughnut is a variation of Bubble.
 *
 * TODO:
 * Base
 * Border SKipped
 * Clip
 * point style
 * Stack
 * XAxisID
 * YAxisID
 *
 * Commons in all but for Radar:
 * Clip
 * BackgroundColors
 * BorderColors
 * BorderWidth
 * hoverBackgroundColor
 * hoverBorderColor
 * hoverBorderWidth
 */
template <typename NumericType>
class BarChartDataset
{
public:
    BarChartDataset() = default;
    BarChartDataset(const std::string& title) : m_label(title){};
    BarChartDataset(const std::vector<NumericType>& data) : m_data(data){};
    BarChartDataset(const std::string& title, const std::vector<NumericType>& data) : m_label(title), m_data(data) {};

    inline const std::vector<Color> GetBackGroundColors() const
    {
        return m_backGroundColors;
    }

    inline const float GetBarPercentage() const
    {
        return m_barPercentage;
    }

    inline const float GetBarThickness() const
    {
        return m_barThickness;
    }

    inline const std::vector<Color> GetBorderColors() const
    {
        return m_borderColors;
    }

    inline const float GetBorderWidth() const
    {
        return m_borderWidth;
    }

    inline const float GetBorderRadius() const
    {
        return m_borderRadius;
    }

    inline const float GetCategoryPercentage() const
    {
        return m_categoryPercent;
    }

    inline const Color GetHoverBackgroundColor() const
    {
        return m_hoverBkgColor;
    }

    inline const Color GetHoverBorderColor() const
    {
        return m_hoverBorderColor;
    }

    inline const std::vector<NumericType> GetData() const
    {
        return m_data;
    }

    inline const NumericType GetDataAt(uint32_t index) const
    {
        return m_data[index];
    }

    inline const bool IsGrouped() const
    {
        return m_isGrouped;
    }

    inline const float GetHoverBorderWidth() const
    {
        return m_hoverBorderWidth;
    }

    inline const float GetHoverBorderRadius() const
    {
        return m_hoverBorderRadius;
    }

    inline const float GetInflateAmount() const
    {
        return m_inflateAmount;
    }

    inline const float GetMaxBarThickness() const
    {
        return m_maxBarThickness;
    }

    inline const float GetMinBarLength() const
    {
        return m_minBarLength;
    }

    inline const std::string GetLabel() const
    {
        return m_label;
    }

    inline const float GetOrder() const
    {
        return m_order;
    }

    inline const bool IsSkipNull() const
    {
        return m_isSkipNull;
    }

    inline BarChartDataset& SetBackgroundColors(std::vector<Color>& colors)
    {
        m_backGroundColors = colors;
        return *this;
    }

    inline BarChartDataset& SetBarPercentage(float barPercentage)
    {
        m_barPercentage = barPercentage;
        return *this;
    }

    inline BarChartDataset& SetBarThickness(float barThickness)
    {
        m_barThickness = barThickness;
        m_userBarThickness = true;
        return *this;
    }

    inline BarChartDataset& SetBorderColors(std::vector<Color>& colors)
    {
        m_borderColors = colors;
        return *this;
    }

    inline BarChartDataset& SetBorderWidth(float borderWidth)
    {
        m_borderWidth = borderWidth;
        return *this;
    }

    inline BarChartDataset& SetBorderRadius(float radius)
    {
        m_borderRadius = radius;
        return *this;
    }

    inline BarChartDataset& SetCategoryPercentage(float categoryPer)
    {
        m_categoryPercent = categoryPer;
        return *this;
    }

    inline BarChartDataset& SetHoverBackgroundColor(Color& hoverBkgColor)
    {
        m_hoverBkgColor = hoverBkgColor;
        m_userHoverBkgColor = true;
        return *this;
    }

    inline BarChartDataset& SetHoverBorderColor(Color& hoverBorderColor)
    {
        m_hoverBorderColor = hoverBorderColor;
        m_userHoverBorderColor = true;
        return *this;
    }

    inline BarChartDataset& SetData(std::vector<NumericType>& data)
    {
        m_data = data;
        return *this;
    }

    inline BarChartDataset& SetDataAt(uint32_t index, NumericType data)
    {
        m_data[index] = data;
        return *this;
    }

    inline BarChartDataset& SetGrouped(bool grouped)
    {
        m_isGrouped = grouped;
        return *this;
    }

    inline BarChartDataset& SetHoverBorderWidth(float hoverBorderWidth)
    {
        m_hoverBorderWidth = hoverBorderWidth;
        return *this;
    }

    inline BarChartDataset& SetHoverBorderRadius(float hoverBorderRadius)
    {
        m_hoverBorderRadius = hoverBorderRadius;
        return *this;
    }

    inline BarChartDataset& SetInflateAmount(float inflateAmt)
    {
        m_inflateAmount = inflateAmt;
        m_userInflateAmount = true;
        return *this;
    }

    inline BarChartDataset& SetMaxBarThickness(float maxBarThickness)
    {
        m_maxBarThickness = maxBarThickness;
        m_userMaxBarThickness = true;
        return *this;
    }

    inline BarChartDataset& SetMinBarLength(float minBarLength)
    {
        m_minBarLength = minBarLength;
        m_userMinBarLength = true;
        return *this;
    }

    inline BarChartDataset& SetLabel(const std::string& label)
    {
        m_label = label;
        return *this;
    }

    inline BarChartDataset& SetOrder(float order)
    {
        m_order = order;
        return *this;
    }

    inline BarChartDataset& SetSkipNull(bool skipNull)
    {
        m_isSkipNull = skipNull;
        return *this;
    }

    template <typename NumericType>
    inline friend std::ostream& operator<<(std::ostream& os, BarChartDataset<NumericType>& ds)
    {
        if (ds.m_data.empty())
            return os;

        /// Labels & Data..
        os << "label: '" << ds.m_label << "',"
           << "data: [";
        for (int i = 0; i < ds.m_data.size(); i++)
        {
            os << ds.m_data[i];
            if ((i + 1) != ds.m_data.size())
                os << ",";
        }
        os << "]";

        // Background Colors
        if (!ds.m_backGroundColors.empty())
        {
            os << ",backgroundColor: [";
            for (int i = 0; i < ds.m_backGroundColors.size(); i++)
            {
                os << ds.m_backGroundColors[i].ToHexColorCode();
                if ((i + 1) != ds.m_backGroundColors.size())
                    os << ",";
            }
            os << "]";
        }

        /// Bar Thickness & Bar Percentage/Category Percentage
        if (ds.m_userBarThickness)
            os << ",barThickness: " << ds.m_barThickness;
        else
        {
            if (ds.m_barPercentage != .9f)
                os << ",barPercentage: " << ds.m_barPercentage;
            if (ds.m_categoryPercent != .8f)
                os << ",categoryPercentage" << ds.m_categoryPercent;
        }

        /// Border Colors
        if (!ds.m_borderColors.empty())
        {
            os << ",borderColor: [";
            for (int i = 0; i < ds.m_borderColors.size(); i++)
            {
                os << ds.m_borderColors[i].ToHexColorCode();
                if ((i + 1) != ds.m_borderColors.size())
                    os << ",";
            }
            os << "]";
        }

        /// Border Width and Border Radius
        if (ds.m_borderWidth != 0)
            os << ",borderWidth: " << ds.m_borderWidth;
        if (ds.m_borderRadius != 0)
            os << ",borderRadius: " << ds.m_borderRadius;

        /// Grouped
        if (!ds.m_isGrouped)
            os << ",grouped: false";

        /// Hover Background Color and HoverBorderColor
        if (ds.m_userHoverBkgColor)
            os << ",hoverBackgroundColor: " << ds.m_hoverBkgColor.ToHexColorCode();
        if (ds.m_userHoverBorderColor)
            os << ",hoverBorderColor: " << ds.m_hoverBorderColor.ToHexColorCode();

        /// HoverBorderWidth and HoverBorderRadius
        if (ds.m_hoverBorderWidth != 1.0f)
            os << ",hoverBorderWidth: " << ds.m_hoverBorderWidth;
        if (ds.m_hoverBorderRadius != 0)
            os << ",hoverBorderRadius: " << ds.m_hoverBorderRadius;

        /// Inflate Amount
        if (ds.m_userInflateAmount)
            os << ",inflateAmount: " << ds.m_inflateAmount;

        // MaxBarThickness and MinBarLength
        if (ds.m_userMaxBarThickness)
            os << ",maxBarThickness: " << ds.m_maxBarThickness;
        if (ds.m_userMinBarLength)
            os << ",minBarLength: " << ds.m_minBarLength;

        /// Order and SkipNull
        if (ds.m_order)
            os << ",order: " << ds.m_order;
        if (ds.m_isSkipNull)
            os << ",skipNull: true";
        return os;
    }

private:
    std::vector<Color> m_backGroundColors;
    float m_barPercentage = .9f;
    float m_barThickness = 0.0f;
    std::vector<Color> m_borderColors = {};
    float m_borderWidth = 0.00f;
    float m_borderRadius = 0.0f;
    float m_categoryPercent = .8f;
    Color m_hoverBkgColor;
    Color m_hoverBorderColor;
    std::vector<NumericType> m_data;
    bool m_isGrouped = true;
    float m_hoverBorderWidth = 1.0f;
    float m_hoverBorderRadius = 0.0;
    float m_inflateAmount = 0.0f;
    float m_maxBarThickness = 0;
    float m_minBarLength = 0;
    std::string m_label;
    float m_order = 0;
    bool m_isSkipNull = false;
    bool m_userHoverBorderColor = false;
    bool m_userHoverBkgColor = false;
    bool m_userBarThickness = false;
    bool m_userInflateAmount = false;
    bool m_userMaxBarThickness = false;
    bool m_userMinBarLength = false;
};