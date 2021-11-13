use std::fmt;

pub struct CandyBar {
    pub brand: String,
    pub weight: f64,
    pub calorie: i64,
}

impl CandyBar {
    pub fn set_candy_bar(&mut self) {
        let mut input_str = String::new();
        println!("Enter brand name of a Candy bar:");
        std::io::stdin().read_line(&mut input_str).expect("Read Name Fail");
        self.brand = input_str.trim().parse().unwrap();
        println!("Enter weight of the candy bar:");
        input_str.clear();
        std::io::stdin().read_line(&mut input_str).expect("Read weight Fail");
        self.weight = input_str.trim().parse::<f64>().expect("parse f64 fail");
        input_str.clear();
        println!("Enter calories(an integer value) in the Candy bar:");
        std::io::stdin().read_line(&mut input_str).expect("Read calories Fail");
        self.calorie = input_str.trim().parse::<i64>().expect("parse i64 fail");
    }
    pub fn show_candy_bar(&self) {
        println!("{}", &self);
    }
}

impl fmt::Display for CandyBar {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        return write!(f, r#"Brand: {}
Weight: {}
Calorie: {}"#, self.brand, self.weight, self.calorie);
    }
}