pub mod ass4 {
    use csv;
    use rand::Rng;
    use std::collections::HashMap;
    use std::path::Path;

    use crate::lib::ass4_01::ass4;
    use crate::lib::ass4_01::ass4::LAB_NUMBER;

    pub fn question3() -> HashMap<i64, [i64; LAB_NUMBER]> {
        const LAB_SCORES_CSV: &str = "./Assignment_4/lab_records.csv";
        let path = Path::new(LAB_SCORES_CSV);
        let mut score_map: HashMap<i64, [i64; LAB_NUMBER]> = HashMap::new();
        let mut rdr = csv::Reader::from_path(path).expect("read file fail");
        for result in rdr.records() {
            let record = result.expect("Do not have this line");
            let mut rec_iter = record.iter();
            println!("{:?}", record);
            let key = rec_iter.next().expect("Even not have first ID").trim().parse::<i64>().expect("parse fail");
            let mut value = [0i64; LAB_NUMBER];
            for order in 0..LAB_NUMBER {
                value[order] = rec_iter.next().expect("Score not enough").trim().parse::<i64>().expect("parse fail");
            }
            score_map.insert(key, value);
        }
        score_map
    }
}