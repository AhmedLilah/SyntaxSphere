import std;

// C-like function declaration
// UFCS-style (Unified Function Calling Syntax)
void print(T)(T x, string a = "      ")  {
        std.stdio.writeln(a, x);
}

// template function
T add(T)(T a, T b) {
        return a+b;
}

struct Person {
        uint age;
        string name;
}

class Employee {
        this() {
                age = 0;
                name = "";
                pointer = null;
        }

        this(Person * p) {
                pointer = p;
        }

        this(int a, string n) {
                age = a;
                name = n;
                pointer = null;
        }

        uint age;
        string name;
        Person * pointer;
}

void main()  {
        string name = "Ahmed";
        int x = 13;
        float y;
        y = 4.3;
        std.stdio.writeln(name, x, y);
        x.print();

        float z = add(x, y);
        z.print();


        Person ahmed = { 25, "Ahmed"};
        ahmed.age.print();
        ahmed.name.print();

        // class instanciation must be done using the new keyword;
        // using the constructor.
        Employee sabry = new Employee(65, "Sabry");
        sabry.age.print();
        sabry.name.print();

        // class instanciation must be done using the new keyword.
        // when using the default constructor the braces are optional.
        Employee anon = new Employee;
        anon.age.print();
        anon.name.print();

        Employee reff = new Employee(& ahmed);
        reff.pointer.age.print();
        reff.pointer.name.print();


        int[5] array = [0, 1, 2, 3, 18];
        array[0].print();
        array[4].print();

        "************".print();
        for(int i=0; i<5; ++i) {
                array[i].print();
        }
}
