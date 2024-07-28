use std::fmt::Error;
use std::string::String;

fn devideIntOrError(x : i32, y : i32) -> Result<i32, String> {
    if y == 0 {
        return Error("{Error] : Can't Devide by zero.");
    }
    return Ok(x/y);
}

fn main() {
    println!("Hello, world!");
    match devideIntOrError(5, 0) {
        Ok(i32) => println!("{}", Ok.unwrap()),
        Error => println!("{}", Error.unwrap()),
    }
}
