mod lib;

mod lab07_02 {
    use crate::lib::lab07_02::book;

    pub(crate) fn main() {
        let book1 = book::Book {
            maker: ['a'; 40],
            height: 1.0f64,
            width: 2.0f64,
            length: 3.0f64,
            volume: 4.0f64,
        };
        let mut book2 = Box::new(book::Book {
            maker: ['b'; 40],
            height: 5.0f64,
            width: 6.0f64,
            length: 7.0f64,
            volume: 8.0f64,
        });
        let book2_pointer: *mut book::Book = &mut *book2;
        book::cal_by_ref(&book1);
        book::cal_by_val(book1);
        book::cal_by_pointer(book2_pointer);
    }
}

pub fn main() { lab07_02::main(); }
