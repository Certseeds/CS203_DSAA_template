mod lab06_01 {
    pub(crate) fn main() {
        println!("Enter ang alphabet : ");
        let mut input_str = String::new();
        std::io::stdin().read_line(&mut input_str).expect("read file");
        let input_str = input_str.to_lowercase();
        let input_str = input_str.trim();
        match input_str.chars().nth(0).expect("Input Should Not Empty") {
            'a' | 'e' | 'i' | 'o' | 'u' => { println!("Vowel") }
            _ => { println!("Consonant") }
        }
    }
}

fn main() {
    lab06_01::main();
}