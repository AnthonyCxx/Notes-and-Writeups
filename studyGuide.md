# 1720 Study Guide
## This is a free resource; I am not responsible for any discrepancies

## Chapter 13 - Operator Overloading and Templates

### Operator Overloading
		
 #### To overload an operator, you must write an operator function <br />
- Operator function format: ```returnType operator operatorSymbol(formal parameter list);``` <br />
- Example:                  ```bool operator==(const clockType& otherClock) const;``` <br />
	
	```(),  [],  ->,  = ``` must be overloaded from within a class definition if used with a class.
			
#### Notable restrictions on operator overloading <br />
- You cannot change operator precedence <br />
- Associativity cannot be changed  <br />
- You cannot use default parameters <br />
- You cannot create new operators <br />
- You cannot overload some operators ``` .    .*   ::   ?:   sizeof()``` <br />
		
- Some overloaded operators (<< and >> notably) cannot be a part of the class itself, but still need access <br /> 
  to the data members of the class (public and private). Using the keyword friend at the front of a function  <br />
  declaration gives the function access to all the data members of the given class. **The keyword friend is only   <br />
  included in the function declaration**.  <br />
	
```class1.operator=(class2)``` is an equally valid way to write ```class1 = class2``` <br />
	
#### Some Cases of Overloading...
##### Example of function overloading in a class: <br />
``` c++
rectangleType rectangleType::operator* (const rectangleType& rectangle) const 
{ 
      rectangleType tempRect;   //delcare a temporary rectangle object (goes out of scope when the function ends)
      
      tempRect.length = length * rectangle.length; 
      tempRect.width = width * rectangle.width; 
      
      return tempRect; 
}
```

##### Example of operator overloading outside of a class: <br />
```c++
returnType operator#(const className& firstObject, const className& secondObject)
{
 	//algorithm to perform the operation
 	return value;
}
```

##### Overloading the Stream Insertion and Extraction Operators (Special Case!):
```c++
friend ostream& operator<<(ostream&, const className&);		//declaration

ostream& operator<<(ostream& osObject, const className& cObject)   //instantiation
{
   osObject << cObject.someAttribute << endl;    //You can directly access the member because it's a friend function!
}
```

##### Overloading the = Operator (performs a deep copy):
```c++
//Overloading the '=' operator is important because it only performs a shallow copy by default
const arrayClass& arrayClass::operator=(const arrayClass& rightObject)
{
 //local declaration, if any
 	if (this != &rightObject)    //avoid self-assignment
 	{
 		delete [] list;      //Delete the current instantiation of the list (otherwise this list would just append items)
		
 		maxSize = otherList.maxSize;    //Copy data members
 		length = otherList.length; 
 		list = new int[maxSize]; 
		
 		for (int i = 0; i < length; i++) 5    //Copy data values sequentially
 			list[i] = otherList.list[i]; 
 		
		return *this;				//Return *this
 	}
}
```

### 'This' Keyword 
- The keyword this is a pointer to the current object. It is commonly used to call other methods from within the same class. For example, ```this->listKiller()``` 
  could be  written inside a destructor to call the 'listKiller' method. <br />

- It is common to return a whole object by doing ```return *this```. Doing so allows you to chain method calls. <br />
  For example. You could do ```myRectangle.setLength(15.25).setWidth(12.00)``` as the first method (setLength) will return the object. Essentially, by returning 
  ```*this``` from our function, we allow ourselves to write  ```myRectangle.setLength(15.25)``` and ```myRectange.setWidth(12.00)``` in a single line.
  If you use Python, this is how method chaining works in Python too. <br />
  
- **It is necessary to use ```this->``` when using a method or data member inherited from a base class.**
	
### Templates

#### General Template Format
```c++
template <class Type>
variable/function declaration;
```

##### Example : Templated Comparison Function
```c++
template <class Type>    
Type larger(Type x, Type y)
{
   if (x >= y)		
      return x;
   else
      return y;
}
```

- When declaring **or** referencing a templated variable, you must also specify the data type. For example, you declare an integer array from an array template as <br />
```c++
arrayTemplate<int> thisArray;
```
	

#### Misc.
- ```->```  is a shorthand for ```(*someObject).someObjectMember``` <br />
- To overload the ```++``` operator, you have to specify whether it is the pre- or post-increment operator. You do so by adding a dummy variable, which <br />
  will allow the compiler to differentiate. With no dummy variable, the operator is pre-increment; with a dummy variable, the operator is post-increment. <br />
  You can use an integer as this dummy value and just pass '0' every time. <br />
- Most methods can be overloaded as either a member or non-member function, but some cannot (```<<``` and ```>>```) <br />

## Chapter 14 - Exception Handling

