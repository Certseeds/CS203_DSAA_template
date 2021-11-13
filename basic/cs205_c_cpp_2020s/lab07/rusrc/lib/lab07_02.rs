pub mod book {
    use std::fmt;

    pub struct Book {
        pub maker: [char; 40],
        pub height: f64,
        pub width: f64,
        pub length: f64,
        pub volume: f64,
    }

    pub fn cal_by_val(book: Book) {
        println!("{}", &book);
    }

    pub fn cal_by_pointer(book: *mut Book) {
        unsafe {
            println!("{}", *book);
        }
    }

    pub fn cal_by_ref(book: &Book) {
        println!("{}", &book);
    }

    impl fmt::Display for Book {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            let s: String = self.maker.iter().collect();
            return write!(f, r#"{} {} {} {} {}"#, s, self.height, self.width, self.length, self.volume);
        }
    }
}