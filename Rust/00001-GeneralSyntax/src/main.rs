// mod lib;

// use crate::lib::person::Person;
// use crate::lib::project::Project;
// use crate::lib::honk;

#[derive(Debug, Clone)]
struct MyStruct {
    pub x : String,
    pub y : i8,
}

fn consume(x : MyStruct) {
    _ = x;
}

fn main() {
    let mystruct = MyStruct{x: "Hi".to_string(), y : 4i8};
    consume(mystruct.clone());
    println!("MyStruct{{{}, {}}}", mystruct.x, mystruct.y);
}
