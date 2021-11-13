pub mod lib;

mod lab13_01 {
    use crate::lib::c_stereo_shape;
    use crate::lib::c_stereo_shape::CStereoShape;
    use crate::lib::shape::shape::Shape;

    pub(crate) fn main() {
        let css1 = CStereoShape::default();
        println!("{}", css1.get_area());
        println!("{}", css1.get_volumn());
        css1.show();
        println!("value is {}", CStereoShape::value());
    }
}

fn main() {
    lab13_01::main();
}