### \<cassert\>
- \<cassert\> is an exception-handling library used by programmers to end their code pre-maturely in the case of what would be a fatal error. <br />
   The entire library consists of a single function, which aborts the program if the user-specified condition is not true. This allows you to make <br />
   sure that everything is always in order. Now, the errors thrown from \<cassert\> aren't very helpful to the end-user, so \<cassert\> should only be 
   used by the programmer. 
 
 - Side note: since 0 always evaluates to false, you can put something like 'assert(0);' at the end of a switch statement for the default value 
              (assuming you never want to run into a default value)

### Try, Throw, and Catch
- Try, throw, and catch are the three exception-handling keywords that help out the user understand the problem. The primary difference is that 
  using try, throw, and catch will not end the program, but instead execute a different section of code (an error message, usually), whereas 
  \<cassert\> straight-up kills the program.

#### Example : Catching a Division by Zero Error with Try, Throw, and Catch
```c++
#include <iostream> 
#inlucde <string>
using namespace std; 

int main() 
{ 
	try
	{
		int dividend = 0, divisor = 0, quotient = 0; 
		string divisionByZeroError = "You cannot divide by zero";
		
 		cout << "Enter a dividend: ";   //The number to be divided
 		cin >> dividend; 
		cout << endl; 
 		
		cout << "Enter a divisor: ";    //The number to divide by
 		cin >> divisor; 
 		cout << endl; 
	
		if (divisor == 0)
		    throw divisionByZeroError;	    //Breaks out of the 'try' statement if thrown
		
 		quotient = dividend / divisor;     //Divide the dividend by the divisor
 	
		cout << "The quotient is " << quotient << endl; 
 
		return 0;
	}
	catch(string zeroErr)	//Catch by data type -- since 'zeroErr' is a string, and a string (divisionByZeroError)
	{                      // was thrown, this statement will catch it
		cout << "Error: " << zeroErr << endl;    //cout << "Error: " << "You cannot divide by zero" << endl;
	}
}
```
- Here, you can see a try, throw, and catch statement trio. Here's how it works: for any block of code that you expect an error may occur in, 
  you should put the statements in a try block. Then, write a conditional that throws a some data-type (usually a string) that evaluates to true if the 
  program _would_ have run into an error. This will immediately exit the try block whenever that error would have been thrown. Since you're throwing an error, 
  you will also need to catch it. The 'catch' statement activates whenever an exception (error) is thrown, and which catch statement activates depends 
  on the data-type being thrown. 
  
  ##### Catching Other Errors
  If you want to catch any data type, write 'catch(...)' (this is for variadic statements, which were introduced in C++11. You can put this at the end of a series 
  of catch statements to make sure you catch everything.
  
  ### Exception Classes with Try, Throw, and Catch
  - One of the more efficent ways to catch errors is to write a class that can handle errors by taking in a string in its parameterized constructor (this
    saves you from having to declare tons of different strings for every error). Here is an example of what a divisionByZero class should look like.
```c++
#include <iostream> 
#include <string> 

using namespace std; 
class divisionByZeroError 
{ 
	public: 
 	divisionByZeroError()
 	{ 
 	    cmessage = "You cannot divide by zero"; 
 	} 
 	divisionByZeroError(string inputStr) 
 	{ 
 	    cmessage = inputStr; 
 	} 
 	string what() 
 	{ 
 	    return cmessage;
 	} 
	
	private: 
            string cmessage; 
}; 
 ```
 Now with this class, you could just throw ```divisionByZeroError("someErrorMessage")```  for custom error messages <br />
 or ```divisionByZeroError()``` for the default one. In this case, you would need to instantiate a divisionByZeroError object <br />
 call ```divisionByZeroErrorObject.what()``` to get the error message.

## Chapter 15 - Recursion
- Recursion is the simple idea that a function can call itself. Obviously, this would cause an infinite loop, so you should have a base case <br />
  that should break the recursion loop when it gets to a simple enough answer. A common example would be calculating a factorial. <br />
  
  ### Recursion
  ```c++
  int factorial(int targetNumber){
 	if (num == 0)
 	  return 1;
 	else
 	  return targetNumber * factorial(targetNum - 1);
  }
  ```
  int factorial(int) -- a function which takes the factorial of a number <br />
  TargetNumber -- the number you want to calculate the factorial of <br />
  
  The function factorial calls itself with the ```targetNumber - 1``` whenever the target number is not 0. So, what happens is the function creates
  replicas of itself until it reaches the base case (0) and then starts returning the numbers it needs to actually calculate the factorials. <br />
  
  The problem with recursion is that it involves an exponential amount of function calls, which are inefficient in both memory and processing speed -- 
  This is because each new instance of the function has overhead involved and declares its own local variables; moreover, a function instance cannot 
  deinstantiate until the calls it relies on finish. If you want a convenient approach, go with recursion, but if you want an efficient one, go with iteration. 

#### Example of Recusion with a Recursive Binary Search
```c++
  // C++ program to implement recursive Binary Search
#include <bits/stdc++.h>
using namespace std;
  
// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}
  
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
  
```
[Adapted from This GeeksForGeeks Article](https://www.geeksforgeeks.org/binary-search/)

## Chapter 16 - Linked Lists and Iterators

### Linked Lists Data Structure
- Linked lists are similar to arrays in that they are both a series of individual items, but the main difference is the way they are stored 
  in memory. Arrays are contiguous, which means that you have to have enough consecutive space in memory to store one, which becomes a problem 
  when you have massive arrays. Linked lists on the other hand are non-contiguous, so you don't have to store them consecutively. This allows 
  for having more individual nodes. Now, the only drawback with linked lists is that you have to have some way to connect the nodes (indices) 
  together, which is done by using a pointer. This means that since each individual element of a linked list is composed of the actual data 
  **and** the pointer to the next node in the linked list, each individual element requires more memory. Essentially, linked lists are a little
  more versatile but require more memory.
  
  #### Nodes (the indivdual elements)
  
  Now that you understand what a node (item) in a linked list is, let's have a look at an individual node in one:
  ```c++
  template <class Type>
  struct nodeType       
  {
    Type info;                     //The information held by that node
    nodeType<Type> *link;    //Pointer to the info! Not an actual instance of a nodeType variable
  };
  ```
  Here you can see a struct _nodeType_ that defines an individual node (item) in a linked list. You can see that it's composed of some data (of varied type). 
  Additionally, you can see that it contains a nodeType<Type> pointer that points to the next item in the linked list. It's important that you include the \*, 
  otherwise the program will not compile since a struct cannot contain itself (it would cause an infinite loop). 
  
  #### Linked List Data Members
  ```c++
  template <class Type>
  class linkedListType
  {    
	protected:       
	    int count;  //number of elements in the list
            nodeType<Type> *first;  //point to first node
            nodeType<Type> *last;   //point to last node
             
	    ...the other methods 
  }
  ```
  In this excerpt from our lab12 linkedList.h, you can see the rest of the data members for a linked list - the count and the pointers to the first and last elements 
  in the list. The count is self-explanatory, it's the amount of items in the list (\*first and \*last are pointers, and thus are not counter by 'count'). 
  When you have an empty linked list, the pointers \*first and \*last should both be ```nullptr``` to prevent dangling pointers. Otherwise, they should 
  point to the first and last nodes in the linked list respectively, as those pointers are the _only_ way to keep track of the list. If you lose track of  the 
  \*first pointer in particular, you will lose the entire list and all that memory will be leaked.
  
  #### Linked List Implementation
 
Here is the excerpt our implementation of the methods of a linked list from lab12
```c++
//Default constructor
template <class Type>
linkedListType<Type>::linkedListType()
{
   first = nullptr;    //Instantiates an empty linked list -- a linked list with no nodes
    last = nullptr;
   count = 0;
}

template <class Type>
linkedListType<Type>::~linkedListType()
{
   listKiller();     //Refer to listKiller()
}

//front() -- returns the data from the first node
template <class Type>
Type linkedListType<Type>::front() const
{
   assert(first != nullptr);   //Prevent calling data from a null pointer
   return first->info;           //Return the data from the first node
}

//back() -- returns the data from the last node
template <class Type>
Type linkedListType<Type>::back() const
{
   assert(last != nullptr);   //Refer to first() for comments
   return last->info;
}

//isEmpty()
template <class Type>
bool linkedListType<Type>::isEmpty() const
{
   return first==nullptr;    //List is empty if count is 0 or the *first pointer is nullptr
}

//print() -- iterate over the list and print out values as it goes
template <class Type>
void linkedListType<Type>::print() const
{
   nodeType<Type> *cur=first;    //set the pointer to the first node

   while(cur != nullptr)     //the last item equals nullptr, so this means iterate until you reach the end of the list 
   {
      cout << cur->info << " ";		//output the info for that node
      cur = cur->link;                     //follow the link from that node
   }
}

template <class Type>
int linkedListType<Type>::length() const
{
   return count;	//count is the amount of elements (aka the length of the linked list)
}

//Copy consturctor
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
   first = nullptr;	
   copyList(otherList); 	//Refer to copyList()
}

//Overloaded operator= =
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
   if(this != &otherList) 	//avoid self-assignment
      copyList(otherList);		//Refer to copyList()
   return *this;

}

//copyList()
template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{        
   //If the current list is not empty, empty it
   if(this->first != nullptr) 
   {
      listKiller();	//Refer to listKiller()
   }
   
   //If the list to be copied is empty, set the new list to empty
   if(otherList.first == nullptr)
   {
      //the source list is empty
      first = last = nullptr;
      count = 0;  
   } 
   else //if the other list is not empty...
   {
      nodeType<Type> *curPtr;
      nodeType<Type> *newNode;
   
      count = otherList.count;	//copy the count
      
      //point to first node in the other list
      curPtr = otherList.first;
      
      //setup the new list with the first node
      first = new nodeType<Type>;
      first->info = curPtr->info;
      first->link = nullptr;
     
      //get ready to copy the rest of the list to
      //the new list.  last will track the new list
      //while curPtr will track the other list. 
      last = first;
      curPtr = curPtr->link; 
      
      while(curPtr != nullptr) {
         newNode = new nodeType<Type>;
         newNode->info = curPtr->info;
         newNode->link = nullptr;
        
         //tie in new node on end of the new list 
         last->link = newNode;
         last = newNode;
        
         //move to the next node in the other list. 
         curPtr = curPtr->link;
      }
   }
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
   linkedListIterator<Type> temp(first);	//return an iterator pointing to the first node
   return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
   linkedListIterator<Type> temp(nullptr);	//return an iterator to the last node (the last node is always nullptr, so no need to do last)
   return temp;
}

//listKiller()
template <class Type>
void linkedListType<Type>::listKiller()
{
   //Declare a temporary node
   nodeType<Type> *tmp;

   //Iterate over all nodes, deleting them as it goes
   while(first!= nullptr) 
   {
      tmp = first;
      first = first->link;
      delete tmp; 
   }

   //Change class values to indicate an empty list
   last = nullptr;
   //first is implicitly set to nullptr because the it followed the link from before the last element, which set it to nullptr
   count = 0;
}

```
  
  
 ### Iterators
 An iterator is quite simple - an iterator is an object that contains a pointer and some methods for working with the pointer more easily.
 Here is a look at the example linked list iterator from our book:
 
 ```c++
 //****************** linkedListIterator Declaration *****************************
 template <class Type>
 class linkedListIterator
 {
	public:
 	linkedListIterator();
 	//Default constructor
 	//Postcondition: current = nullptr;
 	
	linkedListIterator(nodeType<Type> *ptr);
 	//Constructor with a parameter.
 	//Postcondition: current = ptr;
 
 	Type operator*();
 	//Function to overload the dereferencing operator *.
 	//Postcondition: Returns the info contained in the node.
 
 	linkedListIterator<Type> operator++();     
 	//Overload the pre-increment operator.
 	//Postcondition: The iterator is advanced to the next
	 // node.
 
 	bool operator==(const linkedListIterator<Type>& right) const;
 	//Overload the equality operator.
 	//Postcondition: Returns true if this iterator is equal to
 	// the iterator specified by right,
 	// otherwise it returns false.
 
 	bool operator!=(const linkedListIterator<Type>& right) const;
 	//Overload the not equal to operator.
 	//Postcondition: Returns true if this iterator is not equal
 	// to the iterator specified by right,
 	// otherwise it returns false.

	private:
 	nodeType<Type> *current; //pointer to point to the current
 	//node in the linked list
 };
 
 
 
 //********************** linkedListIterator Implementation ***************************
 template <class Type>
 linkedListIterator<Type>::linkedListIterator()
 {
     curptr = nullptr;		//iterator defaults to nullptr
  }
 
 template <class Type>
 linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)  //takes a _pointer_ to a nodeType!
 {
     curptr = ptr;	//iterator is set to the given pointer
 }
 
 template <class Type>
 Type linkedListIterator<Type>::operator*()
 {
    assert(curptr != nullptr);
     return curptr->info;		//return the current info
 }
 
 template <class Type>
 linkedListIterator<Type> linkedListIterator<Type>::operator++()
 {
    assert(curptr != nullptr)
    curptr = curptr->link;		//follow the current link
    return *this;			//return the iterator
 }
 
 template <class Type>
 bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
 {
    return (curptr == right.curptr);		//compare two iterators
 }

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
    return (curptr != right.curptr);		//compare the addresses of the two items
}
```
 LinkedListIterator Example taken from [C++ Programming: Program Design Including Data Structures by D.S. Malik](https://www.amazon.com/Programming-Program-Design-Including-Structures/dp/1337117560/ref=sr_1_22?dchild=1&keywords=C%2B%2B+programming+eighth+edition&qid=1618090926&sr=8-22)
 
 This class is pretty simple, it's just a pointer called ```current``` with a few overloaded operators. You need the extra pointer because without <br />
 another pointer, you would lose track of \*first or \*last, both of which would be bad.
 
 | Operator | Function                                            |
 | -------- | --------------------------------------------------- |
 | *        | Returns ```current->info``` of the current object   |
 | ++       | Increments the pointer to the next node in the list |
 | ==       | Returns ```current == other.current```              |
 | !=       | Returns ```current != other.current```              |

 
 # End of Study Guide 
