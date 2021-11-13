use std::fmt;

pub mod complex {
    use std::{fmt, ops};
    use std::ops::Not;
    use std::str::FromStr;

    #[derive(PartialEq, Clone, Copy)]
    pub struct Complex {
        pub(crate) real: f64,
        pub(crate) imag: f64,
    }

    impl ops::Add<Complex> for Complex {
        type Output = Complex;

        fn add(self, _rhs: Complex) -> Complex {
            Self { real: self.real + _rhs.real, imag: self.imag + _rhs.imag }
        }
    }

    impl ops::Sub<Complex> for Complex {
        type Output = Complex;
        fn sub(self, _rhs: Complex) -> Complex {
            Self { real: self.real - _rhs.real, imag: self.imag - _rhs.imag }
        }
    }

    impl ops::Mul<Complex> for Complex {
        type Output = Complex;
        fn mul(self, _rhs: Complex) -> Complex {
            Self { real: self.real * _rhs.real, imag: self.imag * _rhs.imag }
        }
    }

    impl ops::Mul<Complex> for i64 {
        type Output = Complex;
        fn mul(self, _rhs: Complex) -> Complex {
            Complex { real: self as f64 * _rhs.real, imag: self as f64 * _rhs.imag }
        }
    }

    impl ops::Div<Complex> for Complex {
        type Output = Complex;
        fn div(self, _rhs: Complex) -> Complex {
            Self { real: self.real / _rhs.real, imag: self.imag / _rhs.imag }
        }
    }

    impl ops::Not for Complex {
        type Output = Complex;
        fn not(self) -> Self::Output {
            Self { real: -self.real, imag: -self.imag }
        }
    }

    impl fmt::Display for Complex {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            return write!(f, r#"{} + {}i"#, self.real, self.imag);
        }
    }

    impl FromStr for Complex {
        type Err = std::io::Error;
        fn from_str(s: &str) -> Result<Self, Self::Err> {
            let strvec: Vec<&str> = s.trim()
                .split(' ').collect();
            let real = usize::from_str_radix(strvec[0].trim(), 10).expect("real error");
            let imag = usize::from_str_radix(strvec[1].trim(), 10).expect("imag error");
            Ok(Complex {
                real: real as f64,
                imag: imag as f64,
            })
        }
    }
}