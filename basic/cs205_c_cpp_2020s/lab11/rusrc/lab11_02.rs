mod lib;

mod lab11_02 {
    use crate::lib::rectangle::Rectangle;

    pub(crate) fn main() {
        let rectangle1 = Rectangle {
            width: 4.0f64,
            height: 40.0f64,
        };
        rectangle1.display();
        let rectangle2 = Rectangle {
            width: 3.5f64,
            height: 35.9f64,
        };
        rectangle2.display();
    }
}

fn main() {
    lab11_02::main();
}