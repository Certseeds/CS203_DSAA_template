pub mod lib {
    use crate::lib::city::city::City;

    pub fn main() {
        let city1st = read_city("first");
        match city1st.legal() {
            false => { panic!("latitude should belong to [-90,0),(0,+90],longitude should belong to [-180,0),(0,+180]") }
            _ => {}
        }
        let city2nd = read_city("second");
        match city2nd.legal() {
            false => { panic!("latitude should belong to [-90,0),(0,+90],longitude should belong to [-180,0),(0,+180]") }
            _ => {}
        }
        println!("{}", city1st.distance(&city2nd));
    }

    fn read_city(s: &str) -> City {
        let mut input_str = String::new();
        println!("The {} city: ", s);
        std::io::stdin().read_line(&mut input_str).expect("Read Name Fail");
        let str1st = input_str.trim().parse::<String>().expect("Parse Fail");
        input_str.clear();
        println!("The latitude and longitude of {} city: ", s);
        let mut str_vec: Vec<String> = Vec::new();
        while str_vec.len() < 2 {
            std::io::stdin().read_line(&mut input_str).expect("Read Fail");
            for input in input_str.split(" ") {
                str_vec.push(String::from(input));
            }
            input_str.clear();
        }
        let longti1st = str_vec[0].to_string().trim().parse::<f64>().expect("parse longti1st fail");
        let langti1st = str_vec[1].to_string().trim().parse::<f64>().expect("parse longti1st fail");
        println!("{} {}", longti1st, langti1st);
        City {
            name: str1st,
            latitude: longti1st,
            longitude: langti1st,
        }
    }
}
