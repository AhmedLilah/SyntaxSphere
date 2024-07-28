trait TestTrait {
    fn testFunction(&self) -> String;
}

struct TestStruct {
    x : String,
}

impl TestStruct {
    pub fn new(x : String) -> TestStruct {
        return TestStruct { x: x };
    }
}
impl TestTrait for TestStruct {
    fn testFunction(&self) -> String {
        return "implicit trait conformance.".to_string();
    }
}

fn test(a : impl TestTrait) {
    println!("{}", a.testFunction());
}

fn main() {
    let x = TestStruct::new("Hi".to_string());
    test(x);
}
