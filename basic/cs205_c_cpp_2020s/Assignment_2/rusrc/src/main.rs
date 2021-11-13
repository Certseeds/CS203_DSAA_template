pub mod lib;

mod ass02 {
    use std::{env, fs};
    use std::path::Path;
    use std::path::PathBuf;

    use crate::lib::city::city::City as City;

    pub(crate) fn main() {
        println!("{:?}", fs::canonicalize(PathBuf::from("./")));
        const WORLD_CITIES_CSV: &str = "./Assignment_2/test/world_cities.csv";
        let city_array = City::read_file(WORLD_CITIES_CSV);
        loop {
            let city1st = City::get_city(&city_array, "1st");
            let city2nd = City::get_city(&city_array, "2nd");
            println!("{}", city1st.distance(&city2nd));
            println!("input Bye to break out");
            let mut input_str = String::new();
            std::io::stdin().read_line(&mut input_str).expect("read fail");
            let input_str = input_str.to_lowercase().trim().parse::<String>().expect("parse fail");
            if input_str == "bye" {
                return;
            }
            println!("{}", city1st.distance(&city2nd));
        }
    }
}

fn main() {
    ass02::main();
}