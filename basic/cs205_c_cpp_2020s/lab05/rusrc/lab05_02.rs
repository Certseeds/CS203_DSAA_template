mod lab05_02 {
    pub(crate) fn main() {
        println!("Enter Words (End Count when Find 'Done')");
        let mut input_str = String::new();
        let done = "done";
        let mut count = 0;
        'unlim: loop {
            std::io::stdin().read_line(&mut input_str).expect("Read Fail");
            let word_vec: Vec<&str> = input_str.split(' ').collect();
            for (iter, order) in word_vec.iter().enumerate() {
                let word = order.trim();
                if word.len() != 0 {
                    if word == done {
                        break 'unlim;
                    }
                    count += 1;
                }
            }
            input_str.clear();
        }

        println!("{}", count);
    }
}

fn main() {
    lab05_02::main();
}