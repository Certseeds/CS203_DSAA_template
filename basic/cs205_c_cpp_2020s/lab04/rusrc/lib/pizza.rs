pub mod pizza {
    use std::fmt;

    pub struct Pizza {
        pub name: String,
        pub diameter: f64,
        pub weight: f64,
    }

    impl fmt::Display for Pizza {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            return write!(f, r#"Name of the pizza : {}
diameter of the pizza : {}
weight of the pizza : {}"#, self.name, self.diameter, self.weight);
        }
    }
}
