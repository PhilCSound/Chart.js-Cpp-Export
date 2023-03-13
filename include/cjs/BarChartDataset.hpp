#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include "Color.hpp"

/// @brief Class used to contain the data in a bar chart.
/// @tparam NumericType that should support the << operator
template <typename NumericType>
class BarChartDataset
{
public:
    /// @brief Constructor.
    /// @param data std::vector of a templated Numerical Type that supports << operator.
    /// @param title Optional, but if provided provides a label for this dataset on the chart.
    BarChartDataset(const std::vector<NumericType>& data = {}, const std::string& title = "")
         : m_label(title), m_data(data) {};

    /// @return Returns a const std::vector of Colors that are used to color the bars of this dataset.
    inline const std::vector<Color> GetBackGroundColors() const
    {
        return m_backGroundColors;
    }

    /// @brief Percent (0-1) of the available width each bar should be within the category width. 1.0 will take the whole category width and put the bars right next to each other.
    /// @return Returns a const float value that should be in the range 0 - 1.0. Default being .9f.
    inline const float GetBarPercentage() const
    {
        return m_barPercentage;
    }

    /// @brief If this value is a number, it is applied to the width of each bar, in pixels. When this is enforced, barPercentage and categoryPercentage are ignored.
    /// @return Returns the current BarThickness. Default is 0.0f if set to anything different, it will be enabled.
    inline const float GetBarThickness() const
    {
        return m_barThickness;
    }

    /// @return Returns a const std::vector of Colors that are used to color the borders of the bars of this dataset.
    inline const std::vector<Color> GetBorderColors() const
    {
        return m_borderColors;
    }

    /// @return Returns the current setting for border width, default set to 0.0f.
    inline const float GetBorderWidth() const
    {
        return m_borderWidth;
    }

    /// @return Returns the radius value used to round the edges of the bars in the dataset.
    inline const float GetBorderRadius() const
    {
        return m_borderRadius;
    }

    /// @return Percent (0-1) of the available width each category should be within the sample width.
    inline const float GetCategoryPercentage() const
    {
        return m_categoryPercent;
    }

    /// @return Returns a copy of the bar color used when a bar is hovered.
    /// @todo This could be converted to a vector of colors.
    inline const Color GetHoverBackgroundColor() const
    {
        return m_hoverBkgColor;
    }

    /// @return Returns a copy of the border color used when a bar is hovered.
    /// @todo This could be converted to a vector of colors.
    inline const Color GetHoverBorderColor() const
    {
        return m_hoverBorderColor;
    }

    /// @return Returns a copy of the numerical data in the dataset.
    inline const std::vector<NumericType> GetData() const
    {
        return m_data;
    }

    /// @param index Index begining at 0, of the data you wish to check.
    /// @warning This function is not bounds checked and will likely throw exceptions if out of bounds
    /// @return Returns a copy of the numerical data at index in the dataset.
    inline const NumericType GetDataAt(uint32_t index) const
    {
        return m_data[index];
    }

    /// @return Returns the current setting for hover border width, default set to 1.0f.
    inline const float GetHoverBorderWidth() const
    {
        return m_hoverBorderWidth;
    }

    /// @return Returns the radius value used to round the edges of the bars in the dataset when hovered.
    inline const float GetHoverBorderRadius() const
    {
        return m_hoverBorderRadius;
    }

    /// @brief This option can be used to inflate the rects that are used to draw the bars. 
    ///This can be used to hide artifacts between bars when barPercentage * categoryPercentage is 1.
    /// @return Returns the current inflate amount. Defaulted to 0.0 which is 'auto' in chart.js.
    inline const float GetInflateAmount() const
    {
        return m_inflateAmount;
    }

    /// @return Returns the value used to ensure that bars are not sized thicker than this.
    inline const float GetMaxBarThickness() const
    {
        return m_maxBarThickness;
    }

    /// @return Returns the value used to ensure that bars are not sized smaller than this.
    inline const float GetMinBarLength() const
    {
        return m_minBarLength;
    }

    /// @return Returns a copy of the string used to label the dataset.
    inline const std::string GetLabel() const
    {
        return m_label;
    }

    /// @return Returns a float used to indicate the draw order of this dataset.
    inline const float GetOrder() const
    {
        return m_order;
    }

    /// @return Returns a bool chart.js uses to skip null values, which is hard to do in C++ I'd imagine, but its here.
    inline const bool IsSkipNull() const
    {
        return m_isSkipNull;
    }

