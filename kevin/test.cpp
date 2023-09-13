
#include <iostream>

namespace Number
{
#define NUMBER_OF_ITEMS_A_NORMAL_SHELF_CAN_HOLD 4

    class Container
    {
    public:

        Container(float value = 0) : m_Contents(value) {}

        float &GetContents()
        {
            return &m_Contents;
        }

        virtual void SetContents(float value) { m_Contents = value; }

    private:
        float m_Contents;
    };

    class IntegerContainer : public Container
    {
        IntegerContainer(int value) : m_IntContents(value) {}
        ~IntegerContainer() { std::cout << "Destructing IntegerContainer" << std::endl; }

        int GetContents()
        {
            return m_IntContents;
        }

        void SetContents(float value) { m_IntContents = static_cast<int>(value); }

        int m_IntContents;
    };

    class Shelf
    {
    public:

        Shelf(int size = NUMBER_OF_ITEMS_A_NORMAL_SHELF_CAN_HOLD) : m_ContentsSize(size)
        {
            m_Contents = new Container[size];
        }

        void AddContainer(const Container &c)
        {
            for (auto i = 0; i < m_ContentsSize;)
            {
                if (!m_Contents[i])
                {
                    m_Contents[i] = const_cast<Container*>(&c);
                    break;
                }

                ++i;
            }
        }

        float CalculateContainedSum()
        {
            float total = 0;

            for (auto i = 0; i < m_ContentsSize; ++i)
            {
                if (m_Contents[i])
                {
                    total += m_Contents[i]->GetContents();
                }
            }

            return total;
        }

        int m_ContentsSize;
        Container **m_Contents;
    };


}


using namespace Number;

int main()
{
    Shelf normalShelf;
    Shelf smallShelf(2);
    Shelf bigShelf(8);

    Container smallValue(0.3f);
    IntegerContainer integerValue(2.5);
    Container bigValue(0.7f);

    bigShelf.AddContainer(smallValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    bigShelf.AddContainer(smallValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    bigShelf.AddContainer(integerValue);
    bigShelf.AddContainer(bigValue);
    smallShelf.AddContainer(bigValue);
    smallShelf.AddContainer(integerValue);
    smallShelf.AddContainer(smallValue);

    smallValue.SetContents(1.1f);
    integerValue.SetContents(6.5);
    bigValue.SetContents(8.9f);

    normalShelf.AddContainer(bigValue);
    normalShelf.AddContainer(integerValue);
    normalShelf.AddContainer(smallValue);

    std::cout << "Big shelf contains: " << bigShelf.CalculateContainedSum() << std::endl;
    std::cout << "Small shelf contains: " << smallShelf.CalculateContainedSum() << std::endl;
    std::cout << "Normal shelf contains: " << normalShelf.CalculateContainedSum() << std::endl;
}
