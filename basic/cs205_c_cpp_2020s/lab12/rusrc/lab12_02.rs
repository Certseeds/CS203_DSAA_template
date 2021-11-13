mod lib;

mod lab12_02 {
    use crate::lib::number::number::Number;

    pub(crate) fn main() {
        let number1 = Number { number: 20 };
        // RUST DO NOT SUPPORT ++ --
    }
}

fn main() {
    lab12_02::main();
}