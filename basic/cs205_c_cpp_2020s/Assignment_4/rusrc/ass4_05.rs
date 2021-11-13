mod ass4_05 {
    const COMMANDS: [&str; 6] = ["start", "stop", "restart", "reload", "status", "exit"];

    pub(crate) fn main() {
        loop {
            println!("<");
            let mut input_str = String::new();
            std::io::stdin().read_line(&mut input_str).expect("read fail");
            let input_str = input_str.trim().to_ascii_lowercase().parse::<String>().expect("Input fail");
            match COMMANDS.iter().position(|&x| x == input_str) {
                None => { println!("Invalid command"); }
                Some(5) => {
                    println!("exit");
                    return;
                }
                Some(num) => { println!("command {} recognized", COMMANDS[num]); }
            }
        }
    }
}

fn main() {
    ass4_05::main();
}