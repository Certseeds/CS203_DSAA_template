mod lab05_04 {
    pub(crate) fn main() {
        for i in 1..8 {
            for j in 0..i {
                print!("{}", j + 1);
            }
            for _ in i..7 {
                print!("*")
            }
            println!();
        }
    }
}

fn main() {
    lab05_04::main()
}