pub mod lab07_01 {
    pub fn display_menu() {
        println!(
            r#"====================================================
                          MENU
====================================================
   1.Add
   2.Subtract
   3.Multiply
   4.Divide
   5.Modulus"#);
    }

    pub fn add(a: i64, b: i64) -> i64 {
        a + b
    }

    pub fn subtract(a: i64, b: i64) -> i64 {
        a - b
    }

    pub fn multiply(a: i64, b: i64) -> i64 {
        a * b
    }

    pub fn divide(a: i64, b: i64) -> i64 {
        a / b
    }

    pub fn modulus(a: i64, b: i64) -> i64 {
        a % b
    }
}