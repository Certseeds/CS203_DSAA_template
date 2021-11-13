mod lab02_01 {
    pub fn main() {
        println!("Result:");
        println!("x value y value  Expressions     Result");
        const X: i32 = 10;
        const Y: i32 = 5;
        let evalution = [
            Output { expr: String::from("y+3"), left: Y, right: 3, function: |x, y| { x + y } },
            Output { expr: String::from("y-2"), left: Y, right: 2, function: |x, y| { x - y } },
            Output { expr: String::from("y*5"), left: Y, right: 5, function: |x, y| { x * y } },
            Output { expr: String::from("x/y"), left: X, right: Y, function: |x, y| { x / y } },
            Output { expr: String::from("x%y"), left: X, right: Y, function: |x, y| { x % y } }
        ];
        for func in evalution.iter() {
            println!("{} |    {} |      x={}           |x={}   ",
                     X, Y, func.expr, (func.function)(&func.left, &func.right), );
        }
    }

    struct Output<T> {
        expr: String,
        function: fn(&T, &T) -> T,
        left: T,
        right: T,
    }
}

fn main() {
    lab02_01::main();
}