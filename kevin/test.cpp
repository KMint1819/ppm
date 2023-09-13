
#include "test.h"
#include <iostream>

using Kevin::Container;
using Kevin::Shelf;

int main()
{
    Shelf normalShelf;
    Shelf smallShelf(2);
    Shelf bigShelf(8);

    Container smallValue(0.3f);
    Container integerValue(2.5);
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
