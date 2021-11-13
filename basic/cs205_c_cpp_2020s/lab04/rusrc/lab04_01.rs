pub mod lib;

mod lab04_01 {
    use crate::lib::pizza::pizza::Pizza as Pizza;

    pub(crate) fn main() {
        let mut read_str = String::new();
        let name: String;
        let diameter: f64;
        let weight: f64;
        println!("Input name of the pizza : ");
        std::io::stdin().read_line(&mut read_str).expect("Read Name Fail");
        name = read_str.trim().parse().unwrap();
        println!("Input the diameter of pizza : ");
        read_str.clear();
        std::io::stdin().read_line(&mut read_str).expect("Read weight Fail");
        diameter = read_str.trim().parse::<f64>().expect("parse f64 fail");
        read_str.clear();
        println!("Input the weight of pizza : ");
        std::io::stdin().read_line(&mut read_str).expect("Read calories Fail");
        weight = read_str.trim().parse::<f64>().expect("parse i64 fail");
        let pizza = Pizza {
            name,
            diameter,
            weight,
        };
        println!("{}", pizza);
    }
}

fn main() {
    lab04_01::main();
}
