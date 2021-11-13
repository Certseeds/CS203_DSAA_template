pub mod ass4 {
    use rand::Rng;
    use std::collections::HashMap;

    use crate::lib::ass4_01::ass4;
    use crate::lib::ass4_01::ass4::LAB_NUMBER;

    pub fn question2(m: &HashMap<i64, [i64; LAB_NUMBER]>) {
        for (k, v) in m {
            match v.iter().filter(|&&x| x == 0i64).count() {
                0usize | 1usize | 2usize => {}
                _ => { println!("{}", k) }
            }
        }
    }
}