mod candy_bar;

mod lab03_01 {
    use crate::candy_bar::candy_bar as CandyBar;

    pub(crate) fn main() {
        let candy_bar = CandyBar::CandyBar {
            name: String::from("Mocha Munch"),
            weight: 2.3,
            calories: 350,
        };
        println!("{}", candy_bar);
    }
}

fn main() {
    lab03_01::main();
}