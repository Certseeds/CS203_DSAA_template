mod lib;

mod lab08_01 {
    use crate::lib::candy_bar;
    use crate::lib::candy_bar::CandyBar;

    pub(crate) fn main() {
        let mut candy_bar = CandyBar {
            brand: "".to_string(),
            weight: 0.0f64,
            calorie: 0i64,
        };
        CandyBar::set_ref(&mut candy_bar);
        CandyBar::show_ref(&candy_bar);
        unsafe {
            CandyBar::set_pointer(&mut candy_bar);
            CandyBar::show_pointer(&candy_bar);
        }
    }
}

fn main() {
    lab08_01::main();
}