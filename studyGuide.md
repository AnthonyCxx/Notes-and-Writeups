# 1720 Study Guide
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
	
#### Special Cases of Overloading...
##### Example of function overloading in a class: <br />
``` c++
rectangleType rectangleType::operator* (const rectangleType& rectangle) const 
{ 
      rectangleType tempRect;   //del
      
      tempRect.length = length * rectangle.length; 
      tempRect.width = width * rectangle.width; 
      
      return tempRect; 
}
```

##### Example of operator overloading outside of a class: <br />
```c++
returnType operator#(const className& firstObject,
const className& secondObject)
{
 	//algorithm to perform the operation
 	return value;
}
```

##### Overloading the Stream Insertion and Extraction Operators:
```c++
friend ostream& operator<<(ostream&, const className&);		//declaration

ostream& operator<<(ostream& osObject, const className& cObject)   //instantiation
{
 //local declaration, if any
 //Output the members of cObject.
 //osObject << . . .
 //Return the stream object.
 return osObject;
}
```

##### Overloading the = Operator:
```c++
const arrayClass& arrayClass::operator=(const className& rightObject)
{
 //local declaration, if any
 	if (this != &rightObject)//avoid self-assignment
 	{
 		delete [] list; //Delete the current instantiation of the list
		
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
- The keyword this is a pointer to the current object. It is commonly used to call other methods from within the same class. For example, ```this->listKiller()```  <br />
  could be  written inside a destructor to call the 'listKiller' method. <br />

- It is common to return a whole object by doing return \*this. Doing so allows you to chain method calls. <br />
  For example. You could do ```myRectangle.setLength(15.25).setWidth(12.00)``` as the first method (setLength) will return the object. Essentially, by returning 
  ```*this``` from our function, we allow ourselves to write  ```myRectangle.setLength(15.25)``` and ```myRectange.setWidth(12.00)``` in a single line. <br />
  If you use Python, this is how method chaining works in Python too. <br />
	
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
- ```->```  is a shorthand for ```c++(*someObject).someObjectMember``` <br />
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
 
 - Side note: since 0 always evaluates to false, you can put something like 'assert(0);' at the end of a switch statement for the default value <br />
              (assuming you never want to run into a default value)

### Try, Throw, and Catch
- Try, throw, and catch are the three exception-handling keywords that help out the user understand the problem. The primary difference is that <br />
  using try, throw, and catch will not end the program, but instead execute a different section of code (an error message, usually), whereas <br />
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
- Here, you can see a try, throw, and catch statement trio. Here's how it works: for any block of code that you expect an error may occur in, <br />
  you should put the statements in a try block. Then, write a conditional that throws a some data-type (usually a string) that evaluates to true if the <br />
  program _would_ have run into an error. This will immediately exit the try block whenever that error would have been thrown. Since you're throwing an error, <br />
  you will also need to catch it. The 'catch' statement activates whenever an exception (error) is thrown, and which catch statement activates depends <br />
  on the data-type being thrown. 
  
  ##### Catching Other Errors
  If you want to catch any data type, write 'catch(...)' (this is for variadic statements, which were introduced in C++11. You can put this at the end of a series <br />
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


## Chapter 16 - Linked Lists

