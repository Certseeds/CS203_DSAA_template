use crate::lib::c_stereo_shape::CStereoShape;
use crate::lib::shape::shape::Shape;

pub struct CSphere {
    base: CStereoShape,
    radius: f64,
}

impl CSphere {
    pub fn default(radius: f64) -> CSphere {
        CSphere {
            base: CStereoShape::default(),
            radius,
        }
    }
}

impl Shape for CSphere {
    fn get_area(&self) -> f64 {
        4.0f64 * std::f64::consts::PI * self.radius * self.radius
    }
    fn get_volumn(&self) -> f64 {
        (4.0f64 / 3.0f64) * std::f64::consts::PI * self.radius * self.radius * self.radius
    }
    fn show(&self) {
        println!(r#"radius is {}
Area is {:5.3}
Volumn is {:5.3}"#, self.radius, self.get_area(), self.get_volumn())
    }
    fn get_num_of_trait(&self) -> i64 {
        CStereoShape::value()
    }
}