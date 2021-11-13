pub mod city {
    use csv;
    use serde::{Deserialize, Serialize};
    use serde::de::Unexpected::Str;
    use std::error::Error;
    use std::fmt;
    use std::io::Read;
    use std::path::Path;

    use crate::lib::size::size::ARRAY_LENGTH;

    #[derive(Clone, Deserialize)]
    pub struct City {
        pub name: String,
        province: String,
        country: String,
        pub latitude: f64,
        pub longitude: f64,
    }

    impl City {
        pub fn distance(&self, other: &City) -> String {
            use std::f64::consts::PI as PI;
            const RADIUS_EARTH: f64 = 6371f64;
            const PI180: f64 = PI / 180f64;
            let la1 = (90f64 - self.latitude).abs() * PI180;
            let la2 = (90f64 - other.latitude).abs() * PI180;
            let distance1 = la1.sin() * la2.sin() *
                ((self.longitude - other.longitude).abs() * PI180).cos();
            let distance_sum = distance1 + la1.cos() * la2.cos();
            format!("The distance between {} and {} is {:.4} km", self.name, other.name, RADIUS_EARTH * distance_sum.acos())
        }

        pub fn legal(&self) -> bool {
            self.latitude != 0f64 && self.latitude > -90f64 && self.latitude < 90f64
                && self.longitude != 0f64 && self.longitude > -180f64 && self.longitude < 180f64
        }
        pub fn read_file(file: &str) -> Vec<City> {
            let path = Path::new(file);
            let mut city_vec = vec![City::default(); ARRAY_LENGTH];
            let mut csv_file = match std::fs::File::open(&path) {
                Err(why) => panic!("couldn't open {}: {}", path.display(), why.to_string()),
                Ok(file) => file,
            };
            let mut csv_file_inside = String::new();
            csv_file.read_to_string(&mut csv_file_inside).expect("Read File Fail");
            for (count, line) in csv_file_inside.split("\n").enumerate() {
                if count >= ARRAY_LENGTH {
                    eprintln!("Read Unfinished, But Still Can Run");
                    break;
                }
                let mut words = line.split(",");
                city_vec[count].name = words.next().expect("").parse::<String>().unwrap().to_lowercase();
                city_vec[count].province = match words.next() {
                    Some(T) => { T.parse().expect("") }
                    None => {
                        break;
                    }
                };
                city_vec[count].country = words.next().expect("").parse().unwrap();
                city_vec[count].latitude = words.next().expect("a").parse::<f64>().unwrap();
                city_vec[count].longitude = words.next().expect("b").parse::<f64>().unwrap();
            }
            return city_vec;
        }
        pub fn get_city(city_vec: &Vec<City>, s: &str) -> City {
            loop {
                println!("input {} city name, longer than or equal than 3 letter : ", s);
                let mut input_str = String::new();
                std::io::stdin().read_line(&mut input_str).expect("read input fail");
                let input_str = input_str.trim().to_lowercase().parse::<String>().expect("");
                match input_str.len() {
                    0 | 1 | 2 => {
                        println!("please input city name longer than 3 letter");
                        continue;
                    }
                    _ => {}
                }
                let mut orders: Vec<usize> = Vec::new();
                for (order, city) in city_vec.iter().enumerate() {
                    if city.name.contains(&input_str) {
                        orders.push(order);
                    }
                }
                match orders.len() {
                    1 => {
                        let order = orders[0];
                        return city_vec[order].clone();
                    }
                    0 => {
                        println!("No city matches, please input once again ");
                        continue;
                    }
                    _ => {
                        print!("More than one city matches,");
                        println!(" please choose one from those cities using numbers begin at 0");
                        for (or, &order) in orders.iter().enumerate() {
                            let city_name = &city_vec[order].name;
                            println!("{} : {}", or, city_name);
                        }
                        let mut input_str = String::new();
                        std::io::stdin().read_line(&mut input_str).expect("read fail");
                        let input_num = input_str.trim().parse::<usize>().expect("parse fail");
                        if 0 <= input_num && input_num < orders.len() {
                            return city_vec[orders[input_num]].clone();
                        } else {
                            println!("Out of Range, Input Once Again");
                            continue;
                        }
                    }
                }
            }
        }
    }

    impl Default for City {
        fn default() -> City {
            City {
                name: "".to_string(),
                province: "".to_string(),
                country: "".to_string(),
                latitude: 0.0f64,
                longitude: 0.0f64,
            }
        }
    }

    impl fmt::Display for City {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            return write!(f, r#"{} {} {} {} {}"#, self.name, self.province, self.country, self.longitude, self.latitude);
        }
    }
}