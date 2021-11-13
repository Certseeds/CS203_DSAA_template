pub mod ass4 {
    use std::collections::HashMap;

    use crate::lib::ass4_01::ass4;
    use crate::lib::ass4_01::ass4::LAB_NUMBER;

    pub fn question4(m: &HashMap<i64, [i64; LAB_NUMBER]>) {
        let mut avg = [0i64; LAB_NUMBER];
        for (_key, value) in m.iter() {
            for order in 0..LAB_NUMBER {
                avg[order] += value[order];
            }
        }
        let avg_all = avg.iter().sum();
        for (order, value) in avg.iter().enumerate() {
            //println!("{} {}", value, avg_all);
            if (value * (LAB_NUMBER as i64)) < avg_all {
                println!("{}", order + 1);
            }
        }
    }
}