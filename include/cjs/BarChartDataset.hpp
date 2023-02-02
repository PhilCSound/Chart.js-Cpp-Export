#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
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
        BarChartDataset(const std::string& title);

        const std::vector<Color> GetBackGroundColors() const;
        const float GetBarPercentage() const;
        const float GetBarThickness() const;
        const std::vector<Color> GetBorderColors() const;
        const float GetBorderWidth() const;
        const float GetBorderRadius() const;
        const float GetCategoryPercentage() const;    
        const Color GetHoverBackgroundColor() const;
        const Color GetHoverBorderColor() const;
        const std::vector<NumericType> GetData() const;
        const NumericType GetDataAt(uint32_t index) const;
        const bool IsGrouped() const;
        const float GetHoverBorderWidth() const;
        const float GetHoverBorderRadius() const;
        const float GetInflateAmount() const;
        const float GetMaxBarThickness() const;
        const float GetMinBarLength() const;
        const std::string GetLabel() const;
        const float GetOrder() const;
        const bool IsSkipNull() const;

        BarChartDataset& SetBackgroundColors(std::vector<Color>& colors);        
        BarChartDataset& SetBarPercentage(float barPercentage);
        BarChartDataset& SetBarThickness(float barThickness);
        BarChartDataset& SetBorderColors(std::vector<Color>& colors);
        BarChartDataset& SetBorderWidth(float borderWidth);
        BarChartDataset& SetBorderRadius(float radius);
        BarChartDataset& SetCategoryPercentage(float categoryPer) ;
        BarChartDataset& SetHoverBackgroundColor(Color& hoverBkgColor);
        BarChartDataset& SetHoverBorderColor(Color& hoverBorderColor) ;
        BarChartDataset& SetData(std::vector<NumericType>& data);
        BarChartDataset& SetDataAt(uint32_t index, NumericType data);
        BarChartDataset& SetGrouped(bool grouped);
        BarChartDataset& SetHoverBorderWidth(float hoverBorderWidth);
        BarChartDataset& SetHoverBorderRadius(float hoverBorderRadius);
        BarChartDataset& SetInflateAmount(float inflateAmt);
        BarChartDataset& SetMaxBarThickness(float maxBarThickness);
        BarChartDataset& SetMinBarLength(float minBarLength);
        BarChartDataset& SetLabel(const std::string& label);
        BarChartDataset& SetOrder(float order);
        BarChartDataset& SetSkipNull(bool skipNull);
        const std::string ToString();

    private:
        std::vector<Color> m_backGroundColors;
        float m_barPercentage = .9f;
        float m_barThickness = 0.0f;
        std::vector<Color> m_borderColors = { Color(0, 0, 0, 25) };
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

#pragma once
#include "BarChartDataset.cpp"