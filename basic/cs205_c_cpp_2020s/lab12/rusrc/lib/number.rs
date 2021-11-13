pub mod number {
    use std::fmt;

    pub struct Number {
        pub number: i64,
    }

    impl fmt::Display for Number {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            return write!(f, r#"number is {}"#, self.number);
        }
    }
}