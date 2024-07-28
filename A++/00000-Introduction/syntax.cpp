// Language Philosophy
Abstract:
	Multi-Level
	Orthogonal Features
	Performance
	Efficiency
	Fixability
	Zero overhead abstractions














/* Keywords */
allignas allignof and as assert asm async atomic await b8 b16 b32 b64 b128 b512 bit bool break byte catch char
class comptime continue const default Defer delete do enum explicit export extern evaluate f16 f32 f64 f80 f128
false final fn friend for global goto i8 i16 i32 i64 i128 impl import in include inf inline inout interface is
isize label language let match module move mutable namespace nan New noexcept none not null nullptr operator or
out override panic private proc protected public raise return self sizeof static struct switch sync test throw
throws trait true Try type typeof u8 u16 u32 u64 u128 undefined union usize var virtual void volatile while xor yield













/* Operators */
+ .+ Pre ++ Post ++ - .- Pre -- Post -- * .* pre * ** .** *** *** *** / ./ , “ ” ““ ”” “““ ””” ‘ ’ ‘‘ ’’ ‘‘‘ ’’’ ` `
`` `` ``` ``` ` ``` [] () {} [||] #[ ]# #{ }# #()# <> < > = == === : .: :. .:. :: ::: -> << >> . .. ... ; | || & &&
% %% $ $$ ? ?? ! !! @ # ^ ~ _ __ <- => <=> \ \\ // /// /* */


// unary logical operators
not

// binary logical operators
and or xor

// ternary operators
?:

// unary bitwise operators
~
// binary bitwise operators
& | ^ << >>

// shorthand bitwise operators
&= |= ^=

