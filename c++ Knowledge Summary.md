1/ How C++ works?

The preprocesser will PASTE a library or another file into the current file.

The main function is the entry point of every C++ program.

Operators are just a special kind of functions. For example,
1 + 2 is really just a function of adding 2 to 1.

Every cpp file will get compiled into a corresponding object file.

Sometimes, you use a function from another file in your current file. You could just have the function declaration in the current file!
Linker achieves this -- it sees the declaration and tries to find corresponding definition. At the same time, the linker combines the found definition and seen declaration, all together into an executable.

2/ How compilers works?

cpp files are - many translation units, if they are under a big project but never included in each other. For example, if you have one function declaration in your current file, and its definition in another, it still will have two translation units, two object files, and one executable.

cpp files are - only one translation unit, if they are included ultimately into one big cpp file. For example, if file A includes file B and file C, then there will be only only one translation unit, one cpp file, one object file, and one executable.

To demonstrate that #include is really just pasting things, we write a } in a header file called a.h. Then, in b.cpp, we delete a } and replace it with #include "a.h". Voilà, it works!

 #define A B -- this is a preprocesser statement that search for As in the current file and replace them with Bs. For example, #define INT int will basically replace INT to int.

 #if condition -- the code -- #endif 
this will run the surrounded code if the condition is true.

Remember that iostream is rather large!

3/ How linker works?

Even for one single cpp file to turn into an executable, linker is acting to 'link' the source code to the main function. For example, if we write a correct function, but we don't have a main function, if we simply choose to 'compile', there will be no error. However, if we choose to 'build', which includes linking, there will be an error.

Types of linking errors:

Unresolved external symbol -- this error happens when:

1) The function's declaration's return type in current file is different from the definition's return type.
2) The function's declaration in current file couldn't be linked to a definition with the same declaration.
3) NOTICE: if the current file contains a declaration, and it uses this declared function inside the main, even if the declaration doesn't have a corresponding definition outside, if we just 'compile', there will be no error!!!

4/ Variables

float -- 4 bytes
double -- 8 bytes
char a = 65 --> output is 'A'
bool really takes one bit ( 0 / 1), but we say it is one byte.
This means we could actually store 8 bools in a byte!!!

5/ Functions

methods -- functions inside a class
functions -- outside a class

main function is the only non-void function that doesn't require a return statement.

6/ Header Files

xxx.h --> contains all the declarations. 

 #pragma one --> it's in header files, to make sure that declarations are only once for each.

 #include <> / "" --> 
<> -- only for compiler default parts (cmath,cassert,iostream...)
""  -- everything (iostream, your own file...)

7/ Pointers

Pretty much everything we do in C++ is reading or writing to and from the main memory. Pointers help us achieve greater connection with the main memory.

All types of pointers are simply an integer, an address that points to a 'cell' in the main memory. Types are just what humans design to make things clear.

Define a null pointer: 

void* ptr = nullptr; // it's address is zero, which should never be used.

Find the address of an address of an assigned integer:
int var = 8;
void* ptr = &var; // & is used to return the address of the variable.

Dereferencing the pointer: enables you to access the data and write / read. 
 \*ptr = 10; // change the value inside the pointed address to be 10;

Deliberately allocating some memory:
char* buffer = new char[8];
memset(buffer, 0, 8); // pointer;what value to put in;how many.

Double Pointers:
char** ptr = &buffer; // return a pointer named buffer, which is 4 bytes if it's a 32-bit computer.

8/ References:

For example:
int a = 5;
int& ref = a;

Now, ref as a reference is only an alias, which means it doesn't really exist. Thus, if we run the program, there will only be one variable, which is a.

In functions, we could write the following parameters:
int* ptr --> pointer by copy. This means if you pass a pointer p into the int* ptr, if p points to A, then ptr also points to A.(two to one)
int* &ptr --> pointer by reference. This means if you pass a pointer p into the int* &ptr parameter, it will make p = ptr.(one to one)
__________________________________________________________________

void add(int value){
	value++;
}

int a = 5;
add(a);
std::cout << a; // 还是5！！！

void add(int& value){         void add(){
	value++;           <==>       int& value = a;
}							  }

Another way to modify:

void add(int* value){
	\*value++;
}
add(&a); // 相当于 int* value = &a;
__________________________________________________________________

Warning: If you have already declared a reference to A, you couldn't reassign it to B. This will change the value of A to the value of B.

To achieve this, we could only use pointers.

int a = 5;
int b = 8;
int* ref = &a;
\*ref = 2;
ref = &b;
\*ref = 1;

9/ Class vs. Struct

Class, by default, is private. For example, if you declare some properties inside a class and don't write public beforehand, they will be private properties.

Struct is otherwise extremely similar to class, except that it is public.


Struct could be a better choice if you simply want to write some plain old data (POD). For example, you write some vectors in double pairs.

Class could be a better choice if you want inheritence / complex functions.

10/ const

const int MAX_AGE = 100; // It's a promise, that a variable is not actually variable


11/ function template

template <typename a_name>
return type identifier(a_name param){
	statements
}

12/ namespace

namespace a_namespace {
	functions
}

when you call a function from the namespace group, a_namespace::func();

13/ Misc

// convert string to a char array
//std::string s = "geeksforgeeks";
//char char_array[s.length()];
//strcpy(char_array, s.c_str());


// all in one function
//bool process_line(){
//    1. bool continue_func = true;
//
//    2. define the variables you need. Input data and store in them.

//    3. if (termination condition){
//        continue_func = false;
//        return continue_func;
//    }
//    4. use other functions here to achieve the output
//
//    5. return continue_func;
//    }
//    6. in main() only write --> while(process_line()){}

// pass an array to a function with a ptr parameter:
// char a[] = {'a','b','c'};
// func(char \*a);
//func(a); see, you could directly pass the array variable into a ptr parameter.
// convert int array to string --> std::to_string(int_value);

14/ Virtual Functions --> Similar to abstract functions

virtual + original_function

override + new_function















