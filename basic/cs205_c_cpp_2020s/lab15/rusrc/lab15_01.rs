use lib::score::score::Score;

mod lib;

fn main() {
    let mut input_str = String::new();
    std::io::stdin().read_line(&mut input_str).expect("read fail");
    let score_input = input_str.trim().parse::<Score>();
    if let Ok(score_input) = score_input {
        println!("{}", score_input);
        match score_input.calculate_average() {
            Ok(t) => { println!("{}", t) }
            Err(e) => { println!("{}", e) }
        };
    }
}