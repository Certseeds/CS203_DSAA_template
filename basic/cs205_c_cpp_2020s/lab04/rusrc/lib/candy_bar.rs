pub mod candy_bar {
    use std::fmt;

    #[derive(Clone)]
    pub struct CandyBar {
        pub name: String,
        pub weight: f64,
        pub calories: i64,
    }

    impl fmt::Display for CandyBar {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            return write!(f, r#"Brand: {}
Weight: {}
Calorie: {}"#, self.name, self.weight, self.calories);
        }
    }

    impl Default for CandyBar {
        fn default() -> CandyBar {
            return CandyBar {
                name: "".to_string(),
                weight: 0.0f64,
                calories: 0i64,
            };
        }
    }
}