    /// @brief Sets the Colors that are used to color the bars of this dataset. Colors will be reused in order of the vector if there is more data than colors in the vector.
    ///If colors are not set, Chart.js will use it's default colors. 
    /// @param colors 
    inline BarChartDataset& SetBackgroundColors(std::vector<Color>& colors)
    {
        m_backGroundColors = colors;
        return *this;
    }

    /// @brief Percent (0.0f-1.0f) of the available width each bar should be within the category width. 1.0 will take the whole category width and put the bars right next to each other.
    ///Defaulted to .9f.
    inline BarChartDataset& SetBarPercentage(float barPercentage)
    {
        m_barPercentage = barPercentage;
        return *this;
    }

    /// @brief If this value is a number, it is applied to the width of each bar, in pixels. When this is enforced, barPercentage and categoryPercentage are ignored.
    ///Default is 0.0f if set to anything different, it will be enabled.
    inline BarChartDataset& SetBarThickness(float barThickness)
    {
        m_barThickness = barThickness;
        m_userBarThickness = true;
        return *this;
    }

    /// @brief Sets the std::vector of Colors that are used to color the borders of the bars of this dataset.
    inline BarChartDataset& SetBorderColors(std::vector<Color>& colors)
    {
        m_borderColors = colors;
        return *this;
    }

    /// @brief Sets the current setting for border width, by default set to 0.0f which uses Chart.js default width.
    inline BarChartDataset& SetBorderWidth(float borderWidth)
    {
        m_borderWidth = borderWidth;
        return *this;
    }

    /// @brief Sets the radius value used to round the edges of the bars in the dataset.
    inline BarChartDataset& SetBorderRadius(float radius)
    {
        m_borderRadius = radius;
        return *this;
    }

    /// @brief Sets the Percent (0-1) of the available width each category should be within the sample width. See chart.js website for more info.
    inline BarChartDataset& SetCategoryPercentage(float categoryPer)
    {
        m_categoryPercent = categoryPer;
        return *this;
    }

    /// @brief Sets the bar color used when a bar is hovered.
    /// @todo This could be converted to a vector of colors.
    inline BarChartDataset& SetHoverBackgroundColor(Color& hoverBkgColor)
    {
        m_hoverBkgColor = hoverBkgColor;
        m_userHoverBkgColor = true;
        return *this;
    }

    /// @brief Sets the border color used when a bar is hovered.
    /// @todo This could be converted to a vector of colors.
    inline BarChartDataset& SetHoverBorderColor(Color& hoverBorderColor)
    {
        m_hoverBorderColor = hoverBorderColor;
        m_userHoverBorderColor = true;
        return *this;
    }

    /// @brief Copies the data of the vector passed into the dataset.
    /// @param data Vector of NumericType, to be copied.
    inline BarChartDataset& SetData(std::vector<NumericType>& data)
    {
        m_data = data;
        return *this;
    }

    /// @brief Set the bars border width on hover, default set to 0.0f.
    inline BarChartDataset& SetHoverBorderWidth(float hoverBorderWidth)
    {
        m_hoverBorderWidth = hoverBorderWidth;
        return *this;
    }
    
    /// @brief Set the bars border radius on hover.
    inline BarChartDataset& SetHoverBorderRadius(float hoverBorderRadius)
    {
        m_hoverBorderRadius = hoverBorderRadius;
        return *this;
    }

    /// @brief This option can be used to inflate the rects that are used to draw the bars. 
    ///This can be used to hide artifacts between bars when barPercentage * categoryPercentage is 1.
    /// @param inflateAmt What to set the inflate amount. Defaulted to 0.0 which is 'auto' in chart.js.
    inline BarChartDataset& SetInflateAmount(float inflateAmt)
    {
        m_inflateAmount = inflateAmt;
        m_userInflateAmount = true;
        return *this;
    }

    /// @brief Sets the value used to ensure that bars are not sized thicker than this.
    inline BarChartDataset& SetMaxBarThickness(float maxBarThickness)
    {
        m_maxBarThickness = maxBarThickness;
        m_userMaxBarThickness = true;
        return *this;
    }

    /// @brief Sets the value used to ensure that bars are not sized smaller than this.
    inline BarChartDataset& SetMinBarLength(float minBarLength)
    {
        m_minBarLength = minBarLength;
        m_userMinBarLength = true;
        return *this;
    }

