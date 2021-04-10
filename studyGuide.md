# Chapter 13

	## Operator Overloading
		
		• To overload an operator, you must write an operator function
			- Operator function format: ```c++ returnType operator operatorSymbol(formal parameter list);```
			- Example:                                ```c++bool operator==(const clockType& otherClock) const;```
	
		• ```c++ ()	 []	 ->	  = ```   	 must be overloaded from within a class definition if used with a class.
			
		• Notable restrictions on operator overloading
			- You cannot change operator precedence
			- Associativity cannot be changed 
			- You cannot use default parameters
			- You cannot create new operators
			- You cannot overload some operators (```c++ .    .*   ::   ?:   sizeof()   ```)
		
		• Some overloaded operators (<< and >> notably) cannot be a part of the class itself, but still need access
	           to the data members of the class (public and private). Using the keyword friend at the front of a function 
	           declaration gives the function access to all the data members of the given class. The keyword friend is only  
	           included in the function declaration. 
	
		• class1.operator=(class2) is an equally valid way to write class1 = class2 test
	
		• Example of function overloading:
		```c++rectangleType rectangleType::operator* (const rectangleType& rectangle) const 
    { 
      rectangleType tempRect;   //del
      
      tempRect.length = length * rectangle.length; 
      tempRect.width = width * rectangle.width; 
      
      return tempRect; 
    }
		```
	## 'This' Keyword 
		• The keyword this is a pointer to the current object. It is commonly used to call other methods from within the same class. For example, ```c++ this->listKiller()``` could be written inside a destructor to call the 'listKiller' method.
		• It is common to return a whole object by doing return *this. Doing so allows you to chain method calls.
		For example. You could do ```c++ myRectangle.setLength(15.25).setWidth(12.00)``` as the first method (setLength) will return the object. Essentially, by returning *this from our function, we allow ourselves to write 
		```c++ myRectangle.setLength(15.25)``` and ```c++myRectange.setWidth(12.00)``` in a single line. If you use Python, this is how method chaining works in Python too.
	
	## Templates
	

	## Misc.
	```C++->```  is a shorthand for ```c++(*someObject).someObjectMember```

# Chapter 14


# Chapter 15


# Chapter 16

