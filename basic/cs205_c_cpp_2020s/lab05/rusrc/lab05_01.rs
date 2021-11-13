mod lab05_01 {
    pub(crate) fn main() {
        let mut input_number = 0i64;
        let mut sum = 0i64;
        let mut input_str = String::new();
        loop {
            println!("Enter integer number : ");
            std::io::stdin().read_line(&mut input_str).expect("Input Fail");
            input_number = input_str.trim().parse::<i64>().expect("Input Should Be Integer");
            sum += input_number;
            println!("The cumulative sum of the entries to data is : {}", sum);
            input_str.clear();
            if input_number == 0 {
                break;
            }
        }
    }
}

fn main() {
    lab05_01::main();
}