pub mod shape {
    pub trait Shape {
        fn get_area(&self) -> f64 {
            0.0f64
        }
        fn get_volumn(&self) -> f64 {
            0.0f64
        }
        fn show(&self) {
            println!()
        }
        fn get_num_of_trait(&self) -> i64 {
            0i64
        }
    }
}