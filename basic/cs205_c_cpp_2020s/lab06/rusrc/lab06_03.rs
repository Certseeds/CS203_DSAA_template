mod lab06_03 {
    pub(crate) fn main() {
        let quiz: f64;
        let midterm: f64;
        let scores: f64;
        let average: f64;
        let grade: char;
        let mut input_str = String::new();
        println!("Input scores between 0 to 100");
        println!("Input quiz Score : ");
        std::io::stdin().read_line(&mut input_str).expect("read fail");
        quiz = input_str.trim().parse::<f64>().expect("quiz parse fail");
        input_str.clear();
        println!("Input midterm Score : ");
        std::io::stdin().read_line(&mut input_str).expect("read fail");
        midterm = input_str.trim().parse::<f64>().expect("midterm parse fail");
        input_str.clear();
        println!("Input final Score : ");
        std::io::stdin().read_line(&mut input_str).expect("read fail");
        scores = input_str.trim().parse::<f64>().expect("scores parse fail");
        input_str.clear();
        average = (quiz + midterm + scores) / 3f64;
        if average >= 90f64 {
            grade = 'A';
        } else if average >= 70f64 {
            grade = 'B';
        } else if average >= 50f64 {
            grade = 'C';
        } else {
            grade = 'F';
        }
        println!(r#"Average is :{}
Grade is :{}"#, average, grade);
    }
}

fn main() {
    lab06_03::main();
}