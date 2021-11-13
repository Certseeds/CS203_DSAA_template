mod lab04_03 {
    pub(crate) fn main() {
        let mut pointers = Box::new([0i64; 5]);
        let mut read_str = String::new();
        for i in 0..pointers.len() {
            println!("Input the {} Number: ", i);
            std::io::stdin().read_line(&mut read_str).expect("read fail");
            pointers[i] = read_str.trim().parse::<i64>().expect("parse fail");
            read_str.clear();
        }
        for (order, iter) in pointers.iter().rev().enumerate() {
            println!("number {} is : {}", order, iter);
        }
    }
}

fn main() {
    lab04_03::main();
}