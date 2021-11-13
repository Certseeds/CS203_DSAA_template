pub mod matrix_str {
    use std::borrow::Borrow;
    use std::fmt::Display;
    use std::ops::AddAssign;

    use crate::lib::{MAX_COLS, MAX_ROWS};

    pub struct MatrixS {
        pub(crate) inside: Vec<Vec<String>>,
    }

    impl MatrixS {
        pub fn set_matrix(&mut self, array1: &Vec<Vec<&str>>) {
            self.inside = vec![vec!["".to_string(); MAX_COLS]; MAX_ROWS];
            for (c1, line) in array1.iter().enumerate() {
                for (c2, ele) in line.iter().enumerate() {
                    self.inside[c1][c2] = ele.to_string();
                }
            }
        }
        pub fn set_matrix2(&mut self, array1: &[[&str; MAX_COLS]; MAX_ROWS]) {
            for (c1, line) in array1.iter().enumerate() {
                for (c2, ele) in line.iter().enumerate() {
                    self.inside[c1][c2] = ele.to_string();
                }
            }
        }
    }

    impl MatrixS {
        pub fn print_matrix(&self) {
            for line in self.inside.iter() {
                for ele in line.iter() {
                    print!("{} ", ele);
                }
                println!();
            }
        }
    }

    impl MatrixS {
        pub fn add_matrix(&mut self, array1: &Vec<Vec<&str>>) {
            for (c1, line) in array1.iter().enumerate() {
                for (c2, ele) in line.iter().enumerate() {
                    self.inside[c1][c2].add_assign(&*ele.clone());
                }
            }
        }
        pub fn add_matrix2(&mut self, array1: &[[&str; MAX_COLS]; MAX_ROWS]) {
            for (c1, line) in array1.iter().enumerate() {
                for (c2, ele) in line.iter().enumerate() {
                    self.inside[c1][c2].add_assign(&*ele.clone());
                }
            }
        }
    }
}