// unary arithmetic operators
pre++ post++ pre-– post-- .’ .” .`

// binary arithmetic operators
+ .+ - .- * .* / ./ \ .\ % .% ** .** 

// shorthand arithmetic operators
+= .+= -= .-= *= .*= /= ./= \= .\= .*= %= .%= **= .**=

// Binary comparison operators
== != < <= > >= <=> 
=/= // what should that do.

// other custom operators that might be used
// comma\expression separator\ operator
,
// end of expression\statement operator
;
// ignore_return\default_case operator
_
// … operator
__
// pipe operator
|
// object member access
.
// … operator
..
// packing\unpacking operator
...
// inclusive range operator
:
// left exclusive range operator
.:
// right exclusive range operator
:.
// exclusive range operator
.:.
// scope resolution operator
::
// … operator
:::
// pointer dereferencing to member operator
->
// pointer dereferencing to member operator
->*
// match expression operator
=>
// … operator
<-
// pass by value operator
$

// UTF8 String enclosing operator
“ ”
// UTF16 String enclosing operator
““ ””
// UTF32 multiline string enclosing operator
“““ ”””
// ascii char enclosing operator
‘ ’
// c-style char* string operator
‘‘ ’’
// multiline cString enclosing operator
‘‘‘ ’’’
// cString enclosing operator
` `
// c-style string operator
`` ``
// multiline cString enclosing operator
``` ```
// string escape prefix\backward division operator
***
// string escape prefix\backward division operator
*** ***
// string escape prefix\backward division operator
\
// single line comment operator
//
// multiline comment enclosing operator
/* */
// documentation comment operator
///

// function call\tuple operator
()
// subscripting\indexing operator
[]
// … operator
[||]
// lambda expression operator
[](){}
// scope\list\struct operator
{}
// template parameter\documentation tags operator
<>
// … operator
#[ ]#
// … operator
#{ }#
// … operator
#()#
//  operator
===
// c pointer\pointer dereferencing operator
*
// address of\pass by reference operator
&
// moved operator
?
// moved operator
??
// moved operator
!
// moved operator
!!
// … operator
#
// … operator
@
// … operator
%%
// … operator
$$




















/* Default Types */
// bitwise types. Going from b128 and upwards it could be represented as a struct of smaller types.
b8, b16, b32, b64, b128, b256, b512 // Support all operations
bit, byte // I really want to add these but I thing the above are better.

// Boolean type.
bool

// Signed\unsigned integer types. All of them can be used as suffixes after number literals.
// They don’t support bitwise or logical operations 
i8, i16, i32, i64, i128 
u8, u16, u32, u64, u128

// Signed\unsigned architecture based indexing integer type
isize, usize

// Floating point types. All of them can be used as suffixes after number literals.
f16, f32, f64, f80, f128

// Characters & Strings
char


// keeps the value of the variable undefined (essentially it leaves what ever garbage in the memory the same.
Undefined

// keeps the value of the variable undefined (essentially it leaves what ever garbage in the memory the same.
void

// keeps the value of the variable undefined (essentially it leaves what ever garbage in the memory the same.
anyerror

// keeps the value of the variable undefined (essentially it leaves what ever garbage in the memory the same.
Undefined	

&	// Defining a references to a type.

*	// Defines a wide pointer.

@ 	// Defines a C-style pointer.

[N]	// Defines an array of a type. If [<N>] isn’t provided the array size is deduced from the number of elements. If the array is not initialized then [<N>] must be provided.

[_]	// Defines an array of deducible size

[]	// Defines a Slice

[*]	// Defines a pointer to an unknown number of items (C array)

[!]	// Defines a Slice

[?]	// Defines a Slice



/* Variable Definitions */
// declares a mutable variable .
vartName        : type <TP, NTTP> variableQualifiers var   = initialValue;

// automatically deduces the type of the of variable based on the value or the return type of functions.
constName       : type <TP, NTTP> constantQualifiers const = initialValue;

// automatically deduces the type of the of variable based on the value or the return type of functions.
functionalConst : type <TP, NTTP> let                      = initialValue; 

// automatically deduces the type of the of variable based on the value or the return type of functions.
compTimeConst   : type <TP, NTTP>                          : initialValue; 

volatile // Defines a C++ like volatile variable/const.
static // Defines a C++ like static variable.

global // Defines a global variable used in multiple source files. This works only in the global scope.
extern // Declares a global that is defined in another source file.












/* Procedure & Function Definitions */
// declares a mutable variable .
procName :: proc <TP, NTTP> (parameterName : parameterType) : procQualifiers -> returnType, returnType {
	// implementation…; 
}

fnName	 :: fn	 <TP, NTTP> (parameterName : parameterType) : fnQualifiers   -> returnType, returnType {
	// implementation…; 
}


parameterType // parameter type can be a Concrete type, Trait, Interface, or Concept.


// auto template by default and compiler gets the requirements from the use of the body of the function.
procName :: proc (parameterName) : procQualifiers {
	for element in  parameterName{
		std::println(element);
	} 
}

// same as
procName :: proc<T : impl std::range> (parameterName) : procQualifiers {
	for element in  parameterName{
		std::println(element);
	} 
}

// Every thing in a procedure definition is optional except the proc keyword and the name with the minor
// addition that in the case of no function body the function statement should end with ‘;’. The idea
// is that this should help with prototyping without 
 procName :: proc; // This is ok for prototyping purposes. It’s immediately invalidated once another overloading is detected. 


// auto template by default and compiler gets the requirements from the use of the body of the function.
fnName :: fn (parameterName, indx=0) : procQualifiers {
	if parameterName.length() > current index {
		std::println(parameter[indx]);
		fnName(parameterName, ++indx);
	} 
}

// same as 
fnName :: fn <parameterName : impl indexable> (parameterName, indx=0) : procQualifiers {
	if parameterName.length() > current index {
		std::println(parameter[indx]);
		fnName(parameterName, ++indx);
	}
}
// Every thing in a function definition is optional except the fn keyword and the name with the minor
// addition that in the case of no function body the function statement should end with ‘;’. The idea
// is that this should help with prototyping without 
fnName :: fn; // This is ok for prototyping purposes. It’s immediately invalidated once another overloading is detected. 


// In the case of proc/fn if the template parameters are specified to impl <trait name> this means that it must be struct that implements the mentioned type trait. If extends <interface name> this means that it must be a class that extends the mentioned interface. If <concept name> this means any thing for which the concept is valid.
















/* Error Hadling */
// Error handling should be handled by an error value. Such as the Result type in rust or std::expected in C++
 
// all proc/fn are noexcept by default.
throws(ExceptionType, ExceptionType) // for declaring the types of exceptions a proc\fn can throw.




















/* Types Definitions  */
// creates a named-tuple/tuple-struct like rust’s.
TupleName :: Tuple <TP, NTTP> (
	type <TP, NTTP> variableQualifiers var   = initialValue, 
	type <TP, NTTP> constantQualifiers const = initialValue, 
);

// Similar to C++ and Rust struct creates a structure of elements that we can bind procedures or function to it. This happens statically by default and if needed we can make it dynamically using virtual procedure/function tables like C++.
impl TraitName, TraitName for TupleName {
	 // The &self is optional.
	 procName :: proc <TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s {
		 // implementation…; // Can be ignored if the Trait have a default implementation.
	}
	 // The &self is optional.
	 fnName :: fn TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s {
		 // implementation…; // Can be ignored if the Trait have a default implementation.
	}
}

// Similar to C++ and Rust struct creates a structure of elements that we can bind procedures or function to it. This happens statically by default and if needed we can make it dynamically using virtual procedure/function tables like C++.
StructName :: struct <TP, NTTP> conc ConcStructName<TP, NTTP>, ConcStructName<TP, NTTP> {
	vartName      : type <TP, NTTP> variableQualifiers var   = initialValue; 
	constName     : type <TP, NTTP> constantQualifiers const = initialValue; 
	comptimeConst :: type <TP, NTTP> let                      = initialValue; 
}

// trait methods should always be public. private interface methods doesn’t make any sense.
TraitName :: trait<TP, NTTP> {
	// The &self is optional.
	procName :: proc <TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s; // Can have a default implementation. 

	 // The &self is optional.
	fnName :: fn <TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s; // Can have a default implementation.
}


// Similar to C++ and Rust struct creates a structure of elements that we can bind procedures or function to it. This happens statically by default and if needed we can make it dynamically using virtual procedure/function tables like C++.

impl TraitName, TraitName for StructName {
	 // The &self is optional.
	 procName :: proc <TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s {
		 // implementation…; // Can be ignored if the Trait have a default implementation.
	}
	 // The &self is optional.
	 fnName :: fn TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s {
		 // implementation…; // Can be ignored if the Trait have a default implementation.
	}
}

// Similar to dynamic languages class creates a class print of elements that we can bind procedures or function to it. This happens dynamically by default and if needed we can make it dynamically using virtual procedure/function tables like C++.
ClasstName :: class <TP, NTTP> extend ExtendClassName<TP, NTTP>, ExtendClassName<TP, NTTP> {
	vartName      : type <TP, NTTP> variableQualifiers var   = initialValue; 
	constName     : type <TP, NTTP> constantQualifiers const = initialValue; 
	comptimeConst :: type <TP, NTTP> let                      = initialValue; 
}

// interface methods should always be public. private interface methods doesn’t make any sense.
InterfaceName :: interface <TP, NTTP> {
	// The &self is passed by default unless proc/fn is marked static.
	procName :: proc <TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s; // Can have a default implementation. 

	// The &self is passed by default unless proc/fn is marked static.
	fnName :: fn <TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s; // Can have a default implementation.
}

// Similar to C++ and Rust struct creates a structure of elements that we can bind procedures or function to it. This happens statically by default and if needed we can make it dynamically using virtual procedure/function tables like C++.

impl InterfaceName, InterfaceName for ClasstName {
	// The &self is passed by default unless proc/fn is marked static.
	 procName :: proc <TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s {
		 // implementation…; // Can be ignored if the Interface have a default implementation.
	}
	// The &self is passed by default unless proc/fn is marked static.
	 fnName :: fn TP, NTTP>(&slef, parameterName : parameterType) : procIdentifiers 
		-> returnType/s {
		 // implementation…; // Can be ignored if the Interface have a default implementation.
	}
}

// enum declaration loop
EnumName :: enum {
	enumIntegerField,
	enumTypedField : type,
	enumStructureField {type, type, type},
	enumStructureField {namedField : type, namedField : type},
	enumFunction(enumFunctinParameter, enumFunctinParameter), 
	
}

// enum implementation loop
impl EnumName {
	proc functionName(&self, parameter : type) {		 // implementation…;
	}
	fn functionName(&self, parameter : type) {
		 // implementation…;
	}
}


// CV qualifiers allowed only allowed in non-static member proc/fn.
const // for marking a proc/fn that it doesn’t change it’s object values.
volatile // for marking a proc/fn that it doesn’t change it’s object values.

// ref qualifiers allowed only allowed in non-static member proc\fn.
& // for marking a function that works on l-value references
&& // for marking a function that works on R-value references

// exception specification for any proc\fn.
noexcept // for marking a proc\fn that it doesn’t throw any exceptions.
throws ExceptionType, ExceptionType // for declaring the types of exceptions a proc\fn can throw.
// If the throws keyword came before the return operator i.e. “->” then the function throws C++ like 
// exceptions that needs to be handled via try-catch blocks.

// If the throws keyword came after the return operator i.e. “->” then the function throws Rust like 
// exceptions that needs to be handled via unwrapping.















/* Flow Control */
// goto branching.
// this is not order dependent.
goto labelName;
labelName :: label;

// switch statement for value based pattern matching.
switch valueType\weekEnum {
	case valueEvaluatedExpression:{};
		expression;
	case valueEvaluatedExpression:
		expression;
		break;
	default: 
		expression;
		break;
}

// switch statement for value based pattern matching.
Switch (valueType\weekEnum) {
	case (valueEvaluatedExpression) {
		 expressions;
		 break;
	}
	case (valueEvaluatedExpression) {
		 expressions;
		 break;
	}
	default: 
		 expression or break;
}

// match statement for strongly typed language supported tagged enum pattern matching similar to rust.
match valueType\weekEnum\strongEnums {
	(valueEvaluatedExpression) => { expressions },
	(valueEvaluatedExpression) => { expressions },
	(valueEvaluatedExpression) => { expressions },
	_ => { expressions }
}

if (localInitializedVariable; boolianEvaluatedExpression) {
	// implementation…; 
} else if (boolianEvaluatedExpression) {
	// implementation…; 
} else {
	// implementation…; }

if (localInitializedVariable; boolianEvaluatedExpression) 
	// implementation…;
else
	// implementation…;





















/* Loops */
// infinite loop
loopName :: loop {
	// implementation…; 
}

// pre-checking while loop
whileLoopName :: while (localInitializedVariable; boolianEvaluatedExpression) {
	// implementation…;
}

// post-checking while loop
doWhileLoopName :: do {
	// implementation…; 
} while (localInitializedVariable; boolianEvaluatedExpression);

// the name of the loop is optional an is preferred for the cases where it’s used with continue/break.
// loop names are scope limited to the scope of the loop itself.

// for loop
forLoopName :: for (initialization; boolianEvaluatedExpression; changeExpression) {	// implementation…;
}

// range based for loop
forLoopName :: for capturingElementInitialization in iterableCollection {	// implementation…;
	continue;
	break;
}


// the name of the loop is optional an is preferred for the cases where it’s used with continue/break.
// loop names are scope limited to the scope of the loop itself.

// used to skip the current loop iteration.
continue;

// used to break free of the scoop of the current loop and continue the program execution flow.
break;

// used to skip the current iteration of the loop specified by the name given that were’re currently inside this loop block.
// can’t access loop names outside their scope.
continue loopName;

// used to break free of the scoop of the named loop and continue the program execution flow.
// can’t access loop names outside their scope.
break loopName;

