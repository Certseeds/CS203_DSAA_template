pub mod lab05_03 {
    pub fn fib_rec(i: i64) -> i64 {
        match i {
            0 | 1 => i,
            _ => fib_rec(i - 1) + fib_rec(i - 2)
        }
    }

    pub fn fib_while(i: i64) -> i64 {
        match i {
            0 | 1 => i,
            _ => {
                let mut count = 0i64;
                let mut tup = (0i64, 1i64);
                while count < i - 1 {
                    tup = (tup.1, tup.0 + tup.1);
                    count += 1;
                }
                tup.1
            }
        }
    }

    pub fn fib_for(i: i64) -> i64 {
        match i {
            0 | 1 => i,
            _ => {
                let mut tup = (0i64, 1i64);
                for _ in 0..i - 1 {
                    tup = (tup.1, tup.0 + tup.1);
                }
                tup.1
            }
        }
    }

    pub fn fib_do_while(i: i64) -> i64 {
        match i {
            0 | 1 => i,
            _ => {
                let mut tup = (0i64, 1i64);
                let mut count = 0;
                loop {
                    tup = (tup.1, tup.0 + tup.1);
                    count += 1;
                    if count == i - 1 {
                        break;
                    }
                }
                tup.1
            }
        }
    }

    pub fn fib_if_for(i: i64) -> i64 {
        if i == 0 || i == 1 {
            return i;
        }
        {
            let mut tup = (0i64, 1i64);
            for _ in 0..i - 1 {
                tup = (tup.1, tup.0 + tup.1);
            }
            tup.1
        }
    }
}

fn main() {}