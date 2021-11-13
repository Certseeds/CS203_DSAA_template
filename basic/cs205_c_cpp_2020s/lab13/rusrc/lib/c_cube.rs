use crate::lib::c_stereo_shape::CStereoShape;
use crate::lib::shape::shape::Shape;

pub struct CCube {
    base: CStereoShape,
    length: f64,
    height: f64,
    width: f64,
}

impl CCube {
    pub fn default(length: f64, height: f64, width: f64) -> CCube {
        CCube {
            base: CStereoShape::default(),
            length,
            height,
            width,
        }
    }
}

impl Shape for CCube {
    fn get_area(&self) -> f64 {
        2.0f64 * (self.length * self.height +
            self.height * self.width +
            self.width * self.length)
    }
    fn get_volumn(&self) -> f64 {
        self.length * self.height * self.width
    }
    fn show(&self) {
        println!(r#"length is {}
height is {}
width is {}
Area is {:5.3}
Volumn is {:5.3}"#, self.length, self.height, self.width, self.get_area(), self.get_volumn())
    }
    fn get_num_of_trait(&self) -> i64 {
        CStereoShape::value()
    }
}