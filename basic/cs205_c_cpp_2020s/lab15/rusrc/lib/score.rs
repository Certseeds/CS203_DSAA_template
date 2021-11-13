pub mod score {
    use std::fmt;
    use std::str::FromStr;

    use crate::lib::score::score_error::ScoreError;

    pub struct Score {
        first: i64,
        second: i64,
        third: i64,
        fourth: i64,
    }

    impl Score {
        pub fn calculate_average(&self) -> Result<f64, ScoreError> {
            let nums = [self.first, self.second, self.third, self.fourth];
            for num in nums.iter() {
                if num < &0i64 || num > &100i64 {
                    return Err(ScoreError);
                }
            }
            Ok((nums.iter().sum::<i64>() as f64) / 4.0f64)
        }
    }

    impl fmt::Display for Score {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "{} {} {} {}", self.first, self.second, self.third, self.fourth)
        }
    }

    impl FromStr for Score {
        type Err = std::io::Error;
        fn from_str(s: &str) -> Result<Self, Self::Err> {
            let strvec: Vec<&str> = s.trim()
                .split(' ')
                .collect();
            let first = i64::from_str_radix(strvec[0].trim(), 10).expect("1st error");
            let second = i64::from_str_radix(strvec[1].trim(), 10).expect("2nd error");
            let third = i64::from_str_radix(strvec[2].trim(), 10).expect("3rd error");
            let fourth = i64::from_str_radix(strvec[3].trim(), 10).expect("4th error");
            Ok(Score {
                first,
                second,
                third,
                fourth,
            })
        }
    }
}

mod score_error {
    use std::error::Error;
    use std::fmt;

    #[derive(Debug, Clone)]
    pub struct ScoreError;

    impl fmt::Display for ScoreError {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "Score Should In 0-100 as int")
        }
    }

    // 实现 error::Error 这个 trait, 对DoubleError 进行包装
    impl Error for ScoreError {
        fn description(&self) -> &str {
            "Score Should In 0-100 as int"
        }

        fn cause(&self) -> Option<&dyn Error> {
            // Generic error, underlying cause isn't tracked.
            None
        }
    }
}