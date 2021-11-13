mod lib;

mod lab12_01 {
    use crate::lib::complex::complex::Complex;

    pub(crate) fn main() {
        let a = Complex { real: 3.0f64, imag: 4.0f64 };
        let b = Complex { real: 2.0f64, imag: 6.0f64 };
        println!("b is {}", b);
        println!("!b is {}", !b);
        println!("a is {}", a);
        println!("a + b is {}", a + b);
        println!("a - b is {}", a - b);
        println!("a * b is {}", a * b);
        println!("2 * a is {}", 2 * b);
        let c = b;

        println!("b==c is {}", b == c);
        println!("b!=c is {}", b != c);
        println!("a==c is {}", a == c);
        println!("Enter a complex number : ");
        let mut input_str = String::new();
        std::io::stdin().read_line(&mut input_str);
        let d = input_str.trim().parse::<Complex>().expect("parse fail");
        println!("d is {}", d);
    }
}

fn main() {
    lab12_01::main();
}