mod lab08_02 {
    use std::cmp::min;

    pub fn max5<T: PartialOrd>(arr: &[T; 5]) -> &T {
        let mut num = arr.first().expect("length too small");
        for i in arr.iter() {
            num = match i > num {
                true => { i }
                false => { num }
            };
        }
        return num;
    }

    pub(crate) fn main() {
        const INT_ARRAY1: [i32; 5] = [159, 73, 778, 5, 75];
        const DOUBLE_ARRAY1: [f64; 5] = [1.2, -0.23, 6.32, -11.27, 19.8];
        println!("Max int : {}", max5(&INT_ARRAY1));
        println!("Max double : {}", max5(&DOUBLE_ARRAY1));
        const INT_ARRAY2: [i32; 5] = [1, 2, 3, 4, 5];
        const DOUBLE_ARRAY2: [f64; 5] = [1.1, 2.0, 3.0, 4.0, 5.5];
        println!("Max int : {}", max5(&INT_ARRAY2));
        println!("Max double : {}", max5(&DOUBLE_ARRAY2));
    }
}

fn main() { lab08_02::main(); }