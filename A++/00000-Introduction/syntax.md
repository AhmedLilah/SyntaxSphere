# Abstract Lnaguage Syntax

## variable types

- signed integers : `i8`, `i16`, `i32`, `i64`, (the max size is limited by the hardware platform)

- unsigned integers : `u8`, `u16`, `u32`, `u64`, (the max size is limited by the hardware platform)
  
- floating point : `f32`, `f64`, `f82`, (the max size is limited by the hardware platform)
  
- boolian : `bool` (usually an 8-bit as it's the lowes machines can go but should be flexable debending on the hardware platform)
  
- character : `char` (8-bit ascii enclosed by single quotes '')
  
- character sequence : `str` (char arry that is null terminated enclosed by single quotes '')
  
- String : `string` (UTF-8 String representation):

## Collections types

### Array :  a collection of elements of the same type stored in contiguous memory locations

  ```Abstract
  [var/const/let] <arrayName> [: \[<variableType, \] (required only if no value is supplied or the type of arry isn't deducable from the value)] [= {<value> [: <variableType], }];
  ```

### Tuple : basicly an unnamed fields struct

  ```Abstract 
  [var/const/let] <tupleName> [: \(<variableType, \) (required only if no value is supplied or the type of arry isn't deducable from the value)] [= (<value> [: <variableType>], )];
  ```

#### Tuple as function return types

  ```Abstract
  \(<variableType>, \)
  ```

  Example:
  
  ```Abstract
  fn getdata() -> (i32, f64, String);
  ```

#### TupleStructs : used to give a name to the tuple

  ```Abstract
  struct <tupleStructName> (<variableType>, );
  ```
  
  Example:
  
  ```Abstract
  struct color(i8, i8, i8, i8);
  ```

## variables declaration 

  ```Abstract
  let <variableName> [: <variableType> (required if the type couldn't be deducable from the value or the use cases in the code)] [= <value>];
  const <variableName> [\<<templateParameter>\>] [: <variableType> (if not deducable from the value)] = <value>;
  var [mut (indecates that the variable can be changed in const function)] <variableName> [\<<templateParameter>\>] [: <variableType> (if not dedcucable from the value or the is not initialized)] [= <value>];
  ```

  Example
  
  ```Abstract
    const pi : f64 = 3.14159265359;
    let R = 5.0;
    var area = pi*R^2;
    var mut refrenceCounter : u64 = 0;
  ```

## function declaration/implementation
  
  ```Abstract
  fn [[decl/impl] (for splitting declaration from implement)] <functionName> [\<<templateParameter>, \>] (<parameterName> [: <parameterType>], ) [<functionModifiers] [-> returnType] [{<functionImplementation>} (requred if not splitting)]
  ```
  
  Example:

  ```Abstract
  fn add<T,E>(first : T, second : E) -> T {
    return first + second;
  }


  fn decl mult (i32, i32) -> i64;

  fn impl mult (first : i32, second : i32) -> i64 {
    return first * second;
  }
  
  fn getData () const -> (i32, float) {
    refrenceCounter ++;
    return (self.integer, self.floating);
  }
  ```

## struct declaration : structs always use static disbatch

  ```Abstract
  struct <StructName> [[conc/:] <StructName>, (for concatinating structs)] {
  [public:/protected:/private:] (one is required to set the visiablity of the fields)
    <structFields> (same variable declaration convention);
  }
  ```

## struct implementation

  ```Abstract
  impl [[<TraitName>/<StructName>, for] <StructName> {
    <structLogicImplementation> (same as functions implementation)
  }
  ```

## class declaration : calsses use virtual tables or dynamic disbatch

  ```Abstract
  class <ClassName> [[inh/:] <ClassName>, (for inheriting classes)] {
  [public:/protected:/private:] (one is required to set the visiablity of the fields)
    <classFields> (same variable declaration convention);
  }
  ```

## class implementation : calsses use virtual tables or dynamic disbatch

  ```Abstract
  impl [<InterfaceName>/<ClassName>, for] <ClassName> {
    <ClassLogicImplementation> (same as functions implementation) 
  }
  ```
