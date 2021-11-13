pub mod lab02_02 {
    use std::{fmt, io};

    const HOURS_NUM: i64 = 24;
    const MINUTE_NUM: i64 = 60;
    const SECOND_NUM: i64 = 60;

    pub(crate) fn main() {
        let mut number: i64 = 0;
        let mut input_num = String::new();
        while number == 0 {
            println!("Please Input a Number:");
            io::stdin()
                .read_line(&mut input_num)
                .expect("Failed to read line");
            number = match input_num.trim().parse::<i64>() {
                Ok(n) => { n }
                Err(_) => {
                    print!("Input not Integer: {} ", input_num);
                    0i64
                }
            };
            input_num.clear();
        };

        print!("{} ", number);
        println!("{}", parse_int64(number));
    }

    pub fn parse_int64(mut num: i64) -> Time {
        let mut times = [0, 0, 0];
        times[0] = num / (HOURS_NUM * MINUTE_NUM * SECOND_NUM);
        num = num % (HOURS_NUM * MINUTE_NUM * SECOND_NUM);
        times[1] = num / (MINUTE_NUM * SECOND_NUM);
        num = num % (MINUTE_NUM * SECOND_NUM);
        times[2] = num / SECOND_NUM;
        num = num % SECOND_NUM;
        return Time {
            days: times[0],
            hours: times[1] as i8,
            minutes: times[2] as i8,
            seconds: num as i8,
        };
    }

    #[derive(Eq, PartialEq, Debug)]
    pub struct Time {
        pub days: i64,
        pub hours: i8,
        pub minutes: i8,
        pub seconds: i8,
    }

    impl fmt::Display for Time {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "seconds = {} days, {} hours, {} minutes, {} seconds",
                   self.days, self.hours, self.minutes, self.seconds)
        }
    }
}

pub fn main() {
    lab02_02::main();
}

