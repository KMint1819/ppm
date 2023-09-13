#pragma once

#include <any>
#include <iostream>
#include <optional>
#include <variant>
#include <vector>

namespace Kevin
{
const int NUMBER_OF_ITEMS_A_NORMAL_SHELF_CAN_HOLD = 4;

class Container
{
  public:
    using Type = std::variant<int, float, double>;

    template <typename T> Container(T value = 0) : m_Content(value)
    {
    }

    Type GetContents()
    {
        return m_Content;
    }

    template <typename T> void SetContents(T value)
    {
        m_Content = value;
    }

  private:
    Type m_Content;
};

class Accumulator
{
  public:
    template <typename T> void operator()(T i)
    {
        ans += i;
    }

    float getAnswer()
    {
        return ans;
    }

  private:
    float ans = 0.f;
};

class Shelf
{
  public:
    Shelf(int size = NUMBER_OF_ITEMS_A_NORMAL_SHELF_CAN_HOLD) : m_Contents(size)
    {
    }

    void AddContainer(Container c)
    {
        for (int i = 0; i < m_Contents.size(); i++)
        {
            if (!m_Contents[i])
            {
                m_Contents[i] = c;
                break;
            }
        }
    }

    float CalculateContainedSum()
    {
        Accumulator accumulator;

        for (int i = 0; i < m_Contents.size(); i++)
        {
            if (m_Contents[i])
            {
                std::visit(accumulator, m_Contents[i]->GetContents());
            }
        }

        return accumulator.getAnswer();
    }

  private:
    std::vector<std::optional<Container>> m_Contents;
};
} // namespace Kevin
