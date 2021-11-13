pub mod lib;

mod lab04_02 {
    use crate::lib::candy_bar::candy_bar::CandyBar as CandyBar;

    pub(crate) fn main() {
        let mut candy_bars: Vec<CandyBar> = Vec::new();
        let mut read_str = String::new();
        for _ in 0..3 {
            let mut pushed = CandyBar::default();
            println!("Enter brand name of a Candy bar:");
            std::io::stdin().read_line(&mut read_str).expect("Read Name Fail");
            pushed.name = read_str.trim().parse().unwrap();
            println!("Enter weight of the candy bar:");
            read_str.clear();
            std::io::stdin().read_line(&mut read_str).expect("Read weight Fail");
            pushed.weight = read_str.trim().parse::<f64>().expect("parse f64 fail");
            read_str.clear();
            println!("Enter calories(an integer value) in the Candy bar:");
            std::io::stdin().read_line(&mut read_str).expect("Read calories Fail");
            pushed.calories = read_str.trim().parse::<i64>().expect("parse i64 fail");
            candy_bars.push(pushed);
            read_str.clear();
        }
        for (order, iter) in candy_bars.iter().enumerate() {
            println!(
                r#"name of the CandyBar {0} : {1}
weight of the CandyBar {0} : {2}
the calories of CandyBar {0} : {3}"#, order, iter.name, iter.weight, iter.calories);
        }
    }
}

fn main() {
    lab04_02::main();
}