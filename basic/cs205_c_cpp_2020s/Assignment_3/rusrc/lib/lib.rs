pub fn read_a_int(info: &str) -> i64 {
    println!("Input number {} :", info);
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("Input Wrong");
    match input_str.trim().parse::<i64>()
    {
        Ok(num) => { num }
        Err(_error) => {
            println!("Please Input Once Again;");
            read_a_int(&info)
        }
    }
}