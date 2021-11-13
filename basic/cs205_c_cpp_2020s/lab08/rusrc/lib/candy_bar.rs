use std::fmt;

pub struct CandyBar {
    pub brand: String,
    pub weight: f64,
    pub calorie: i64,
}

impl CandyBar {
    // attention
    // Rust Do Not Have Overloading
    // like set(&mut CandyBar) and set(*mut CandyBar)
    pub fn set_ref(cb: &mut CandyBar) {
        let mut input_str = String::new();
        println!("Enter brand name of a Candy bar:");
        std::io::stdin().read_line(&mut input_str).expect("Read Name Fail");
        cb.brand = input_str.trim().parse().unwrap();
        println!("Enter weight of the candy bar:");
        input_str.clear();
        std::io::stdin().read_line(&mut input_str).expect("Read weight Fail");
        cb.weight = input_str.trim().parse::<f64>().expect("parse f64 fail");
        input_str.clear();
        println!("Enter calories(an integer value) in the Candy bar:");
        std::io::stdin().read_line(&mut input_str).expect("Read calories Fail");
        cb.calorie = input_str.trim().parse::<i64>().expect("parse i64 fail");
    }
    pub unsafe fn set_pointer(cb: *mut CandyBar) {
        let mut input_str = String::new();
        println!("Enter brand name of a Candy bar:");
        std::io::stdin().read_line(&mut input_str).expect("Read Name Fail");
        (*cb).brand = input_str.trim().parse().unwrap();
        println!("Enter weight of the candy bar:");
        input_str.clear();
        std::io::stdin().read_line(&mut input_str).expect("Read weight Fail");
        (*cb).weight = input_str.trim().parse::<f64>().expect("parse f64 fail");
        input_str.clear();
        println!("Enter calories(an integer value) in the Candy bar:");
        std::io::stdin().read_line(&mut input_str).expect("Read calories Fail");
        (*cb).calorie = input_str.trim().parse::<i64>().expect("parse i64 fail");
    }
    pub fn show_ref(ch: &CandyBar) {
        println!("{}", ch);
    }
    pub unsafe fn show_pointer(ch: *const CandyBar) {
        println!("{}", *ch);
    }
}

impl fmt::Display for CandyBar {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(f, r#"Brand: {}
Weight: {}
Calorie: {}"#, self.brand, self.weight, self.calorie);
    }
}