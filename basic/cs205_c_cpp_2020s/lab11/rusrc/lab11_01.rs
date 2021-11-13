mod lib;

mod lab11_01 {
    use crate::lib::candy_bar::CandyBar;

    pub(crate) fn main() {
        let mut candybar = CandyBar {
            brand: "".to_string(),
            weight: 0.0,
            calorie: 0,
        };
        candybar.set_candy_bar();
        candybar.show_candy_bar();
    }
}

fn main() {
    lab11_01::main();
}