#include "stack.hpp"
#include <iostream>
#include <iostream>
int main()
{
    Stack<int> intStack;

    intStack.push(5);
    intStack.push(10);
    intStack.push(15);

    std::cout << "Stack size: " << intStack.size() << std::endl;

    while (!intStack.empty())
    {
        std::cout << "Top element: " << intStack.top() << std::endl;
        intStack.pop();
    }

    
    return 0;
    
    
    
    
    

    
    

    
    
    
    

    return 0;
}
