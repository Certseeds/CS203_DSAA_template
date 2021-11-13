pub mod matrix {
    use std::borrow::Borrow;
    use std::fmt::Display;
    use std::ops::AddAssign;

    use crate::lib::{MAX_COLS, MAX_ROWS};

    pub struct Matrix<T> {
        pub(crate) inside: Vec<Vec<T>>,
    }

    impl<T: Clone> Matrix<T> {
        pub fn set_matrix(&mut self, array1: &Vec<Vec<T>>) {
            self.inside = array1.clone();
        }
        pub fn set_matrix2(&mut self, array1: &[[T; MAX_COLS]; MAX_ROWS]) {
            for (c1, line) in array1.iter().enumerate() {
                for (c2, ele) in line.iter().enumerate() {
                    self.inside[c1][c2] = ele.clone();
                }
            }
        }
    }

    impl<T: Display> Matrix<T> {
        pub fn print_matrix(&self) {
            for line in self.inside.iter() {
                for ele in line.iter() {
                    print!("{} ", ele);
                }
                println!();
            }
        }
    }

    impl<T: AddAssign + Clone> Matrix<T> {
        pub fn add_matrix(&mut self, array1: &Vec<Vec<T>>) {
            for (c1, line) in array1.iter().enumerate() {
                for (c2, ele) in line.iter().enumerate() {
                    self.inside[c1][c2].add_assign(ele.clone());
                }
            }
        }
        pub fn add_matrix2(&mut self, array1: &[[T; MAX_COLS]; MAX_ROWS]) {
            for (c1, line) in array1.iter().enumerate() {
                for (c2, ele) in line.iter().enumerate() {
                    self.inside[c1][c2].add_assign(ele.clone());
                }
            }
        }
    }
}