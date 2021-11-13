mod lab02_03 {
    pub(crate) fn main() {
        let only_a_char: char;
        let only_a_num: i64;
        let only_a_float: f64;
        let mut read_str = String::new();
        println!("Please Input A Character : ");
        std::io::stdin().read_line(&mut read_str).expect("Read fail");
        only_a_char = read_str.trim().parse::<char>().expect("char fail");
        println!("Please Input A Integer : ");
        read_str.clear();
        std::io::stdin().read_line(&mut read_str).expect("Read fail");
        only_a_num = read_str.trim().parse::<i64>().expect("Integer fail");
        read_str.clear();
        println!("Please Input A Float : ");
        std::io::stdin().read_line(&mut read_str).expect("Read fail");
        only_a_float = read_str.trim().parse::<f64>().expect("Float fail");
        println!("The Character Value that you Entered is : {}", only_a_char);
        println!("The Integer Value that you Entered is : {}", only_a_num);
        println!("The Float Value that you Entered is : {}", only_a_float);
        // TODO, rewrite by byte-by-byte analysis
    }
}

fn main() {
    lab02_03::main();
}