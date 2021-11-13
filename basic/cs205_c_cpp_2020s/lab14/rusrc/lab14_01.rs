mod lab14_01 {
    fn max<T: std::cmp::PartialOrd>(one: T, two: T) -> T {
        let biggest: T;
        if one < two {
            biggest = two;
        } else {
            biggest = one;
        }
        return biggest;
    }

    pub(crate) fn main() {
        let i_one = 3i64;
        let i_two = 5i64;
        println!("the max of {} and {} is {}", i_one, i_two, max(i_one, i_two));
        let d_one = 5.6f64;
        let d_two = 7.3f64;
        println!("the max of {} and {} is {}", d_one, d_two, max(d_one, d_two));
        let s_one = "donkey";
        let s_two = "apple";
        println!("the max of {} and {} is {}", s_one, s_two, max(s_one, s_two));
    }
}

fn main() {
    lab14_01::main();
}