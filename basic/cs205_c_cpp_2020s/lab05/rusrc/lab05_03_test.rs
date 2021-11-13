mod lab05_03;

#[cfg(test)]
mod tests {
    fn judge(func: fn(i64) -> i64) {
        assert_eq!(0, func(0));
        assert_eq!(1, func(1));
        assert_eq!(1, func(2));
        assert_eq!(2, func(3));
        assert_eq!(3, func(4));
        assert_eq!(5, func(5));
        assert_eq!(8, func(6));
    }

    pub fn test_warpper() {
        use crate::lab05_03::lab05_03 as lab05_03;
        judge(lab05_03::fib_do_while);
        judge(lab05_03::fib_while);
        judge(lab05_03::fib_if_for);
        judge(lab05_03::fib_rec);
        judge(lab05_03::fib_for);
    }

    #[test]
    pub(crate) fn exploration() {
        test_warpper();
    }
}