    /// @brief Sets the string used to label the dataset.
    inline BarChartDataset& SetLabel(const std::string& label)
    {
        m_label = label;
        return *this;
    }

    /// @brief Sets the float used to indicate the draw order of this dataset.
    inline BarChartDataset& SetOrder(float order)
    {
        m_order = order;
        return *this;
    }

    /// @brief Sets a bool chart.js uses to skip null values, which is hard to do in C++ I'd imagine, but its here.
    inline BarChartDataset& SetSkipNull(bool skipNull)
    {
        m_isSkipNull = skipNull;
        return *this;
    }

    /// @brief Used by the BarChart class to format the dataset to chart.js. This doesn't output working HTML/JS code.
    /// @tparam NumericType that supports the << operator.
    /// @param os Outsteam
    /// @return Outstream
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
        if (ds.m_borderWidth != 0.0f)
            os << ",borderWidth: " << ds.m_borderWidth;
        if (ds.m_borderRadius != 0.0f)
            os << ",borderRadius: " << ds.m_borderRadius;

        /// Hover Background Color and HoverBorderColor
        if (ds.m_userHoverBkgColor)
            os << ",hoverBackgroundColor: " << ds.m_hoverBkgColor.ToHexColorCode();
        if (ds.m_userHoverBorderColor)
            os << ",hoverBorderColor: " << ds.m_hoverBorderColor.ToHexColorCode();

        /// HoverBorderWidth and HoverBorderRadius
        if (ds.m_hoverBorderWidth != 1.0f)
            os << ",hoverBorderWidth: " << ds.m_hoverBorderWidth;
        if (ds.m_hoverBorderRadius != 0.0f)
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
    /// @brief Vector of colors used to color the bars. If not set uses Chart.js defaults.
    std::vector<Color> m_backGroundColors;

    /// @brief Percentage used to determine bar size. 1.0 being 100%. Default .9f
    float m_barPercentage = .9f;

    /// @brief Float used to determine bar thickness, not used if not set. Default 0.0f
    float m_barThickness = 0.0f;

    /// @brief Vector of colors used to color bar borders. If not set uses Chart.js defaults.
    std::vector<Color> m_borderColors = {};

    /// @brief Float used to determine bar width. Default 0.0f.
    float m_borderWidth = 0.0f;

    /// @brief Float used to determine bar radius (curved corners), defaulted to 0.0f.
    float m_borderRadius = 0.0f;

    /// @brief Default .8f, Percent (0-1) of the available width each category should be within the sample width.
    float m_categoryPercent = .8f;

    /// @brief Color bar background on hover. @todo Make a vector.
    Color m_hoverBkgColor;

    /// @brief Color bar background on hover. @todo Make a vector.
    Color m_hoverBorderColor;

    /// @brief This is the dataset that contains the numerical data of the dataset.
    std::vector<NumericType> m_data;

    /// @brief Float used to determine bar width on hover. Default 1.0f.
    float m_hoverBorderWidth = 1.0f;

    /// @brief Float used to determine bar width on hover. Default 0.0f.
    float m_hoverBorderRadius = 0.0;

    /// @brief used to inflate the rects that are used to draw the bars. This can be used to hide artifacts between
    /// bars when barPercentage * categoryPercentage is 1. The default value should work in most cases.
    float m_inflateAmount = 0.0f;

    /// @brief Float used to determine max bar thickness, not used if not set. Default 0.0f
    float m_maxBarThickness = 0.0f;

    /// @brief Float used to determine min bar length, not used if not set. Default 0.0f
    float m_minBarLength = 0.0f;

    /// @brief String used to label the dataset.
    std::string m_label;

    /// @brief Draw order.
    float m_order = 0.0f;

    /// @brief Chart.js is false by default so its here, but should be pretty hard to have null values in the chart with this.
    bool m_isSkipNull = false;

    /// @brief If the user changed the hoverborder color this is true, @todo if changed to vector this would be obsolete.
    bool m_userHoverBorderColor = false;

    /// @brief If the user changed the hoverbackground color this is true, @todo if changed to vector this would be obsolete.
    bool m_userHoverBkgColor = false;

    /// @brief If the user changed the barThickness this is true and will be exported when converted to file.
    bool m_userInflateAmount = false;

    /// @brief If the user changed the max barThickness this is true and will be exported when converted to file.
    bool m_userMaxBarThickness = false;

    /// @brief If the user changed the min barLength this is true and will be exported when converted to file.
    bool m_userMinBarLength = false;
};