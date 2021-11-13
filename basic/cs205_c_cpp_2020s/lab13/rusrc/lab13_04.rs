pub mod lib;

mod lab13_04 {
    use crate::lib::c_cube::CCube;
    use crate::lib::c_sphere::CSphere;
    use crate::lib::c_stereo_shape;
    use crate::lib::c_stereo_shape::CStereoShape;
    use crate::lib::shape::shape::Shape;

    pub(crate) fn main() {
        let a_cube = CCube::default(4.0f64, 5.0f64, 6.0f64);
        println!("  value is {}", CStereoShape::value());
        let c_sphere = CSphere::default(7.9f64);
        println!("  value is {}", CStereoShape::value());
        let mut shape: Box<dyn Shape> = Box::new(a_cube);
        println!("  value is {}", CStereoShape::value());
        shape.show();
        println!("  value is {}", CStereoShape::value());
        shape = Box::new(c_sphere);
        println!("  value is {}", CStereoShape::value());
        shape.show();
        println!("  value is {}", CStereoShape::value());
    }
}

fn main() {
    lab13_04::main();
}