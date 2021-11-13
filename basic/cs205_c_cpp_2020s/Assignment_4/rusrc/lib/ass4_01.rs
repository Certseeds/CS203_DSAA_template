pub mod ass4 {
    use rand::Rng;
    use std::collections::HashMap;

    const RANGE: (i64, i64) = (2000, 2020);
    pub const LAB_NUMBER: usize = 14usize;

    pub fn question1() -> HashMap<i64, [i64; LAB_NUMBER]> {
        let mut rng = rand::thread_rng();
        let mut score_map: HashMap<i64, [i64; LAB_NUMBER]> = HashMap::new();
        println!("Integer: {}", rng.gen_range(RANGE.0..RANGE.1));
        let mut input_str = String::new();
        std::io::stdin().read_line(&mut input_str).expect("read fail");
        let input_num = input_str.trim().parse::<usize>().expect("input should be int");
        for _ in 0..input_num {
            let mut order = rng.gen_range(RANGE.0..RANGE.1);
            for __ in 0..4 {
                order *= 10;
                order += rng.gen_range(0..10);
            }
            let mut scores: [i64; LAB_NUMBER] = rand::random();
            for iter in 0..LAB_NUMBER {
                scores[iter] = (scores[iter] % 6).abs();
            }
            score_map.insert(order, scores);
        }
        for (key, value) in &score_map {
            print!("{} :", key);
            for v in value.iter() {
                print!(" {}", v);
            }
            println!();
        }
        score_map
    }
}