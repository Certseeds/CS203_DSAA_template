mod lab02_02;

#[cfg(test)]
mod tests {
    mod lab02_02 {
        use crate::lab02_02 as outer;
        use crate::lab02_02::lab02_02 as moder;

        #[test]
        fn test_parse() {
            assert_eq!(moder::Time {
                days: 365i64,
                hours: 17i8,
                minutes: 46i8,
                seconds: 40i8,
            }, moder::parse_int64(31600000i64));
            assert_eq!(moder::Time {
                days: 4i64,
                hours: 5i8,
                minutes: 23i8,
                seconds: 20i8,
            }, moder::parse_int64(365000i64));
        }
    }
}
