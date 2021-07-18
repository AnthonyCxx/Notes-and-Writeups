# Anatomy of a C++ Program
Here is an analysis of a simple C++ program.

```C++
#include <iostream>
using namespace std;

int main()
{
    // This is a comment

    /*
        This is a multi-line comment
    */

    cout << "Hello, world!" << endl;

    return 0;
}
```

## The _main()_ function
A function is a block of code that performs an action. The _main()_ function is where every C++ program starts. Naturally, this means there can only be one _main()_ function
and the name _main()_ must be written verbatim. 

## Return 0
