mod candy_bar;

mod lab03_02 {
    use crate::candy_bar::candy_bar as CandyBar;

    pub(crate) fn main() {
        let mut read_str = String::new();
        let name: String;
        let weight: f64;
        let calories: i64;
        println!("Enter brand name of a Candy bar:");
        std::io::stdin().read_line(&mut read_str).expect("Read Name Fail");
        name = read_str.trim().parse().unwrap();
        println!("Enter weight of the candy bar:");
        read_str.clear();
        std::io::stdin().read_line(&mut read_str).expect("Read weight Fail");
        weight = read_str.trim().parse::<f64>().expect("parse f64 fail");
        read_str.clear();
        println!("Enter calories(an integer value) in the Candy bar:");
        std::io::stdin().read_line(&mut read_str).expect("Read calories Fail");
        calories = read_str.trim().parse::<i64>().expect("parse i64 fail");
        let candy_bar = CandyBar::CandyBar {
            name,
            weight,
            calories,
        };
        println!("{}", candy_bar);
    }
}

fn main() {
    lab03_02::main();
}