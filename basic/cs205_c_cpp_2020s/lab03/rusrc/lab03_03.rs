mod candy_bar;

mod lab03_03 {
    use crate::candy_bar::candy_bar as CandyBar;

    pub(crate) fn main() {
        let cb_array = [
            CandyBar::CandyBar {
                name: String::from("Mona Coke"),
                weight: 3f64,
                calories: 31i64,
            },
            CandyBar::CandyBar {
                name: String::from("Mona Coke"),
                weight: 11.2f64,
                calories: 45i64,
            }, CandyBar::CandyBar {
                name: String::from("Mona Coke"),
                weight: 91.1f64,
                calories: 92i64,
            }
        ];
        for cb in cb_array.iter() {
            println!("{}", cb);
        }
    }
}

fn main() {
    lab03_03::main();
}