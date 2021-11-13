pub(crate) mod city {
    pub struct City {
        pub name: String,
        pub latitude: f64,
        pub longitude: f64,
    }

    impl City {
        pub fn distance(&self, other: &City) -> String {
            use std::f64::consts::PI as PI;
            const RADIUS_EARTH: f64 = 6371f64;
            const PI180: f64 = PI / 180f64;
            let la1 = (90f64 - self.latitude).abs() * PI180;
            let la2 = (90f64 - other.latitude).abs() * PI180;
            let distance1 = la1.sin() * la2.sin() *
                ((self.longitude - other.longitude).abs() * PI180).cos();
            let distance_sum = distance1 + la1.cos() * la2.cos();
            format!("The distance between {} and {} is {:.4} km", self.name, other.name, RADIUS_EARTH * distance_sum.acos())
        }

        pub fn legal(&self) -> bool {
            let mut will_return = true;
            will_return = will_return && (self.latitude != 0f64) && (self.latitude > -90f64) && (self.latitude < 90f64)
                && (self.longitude != 0f64) && (self.longitude > -180f64) && (self.longitude < 180f64);
            return will_return;
        }
    }

    #[cfg(test)]
    mod tests {
        #[test]
        fn test() {
            assert_eq!(2, 2);
        }
    }
}
