mod lib;

mod lab14_02 {
    use std::fmt::Display;
    use std::ops::AddAssign;

    use crate::lib::{MAX_COLS, MAX_ROWS};
    use crate::lib::matrix::matrix::Matrix;
    use crate::lib::matrix_str::matrix_str::MatrixS;

    fn use_matrix_template<T: Display + AddAssign + Clone>(m: &mut Matrix<T>,
                                                           array1: &Vec<Vec<T>>,
                                                           array2: &Vec<Vec<T>>) {
        m.set_matrix(&array1);
        println!("Matrix set to first array");
        m.print_matrix();
        m.add_matrix(&array2);
        println!("Matrix incremented by second array");
        m.print_matrix();
    }

    fn use_matrix_template2<T: Display + AddAssign + Clone>(m: &mut Matrix<T>,
                                                            array1: &[[T; MAX_COLS]; MAX_ROWS],
                                                            array2: &[[T; MAX_COLS]; MAX_ROWS], ) {
        m.set_matrix2(&array1);
        println!("Matrix set to first array");
        m.print_matrix();
        m.add_matrix2(&array2);
        println!("Matrix incremented by second array");
        m.print_matrix();
    }

    fn use_matrix_template_str(m: &mut MatrixS,
                               array1: &Vec<Vec<&str>>,
                               array2: &Vec<Vec<&str>>) {
        m.set_matrix(&array1);
        println!("Matrix set to first array");
        m.print_matrix();
        m.add_matrix(&array2);
        println!("Matrix incremented by second array");
        m.print_matrix();
    }

    fn use_matrix_template_str2(m: &mut MatrixS,
                                array1: &[[&str; MAX_COLS]; MAX_ROWS],
                                array2: &[[&str; MAX_COLS]; MAX_ROWS], ) {
        m.set_matrix2(&array1);
        println!("Matrix set to first array");
        m.print_matrix();
        m.add_matrix2(&array2);
        println!("Matrix incremented by second array");
        m.print_matrix();
    }

    pub(crate) fn main() {
        let str1 = vec![
            vec!["Congra", "y", "ar"],
            vec!["alm", "don", "La"]];
        let str2 = vec![
            vec!["tulations", "ou", "e"],
            vec!["ost", "e the", "b!"]];
        const STR3: [[&str; 3]; 2] = [
            ["Congra", "y", "ar", ],
            ["alm", "don", "La", ]];
        const STR4: [[&str; 3]; 2] = [
            ["tulations", "ou", "e"],
            ["ost", "e the", "b!"]];
        let mut string_matrix: MatrixS = MatrixS {
            inside: vec![vec!["".to_string(); MAX_COLS]; MAX_ROWS],
        };
        let num1 = vec![vec![1, 2, 3], vec![4, 5, 6]];
        let num2 = vec![vec![6, 5, 4], vec![3, 2, 1]];
        const NUM3: [[i64; 3]; 2] = [[1, 2, 3], [4, 5, 6]];
        const NUM4: [[i64; 3]; 2] = [[6, 5, 4], [3, 2, 1]];
        let mut int_matrix: Matrix<i64> = Matrix {
            inside: vec![vec![0i64; MAX_COLS]; MAX_ROWS],
        };
        use_matrix_template_str(&mut string_matrix, &str1, &str2);
        use_matrix_template_str2(&mut string_matrix, &STR3, &STR4);
        use_matrix_template(&mut int_matrix, &num1, &num2);
        use_matrix_template2(&mut int_matrix, &NUM3, &NUM4);
    }
}

fn main() {
    lab14_02::main();
}