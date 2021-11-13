mod lib;

mod ass3_02 {
    use std::io::ErrorKind;
    use std::str::FromStr;

    use crate::lib::lib::read_a_int;

    pub(crate) fn main() {
        let m = read_a_int("m");
        let n = read_a_int("n");
        let mut mat = vec![vec![0i64; n as usize]; m as usize];
        draw(&mut mat, true, (-1, n), 1, (n, m - 1));
        for line in mat.iter() {
            for word in line.iter() {
                print!("{} ", word);
            }
            println!();
        }
    }

    fn draw(mat: &mut Vec<Vec<i64>>, way: bool, begin: (i64, i64), num: i64, length: (i64, i64)) {
        let mut ana = num;
        let mut point = match way {
            true => { (begin.0 + 1, begin.1 - 1) }
            false => { (begin.0 - 1, begin.1 + 1) }
        };
        let xyway = match way {
            true => { (1i64, -1i64) }
            false => { (-1i64, 1i64) }
        };
        if length.0 == 0 {
            return;
        }
        for _ in 0..length.0 {
            if mat[point.0 as usize][point.1 as usize] != 0 {
                break;
            }
            mat[point.0 as usize][point.1 as usize] = ana;
            ana += 1;
            point = (point.0, (point.1 + xyway.1));
        }
        point = (point.0 + xyway.0, (point.1 - xyway.1));
        if length.1 == 0 {
            return;
        }
        for _ in 0..length.1 {
            if mat[point.0 as usize][point.1 as usize] != 0 {
                break;
            }
            mat[point.0 as usize][point.1 as usize] = ana;
            ana += 1;
            point = ((point.0 + xyway.0), point.1);
        }
        //point = (yway.0 + point.0, yway.1 + point.1);
        draw(mat, !way, point, ana, (length.0 - 1, length.1 - 1));
    }
}

fn main() {
    ass3_02::main();
}