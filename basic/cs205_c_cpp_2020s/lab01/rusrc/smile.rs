fn main() {
    for i in 0..3 {
        for _j in i..3 {
            smile();
        }
        println!();
    }
}

fn smile() {
    print!("Smile!");
}