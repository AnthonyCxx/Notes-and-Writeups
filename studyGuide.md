# 1720 Study Guide
## Chapter 13

### Operator Overloading
		
 #### To overload an operator, you must write an operator function <br />
	- Operator function format: ```returnType operator operatorSymbol(formal parameter list);``` <br />
	- Example:                  ```bool operator==(const clockType& otherClock) const;``` <br />
	
	```()	 []	 ->	  = ```   	 must be overloaded from within a class definition if used with a class.
			
#### Notable restrictions on operator overloading <br />
- You cannot change operator precedence <br />
- Associativity cannot be changed  <br />
- You cannot use default parameters <br />
- You cannot create new operators <br />
- You cannot overload some operators ```c++ .    .*   ::   ?:   sizeof()   ``` <br />
		
Some overloaded operators (<< and >> notably) cannot be a part of the class itself, but still need access <br /> 
to the data members of the class (public and private). Using the keyword friend at the front of a function  <br />
declaration gives the function access to all the data members of the given class. The keyword friend is only   <br />
included in the function declaration.  <br />
	
```c++ class1.operator=(class2)``` is an equally valid way to write ```c++ class1 = class2 ``` <br />
	
#### Example of function overloading: <br />
```c++rectangleType rectangleType::operator* (const rectangleType& rectangle) const 
{ 
      rectangleType tempRect;   //del
      
      tempRect.length = length * rectangle.length; 
      tempRect.width = width * rectangle.width; 
      
      return tempRect; 
}
```

### 'This' Keyword 
The keyword this is a pointer to the current object. It is commonly used to call other methods from within the same class. For example, ```c++ this->listKiller()```  <br />
could be  written inside a destructor to call the 'listKiller' method. <br />

It is common to return a whole object by doing return \*this. Doing so allows you to chain method calls. <br />
For example. You could do ```myRectangle.setLength(15.25).setWidth(12.00)``` as the first method (setLength) will return the object. Essentially, by returning \*this  <br />
from our function, we allow ourselves to write  ```c++ myRectangle.setLength(15.25)``` and ```c++myRectange.setWidth(12.00)``` in a single line. If you use Python, <br />
this is how method chaining works in Python too. <br />
	
### Templates
	

## Misc.
```C++->```  is a shorthand for ```c++(*someObject).someObjectMember``` <br />

## Chapter 14


## Chapter 15


## Chapter 16

