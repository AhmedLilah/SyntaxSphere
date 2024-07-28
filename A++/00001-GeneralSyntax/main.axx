std :: #import "std";

// enums
ASTDataEnum :: enum {
        FOR,
        IMPL,
        AS,
}

// classes and interfaces
FormatableInterface :: interface {
        format :: proc() -> std.string;                                                 // this mehtod is by deafult publi, virtual, and pure unless otherwise specified.
}

Shape2D :: interface  {
        perimeter :: proc() -> f64;                                                     // this mehtod is by deafult publi, virtual, and pure unless otherwise specified.
        area :: proc(s : std.string) -> f64;                                            // this mehtod is by deafult publi, virtual, and pure unless otherwise specified. 
}

LessThanComparableInterface :: interface {
        operator < :: (other : self) -> bool;
}

CopiableInterface :: interface {
        operator = :: (other : self) -> &self;
}

SortableInterface :: interface = LessThanComparableInterface + CopiableInterface;      // this interface is a superset of the two interface "LessThanComparableInterface" and "CopiableInterface".

Square :: class extends Shape2D, FormatableInterface {
        sideLength : f64,
}

Square.perimeter :: proc() -> f64 {
        return 4 * self.sideLength;
}

Square.area :: proc() -> f64 {
        return std.math.pow(self.sideLength, 2);
}

Circle :: class extends Shape2D {
        radius : f64,
}

Circle.perimeter :: proc() -> f64 {
        return 2 * std.math.PI * self.radius;
}

Circle.area :: proc() -> f64 {
        return std.math.PI * std.math.pow(self.radius, 2);
}


// structs 
StructTrait :: trait {
        format :: proc(metadata : std.string,
                    data : ASTNodeData,
                    leftNode : ASTNode, 
                    rightNode : ASTNode
                   ) 
                   -> std.string;
        
        pointer :: proc (&self) -> * {
                return &self;
        }

        setMember :: proc (& mut self, memberData : MemberType)  {
                self.member = memberData;
        }
}

ASTNodeStruct :: struct {
        metadata  : std.string,
        data      : ASTNodeData,
        leftNode  : ASTNode,
        rightNode : ASTNode,
}


// procedures
ASTNode.left :: proc(&self);

add :: proc<T : SupportPlusOperator>(x : T, y : T) -> T {
        return x+y;
}

// loops
loop {
        collectionIterationLoop :: for (i := 0; i <5; ++i) {
                for( j := 0; j < 10; ++j) {
                        if not j%2 {
                                continue collectionIterationLoop;
                        }
                }
        }
}

// concepts
Sortable :: concept<T>(a : T, b : T) {
        a < b -> bool;
        a = a;
        a <- b
}

prototypProc :: proc; // this is a procedure  prototype.

main :: proc() -> i32 {
        largeInteger : i64 = 50;
        normalInteger := 30;
        largeInteger = normalInteger; // acceptable because i64 is an integer type that supsumes the i32 range.
        normalInteger = largeInteger; // this is an error because conversion from i64 to i32 is my include overflow.
        return 0;
}
