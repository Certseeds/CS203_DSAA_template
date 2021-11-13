pub mod lib;

mod lab13_02 {
    use crate::lib::c_stereo_shape;
    use crate::lib::c_stereo_shape::CStereoShape;
    use crate::lib::shape::shape::Shape;

    pub(crate) fn main() {
        let css2 = Box::new(CStereoShape::default());
        println!("{}", (*css2).get_area());
        println!("{}", (*css2).get_volumn());
        (*css2).show();
        println!("value is {}", CStereoShape::value());
    }
}

fn main() {
    lab13_02::main();
}